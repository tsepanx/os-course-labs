#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_SIZE 256


void sort(int ** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = i +1; j < rows; ++j) {
            if (arr[i][0] > arr[j][0])  {
                int* swap = arr[i];
                arr[i] = arr[j];
                arr[j] = swap;
            }
        }
    }
}

void print_2d_ints_arr(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int comp (const void * elem1, const void * elem2) {
    int *f = ((int**)elem1);
    int *s = ((int**)elem2);

    printf("%d V %d", f[0], s[0]);
//    printf("%d", s[0]);

    if (f[1] > s[1]) {
        return 1;
    } else if (f[1] < s[1]) {
        return -1;
    } return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int **arr;
    arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        arr[i] = malloc(2 * sizeof(int));
    }
    int l = 0;

    for (int i = 0; i < n; ++i) {
        int at, bt;
        scanf("%d%d", &at, &bt);
        arr[i][0] = at;
        arr[i][1] = bt;
    }

//    print_2d_ints_arr(arr, n, 2);
//    printf("\n");

//    qsort (arr, sizeof(arr)/sizeof(*arr), sizeof(*arr), comp);
    sort(arr, n);

//    print_2d_ints_arr(arr, n, 2);


    int cur_tick = 0;
    int sum_compl_time = 0;
    int sum_tat_time = 0;

    for (int i = 0; i < n; ++i) {
        int at = arr[i][0];
        int bt = arr[i][1];

        if (cur_tick < at) {
            cur_tick = at;
        }

        int waiting_time = cur_tick - at;
        printf("Waiting time for %d proc: %d\n", i, waiting_time);

//        cur_tick = at;
        cur_tick += bt;

        printf("Completion time for %d proc: %d\n", i, cur_tick);

        sum_compl_time += cur_tick;

        printf("TAT for %d proc: %d\n", i, bt);

        sum_tat_time += bt;
    }

    float avg_compl_time = (float) sum_compl_time / (float) n;
    float avg_tat_time = (float) sum_tat_time / ( float) n;

    printf("Avg: %f, %f", avg_compl_time, avg_tat_time);
}
