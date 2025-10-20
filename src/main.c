#include <stdio.h>

#define NOB_IMPLEMENTATION
#define NOB_STRIP_PREFIX
#include "../nob.h"

_Bool cp_template_to(const char *dst_path);
void print_help();

int main(int argc, char **argv) {

  switch (argc) {
  case 1:
    cp_template_to(get_current_dir_temp());
    break;
  case 2:
    cp_template_to(argv[1]);
    break;
  default:
    print_help();
    break;
  }
  return 0;
}
_Bool cp_template_to(const char *dst_path) {

  if (!mkdir_if_not_exists(dst_path))
    return false;
  set_current_dir(dst_path);
  if (file_exists("nob.c")) {
    printf("nob.c already exists, aborting.");
    return false;
  }
  if (!file_exists(TEMPLATE_PATH)) {
    nob_log(ERROR,
            "Template folder \"" TEMPLATE_PATH
            "\" doesn't exist. Aborting. (Create that folder or recompile "
            "nob.helper with different TEMPLATE_PATH that you desire.)");
    return false;
  }
  if (!copy_directory_recursively(TEMPLATE_PATH, get_current_dir_temp())) {
    return false;
  }
  return true;
}
void print_help() { printf("help"); }
