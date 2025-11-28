#include<stdio.h>
#include<stdlib.h>
int main(){
	int n = 5,i;
	int *arr = (int *)calloc(n, sizeof(int));
	if(arr == NULL){
		printf("Memort allocation failed!\n");
		return 1;
	}
	printf("Array allocated with calloc (initialized to zero):\n");
	for(i=0;i<n;i++){
		printf("%d",arr[i]);
	}
	printf("\n");
	for(i=0;i<n;i++){
		arr[i] = (i+1) * 20;
	}
	printf("Array after modification:\n");
	for(i=0;i<n;i++){
		printf("%d",arr[i]);
	}
	printf("\n");
	free(arr);
	arr = (int *) malloc(n * sizeof(int));
	if(arr == NULL){
		printf("Memory allocation failed!\n");
		return 1;
	}
	printf("Array allocated with malloc(uninitialized values):\n");
	for(i=0;i<n;i++){
		printf("%d",arr[i]);
	}
	printf("\n");
	free(arr);
	return 0;
}
