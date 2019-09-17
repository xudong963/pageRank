//
// Created by robot on 19-8-4.
//

#ifndef PRACTICE_READDATA_H
#define PRACTICE_READDATA_H

#include "graph.h"
#include <string.h>

extern char urlArr[10][10];  // store url
extern int urlNum;
int* outDegree;
//read data from collection.txt
void readData();

//after store url into urlArr, build graph.
graphStructure buildGraph();

#endif //PRACTICE_READDATA_H


