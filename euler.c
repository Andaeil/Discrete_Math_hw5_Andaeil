#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void taka_a_tour(graph_t * g, int start){
	int curr = start;
	int n_edges, next;

	do{
		printf("%d\n", curr);
		for(next = 0; next < g->n_vertices; next++){
			if(g->m[curr][next] > 0){
				break;
			}
		}
		if(next < g->n_vertices){
			graph_remove_edge(g, curr, next, g->w[curr][next][0]);
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

	take_a_tour(g, 0);

	/* TODO: implement here */

	graph_free(g) ;
	return 0 ;
}
