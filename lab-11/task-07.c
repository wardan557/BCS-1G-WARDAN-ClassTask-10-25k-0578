#include<stdio.h>
#include<string.h>
char tolwerManual(char c){
	if(c >= 'A' && c <= 'Z')
	return c + 32;
	return c;
}
int ispalindrome(char str[], int start , int end){
	if(start >= end)
	return 1; // palindrome
	char left = tolwerManual(str[start]);
	char right = tolwerManual(str[end]);
	if(left != right)
	return 0;
	return ispalindrome(str , start+1, end-1);
}
int main(){
  int str[100];
  printf("Enter the string: ");
  scanf("%99s",str);
  int len = strlen(str);
  if(ispalindrome(str,0, len-1) == 1)
  printf("1.\n");
  else
  printf("0\n");
	return 0;
}
