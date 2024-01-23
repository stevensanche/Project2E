/* Steven Sanchez Jimenez */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
	FILE* f = fopen(argv[1], "r");
	fseek(f, 0, SEEK_END);
	int filesize = ftell(f);
	fseek(f, 0, SEEK_SET);
	char *buffer = malloc(filesize);
	fread(buffer, 1, filesize, f);
	int *counter = calloc(argc - 2, sizeof(int));

	for (int x = 0; x < filesize; x++) {
		if (buffer[x-1] == ' ' || buffer[x-1] == ',' || buffer[x-1] == '.' || buffer[x-1] == '\n') {
			for (int i = 2; i < argc; i++) {
				int len = strlen(argv[i]);
				if (buffer[x+len] == ' ' || buffer[x+len] == ',' || buffer[x+len] == '.' || buffer[x+len] == '\n') {
					if (strncmp(argv[i], (buffer + x), len) == 0) {
						counter[i-2] += 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < argc-2; i++) {
		printf("The word \"%s\" occurs %d times.\n", argv[i+2], counter[i]);
	}

	free(buffer);
	free(counter);
	return 0;
}



	