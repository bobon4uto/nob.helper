# nob.helper
Utility to quickly setup build system using [nob.h](https://github.com/tsoding/nob.h/)
It's actually very simple - it just copies nob.c and nob.h, compiles and runs it.
Edit nob.c to any template you like, the one in here is just an example that does nothing. 
I found it to be a good idea to create such a utility, because I found myself copypasting my own nob.c from project to project, since they follow similar structure. with nobh I can write 1 (one[uno]) nob.c that will have all the basic stuff and then I just roll from here.
"Utility" is just a bash script. creating a c program in nob would be better, but I'm kinda lazy to do so.

