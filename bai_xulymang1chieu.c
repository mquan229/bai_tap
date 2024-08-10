#include <stdio.h>
#include <stdbool.h>
#include <string.h> //bo sung them cai dat

#define MAX_SIZE 100

// Hàm nhập mảng
void inputArray(int arr[], int *n) {
    printf("Nhập số lượng phần tử của mảng: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Nhập phần tử thứ %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Hàm xuất mảng
void printArray(int arr[], int n) {
    printf("Mảng là: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Hàm tìm max và min của mảng
void findMaxMin(int arr[], int n, int *max, int *min) {
    *max = arr[0];
    *min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > *max) *max = arr[i];
        if (arr[i] < *min) *min = arr[i];
    }
}

// Hàm đếm số phần tử chẵn và lẻ
void countEvenOdd(int arr[], int n, int *evenCount, int *oddCount) {
    *evenCount = 0;
    *oddCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) (*evenCount)++;
        else (*oddCount)++;
    }
}

// Hàm tìm kiếm tuyến tính
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i;
    }
    return -1;
}

// Hàm tìm kiếm nhị phân (cần mảng đã sắp xếp)
int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Hàm đếm số lần xuất hiện của phần tử x
int countOccurrences(int arr[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) count++;
    }
    return count;
}

// Hàm đếm số phần tử lớn hơn x
int countGreaterThanX(int arr[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > x) count++;
    }
    return count;
}

// Hàm tính tổng các phần tử
int sumArray(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Hàm kiểm tra số hoàn thiện
bool isPerfectNumber(int num) {
    if (num <= 1) return false;
    int sum = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) sum += i;
    }
    return sum == num;
}

// Hàm xuất số nguyên tố trong mảng
void printPrimes(int arr[], int n) {
    printf("Các số nguyên tố trong mảng là: ");
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) printf("%d ", arr[i]);
    }
    printf("\n");
}

// Hàm xuất số hoàn thiện trong mảng
void printPerfectNumbers(int arr[], int n) {
    printf("Các số hoàn thiện trong mảng là: ");
    for (int i = 0; i < n; i++) {
        if (isPerfectNumber(arr[i])) printf("%d ", arr[i]);
    }
    printf("\n");
}

// Hàm xuất các phần tử ở vị trí chẵn/lẻ
void printEvenOddIndexElements(int arr[], int n) {
    printf("Các phần tử ở vị trí chẵn là: ");
    for (int i = 0; i < n; i += 2) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Các phần tử ở vị trí lẻ là: ");
    for (int i = 1; i < n; i += 2) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Hàm xuất giá trị max/min kèm theo vị trí của chúng
void printMaxMinWithPosition(int arr[], int n) {
    int max, min;
    findMaxMin(arr, n, &max, &min);
    int maxPos = linearSearch(arr, n, max);
    int minPos = linearSearch(arr, n, min);
    printf("Giá trị max là %d và vị trí của nó là %d\n", max, maxPos);
    printf("Giá trị min là %d và vị trí của nó là %d\n", min, minPos);
}

// Hàm ghép và sắp xếp hai dãy tăng dần
void mergeAndSort(int b[], int m, int c[], int n, int a[]) {
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (b[i] <= c[j]) a[k++] = b[i++];
        else a[k++] = c[j++];
    }
    while (i < m) a[k++] = b[i++];
    while (j < n) a[k++] = c[j++];
}


