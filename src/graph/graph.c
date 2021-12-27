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
 * This function initiates a graph of height and width with white pixels.
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
			graph->pixels[i][j].r = 255;
			graph->pixels[i][j].g = 255;
			graph->pixels[i][j].b = 255;
		}
	}

	graph->width = width;
	graph->height = height;
	return graph;
}

/**
 * This function writes the axes to a graph
 * @param the graph for which the axes are to be written
 * @return N/a
 */
void write_axes(graph_t * graph) {
	for(int i = 0; i < graph->height; i++) {
		for(int j = 0; j < graph->width; j++) {
			if ((j > ((graph->width/2 - BORDER) - (RULE_W)) && j < ((graph->width/2 - BORDER) + (RULE_W))) || ((i > graph->height/2 - BORDER - RULE_W) && (i < graph->height/2 - BORDER + RULE_W))) {
				graph->pixels[i][j].r = 0;
				graph->pixels[i][j].g = 0;
				graph->pixels[i][j].b = 0;
			}
		}
	}
}

/**
 * This function writes borders into a given graph_t struct
 * @param The grpah tp be written to
 * @return N/a
 */
void write_border(graph_t * graph) {
	for(int i = 0; i < graph->height; i++) {
		for(int j = 0; j < graph->width; j++) {
			if((j < BORDER || j > GRAPH_W - BORDER) || (i < BORDER || i > GRAPH_H - BORDER)) {
				graph->pixels[i][j].r = BORDER_R;
				graph->pixels[i][j].g = BORDER_G;
				graph->pixels[i][j].b = BORDER_B;
			}
		}
	}
}

void write_tic_marks(graph_t * graph) {
	if((GRAPH_W - 2*BORDER) % TICS_X != 0 || (GRAPH_H - 2*BORDER) % TICS_Y != 0) {
		fprintf(stderr, "[ERROR]: graph width||height not divisible by tics_x||tic_y\n");
	}
	int inc_x = (GRAPH_W - 2*BORDER) / TICS_X;
	int tmp_x = (GRAPH_W - 2*BORDER) / TICS_X;
	int inc_y = (GRAPH_H - 2*BORDER) / TICS_Y;
	int tmp_y = (GRAPH_H - 2*BORDER) / TICS_Y;

	for(int i = BORDER; i < (graph->height - BORDER); i++) {
		for(int j = BORDER; j < (graph->width - BORDER); j++) {
			if (j > (tmp_x - RULE_W) && j < (tmp_x + RULE_W) && i > (graph->height/2 - BORDER - TIC_MAG) && i < (graph->height/2 - BORDER + TIC_MAG)) {
				graph->pixels[i][j].r = 0;
				graph->pixels[i][j].g = 0;
				graph->pixels[i][j].b = 0;
			}
			if(j > tmp_x + RULE_W) {
				tmp_x += inc_x;
			}
		}
		tmp_x = inc_x;
	}
}

/**
 * This function prints out the pixels of the graph to the terminal.  Only 
 * recomended for very small graphs.
 * @param The graph
 * @return N/a
 */
void print_graph(graph_t * graph) {
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

void print_graph_to_file(FILE * fp, graph_t * graph) {
	for(int i = 0; i < graph->height; i++) {
		for(int j = 0; j < graph->width; j++) {
			fprintf(fp, "%d %d %d\t", graph->pixels[i][j].r, graph->pixels[i][j].g, graph->pixels[i][j].b);
		}
		fprintf(fp, "\n");
	}
}
