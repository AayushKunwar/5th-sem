#include<stdio.h>

#define count 6 // no of vertices in graph

int edge[count][count] = {
	{-1, 3, 1, 2,-1,-1},
	{ 3,-1, 4, 2, 8,-1},
	{ 1, 4,-1, 3,-1,-1},
	{ 2, 2, 3,-1, 2,-1},
	{-1, 8,-1, 2,-1, 4},
	{-1,-1,-1,-1, 5,-1}
};

int v_vertic[count]; // visited vertice

int main() {
	// initialize vertice to -1
	// -1 means not visited
	for (int i = 0; i < 10; i++) v_vertic[i] = -1;
	v_vertic[0] = 0;

	// find the lowest edge
	// go through all the vertices
	for (int foo = 0; foo < count - 1; foo++) {
		// loop through the visited vertex
		int low_edge = 10000;
		int temp_vertix, temp_vertix_2;
		for (int i = 0; i < count; i++) {
			if (v_vertic[i] == -1) continue; // visited vertex test
			// loop through the edges
			for (int curr_edge = 0; curr_edge < count; curr_edge++) {
				if (edge[i][curr_edge] < low_edge && edge[i][curr_edge] != -1) {
					// make sure the low edge vertex (to print) is not visited
					if (v_vertic[curr_edge] != -1) continue;
					low_edge = edge[i][curr_edge];
					temp_vertix = curr_edge;
					temp_vertix_2 = i;
				}
			}
		}
		v_vertic[temp_vertix] = 1;
		printf("%c-%c %d\n", temp_vertix + 'a', temp_vertix_2 + 'a', low_edge);
	}
	return 0;
}
