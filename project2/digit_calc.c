#include <stdio.h>
#include <stdlib.h> 

void raqamlar(int n, int *yig, int *soni) {
    int abs_n = abs(n);
    *yig = 0;
    *soni = 0;

    if (abs_n == 0) {
        *soni = 1;
        *yig = 0;
        return;
    }

    while (abs_n > 0) {
        *yig += abs_n % 10;
        (*soni)++;
        abs_n /= 10;
    }
}

int main() {
    int n;
    printf("Son kiriting (n): ");
    if (scanf("%d", &n) != 1) return 1;

    int yigindi = 0;
    int soni = 0;

    printf("Raqamlar yig'indisi (pointer orqali): %d\n", yigindi);
    printf("Raqamlar soni (pointer orqali): %d\n", soni);

    return 0;
}
