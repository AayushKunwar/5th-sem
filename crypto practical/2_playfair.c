#include<stdio.h>
#include<string.h>

#define MAX 15

//globabl variable because i cant pass 2d array in func :(
char mat[5][5];

//init the unique alphabet arr
//int alp[26] = {0}; with this you have to minus the 'a' from each access
int alp['z'+1] = {0};
int cur_key = 0;

int mod5(int num){
	return ((num%5)+5)%5;
}

// get char from the input key to add to the key matrix
char get_char(char key[]){
	if(cur_key>=strlen(key)){
		return ' ';
	}
	// to handle repetition in the key
	while(alp[key[cur_key]] == 1){
		cur_key++;
	}
	if(cur_key>=strlen(key)){
		return ' ';
	}
	cur_key++;
	if(key[cur_key-1] == 'i' || key[cur_key-1] == 'j'){
		alp['i'] = 1;
		alp['j'] = 1;
		return 'i';
	}else{
		alp[key[cur_key-1]] = 1;
		return key[cur_key-1];
	}				
}

void encr(char a, char b, int pos[]){
	if(pos[0]==pos[2]){
		a = mat[pos[0]][(pos[1]+1)%5];
		b = mat[pos[0]][(pos[3]+1)%5];
	}
	else if(pos[1]==pos[3]){
		a = mat[(pos[0]+1)%5][pos[1]];
		b = mat[(pos[2]+1)%5][pos[1]];
	}
	else{
		a = mat[pos[0]][pos[3]];
		b = mat[pos[2]][pos[1]];
	}
	printf("%c%c",a,b);
}
void decr(char a, char b, int pos[]){
	if(pos[0]==pos[2]){
		a = mat[pos[0]][mod5(pos[1]-1)];
		b = mat[pos[0]][mod5(pos[3]-1)];
	}
	else if(pos[1]==pos[3]){
		a = mat[mod5(pos[0]-1)][pos[1]];
		b = mat[mod5(pos[2]-1)][pos[1]];
	}
	else{
		a = mat[pos[3]][pos[0]];
		b = mat[pos[2]][pos[1]];
	}
	printf("%c%c",a,b);
}

int main(){
	char key[MAX], input_str[MAX];
	// this to pass the pos 
	int pos[4];
	
	printf("Enter the key: ");
	scanf("%s",&key);
	
	int cur_alp = 'a';
	
	for(int i=0; i<5; i++){
		for (int j=0; j<5; j++){
			// first put all the key into table
			char temp = get_char(key);
			if(temp != ' '){
				mat[i][j] = temp;
			}
			// now fill the table with rest of the alphabet
			else{
				while(1){
					if(alp[cur_alp] != 0){
						cur_alp++;
					}
					else if(cur_alp =='i' || cur_alp =='j'){
						alp['i'] = 1;
						alp['j'] = 1;
						mat[i][j] = 'i';
						cur_alp++;
						break;	
					}else{
						mat[i][j] = cur_alp;
						alp[cur_alp] = 1;
						cur_alp++;
						break;
					}
				}
			}
		}
	}
	// i is col, j is row
	for(int i=0; i<5; i++){
		for (int j=0; j<5; j++){
			printf("%c ", mat[i][j]);
		}
		printf("\n");
	}
	
	char a,b;
	int choice;
	printf("Enter the String: ");
	scanf("%s",&input_str);
	
	printf("Press 1 to Encrypt, 2 for Decrypt: ");
	scanf("%d",&choice);
	
	// handle the encryption and decryption
	for(int i=0; i<strlen(input_str);i+=2){
		a = input_str[i];
		if(input_str[i] != input_str[i+1] && input_str[i+1] != '\0'){
		//	printf("-%c%c-",input_str[i],input_str[i+1]);	
			b = input_str[i+1];
		}else{
			//printf("-%c%c-",input_str[i],'x');
			i--;
			b='x';
		}
		// lookup a and b;
		// put the row and col of a and b in pos array in sequence
		for(int col=0; col<5; col++){
			for(int row=0; row<5; row++){
				if(mat[row][col] == a){
					pos[0] = row;
					pos[1] = col;
				}
				if(mat[row][col] == b){
					pos[2] = row;
					pos[3] = col;
				}
			}
		}
		
		// not necessary to pass a,b in encr and decr
		if(choice == 1) encr(a,b,pos);
		else decr(a,b,pos);
	}	
	return 0;
}
