#include <stdio.h>

// Hàm tìm kiếm nhị phân
int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main() {
    // Bài 1: Dãy số
    int arr1[] = {7, 9, 13, 17, 27, 30, 31, 35, 38, 40};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int x;

    printf("Bài 1:\n");
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    int result = binarySearch(arr1, 0, n1 - 1, x);
    if (result == -1)
        printf("Khong tim thay %d trong day\n", x);
    else
        printf("Tim thay %d tai vi tri %d\n", x, result);

    // Bài 2: Dãy ký tự
    char arr2[] = "ZRLKHFECA";
    int n2 = sizeof(arr2) - 1; // Trừ 1 để loại bỏ ký tự null '\0'
    char ch;

    printf("Bài 2:\n");
    printf("Nhap ky tu can tim: ");
    scanf(" %c", &ch); // Dùng khoảng trắng trước %c để bỏ qua dấu cách

    int i;
    for (i = 0; i < n2; i++) {
        if (arr2[i] == ch) {
            printf("Tim thay '%c' tai vi tri %d\n", ch, i);
            break;
        }
    }
    if (i == n2)
        printf("Khong tim thay '%c' trong day\n", ch);

    return 0;
}
