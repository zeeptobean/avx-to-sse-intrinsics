gcc -O2 -Wall -Wextra -pedantic -fsanitize=address machine_run.c -c -o machine_run.o -mpclmul -msse2
gcc -O2 -Wall -Wextra -pedantic -fsanitize=address emulate_run.c -c -o emulate_run.o
gcc -O2 -Wall -Wextra -pedantic -fsanitize=address test.c machine_run.o emulate_run.o -o test
