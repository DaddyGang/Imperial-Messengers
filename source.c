#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>

/* Maximum number of vertice */
#define eMax 100
/* Largest integer distance possible */
#define INT_MAX 100000

/* Properties of an edge */
typedef struct {
	int start, end, dis;
} Edge;

/* Helper function to test whether we get the correct input edges */
void print_Edge(Edge es[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d %d %d\n", es[i].start, es[i].end, es[i].dis);
	}
}

int main() {
	/* Allocate space for all the edges in the map */
	Edge edges[eMax*eMax];
	int N;
	/* Read from stdin and construct the map into edges array */
	scanf("%d", &N);
	int i, j, k = 0;
	char s[100];
	for (i = 1; i < N; i++) {
		for (j = 0; j < i; j++) {
			// If the input is not a number, just pass it
			scanf("%s", s);
			if (s[0]=='x') continue;
			int temp = atoi(s);
			edges[k].start = i;
			edges[k].end = j;
			edges[k].dis = temp;
			k++;
		}
	}
	// Now k is the number of edges in the array
	/* Allocate memory for a book to record minimum distance to reach each point */
	int *book = (int*) malloc(N*sizeof(int));
	book[0] = 0;
	for (i = 1; i < N; i++) {
		book[i] = INT_MAX;
	}
	/* It takes at most N iterations to reach optimal distance for every node in the map */
	for (i = 0; i < N; i++) {
		bool finish = true;
		for (j = 1; j < k; j++) {
			int u = edges[j].start;
			int v = edges[j].end;
			int w = edges[j].dis;
			/* Relax for Bidirectional edges */
			if (book[v] > book[u] + w) {
				book[v] = book[u] + w;
				finish = false;
			}
			if (book[u] > book[v] + w) {
				book[u] = book[v] + w;
				finish = false;
			}
		}
		if (finish) break;
	}
	int max_dis = book[0];
	for (i = 0; i < N; i++) {
		max_dis = book[i] > max_dis ? book[i] : max_dis;
	}
	/* Print result */
	printf("%d\n", max_dis);

	getchar();
	return 0;
}
