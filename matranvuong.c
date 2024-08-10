#include <stdio.h>

#define MAX_SIZE 50

// Hàm tính tổng các phần tử nằm trên đường chéo chính
int sumMainDiagonal(int matrix[][MAX_SIZE], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][i];
    }
    return sum;
}

// Hàm tính tổng các phần tử nằm trên đường chéo phụ
int sumSecondaryDiagonal(int matrix[][MAX_SIZE], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][n - 1 - i];
    }
    return sum;
}

// Hàm tính tổng các phần tử nằm phía trên đường chéo chính
int sumAboveMainDiagonal(int matrix[][MAX_SIZE], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

// Hàm tính tổng các phần tử nằm phía trên đường chéo phụ
int sumAboveSecondaryDiagonal(int matrix[][MAX_SIZE], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

// Hàm hiển thị ma trận
void printMatrix(int matrix[][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Hàm hiển thị menu
void displayMenu() {
    printf("Menu:\n");
    printf("1. Tính tổng các phần tử nằm trên đường chéo chính\n");
    printf("2. Tính tổng các phần tử nằm trên đường chéo phụ\n");
    printf("3. Tính tổng các phần tử nằm phía trên đường chéo chính\n");
    printf("4. Tính tổng các phần tử nằm phía trên đường chéo phụ\n");
    printf("0. Thoát\n");
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int n;
    int choice;

    // Nhập kích thước ma trận
    printf("Nhập kích thước ma trận vuông n: ");
    scanf("%d", &n);

    // Nhập ma trận
    printf("Nhập các phần tử của ma trận:\n");
    for (int i = 0; i < n; i++) {
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
                printf("Tổng các phần tử nằm trên đường chéo chính: %d\n", sumMainDiagonal(matrix, n));
                break;
            case 2:
                printf("Tổng các phần tử nằm trên đường chéo phụ: %d\n", sumSecondaryDiagonal(matrix, n));
                break;
            case 3:
                printf("Tổng các phần tử nằm phía trên đường chéo chính: %d\n", sumAboveMainDiagonal(matrix, n));
                break;
            case 4:
                printf("Tổng các phần tử nằm phía trên đường chéo phụ: %d\n", sumAboveSecondaryDiagonal(matrix, n));
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
