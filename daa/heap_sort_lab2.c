#include<stdio.h>
#include<math.h>

int a[] = {1,5,2,8,9};
int size = sizeof a/ sizeof a[0];
int size2 = sizeof a/ sizeof a[0];

void print_arr(){
	for(int i=0; i<size2; i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
}

void swap(int *a, int *b){
	int temp = *b;
	*b = *a;
	*a = temp;
}

void max_heapify(int a[], int i){

	print_arr();

	int l = 2 * i;
	int r = 2 * i + 1;
	int largest;
	
	if( l<= size && a[l] > a[i]){
		largest = l;
	}
	else largest = i;
	if( r <= size && a[r] > a[largest]) largest = r;
	
	if(largest != i){
		swap(&a[i], &a[largest]);
		max_heapify(a,largest);
	}	
}

void build_max(int a[]){
	for(int i=floor(size/2); i>1; i--){
		max_heapify(a, i);
	}

}
    
int main(){
	
	build_max(a);
	for(int p=size; p>=2; p--){
		swap(&a[1], &a[p]);
		size--;
		max_heapify(a,1);
	}
	
	return 0;
}
