// Rail fence cipher
#include<stdio.h>
#include<string.h>

void encr(char input[], int rails, int pos[]){
	char output[15];
	int currPos = 0;
	
	for(int i=rails; i>0; i--){ // loop through the rails
		for(int j=0; j<strlen(input);j++){ // loop through the string	
			if(pos[j]==i){
				output[currPos] = input[j]; 
				currPos++;
			}
		}
	}
	
	printf("Output: %s",output);
}

void decr(char input[], int rails, int pos[]){
	char output[15];
	int currPos = 0;
	// go through all rails
	for(int i = rails; i>0; i--){
		// this to find the j pos from pos[]
		for(int j = 0; j<strlen(input); j++){
			if(pos[j]==i){
				output[j] = input[currPos]; 
				currPos++;
			}
		}
	}
	printf("Output: %s",output);
}

int main(){
	char input[15];

	int rails, choice;
	printf("Enter the pass phrase: ");
	scanf("%s",&input);
	printf("Enter the no of rails: ");
	scanf("%d",&rails);
	
	printf("Press 1 to encrypt, 2 to decrupt: ");
	scanf("%d",&choice);
	
	int currPos = rails;
	int pos[15];
	int toIncr = -1;
	for(int i=0; i<strlen(input); i++){
		pos[i] = currPos;
		currPos += toIncr;
		if(currPos == rails && toIncr == 1){
			toIncr = -1;
		}
		else if(currPos == 1 && toIncr == -1){
			toIncr = 1;
		}
	}
	
	if(choice == 1){
		encr(input, rails, pos);
	}
	if(choice == 2){
		decr(input, rails, pos);
	}
	
	return 0;
}
