/**
 * @file main.c
 * @brief
 * @author Matthew C. Lindeman
 * @date 12/27/21
 * @bug None known
 * @todo Nothing atm
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../constants/include/constants.h"
#include"../graph/include/graph.h"

int main(void) {
	FILE * fp = fopen(PATH, "w");
	print_headings(fp, GRAPH_H, GRAPH_W);
	print_graph(fp, GRAPH_H, GRAPH_W);
	graph_t * graph = init_graph(GRAPH_H, GRAPH_W);
	term_print_graph(graph);
	free_graph(graph);

	fclose(fp);
	return 0;
}
