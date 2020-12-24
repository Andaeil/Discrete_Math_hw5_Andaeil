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
			length[i] = 2000000000;
		}
	}
	visited[start] = 1;

	for(int i = 0; i < g->n_vertices; i++){
		int curr;
		int min = 2000000000;

		for(int j = 0; j < g->n_vertices; j++){
			if(length[j] < min && visited[j] != 1){
				curr = j;
				break;
			}
		}

		for(int j = 0; j < g->n_vertices; j++){
			if(g->m[curr][j] > 0){
				for(int k = 0; k < g->m[curr][j]; k++){
					if(length[curr] + g->w[curr][j][k] < length[j]){
						length[j] = length[curr] + g->w[curr][j][k];
					}
				}
			}
		}
		visited[curr] = 1;
	}

	printf("%d에서 %d까지의 최단 경로는 %d입니다.\n", start, end, length[end]);
}

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
