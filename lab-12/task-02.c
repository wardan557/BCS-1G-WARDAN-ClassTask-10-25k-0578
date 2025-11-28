#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char string[50];
	int i;
	printf("Enter a string: ");
	fgets(string,50,stdin);
	int length = strlen(string)-1;
	char *ptr= (char*)malloc(length*sizeof(char));
	for(i=0; i<length/2; i++){
		char temp = string[i];
		string[i]= string[length-i-1];
		string[length-i-1] = temp;
	}
	printf("Reversed String: %s", string);
	free(ptr);
	return 0;
}
