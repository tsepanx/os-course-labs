#include <stdio.h>
#include <stdlib.h>

int main(void){

    char input[1024];

    while (1) {
        if (fgets(input, 1024, stdin)) {
            system(input);
        } else break;
    }

	return EXIT_SUCCESS;

}