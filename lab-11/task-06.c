#include<stdio.h>
int digitalroot(int n){
	if(n==0){
		return 0;
	}
	if(n<10){
		return n;
	}
	int sum =  (n % 10) + digitalroot(n / 10);
	return digitalroot(sum);
}
int main(){
  int n;
  printf("Enter a number: ");
  scanf("%d",&n);
  int DR = digitalroot(n);
  printf("The digital root is: %d",DR);
	return 0;
}
