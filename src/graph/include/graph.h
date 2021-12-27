/**
 * @file graph.h
 * @brief This file contains the function definitions of the functions defined
 * in graph.c
 * @author Matthew C. Lindeman
 * @date 12/27/21
 * @bug None known
 * @todo Nothing atm
 */
#ifndef GRA_H
#define GRA_H

typedef struct PIXEL_T {
	int r;
	int g;
	int b;
}pixel_t;

typedef struct GRAPH_T {
	pixel_t ** pixels;
	int height;
	int width;
} graph_t;

graph_t * init_graph(int height, int width);
void write_axes(graph_t * graph);
void write_border(graph_t * graph);
void write_tic_marks(graph_t * graph);
void print_graph(graph_t * graph);
void free_graph(graph_t * graph);

void print_headings(FILE * fp, int height, int width);
void print_graph_to_file(FILE * fp, graph_t * graph);

#endif
