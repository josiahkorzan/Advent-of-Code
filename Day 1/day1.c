#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    FILE* input;

    input = fopen("input.txt", "r");
    int sum = 0;
    char* current_line = (char*) malloc(100*sizeof(char));
    while (fscanf(input, "%s", current_line) != EOF) {
        char* number = calloc(16, sizeof(char));
        char first_num;
        char last_num;
        int counter = 0;
        for(char* ptr = current_line; *ptr != '\0'; ptr++) {
            if (*ptr >= '0' && *ptr <= '9') {
                if (counter == 0) {
                    first_num = *ptr;
                    last_num = *ptr;
                } else {
                    last_num = *ptr;
                }
                counter++;
            }
        }
        strncat(number, &first_num, 1);
        strncat(number, &last_num, 1);
        sum += atoi(number);
        printf("%d\n", atoi(number));
    }
    printf("%d", sum);

    fclose(input);
    free(current_line);

    return 0;
}