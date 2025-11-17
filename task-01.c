#include<stdio.h>
#include<string.h>
#include<ctype.h>
int validate_password(const char *password){
	int has_upper = 0 , has_digit = 0, has_special = 0;
	int length = strlen(password);
	if(length<8) return 0;
	int i;
	for(i=0;i<length;i++){
	if(isupper(password[i]))
	has_upper = 1;
	else if(isdigit(password[i]))
	has_digit = 1;
	else if (password[i]=='!'|| password[i]=='@'|| password[i]=='#'|| password[i]=='$'||password[i]=='%')
	has_special = 1;
	}
	return has_upper && has_digit && has_special;
}
int main(){
	char password[100];
	printf("Enter the password :\n");
	fgets(password, sizeof(password),stdin);
	password[strcspn(password,"\n")] = 0;
	if(validate_password(password)){
		printf("VALID PASSWORD \n");
	} else{
		printf("INVALID PASSWORD \n");
	}
	
	return 0;
}
