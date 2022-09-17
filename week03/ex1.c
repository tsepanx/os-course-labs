#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int foo(int age) {
	int result;
	
	result = 2022 - age;
	
	return result;
}

int main() {

    const n = 5;

    const int x = 10;
    const int *q = &x;

    int *const p = malloc(sizeof(int) * 5);

    for (int i = 0; i < n; ++i) {
        *(p + i) = x;
        printf("%p\n", p+i);
    }

    for (int i = 0; i < n; ++i) {
        int c;
        scanf("%d", &c);
        *(p + i) = c;
    }

    for (int i = 0; i < n; ++i) {
        int xx = p[i];
        p[i] = foo(xx);
    }

    free(p);


	return EXIT_SUCCESS;
}
