#include <stdio.h>
#define NOB_IMPLEMENTATION
#define NOB_STRIP_PREFIX
#include "nob.h"

#define SRC_FOLDER "src/"
#define BUILD_FOLDER "build/"

Cmd cmd0 = {0};
Cmd *cmd = &cmd0;

_Bool compile(const char *template_path) {
  String_Builder sb = {0};
  sb_append_cstr(&sb, "-DTEMPLATE_PATH=");
  sb_append_cstr(&sb, template_path);
  nob_cc(cmd);
  nob_cc_flags(cmd);
  nob_cc_inputs(cmd, SRC_FOLDER "main.c");
  nob_cc_output(cmd, BUILD_FOLDER "nobh");
  cmd_append(cmd, sb.items);
  return cmd_run(cmd);
}
void info() {
  nob_log(INFO,
          "Done with normal compilation. For compilation with installation, "
          "run ./nob -I /path/to/template if no path to template is specified,"
          " it is assumed to be /usr/local/share/nobh");
}
void print_help() { printf("help"); }

int main(int argc, char **argv) {
  NOB_GO_REBUILD_URSELF(argc, argv);
  const char *template_path = "/usr/local/share/nobh";
  _Bool install = false;
  switch (argc) {
  case 1:
    compile(template_path);
    info();
    return 0;
    break;
  default:
    for (int i = 1; i < argc; ++i) {
      if (argv[i][0] == '-') {
        if (argv[i][1] == 'I') {
          install = true;
        } else {
          print_help();
        }
      } else {
        template_path = argv[i];
      }
    }
  }

  if (!compile(template_path))
    return 1;

  copy_directory_recursively("template/", template_path);

  cmd_append(cmd, "build/nobh");
  cmd_run(cmd);
  return 0;
}
