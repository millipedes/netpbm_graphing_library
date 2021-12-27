#include<stdio.h>
#include<stdlib.h>
#include"include/graph.h"
#include"../constants/include/constants.h"

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

void term_print_graph(graph_t * graph) {
	for (int i = 0; i < graph->height; i++) {
		for(int j = 0; j < graph->width; j++) {
			printf("%d %d %d\t", graph->pixels[i][j].r, graph->pixels[i][j].g, graph->pixels[i][j].b);
		}
		printf("\n");
	}
}
 
void free_graph(graph_t * graph) {
	for(int i = 0; i < graph->height; i++) {
		free(graph->pixels[i]);		
	}
	free(graph->pixels);
	free(graph);
}

void print_headings(FILE * fp, int height, int width) {
	fprintf(fp, "P3\n");
	fprintf(fp, "%d %d\n", height, width);
	fprintf(fp, "%d\n", MAX_VALUE);
}

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
