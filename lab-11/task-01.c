#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char name[50];
    int roll;
    int m1, m2, m3;
    float percentage;
    char grade;
} Student;
char getGrade(float p) {
    if (p >= 90) return 'A';     // A+
    else if (p >= 80) return 'B';// A
    else if (p >= 70) return 'C';// B+
    else if (p >= 60) return 'D';// B
    else if (p >= 50) return 'E';// C
    return 'F';                  // Fail
}
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void addStudent(Student s[], int *n) {
    clearBuffer();   
    printf("\nEnter Name: ");
    fgets(s[*n].name, 50, stdin);
    s[*n].name[strcspn(s[*n].name, "\n")] = '\0'; 

    printf("Enter Roll Number: ");
    scanf("%d", &s[*n].roll);
    do {
        printf("Enter Marks (Subject 1): ");
        scanf("%d", &s[*n].m1);
    } while (s[*n].m1 < 0 || s[*n].m1 > 100);
    do {
        printf("Enter Marks (Subject 2): ");
        scanf("%d", &s[*n].m2);
    } while (s[*n].m2 < 0 || s[*n].m2 > 100);
    do {
        printf("Enter Marks (Subject 3): ");
        scanf("%d", &s[*n].m3);
    } while (s[*n].m3 < 0 || s[*n].m3 > 100);
    s[*n].percentage = (s[*n].m1 + s[*n].m2 + s[*n].m3) / 3.0;
    s[*n].grade = getGrade(s[*n].percentage);

    (*n)++;
    printf("\nStudent Added Successfully!\n");
}
void display(Student s[], int n) {
    printf("\n%-10s %-20s %-10s %-10s\n", "Roll", "Name", "Percent", "Grade");
    int i;
    for (i = 0; i < n; i++)
        printf("%-10d %-20s %-10.2f %-10c\n",s[i].roll, s[i].name, s[i].percentage, s[i].grade);
}

void search(Student s[], int n) {
    int roll;
    int i;
    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);
    for (i = 0; i < n; i++) {
        if (s[i].roll == roll) {
            printf("\nFound:\nName: %s\nPercentage: %.2f\nGrade: %c\n",s[i].name, s[i].percentage, s[i].grade);
            return;
        }
    }
    printf("\nStudent Not Found!\n");
}
void byGrade(Student s[], int n) {
    char g;
    int i;
    printf("\nEnter Grade to Search (A/B/C/D/E/F): ");
    clearBuffer();
    scanf("%c", &g);
    printf("\nStudents with Grade %c:\n", g);
    for (i = 0; i < n; i++)
        if (s[i].grade == g)
            printf("%s (Roll %d)\n", s[i].name, s[i].roll);
}
void classAverage(Student s[], int n) {
    float sum = 0;
    int i;
    for (i = 0; i < n; i++) sum += s[i].percentage;
    float avg = sum / n;
    printf("\nClass Average = %.2f\n", avg);
    printf("\nAbove Average Students:\n");
    for (i = 0; i < n; i++)
        if (s[i].percentage > avg)
            printf("%s (%.2f)\n", s[i].name, s[i].percentage);
    printf("\nBelow Average Students:\n");
    for (i = 0; i < n; i++)
        if (s[i].percentage < avg)
            printf("%s (%.2f)\n", s[i].name, s[i].percentage);
}

void rankStudents(Student s[], int n) {
    int i , j;
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (s[j].percentage > s[i].percentage) {
                Student temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }

    printf("\n--- Rank List ---\n");
    for (i = 0; i < n; i++)
        printf("Rank %d: %s (%.2f)\n", i + 1, s[i].name, s[i].percentage);
}

int main() {
    Student s[MAX];
    int n = 0, choice;

    while (1) {
        printf("\n--- Student Record System ---\n");
        printf("1. Add Student\n2. Display All Students\n3. Search by Roll\n4. Find by Grade\n5. Class Average\n6. Rank Students\n7. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(s, &n); break;
            case 2: display(s, n); break;
            case 3: search(s, n); break;
            case 4: byGrade(s, n); break;
            case 5: classAverage(s, n); break;
            case 6: rankStudents(s, n); break;
            case 7: return 0;
            default: printf("Invalid Choice!\n");
        }
    }
    return 0;
}
