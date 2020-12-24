#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void take_a_tour(graph_t * g, int start){
	int curr = start;
	int next;

	do{
		printf("%d\n", curr);
		for(next = 0; next < g->n_vertices; next++){
			if(g->m[curr][next] > 0){ 
				break;
			}
		}
		
		if(next < g->n_vertices){
			graph_remove_edge(g, curr, next, g->w[curr][next][g->m[curr][next] - 1]);
			curr = next;
		}
	}while(next != g->n_vertices);
}

/*TODO: you can add functions as you want */

int
main ()
{
	graph_t * g ; 

	g = graph_read_stdin() ;

	int start;
	int odd_v = 0;

	for(int i = 0; i < g->n_vertices; i++){
		int count = 0;
		for(int j = 0; j < g->n_vertices; j++){
			count += g->m[i][j];
		}
		if(count%2 != 0){
			odd_v += 1;
		}
	}

	if(odd_v == 2){
		for(int i = 0; i < g->n_vertices; i++){
			int count = 0;
			for(int j = 0; j < g->n_vertices; j++){
				count += g->m[i][j];
			}
			if(count%2 != 0){
				start = i;
				break;
			}
		}
		take_a_tour(g, start);
	}else if(odd_v == 0){
		take_a_tour(g, 0);
	}

	/* TODO: implement here */

	graph_free(g) ;
	return 0 ;
}
