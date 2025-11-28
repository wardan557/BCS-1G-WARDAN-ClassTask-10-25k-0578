#include<stdio.h>
#include<stdlib.h>
int main(){
  char str1[100], str2[100];
  printf("Enter first string: ");
  scanf("%s",str1);
  printf("Enter second string: ");
  scanf("%s",str2);
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  char *result = (char *) malloc((len1 + len2 + 1) * sizeof(char));
  if(result == NULL){
  	printf("Memory allocation failed!\n");
  	return 1;
  }
  strcpy(result , str1);
  strcat(result , str2);
  printf("\nConcatenated string is %s\n",result);
  free(result);
	return 0;
}
