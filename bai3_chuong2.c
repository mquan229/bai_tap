#include <stdio.h>
#include <string.h>

#define MAX_SIZE 50
#define NUM_SUBJECTS 5

// Định nghĩa cấu trúc thông tin môn học
typedef struct {
    char code[10];      // Mã môn
    char name[30];      // Tên môn
    int credits;        // Số tín chỉ
    float score;        // Điểm
} Subject;

// Định nghĩa cấu trúc thông tin sinh viên
typedef struct {
    char id[10];           // Mã số sinh viên
    char name[50];         // Họ tên sinh viên
    Subject subjects[NUM_SUBJECTS]; // Danh sách môn học
    float gpa;             // Điểm trung bình tích lũy
} Student;

// Hàm nhập thông tin một môn học
void inputSubject(Subject *sub) {
    printf("Nhập mã môn: ");
    scanf("%s", sub->code);
    printf("Nhập tên môn: ");
    scanf(" %[^\n]", sub->name);
    printf("Nhập số tín chỉ: ");
    scanf("%d", &sub->credits);
    printf("Nhập điểm: ");
    scanf("%f", &sub->score);
}

// Hàm tính điểm trung bình tích lũy
float calculateGPA(const Subject subjects[], int numSubjects) {
    int totalCredits = 0;
    float weightedSum = 0.0;

    for (int i = 0; i < numSubjects; i++) {
        weightedSum += subjects[i].score * subjects[i].credits;
        totalCredits += subjects[i].credits;
    }

    if (totalCredits == 0) {
        return 0.0; // Tránh chia cho 0 nếu không có môn học
    }

    return weightedSum / totalCredits;
}

// Hàm nhập thông tin một sinh viên
void inputStudent(Student *stu) {
    printf("Nhập mã số sinh viên: ");
    scanf("%s", stu->id);
    printf("Nhập họ tên sinh viên: ");
    scanf(" %[^\n]", stu->name);

    for (int i = 0; i < NUM_SUBJECTS; i++) {
        printf("Nhập thông tin môn học %d:\n", i + 1);
        inputSubject(&stu->subjects[i]);
    }

    stu->gpa = calculateGPA(stu->subjects, NUM_SUBJECTS); // Tính điểm trung bình tích lũy
}

// Hàm xuất thông tin một môn học
void printSubject(const Subject *sub) {
    printf("%-10s %-30s %d tín chỉ: %.2f\n", sub->code, sub->name, sub->credits, sub->score);
}

// Hàm xuất thông tin một sinh viên
void printStudent(const Student *stu) {
    printf("Mã số sinh viên: %s\n", stu->id);
    printf("Họ tên sinh viên: %s\n", stu->name);

    for (int i = 0; i < NUM_SUBJECTS; i++) {
        printf("Môn học %d:\n", i + 1);
        printSubject(&stu->subjects[i]);
    }

    printf("Điểm trung bình tích lũy: %.2f\n", stu->gpa);
}

// Hàm nhập danh sách sinh viên
void inputStudents(Student students[], int *n) {
    printf("Nhập số lượng sinh viên: ");
    scanf("%d", n);
    if (*n > MAX_SIZE) {
        printf("Số lượng sinh viên vượt quá giới hạn cho phép.\n");
        *n = MAX_SIZE;
    }
    for (int i = 0; i < *n; i++) {
        printf("Nhập thông tin sinh viên %d:\n", i + 1);
        inputStudent(&students[i]);
    }
}

// Hàm xuất danh sách sinh viên
void printStudents(const Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nSinh viên %d:\n", i + 1);
        printStudent(&students[i]);
    }
}

// Hàm tìm một sinh viên qua mã số sinh viên
Student* findStudentById(Student students[], int n, const char *id) {
    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].id, id) == 0) {
            return &students[i];
        }
    }
    return NULL;
}

// Hàm tìm sinh viên có điểm trung bình cao nhất
Student* findTopStudent(Student students[], int n) {
    if (n == 0) return NULL;

    Student *topStudent = &students[0];
    for (int i = 1; i < n; i++) {
        if (students[i].gpa > topStudent->gpa) {
            topStudent = &students[i];
        }
    }
    return topStudent;
}

// Hàm thêm một sinh viên vào danh sách
void addStudent(Student students[], int *n, Student newStudent) {
    if (*n < MAX_SIZE) {
        students[*n] = newStudent;
        (*n)++;
    } else {
        printf("Danh sách sinh viên đã đầy.\n");
    }
}

