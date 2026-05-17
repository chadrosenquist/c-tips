/*
    count_lines.c

    gcc -Wall -g count_lines.c -o count_lines
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define SUCCESS ((int) 1)
#define FAILURE ((int) 0)

const char *TEST_FILE_001 = "test_file_001.txt";

int count_lines(const char* filename, int *lines) {
    int return_value = FAILURE;
    FILE *file = NULL;

    *lines = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file %s: %s (errno=%d)\n",
                filename, strerror(errno), errno);
        goto cleanup;
    }


    return_value = SUCCESS;
cleanup:
    if (file != NULL) {
        if (fclose(file) == EOF) {
            fprintf(stderr, "Failed to close file %s: %s (errno=%d)\n",
                    filename, strerror(errno), errno);
            return_value = FAILURE;
        }
    }

    return return_value;
}

int main() {
    int lines = 0;
    if (!count_lines(TEST_FILE_001, &lines)) {
        fprintf(stderr, "Failed to count lines from %s\n", TEST_FILE_001);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}