//
// Created by robot on 19-8-4.
//

#ifndef PRACTICE_GRAPH_H
#define PRACTICE_GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#define MAXV  10
struct GraphStructure
{
    int v;       //vertex
    int e;       //edge
    int w[MAXV][MAXV];     //weight of edges
};
typedef struct GraphStructure * graphStructure;

//initialize a graph (empty
graphStructure createGraph(int v);

//build edge
void buildEdge(graphStructure g, int v1, int v2);

//number of inLinks of v
double inLinks(graphStructure g, int v);

//number of outLinks of v
double  outLinks(graphStructure g, int v);

//sum of inlinks
double sumIn(graphStructure g, int v);

//sum of outlinks
double sumOut(graphStructure g, int v);

//release memory
void releaseMem(graphStructure g);
#endif //PRACTICE_GRAPH_H


