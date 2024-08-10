#include <stdio.h>

#define MAX_SIZE 50

// Định nghĩa cấu trúc phân số
typedef struct {
    int numerator;   // Tử số
    int denominator; // Mẫu số
} Fraction;

// Hàm nhập danh sách các phân số
void inputFractions(Fraction arr[], int *n) {
    printf("Nhập số lượng phân số (<= 50): ");
    scanf("%d", n);
    if (*n > MAX_SIZE) {
        printf("Số lượng phân số vượt quá giới hạn cho phép.\n");
        *n = MAX_SIZE;
    }
    for (int i = 0; i < *n; i++) {
        printf("Nhập phân số thứ %d (tử số mẫu số): ", i + 1);
        scanf("%d %d", &arr[i].numerator, &arr[i].denominator);
        if (arr[i].denominator == 0) {
            printf("Mẫu số không thể bằng 0. Vui lòng nhập lại.\n");
            i--;
        }
    }
}

// Hàm xuất danh sách các phân số
void printFractions(Fraction arr[], int n) {
    printf("Danh sách các phân số:\n");
    for (int i = 0; i < n; i++) {
        printf("%d/%d ", arr[i].numerator, arr[i].denominator);
    }
    printf("\n");
}

// Hàm tính giá trị phân số
float value(Fraction f) {
    return (float)f.numerator / f.denominator;
}

// Tìm phân số lớn nhất và nhỏ nhất
void findMaxMinFractions(Fraction arr[], int n, Fraction *max, Fraction *min) {
    *max = arr[0];
    *min = arr[0];
    for (int i = 1; i < n; i++) {
        if (value(arr[i]) > value(*max)) {
            *max = arr[i];
        }
        if (value(arr[i]) < value(*min)) {
            *min = arr[i];
        }
    }
}

// Tính tổng và tích các phân số
Fraction addFractions(Fraction arr[], int n) {
    Fraction sum = {0, 1}; // Khởi tạo tổng = 0/1
    for (int i = 0; i < n; i++) {
        sum.numerator = sum.numerator * arr[i].denominator + arr[i].numerator * sum.denominator;
        sum.denominator *= arr[i].denominator;
    }
    return sum;
}

Fraction multiplyFractions(Fraction arr[], int n) {
    Fraction product = {1, 1}; // Khởi tạo tích = 1/1
    for (int i = 0; i < n; i++) {
        product.numerator *= arr[i].numerator;
        product.denominator *= arr[i].denominator;
    }
    return product;
}

// Xuất nghịch đảo các phân số
void printReciprocalFractions(Fraction arr[], int n) {
    printf("Nghịch đảo các phân số:\n");
    for (int i = 0; i < n; i++) {
        printf("%d/%d ", arr[i].denominator, arr[i].numerator);
    }
    printf("\n");
}

// Hoán đổi hai phân số
void swap(Fraction *a, Fraction *b) {
    Fraction temp = *a;
    *a = *b;
    *b = temp;
}

// Sắp xếp phân số tăng dần và giảm dần
void sortFractions(Fraction arr[], int n, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ascending && value(arr[i]) > value(arr[j])) ||
                (!ascending && value(arr[i]) < value(arr[j]))) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

// Hiển thị menu
void displayMenu() {
    printf("Menu:\n");
    printf("1. Nhập danh sách các phân số\n");
    printf("2. Xuất danh sách các phân số\n");
    printf("3. Tìm phân số lớn nhất và nhỏ nhất\n");
    printf("4. Tính tổng và tích các phân số\n");
    printf("5. Xuất nghịch đảo các phân số\n");
    printf("6. Sắp xếp phân số (1: tăng dần, 2: giảm dần)\n");
    printf("0. Thoát\n");
}

int main() {
    Fraction arr[MAX_SIZE];
    int n;
    int choice;

    do {
        displayMenu();
        printf("Chọn chức năng: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputFractions(arr, &n);
                break;
            case 2:
                printFractions(arr, n);
                break;
            case 3: {
                Fraction max, min;
                findMaxMinFractions(arr, n, &max, &min);
                printf("Phân số lớn nhất: %d/%d\n", max.numerator, max.denominator);
                printf("Phân số nhỏ nhất: %d/%d\n", min.numerator, min.denominator);
                break;
            }
            case 4: {
                Fraction sum = addFractions(arr, n);
                Fraction product = multiplyFractions(arr, n);
                printf("Tổng các phân số: %d/%d\n", sum.numerator, sum.denominator);
                printf("Tích các phân số: %d/%d\n", product.numerator, product.denominator);
                break;
            }
            case 5:
                printReciprocalFractions(arr, n);
                break;
            case 6: {
                int order;
                printf("Sắp xếp theo thứ tự (1: tăng dần, 2: giảm dần): ");
                scanf("%d", &order);
                sortFractions(arr, n, order == 1);
                printf("Danh sách phân số sau khi sắp xếp:\n");
                printFractions(arr, n);
                break;
            }
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
