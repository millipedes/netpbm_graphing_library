/**
 * @file graph.c
 * @brief This file contains the definitions for functions relating to the
 * graph structure
 * @author Matthew C. Lindeman
 * @date 12/27/21
 * @bug None known
 * @todo Nothing atm
 */
#include<stdio.h>
#include<stdlib.h>
#include"include/graph.h"
#include"../constants/include/constants.h"

/**
 * This function initiates a graph of height and width with black pixels.
 * @param the height and width of the graph
 * @return the initialized graph
 */
graph_t * init_graph(int height, int width) {
	graph_t * graph = calloc(1, sizeof(struct GRAPH_T));
	graph->pixels = calloc(height, sizeof(struct PIXEL_T *));
	for (int i = 0; i < height; i++) {
		graph->pixels[i] = calloc(width, sizeof(struct PIXEL_T));
	}

	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			graph->pixels[i][j].r = 0;
			graph->pixels[i][j].g = 0;
			graph->pixels[i][j].b = 0;
		}
	}

	graph->width = width;
	graph->height = height;
	return graph;
}

/**
 * This function prints out the pixels of the graph to the terminal.  Only 
 * recomended for very small graphs.
 * @param The graph
 * @return N/a
 */
void term_print_graph(graph_t * graph) {
	for (int i = 0; i < graph->height; i++) {
		for(int j = 0; j < graph->width; j++) {
			printf("%d %d %d\t", graph->pixels[i][j].r, graph->pixels[i][j].g, graph->pixels[i][j].b);
		}
		printf("\n");
	}
}
 
/**
 * This function frees a graph struct.
 * @param The graph struct.
 * @return N/a
 */
void free_graph(graph_t * graph) {
	for(int i = 0; i < graph->height; i++) {
		free(graph->pixels[i]);		
	}
	free(graph->pixels);
	free(graph);
}

/**
 * This function prints the file headings to the netpbm file
 * @param the height and width of the graph
 * @return N/a
 */
void print_headings(FILE * fp, int height, int width) {
	fprintf(fp, "P3\n");
	fprintf(fp, "%d %d\n", height, width);
	fprintf(fp, "%d\n", MAX_VALUE);
}

/**
 * This function
 * @param
 * @return
 */
void print_graph(FILE * fp, int height, int width) {
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			// The vertical line
			if ((j > ((width/2) - (RULE_W/2)) && j < ((width/2) + (RULE_W/2))) || ((i > height/2 - RULE_W/2) && (i < height/2  + RULE_W/2))) {
				fprintf(fp, "0 0 0\n");
			} else if((j < BORDER || j > GRAPH_W - BORDER) || (i < BORDER || i > GRAPH_H - BORDER)) {
				fprintf(fp, "%d %d %d\n", BORDER_R, BORDER_G, BORDER_B);
			} else {
				fprintf(fp, "%d %d %d\n", MAX_VALUE, MAX_VALUE, MAX_VALUE);
			}
		}
	}
}
