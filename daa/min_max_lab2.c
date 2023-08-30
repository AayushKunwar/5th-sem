#include<stdio.h>
#include<math.h>

typedef struct{
	int min;
	int max;
} tuple;

tuple eval(tuple a, tuple b){
	tuple result;
	result.min = a.min < b.min ? a.min : b.min;
	result.max = a.max > b.max ? a.max : b.max;	
	return result;
}

tuple minimax(int a[], int p, int q){
	tuple result;
	if(p==q){
		result.min = a[p];
		result.max = a[p];
		return result;
	}
	if(p<(q+1)){
		int min = floor((p+q)/2);
		printf("%d, %d, %d\n",min, p, q);
		tuple atemp, btemp;
		atemp = minimax(a,p,min);
		btemp = minimax(a,min+1, q);
		return eval(atemp,btemp);
	}
	
	if(p == (q+1)){
		
		if(a[p] > a[q]){
			result.max = a[p];
			result.min = a[q]; 
		}
		else{
			result.min = a[p];
			result.max = a[q];
		}
		return result;
	}
	
	printf("Something wrong");
	return result;
	
}

int main(){
	int a[] = {6,3,4,8,7,5,1,23};
	int size = sizeof a / sizeof a[0];
	tuple ans = minimax(a,0,size);
	printf("min = %d, max = %d \n", ans.min, ans.max);
	return 0;
}
