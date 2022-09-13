#include<limits.h>
#include <float.h>
#include <stdio.h>

int main() {
    int i;
    unsigned short int usi;
    long int sli;
    float f;
    double d;

    i = INT_MAX;
    usi = USHRT_MAX;
    sli = LONG_MAX;
    f = FLT_MAX;
    d = DBL_MAX;

    printf("%d\n", i);
    printf("%u\n", usi);
    printf("%ld\n", sli);
    printf("%f\n", f);
    printf("%f\n", d);

    return 0;
}
