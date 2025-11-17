#include <stdio.h>
#include <string.h>
int main() {
    char names[5][20];
    float marks[5];
    int i;
    float sum = 0, average;
    float highest = 0;
    int topIndex = 0;
    for (i = 0; i < 5; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", names[i]);
        printf("Enter marks of %s: ", names[i]);
        scanf("%f", &marks[i]);
        sum += marks[i]; 
        if (marks[i] > highest) { 
            highest = marks[i];
            topIndex = i;
        }
    }
    average = sum / 5;
    printf("\n----------- Student Marks Table -----------\n");
    printf("Name\t\tMarks\n");
    printf("-------------------------------------------\n");
    for (i = 0; i < 5; i++) {
        printf("%s\t\t%.2f\n", names[i], marks[i]);
    }
    printf("-------------------------------------------\n");
    printf("Top Student : %s (%.2f marks)\n", names[topIndex], marks[topIndex]);
    printf("Class Average: %.2f\n", average);
    return 0;
}

