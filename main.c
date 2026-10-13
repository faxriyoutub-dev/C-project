#include <stdio.h>
#include <stdlib.h>

// Функция для инвертирования массива с использованием только указательной арифметики (без [])
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

    // 1. Dinamik xotira ajratish (malloc)
    int *arr = (int *)malloc(n * sizeof(int));
    
    // 2. malloc natijasini NULL ga tekshirish
    if (arr == NULL) {
        printf("Xotira ajratishda xatolik (malloc NULL qaytardi)!\n");
        return 1;
    }

    printf("%d ta element kiriting:\n", n);
    for (int i = 0; i < n; i++) {
        // Pointer arifmetikasi yordamida elementlarni kiritish ([] ishlatilmagan)
        if (scanf("%d", arr + i) != 1) {
            printf("Kiritishda xatolik!\n");
            free(arr);
            return 1;
        }
    }

    // 3. Funksiya orqali massivni teskari tartibga keltirish (pointer orqali o'zgartirish)
    reverse_array(arr, n);

    printf("Teskari tartibdagi massiv:\n");
    for (int i = 0; i < n; i++) {
        // Pointer arifmetikasi yordamida elementlarni chiqarish ([] ishlatilmagan)
        printf("%d ", *(arr + i));
    }
    printf("\n");

    // 4. Dastur oxirida barcha xotirani bo'shatish
    free(arr);
    arr = NULL;

    return 0;
}


