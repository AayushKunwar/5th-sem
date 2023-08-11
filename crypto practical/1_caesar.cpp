#include<stdio.h>

int main(){
	char input[15],output[15];
	int offset=0;
	int toEnc;
	
	printf("Enter the input: ");
	scanf("%s",&input);
	printf("Enter the offset: ");
	scanf("%d",&offset);
	printf("press 1 to encrypt, 2 to decrypt: ");
	scanf("%d",&toEnc);
	
	if(toEnc==2){
		offset *= -1;
	}
	for(int i=0; input[i]!='\0';i++){
		output[i] = (input[i] -'a' + offset ) % 26 + 'a';
		printf("output[%d]= %c\n",i,output[i]);
	}
	printf("The output is %s",output);
	return 0;	
}
