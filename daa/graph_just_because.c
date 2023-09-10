// Prims algo
#include<stdio.h>

#define true 1
#define false 0

int count = 0;
char visited_node[20];
int visit_count = 0;

typedef struct node {
	char name;
	struct node* nbour[10];
	int weight[10];
	int count;
}Node;

Node make_node(char name) {
	Node temp;
	temp.name = name;
	temp.count = 0;
	count++;
	return temp;
}

void make_edge(struct node* a, struct node* b, int weight) {
	a->nbour[a->count] = b;
	b->nbour[b->count] = a;
	a->weight[a->count] = weight;
	b->weight[b->count] = weight;
	a->count++;
	b->count++;
}

void print_edges(struct node* a) {
	for (int i = 0; i <= (*a).count; i++) {
		printf("%c ", (*(*a).nbour[i]).name);
	}
}

int is_visited(char name) {
	for (int i = 0; i <= count; i++) {
		if (name == visited_node[i]) return true;
	}
	return false;
}

int main() {
	Node a = make_node('a');
	Node b = make_node('b');
	Node c = make_node('c');
	Node d = make_node('d');
	Node e = make_node('e');
	Node f = make_node('f');
	make_edge(&a, &b, 3);
	make_edge(&a, &c, 1);
	make_edge(&a, &d, 2);
	make_edge(&b, &d, 2);
	make_edge(&b, &e, 8);
	make_edge(&e, &d, 2);
	make_edge(&e, &f, 4);
	make_edge(&d, &f, 5);
	make_edge(&b, &c, 4);
	make_edge(&c, &d, 3);
	//printf("%c", (*(a.nbour[0])).name);
	print_edges(&a);

	// now the prims algo starts
	Node start_node = a;
	for (int i = 0; i < count; i++) {
		int curr_min_weight = 100000;
		char curr_name = 'x';
		// find the lowest edge and add to visited list
		for (int j = 0; i < count; j++) {

		}
	}

	return 0;
}
