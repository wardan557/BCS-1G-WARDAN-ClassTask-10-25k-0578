#include <stdio.h>
#include <string.h>
int main() {
    char names[5][20] = {"Alice","Bob","Charlie","Diana","Eve"};
    int marks[5] = {85,92,78,96,88};
    int highest = marks[0];
    char highestname[20];
    strcpy(highestname,names[0]);
    float sum = 0;
    printf("Student Marks:\n");
    printf("Names\t\tMarks\n");
    printf("----------------------------\n");
    int i;
    for(i=0;i<5;i++){
    	printf("%-10s\t%d\n",names[i],marks[i]);
    	sum += marks[i];
    if(marks[i]>highest){
    	highest = marks[i];
    	strcpy(highestname,names[i]);
	}
}
 float average = sum/5;
 printf("\nHighest Scorer : %s with %d marks\n",highestname,highest);
 printf("Average Marks:%.2f\n",average);
    return 0;
}

