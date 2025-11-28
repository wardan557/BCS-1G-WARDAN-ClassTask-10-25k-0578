#include<stdio.h>
#include<stdlib.h>
int main(){
	int size,i;
	printf("Enter size of array: ");
	scanf("%d",&size);
	int *ptr= (int*)malloc(size*sizeof(int));
	if(ptr==NULL){
		printf("Memory Allocation Failed.\n");
		return 1;
	}
	for(i=0; i<size; i++){
		printf("Enter a number: ");
		scanf("%d", &ptr[i]);
	}
	for(i=0;i<size;i++) printf("ptr[%d]= %d\n", i,ptr[i]);
	free(ptr);
	return 0;
}
