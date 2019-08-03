//
// Created by robot on 19-8-4.
//

#ifndef PRACTICE_GRAPH_H
#define PRACTICE_GRAPH_H

#include <stdio.h>
#include <stdlib.h>
struct GraphStructure
{
    int v;       //vertex
    int e;       //edge
    int **w;     //weight of edges
};
typedef struct GraphStructure * graphStructure;

//initialize a graph (empty
graphStructure createGraph(int v)
{
    graphStructure graph = malloc(sizeof(struct GraphStructure));  //allocate the memory of graph
    graph->v = v;      // initialize the number of vertex
    graph->e = 0;      // initialize the number of edge
    graph->w = malloc(v * sizeof(int));
    for(int i=0; i<v; i++)
    {
        graph->w[i] = malloc(v * sizeof(int *));
        for(int j=0; j<v; j++)
            graph->w[i][j] = 0;   //initialize the weight of edge : 0
    }
    return graph;
}

//build edge
void buildEdge(graphStructure g, int v1, int v2, int w)
{
    if(g!=NULL)
    {
        if(g->w[v1][v2]==0)
        {
            g->w[v1][v2] = w;   //the weight between v1 and v2
            g->e++;             //number of edge ++
        }
    }
}

//number of inLinks of v
double inLinks(graphStructure g, int v)
{
    double inlinks = 0;
    for(int i=0; i<g->v; i++)
    {
        if(g->w[i][v])
            inlinks++;
    }
    return inlinks;
}

//number of outLinks of v
double  outLinks(graphStructure g, int v)
{
    double outlinks = 0;
    for(int j=0; j<g->v; j++)
    {
        if(g->w[v][j])
            outlinks++;
    }
    //a special situation
    if(outlinks==0)
        outlinks=0.5;
    return outlinks;
}

//sum of outlinks
double sumOut(graphStructure g, int v)
{
    double sumout = 0;
    for(int i=0; i<g->v; i++)
    {
        if(g->w[v][i])
            sumout += outLinks(g, v);
    }
    return sumout;
}

//release memory
void releaseMem(graphStructure g)
{
    if(g!=NULL)
    {
        for(int i = 0; i<g->v; i++)
            free(g->w[i]);
    }
    free(g->w); free(g);
}

#endif //PRACTICE_GRAPH_H
