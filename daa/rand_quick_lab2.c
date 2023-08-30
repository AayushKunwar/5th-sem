// RANDOM quick sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int a[] = {1,5,2,8,4,2,1};
int size = sizeof a / sizeof a[0];
int swap_ctr = 0;

void print_arr(){
	for(int i=0; i<size; i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
}

void swap(int *a, int *b){
	int temp = *b;
	*b = *a;
	*a = temp;
	swap_ctr++;
}

int partition(int a[], int p, int r){
	int pivot = a[p];
	int i = p;
	for(int j= i+1; j<r; j++){
		if(a[j] <= pivot){
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[p], &a[i]);
	return i;
}

int len_partition(int a[], int p, int r){
	
	int k = rand()%size; // this is random number
	//int k = size -1;
	swap(&a[p], &a[k]);
	return partition(a, p, r);
}

void rnd_quick(int a[], int p, int r){
	if(p<r){
		int q = len_partition(a,p,r);
		partition(a, p, q-1);
		partition(a, q+1, r);
	}
}

int main(){
	srand(time(0));
	print_arr();
	rnd_quick(a,0,size);
	print_arr();
	printf("The swap counter is %d\n",swap_ctr);
	return 0;
}
