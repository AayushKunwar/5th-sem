#include<stdio.h>
#include<math.h>

int count_digit(int num){
	int count = 0;
	while(num){
		count++;
		num = num/10;
	}
	return count;
}

int get_middle(int input,int n){
	int half_n = floor(n/2);

	// remove the right side
	input = input/(int)pow(10,half_n);
	// extract the middle n digits
	input = input%((int)pow(10,n));

	return input;
}

int main(){
	
	int input;
	printf("Enter the input: ");
	scanf("%d", &input);
	int n = count_digit(input);
	printf("digits: %d\n",n);
	
	if(n % 2 !=0){
		printf("no of digits, must be even\n");
		return 0;
	}
	
	for(int i=0; i<10; i++){
		input = input * input;
		int input_sq = input;
		input = get_middle(input,n);
		printf("%d: %d : %d\n",i,input_sq,input);
	}
}
