# nob.helper
Utility to quickly setup build system using [nob.h](https://github.com/tsoding/nob.h/)
It's actually very simple - it just copies nob.c and nob.h, compiles and runs it.
Edit template folder to any template you like, the one in here is just an example that does nothing. 
I found it to be a good idea to create such a utility, because I found myself copypasting my own nob.c from project to project, since they follow similar structure. with nobh I can write 1 (one[uno]) nob.c that will have all the basic stuff and then I just roll from here.
"Utility" is just a C program that uses nob.h folder copy. You can just make a bash alias that copies some template folder to current dir, and it will work just fine. 
# usage
'''
nobh <project_folder>
'''
If none cspecified, it is assumed to be the current one. nobh will not copy, if it finds already existing nob.c.

