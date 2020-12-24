#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

void bfs(graph_t * g, int start, int end){
	int visited[g->n_vertices];
	int length[g->n_vertices];

	for(int i = 0; i < g->n_vertices; i++){
		if(g->m[start][i] > 0){
			length[i] = g->w[start][i][g->m[start][i]-1];
		}else if(start == i){
			length[i] = 0;
		}else{
			length[i] = 1000000000;
		}
	}
	visited[start] = 1;

	for(int i = 0; i < g->n_vertices; i++){
		int curr;
		int min = 1000000000;

		for(int j = 0; j < g->n_vertices; j++){
			if(length[j] < min && visited[j] != 1){
				curr = j;
				break;
			}
		}

		for(int j = 0; j < g->n_vertices; j++){
			if(g->m[curr][j] > 0){
				printf("curr = %d, j = %d, length[curr] = %d, g->w[curr][j][g->m[curr][j]-1] = %d, length[j] = %d\n", curr, j, length[curr], g->w[curr][j][g->m[curr][j]-1], length[j]);
				if(length[curr] + g->w[curr][j][g->m[curr][j]-1] < length[j]){
					length[j] = length[curr] + g->w[curr][j][g->m[curr][j]-1];
				}
			}
		}
		visited[curr] = 1;
	}

	printf("%d에서 %d까지의 최단 경로는 %d입니다.\n", start, end, length[end]);
}

// void bfs(graph_t * g, int start){
// 	int n_queue = 0;
// 	int queue[63];
// 	int head = 0;
// 	int tail = 0;
// 	int length[64];

// 	int visited[64] = {0};

// 	memset(visited, 0, sizeof(int) * 64);

// 	queue[tail++] = start; n_queue++; visited[start] = 1;

// 	while(n_queue > 0){
// 		int curr = queue[head++]; n_queue --;
// 		printf("%d\n", curr);

// 		for(int neighbor = 0; neighbor < g->n_vertices; neighbor++){		
// 			if(g->m[curr][neighbor] > 0){
// 				if(visited[neighbor] == 0){
// 					queue[tail++] = neighbor; n_queue++; visited[neighbor] = 1;	
// 				}
// 			} 
// 		}
// 	}
// }

/*TODO: you can add functions as you want */

int
main (int argc, char ** args)
{
	graph_t * g ; 

	g = graph_read_stdin() ;

	if (argc != 3) { 
		fprintf(stderr, "Too few arguments\n") ;
		return 1 ;
	}

	int start, end ;

	start = atoi(args[1]) ;
	end = atoi(args[2]) ;

	if (start < 0 || g->n_vertices <= start ||
		end < 0 || g->n_vertices <= end) {
		fprintf(stderr, "Wrong arguments\n") ;
		return 1 ;
	}

	bfs(g, start, end);

	/* TODO: implement here */

	graph_free(g) ;
	return 0 ;
}
