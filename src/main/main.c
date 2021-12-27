/**
 * @file main.c
 * @brief this file initiates the program
 * @author Matthew C. Lindeman
 * @date 12/27/21
 * @bug None known
 * @todo Nothing atm
 */
#include<stdio.h>
#include<stdlib.h>
#include"../constants/include/constants.h"
#include"../graph/include/graph.h"

int main(void) {
	FILE * fp = fopen(PATH, "w");
	print_headings(fp, GRAPH_H, GRAPH_W);
	graph_t * graph = init_graph(GRAPH_H, GRAPH_W);
	write_axes(graph);
	//write_border(graph);
	print_graph_to_file(fp, graph);
	free_graph(graph);

	fclose(fp);
	return 0;
}
