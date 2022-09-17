#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int foo(int age) {
	int result;
	
	result = 2022 - age;
	
	return result;
}

int main() {

    const int x = 10;
    const int *q = &x;

    int nbytes = sizeof (const int) * 5;

    int *const p = malloc(nbytes);

    for (int i = 0; i < 5; ++i) {
        *(p + i) = x;
        printf("%p\n", p+i);
    }

    for (int i = 0; i < 5; ++i) {
        int c;
        scanf("%d", &c);
        *(p + i) = c;
    }

    for (int i = 0; i < 5; ++i) {
        int xx = p[i];
        p[i] = foo(xx);
    }

    for (int i = 0; i < 5; ++i) {
        p[i] = NULL;
    }


	return EXIT_SUCCESS;
}
