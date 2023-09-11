#include<stdio.h>

typedef struct node {
    char name;
    int weight;
    int parent; // parent idx inside the main_list
    int parent_code;
    int avail;
} node;

node main_list[20] = { 0 };
int main_counter = -1;

int add_node(char name, int weight) {
    node temp;
    temp.name = name;
    temp.weight = weight;
    temp.parent = 0;
    temp.parent_code = -1;
    temp.avail = 1;
    main_list[++main_counter] = temp;
    return main_counter;
}

int find_min() {
    int curr_min;
    int curr_wt = 10000;
    for (int i = 0; i <= main_counter; i++) {
        if (main_list[i].weight < curr_wt && main_list[i].avail) {
            curr_min = i;
            curr_wt = main_list[i].weight;
        }
    }
    return curr_min;
}

// this for debug only
void print_list() {
    for (int i = 0; i <= main_counter; i++) {
        if (main_list[i].avail) {
            printf("%c:%d:%d\t", main_list[i].name, main_list[i].weight, i);
        }
    }
    printf("\n");
}

void print_parent(int idx) {
    if (main_list[idx].parent == 0) return;
    print_parent(main_list[idx].parent);
    printf("%d", main_list[idx].parent_code);
}

int main() {
    char s[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    char f[] = { 45, 13, 12, 16, 9, 5 };
    int size = sizeof s / sizeof s[0];

    for (int i = 0; i < size; i++) {
        add_node(s[i], f[i]);
    }
    for (int i = 0; i < size - 1; i++) {
        // print_list();
        int left = find_min();
        main_list[left].avail = 0;
        int right = find_min();
        main_list[right].avail = 0;
        // printf("left %d right %d\n", left, right);
        int temp = add_node('x', main_list[left].weight + main_list[right].weight);
        main_list[left].parent = temp;
        main_list[left].parent_code = 0;
        main_list[right].parent = temp;
        main_list[right].parent_code = 1;
    }

    // print_list();
    // now print the answer
    for (int i = 0; i < size; i++) {
        printf("%c->", main_list[i].name);
        print_parent(i);
        printf("\n");
    }
}