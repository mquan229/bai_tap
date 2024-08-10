#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 50

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

// Hàm kiểm tra chữ số đầu của số nguyên
int firstDigit(int num) {
    if (num < 0) num = -num; // Chuyển số âm thành số dương
    while (num >= 10) {
        num /= 10;
    }
    return num;
}

// Hàm tính tổng các phần tử có chữ số đầu là chữ số lẻ
int sumOddFirstDigit(int matrix[][MAX_SIZE], int m, int n) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (firstDigit(matrix[i][j]) % 2 != 0) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

// Hàm kiểm tra số hoàn thiện
bool isPerfectNumber(int num) {
    if (num <= 1) return false;
    int sum = 1;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            if (i * i != num) sum += i + num / i;
            else sum += i;
        }
    }
    return sum == num;
}

// Hàm liệt kê các số hoàn thiện trong ma trận
void listPerfectNumbers(int matrix[][MAX_SIZE], int m, int n) {
    printf("Các số hoàn thiện trong ma trận:\n");
    bool found = false;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isPerfectNumber(matrix[i][j])) {
                printf("%d ", matrix[i][j]);
                found = true;
            }
        }
    }
    if (!found) printf("Không có số hoàn thiện nào.");
    printf("\n");
}

// Hàm tính tổng các phần tử lớn hơn trị tuyệt đối của phần tử liền sau nó
int sumGreaterThanAbsNext(int matrix[][MAX_SIZE], int m, int n) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (matrix[i][j] > abs(matrix[i][j + 1])) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

// Hàm tính tổng các giá trị nằm trên dòng k
int sumRow(int matrix[][MAX_SIZE], int n, int k) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
        sum += matrix[k][j];
    }
    return sum;
}

// Hàm tính tổng các giá trị nằm trên biên của ma trận
int sumBorder(int matrix[][MAX_SIZE], int m, int n) {
    int sum = 0;
    // Tổng các giá trị trên hàng đầu và hàng cuối
    for (int j = 0; j < n; j++) {
        sum += matrix[0][j];
        if (m > 1) sum += matrix[m - 1][j];
    }
    // Tổng các giá trị trên cột trái và cột phải (trừ các góc)
    for (int i = 1; i < m - 1; i++) {
        sum += matrix[i][0];
        if (n > 1) sum += matrix[i][n - 1];
    }
    return sum;
}

// Hàm đếm tần suất xuất hiện của giá trị x trong ma trận
int countFrequency(int matrix[][MAX_SIZE], int m, int n, int x) {
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == x) {
                count++;
            }
        }
    }
    return count;
}

// Hàm đếm số lượng các phần tử là số chẵn, số lẻ, số âm, số dương, số nguyên tố
void countElements(int matrix[][MAX_SIZE], int m, int n, int *even, int *odd, int *negative, int *positive, int *primes) {
    *even = *odd = *negative = *positive = *primes = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int value = matrix[i][j];
            if (value % 2 == 0) (*even)++;
            else (*odd)++;
            if (value < 0) (*negative)++;
            else if (value > 0) (*positive)++;
            if (isPrime(value)) (*primes)++;
        }
    }
}

// Hàm hiển thị menu
void displayMenu() {
    printf("Menu:\n");
    printf("1. Tính tổng các phần tử có chữ số đầu là chữ số lẻ\n");
    printf("2. Liệt kê các số hoàn thiện trong ma trận\n");
    printf("3. Tính tổng các phần tử lớn hơn trị tuyệt đối của phần tử liền sau nó\n");
    printf("4. Tính tổng giá trị trên dòng k\n");
    printf("5. Tính tổng các giá trị nằm trên biên của ma trận\n");
    printf("6. Đếm tần suất xuất hiện của một giá trị\n");
    printf("7. Đếm số lượng các phần tử là số chẵn, số lẻ, số âm, số dương, số nguyên tố\n");
    printf("0. Thoát\n");
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int m, n;
    int choice;
    int k, x;
    int even, odd, negative, positive, primes;

    // Nhập kích thước ma trận
    printf("Nhập số hàng của ma trận: ");
    scanf("%d", &m);
    printf("Nhập số cột của ma trận: ");
    scanf("%d", &n);

    // Nhập ma trận
    printf("Nhập các phần tử của ma trận:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Nhập phần tử [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    do {
        displayMenu();
        printf("Chọn chức năng: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Tổng các phần tử có chữ số đầu là chữ số lẻ: %d\n", sumOddFirstDigit(matrix, m, n));
                break;
            case 2:
                listPerfectNumbers(matrix, m, n);
                break;
            case 3:
                printf("Tổng các phần tử lớn hơn trị tuyệt đối của phần tử liền sau nó: %d\n", sumGreaterThanAbsNext(matrix, m, n));
                break;
            case 4:
                printf("Nhập chỉ số dòng k: ");
                scanf("%d", &k);
                if (k >= 0 && k < m) {
                    printf("Tổng giá trị trên dòng %d: %d\n", k, sumRow(matrix, n, k));
                } else {
                    printf("Chỉ số dòng k không hợp lệ.\n");
                }
                break;
            case 5:
                printf("Tổng các giá trị nằm trên biên của ma trận: %d\n", sumBorder(matrix, m, n));
                break;
            case 6:
                printf("Nhập giá trị x để đếm: ");
                scanf("%d", &x);
                printf("Tần suất xuất hiện của %d trong ma trận: %d\n", x, countFrequency(matrix, m, n, x));
                break;
            case 7:
                countElements(matrix, m, n, &even, &odd, &negative, &positive, &primes);
                printf("Số chẵn: %d\n", even);
                printf("Số lẻ: %d\n", odd);
                printf("Số âm: %d\n", negative);
                printf("Số dương: %d\n", positive);
                printf("Số nguyên tố: %d\n", primes);
                break;
            case 0:
                printf("Thoát chương trình.\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
