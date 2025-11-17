#include<stdio.h>
#include<string.h>
int main(){
   char word[4][15] = {
   "APPLE",
   "GRAPES",
   "STRAWBERRY",
   "PINEAPPLE"
   };
   int i,j;
   for(i=0;i<4;i++){
   	printf("%s\n",word[i]);
   	printf("%d\n",strlen(word[i]));
   }
   strcpy(word[1],"ANAR");
   printf("\n");
    for(i=0;i<4;i++){
   	printf("%s\n",word[i]);
   	printf("%d\n",strlen(word[i]));
   }
   printf("\n");
   for(i=0;i<4;i++){
   		printf("%s: \n",word[i]);
   		for(j=0;j<strlen(word[i]);j++)
   			printf("%c\n",word[i][j]);
   }
   
	return 0;
} 
