#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
		char name[50];
		float marks;
	};
int main(){
	int n,i;
	printf("Enter number of student:\n");
	scanf("%d",&n);
	struct student *s = (struct student*)malloc(n * sizeof(struct student));
	if(s==NULL){
		printf("Memory allocation failed!\n");
		return 1;
	}
	for(i=0;i<n;i++){
		printf("Enter name of student %d: ",i+1);
		scanf("%s",s[i].name);
	  printf("Enter marks of student %s: ",s[i].name);
		scanf("%f",&s[i].marks);	
	}
		printf("\nStudent scoring more than 75 marks: \n");
		for(i=0;i<n;i++){
			if(s[i].marks > 75)
			printf("Name: %s, Marks: %f\n",s[i].name,s[i].marks);
		}
		free(s);
	return 0;
}