// bo sung cai dat
// Hàm sắp xếp mảng số nguyên theo phương pháp interchange sort
void interchangeSortIntAscending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp mảng số thực theo phương pháp interchange sort
void interchangeSortFloatAscending(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp mảng ký tự theo phương pháp interchange sort
void interchangeSortCharAscending(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                char temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp mảng chuỗi ký tự theo phương pháp interchange sort
void interchangeSortStringAscending(char arr[][MAX_SIZE], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                char temp[MAX_SIZE];
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

// Hàm sắp xếp mảng số nguyên theo phương pháp interchange sort giảm dần
void interchangeSortIntDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp mảng số thực theo phương pháp interchange sort giảm dần
void interchangeSortFloatDescending(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp mảng ký tự theo phương pháp interchange sort giảm dần
void interchangeSortCharDescending(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                char temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp mảng chuỗi ký tự theo phương pháp interchange sort giảm dần
void interchangeSortStringDescending(char arr[][MAX_SIZE], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) < 0) {
                char temp[MAX_SIZE];
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}


int main() {
    int choice;
    bool exit = false;

    while (!exit) {
        printf("Menu:\n");
        printf("1. Sắp xếp mảng số nguyên tăng dần\n");
        printf("2. Sắp xếp mảng số thực giảm dần\n");
        printf("3. Sắp xếp mảng ký tự tăng dần\n");
        printf("4. Sắp xếp mảng chuỗi ký tự giảm dần\n");
        printf("5. Thực hiện các phép toán với mảng số nguyên\n");
        printf("6. Thoát\n");
        printf("Nhập lựa chọn của bạn (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int arrInt[MAX_SIZE];
                int n;
                inputArray(arrInt, &n);
                interchangeSortIntAscending(arrInt, n);
                printf("Mảng số nguyên sau khi sắp xếp tăng dần: ");
                printArray(arrInt, n);
                break;
            }
            case 2: {
                float arrFloat[MAX_SIZE];
                int m;
                printf("Nhập số lượng phần tử của mảng số thực: ");
                scanf("%d", &m);
                for (int i = 0; i < m; i++) {
                    printf("Nhập phần tử thứ %d: ", i + 1);
                    scanf("%f", &arrFloat[i]);
                }
                interchangeSortFloatDescending(arrFloat, m);
                printf("Mảng số thực sau khi sắp xếp giảm dần: ");
                for (int i = 0; i < m; i++) {
                    printf("%f ", arrFloat[i]);
                }
                printf("\n");
                break;
            }
            case 3: {
                char arrChar[MAX_SIZE];
                int p;
                printf("Nhập số lượng ký tự trong mảng: ");
                scanf("%d", &p);
                printf("Nhập các ký tự:\n");
                for (int i = 0; i < p; i++) {
                    printf("Nhập ký tự thứ %d: ", i + 1);
                    scanf(" %c", &arrChar[i]);
                }
                interchangeSortCharAscending(arrChar, p);
                printf("Mảng ký tự sau khi sắp xếp tăng dần: ");
                for (int i = 0; i < p; i++) {
                    printf("%c ", arrChar[i]);
                }
                printf("\n");
                break;
            }
            case 4: {
                char arrString[MAX_SIZE][MAX_SIZE];
                int q;
                printf("Nhập số lượng chuỗi ký tự: ");
                scanf("%d", &q);
                printf("Nhập các chuỗi ký tự:\n");
                for (int i = 0; i < q; i++) {
                    printf("Nhập chuỗi thứ %d: ", i + 1);
                    scanf(" %[^\n]", arrString[i]);
                }
                interchangeSortStringDescending(arrString, q);
                printf("Mảng chuỗi ký tự sau khi sắp xếp giảm dần:\n");
                for (int i = 0; i < q; i++) {
                    printf("%s\n", arrString[i]);
                }
                break;
            }
            case 5: {
                int a[MAX_SIZE], b[MAX_SIZE], c[MAX_SIZE];
                int n, m, p;
                int evenCount, oddCount;
                int max, min;
                int x;

                // Nhập mảng a
                inputArray(a, &n);
                printArray(a, n);

                // Tìm max và min
                findMaxMin(a, n, &max, &min);
                printf("Max: %d, Min: %d\n", max, min);

                // Đếm số phần tử chẵn/lẻ
                countEvenOdd(a, n, &evenCount, &oddCount);
                printf("Số phần tử chẵn: %d, số phần tử lẻ: %d\n", evenCount, oddCount);

                // Tìm kiếm phần tử x
                printf("Nhập giá trị x để tìm kiếm: ");
                scanf("%d", &x);

                // Tìm kiếm tuyến tính
                int linearPos = linearSearch(a, n, x);
                if (linearPos != -1) 
                    printf("Tìm thấy %d ở vị trí %d (tìm kiếm tuyến tính)\n", x, linearPos);
                else 
                    printf("Không tìm thấy %d (tìm kiếm tuyến tính)\n", x);

                // Đếm số lần xuất hiện của phần tử x
                int occurrences = countOccurrences(a, n, x);
                printf("Số lần xuất hiện của %d: %d\n", x, occurrences);

                // Đếm số phần tử lớn hơn x
                int greaterCount = countGreaterThanX(a, n, x);
                printf("Số phần tử lớn hơn %d: %d\n", x, greaterCount);

                // Tính tổng các phần tử
                int sum = sumArray(a, n);
                printf("Tổng các phần tử của mảng: %d\n", sum);

                // Xuất các số nguyên tố
                printPrimes(a, n);

                // Xuất các số hoàn thiện
                printPerfectNumbers(a, n);

                // Xuất các phần tử ở vị trí chẵn/lẻ
                printEvenOddIndexElements(a, n);

                // Xuất giá trị max/min kèm theo vị trí của chúng
                printMaxMinWithPosition(a, n);

                // Ghép và sắp xếp hai dãy tăng dần
                printf("Nhập số phần tử của dãy b: ");
                scanf("%d", &m);
                printf("Nhập dãy b:\n");
                inputArray(b, &m);

                printf("Nhập số phần tử của dãy c: ");
                scanf("%d", &p);
                printf("Nhập dãy c:\n");
                inputArray(c, &p);

                int sortedArray[MAX_SIZE];
                mergeAndSort(b, m, c, p, sortedArray);
                printf("Dãy a sau khi ghép và sắp xếp là: ");
                printArray(sortedArray, m + p);
                break;
            }
            case 6:
                exit = true;
                printf("Thoát chương trình.\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ. Vui lòng chọn lại.\n");
                break;
        }
    }

    return 0;
}