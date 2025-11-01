#include <stdio.h>

// Hàm in mảng
void inMang(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%4d", a[i]);
    printf("\n");
}

// Thuật toán Shaker Sort
void shakerSort(int a[], int n) {
    int left = 0, right = n - 1;
    int step = 1;
    printf("Mang ban dau:\n");
    inMang(a, n);

    while (left < right) {
        // Duyệt từ trái sang phải
        for (int i = left; i < right; i++) {
            if (a[i] > a[i + 1]) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
        right--; // phần tử lớn nhất đã ở cuối
        printf("Buoc %d (trai -> phai): ", step++);
        inMang(a, n);

        // Duyệt từ phải sang trái
        for (int i = right; i > left; i--) {
            if (a[i] < a[i - 1]) {
                int temp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = temp;
            }
        }
        left++; // phần tử nhỏ nhất đã ở đầu
        printf("Buoc %d (phai -> trai): ", step++);
        inMang(a, n);
    }

    printf("\nMang sau khi sap xep tang dan:\n");
    inMang(a, n);
}

int main() {
    int a[] = {3, 6, 1, -1, 0, 5, 8, 2, 4};
    int n = sizeof(a) / sizeof(a[0]);

    shakerSort(a, n);

    return 0;
}
