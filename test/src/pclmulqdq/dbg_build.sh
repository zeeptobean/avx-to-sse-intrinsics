gcc -g3 -Wall -Wextra -pedantic machine_run.c -c -o ../bin/machine_run.o -mpclmul -msse2
gcc -g3 -Wall -Wextra -pedantic emulate_run.c -c -o ../bin/emulate_run.o
gcc -g3 -Wall -Wextra -pedantic test.c ../bin/machine_run.o ../bin/emulate_run.o -o ../bin/test