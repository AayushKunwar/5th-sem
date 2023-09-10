#include<stdio.h>

#define max_count 20

typedef struct {
    char name[2];
    int weight;
} edge;

edge list[max_count];
int list_idx = 0;
int visited[max_count] = { 0 };

void swap(edge* a, edge* b) {
    edge temp = *a;
    *a = *b;
    *b = temp;
}

void add_edge(char* name, int weight) {
    edge temp;
    temp.name[0] = name[0];
    temp.name[1] = name[1];
    temp.weight = weight;
    list[list_idx++] = temp;
}

void add_visited(edge foo) {
    visited[foo.name[0] - 'a'] = 1;
    visited[foo.name[1] - 'a'] = 1;
}

int is_printable(edge a) {
    if (visited[a.name[0] - 'a'] == 0 && visited[a.name[1] - 'a'] == 1) return 1;
    if (visited[a.name[0] - 'a'] == 1 && visited[a.name[1] - 'a'] == 0) return 1;
    return 0;
}

int main() {
    add_edge("be", 8);
    add_edge("ad", 2);
    add_edge("de", 2);
    add_edge("ef", 4);
    add_edge("ab", 3);
    add_edge("bd", 2);
    add_edge("cd", 3);
    add_edge("ac", 1);
    add_edge("bc", 4);
    add_edge("df", 5);

    // set a as starting point
    visited[0] = 1;

    for (int i = 0; i < list_idx; i++) {
        // find the lowest weight
        int low_idx = 0;
        // yes, this implementation is n^2
        for (int j = 1; j < list_idx; j++) {
            if (list[j].weight < list[low_idx].weight) low_idx = j;
        }
        if (is_printable(list[low_idx])) {
            add_visited(list[low_idx]);
            printf("%s %d\n", list[low_idx].name, list[low_idx].weight);
        }
        // make sure it isnt considered next time
        // or change the logic to remove this line
        list[low_idx].weight = 1000;

    }
    return 0;
}