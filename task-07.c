#include<stdio.h>
#include<string.h>
void displaycourses(char names[][20], char courses[][40], int n){
	printf("\n------Student Courses List------\n");
	int i;
	for(i=0;i<n;i++){
	printf("%s is registered for : %s\n",names[i],courses[i]);
	}
}
void findstudentBycourse(char names[][20], char courses[][40], int n, char course[]){
	int found = 0;
	printf("\nStudent taking %s: ",course);
	int i;
	for(i=0;i<n;i++){
	if(strstr(courses[i],course) != NULL){
		printf("%s ", names[i]);
		found = 1;
	}
	}
	if(!found)
	printf("Student not found");
	printf("\n");
}
void findoverloaded(char names[][20], char courses[][40], int n){
	printf("\n---Overloaded students(more than 3 subjects)---\n");
	int i,j;
	int found = 0;
	for(i=0;i<n;i++){
		int count = 1;
		for(j=0;j<strlen(courses[i]);j++){
			if(courses[i][j]== ' ')
			count++;
		}
		if(count>3){
			printf("%s (%d courses)",names[i],count);
			found = 1;
		}
	}
	if(!found)
	printf("No overloaded student");
}
int main (){
	int n = 4;
	char names[4][20] = {"Alice","Bob","Charlie","Diana"};
	char courses[4][40] = {
	"Math Physics English",
	"Biology Chemistry",
	"Math Physics Chemistry English",
	"Computer Math"
	};
	displaycourses(names,courses,n);
	findstudentBycourse(names,courses,n,"Physics");
	findoverloaded(names,courses,n);
	return 0;
}
