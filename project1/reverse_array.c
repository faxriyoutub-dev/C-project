#include <stdio.h>
#include <stdlib.h>

void reverse_array(int *arr, int size) {
    int *start = arr;
    int *end = arr + size - 1;
    
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        
        start++;
        end--;
    }
}

int main() {
    int n;
    printf("Massiv o'lchamini kiriting (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Xato o'lcham kiritildi!\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    
    if (arr == NULL) {
        printf("Xotira ajratishda xatolik (malloc NULL qaytardi)!\n");
        return 1;
    }

    printf("%d ta element kiriting:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", arr + i) != 1) {
            printf("Kiritishda xatolik!\n");
            free(arr);
            return 1;
        }
    }

    reverse_array(arr, n);

    printf("Teskari tartibdagi massiv:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    free(arr);
    arr = NULL;

    return 0;
}
