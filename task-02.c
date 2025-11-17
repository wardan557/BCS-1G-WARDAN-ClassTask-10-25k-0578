#include<stdio.h>
#include<string.h>
void extract_domain(const char *email){
	const char *ptr = strchr(email,'@');
	if(ptr == NULL){
	printf("Email: %s -> Domain: Invalid email\n", email);
	return;	
	}
   printf("Email: %s -> Domain: %s\n", email,ptr+1);
}
int main(){
	char emails[][50] = {
	 "user@gmail.com",
      "john.doe@company.org",
      "invalid-email",
     "admin@university.edu"	
	};
	int n = sizeof(emails) / sizeof(emails[0]);
	int i;
	for(i=0;i<n;i++){
		extract_domain(emails[i]);
	}
	return 0;
}
