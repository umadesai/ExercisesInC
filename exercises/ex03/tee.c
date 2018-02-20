/* Simple implementation of the Unix command tee - which reads standard input
* and writes it to both standard output and one or more files.
* Based on code from HFC chapter 3.
*/

/* Reflect:
* I attempted to write this script before reading HFC chapter 3, which really slowed me down
* because the chapter covers a lot of the techniques used to complete the program. However, once
* I read the chapter it was much simpler to identify the tools useful to write this program,
* such as fopen/fclose() and getopt(). Next time I would use my resources more effectively and
* reference HFC before starting the implementation.
*/

/* Compare:
* The professional implementation is much more polished. Two of the biggest differences are that it
* has more efficient error checking and handles more flags. The code is also better organized by
* separating some of the code in a function outside of main.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv){
	char ch;
	unsigned int append = 0;

	while ((ch = getopt(argc, argv, "a")) != -1){
		switch (ch)
		{
			case 'a':
			append = 1;
			break;
			default:
			fprintf(stderr, "Unknown option: '%s'\n", optarg);
			exit(1);
		}
	}

	argc -= optind;
	argv += optind;
	FILE *f[argc];

	int i = 0;
	while (i < argc){
		if (append) {
			f[i] = fopen(argv[i], "a");
		} else {
			f[i] = fopen(argv[i], "w");
		}
		i++;
	}

	char input[100];
	while (scanf("%79[^\n]\n", input) == 1) {
		printf("%s\n", input);

		for (i = 0; i < argc; i++) {
			if (f[i] == NULL) {
				printf("Error\n");
				exit(1);
			}
			fprintf(f[i], "%s\n", input);
		}
	}

	i = 0;
	while (i < argc){
		fclose(f[i]);
		i++;
	}

	return 0;
}