// Hàm xóa một sinh viên khỏi danh sách
void removeStudent(Student students[], int *n, const char *id) {
    for (int i = 0; i < *n; i++) {
        if (strcmp(students[i].id, id) == 0) {
            for (int j = i; j < *n - 1; j++) {
                students[j] = students[j + 1];
            }
            (*n)--;
            return;
        }
    }
    printf("Sinh viên với mã số %s không tìm thấy.\n", id);
}

// Hàm sắp xếp danh sách sinh viên theo điểm trung bình
void sortStudents(Student students[], int n, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ascending && students[i].gpa > students[j].gpa) ||
                (!ascending && students[i].gpa < students[j].gpa)) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// Hàm xếp loại học tập của sinh viên
void classifyStudent(const Student *stu) {
    printf("Xếp loại học tập của sinh viên %s:\n", stu->name);
    if (stu->gpa >= 8.5) {
        printf("Xuất sắc\n");
    } else if (stu->gpa >= 7.0) {
        printf("Giỏi\n");
    } else if (stu->gpa >= 5.5) {
        printf("Khá\n");
    } else if (stu->gpa >= 4.0) {
        printf("Trung bình\n");
    } else {
        printf("Yếu\n");
    }
}

// Hàm thống kê số môn đậu rớt của sinh viên
void countPassedFailedSubjects(const Student *stu) {
    int passed = 0, failed = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        if (stu->subjects[i].score >= 5.0) {
            passed++;
        } else {
            failed++;
        }
    }
    printf("Số môn đậu: %d, số môn rớt: %d\n", passed, failed);
}

// Hiển thị menu
void displayMenu() {
    printf("Menu:\n");
    printf("1. Nhập danh sách sinh viên\n");
    printf("2. Xuất danh sách sinh viên\n");
    printf("3. Tìm một sinh viên theo mã số\n");
    printf("4. Tìm sinh viên có điểm trung bình cao nhất\n");
    printf("5. Thêm một sinh viên\n");
    printf("6. Xóa một sinh viên\n");
    printf("7. Sắp xếp danh sách sinh viên (1: tăng dần, 2: giảm dần)\n");
    printf("8. Xếp loại học tập của sinh viên\n");
    printf("9. Thống kê số môn đậu rớt của sinh viên\n");
    printf("0. Thoát\n");
}

int main() {
    Student students[MAX_SIZE];
    int n = 0;
    int choice;
    char id[10];
    Student tempStudent;

    do {
        displayMenu();
        printf("Chọn chức năng: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputStudents(students, &n);
                break;
            case 2:
                printStudents(students, n);
                break;
            case 3:
                printf("Nhập mã số sinh viên cần tìm: ");
                scanf("%s", id);
                {
                    Student *stu = findStudentById(students, n, id);
                    if (stu) {
                        printStudent(stu);
                    } else {
                        printf("Sinh viên với mã số %s không tìm thấy.\n", id);
                    }
                }
                break;
            case 4:
                {
                    Student *topStudent = findTopStudent(students, n);
                    if (topStudent) {
                        printStudent(topStudent);
                    } else {
                        printf("Danh sách sinh viên rỗng.\n");
                    }
                }
                break;
            case 5:
                printf("Nhập thông tin sinh viên cần thêm:\n");
                inputStudent(&tempStudent);
                addStudent(students, &n, tempStudent);
                break;
            case 6:
                printf("Nhập mã số sinh viên cần xóa: ");
                scanf("%s", id);
                removeStudent(students, &n, id);
                break;
            case 7:
                {
                    int order;
                    printf("Sắp xếp theo thứ tự (1: tăng dần, 2: giảm dần): ");
                    scanf("%d", &order);
                    sortStudents(students, n, order == 1);
                    printf("Danh sách sinh viên sau khi sắp xếp:\n");
                    printStudents(students, n);
                }
                break;
            case 8:
                printf("Nhập mã số sinh viên cần xếp loại: ");
                scanf("%s", id);
                {
                    Student *stu = findStudentById(students, n, id);
                    if (stu) {
                        classifyStudent(stu);
                    } else {
                        printf("Sinh viên với mã số %s không tìm thấy.\n", id);
                    }
                }
                break;
            case 9:
                printf("Nhập mã số sinh viên để thống kê số môn đậu rớt: ");
                scanf("%s", id);
                {
                    Student *stu = findStudentById(students, n, id);
                    if (stu) {
                        countPassedFailedSubjects(stu);
                    } else {
                        printf("Sinh viên với mã số %s không tìm thấy.\n", id);
                    }
                }
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
