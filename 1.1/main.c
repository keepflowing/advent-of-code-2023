#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {

    FILE *file = fopen("input", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Assuming lines are <255 characters
    char line[256];  
    int total = 0;

    // Read lines from the file and process them
    while (fgets(line, sizeof(line), file)) {
	
        // Remove the newline character if it exists
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

	// Remove non-numeric characters
        char numeric_line[256];
        int j = 0;
        for (int i = 0; line[i] != '\0'; i++) {
            if (isdigit(line[i])) {
                numeric_line[j++] = line[i];
            }
        }
        numeric_line[j] = '\0';
	size_t length = strlen(numeric_line);
	
	char first_last[3];
	first_last[0] = numeric_line[0];
	first_last[2] = '\0';

	if (length >= 2) {
	    first_last[1] = numeric_line[length - 1];
	} else {
	    first_last[1] = numeric_line[0];
	}
	int num = atoi(first_last);

	
	printf("%d\n", num);
	total += num;
    }

    printf("\nTotal: %d\n", total);

    fclose(file);

    return 0;
}
