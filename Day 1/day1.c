#include <stdio.h>

int main() {

    FILE* input;
    char myString[100];
    input = fopen("input.txt", "r");
    
    // If the file exist
    if(input != NULL) {
        // Read the content and print it
        while(fgets(myString, 100, input)) {
            printf("%s", myString);
        }
    } else {
        printf("Not able to open the file.\n");
    }
    
    fclose(input);



    return 0;
}