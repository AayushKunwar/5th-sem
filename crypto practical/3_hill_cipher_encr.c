#include<stdio.h>
#include<string.h>

int main(){
	char input[15] = {0};
	char temp[15]  = {0};
	int key[3][3], choice;
	printf("Press 2 for 2x2 or 3 for 3x3 key: ");
	scanf("%d",&choice);
	
	if(choice != 2 && choice != 3) return 1;
		
	printf("Enter the key: ");
	scanf("%s",temp);
	int temp_c = 0;
	for(int i=0; i<(choice); i++){ // row
		for(int j=0; j<choice; j++){ // col
			// assume alphabet input
			key[i][j] = temp[temp_c]-'a';
			temp_c++;
		}
	}
	printf("The key is :\n");
	for(int i=0; i<choice; i++){ // row
		for(int j=0; j<choice; j++){ // col
			printf("%d \t",key[i][j]);
		}
		printf("\n");
	}
	printf("Note: key is padded with 'a' to be multiple of 3\n");
	printf("Enter the Plain Text: ");
	scanf("%s",&input);
	// cleanup the input
	int last = strlen(input)%3;
	if(last==1){
		input[strlen(input)+2] = 0;
		last++;
	}
	if(last==2){
		input[strlen(input)+1] = 0;
	}
	printf("The encrypted text is: ");
	for(int word=0; word<strlen(input); word+=choice){

		for(int col=0; col<choice; col++){
					int curr = 0;
			for(int row=0; row<choice; row++){
				curr += ((input[word+row] - 'a') * key[col][row]);
			}
			while(curr<0){
				curr+=26;
			}
			printf("%c",curr%26 + 'a');
		}
	}	
}
