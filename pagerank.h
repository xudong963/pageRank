//
// Created by robot on 19-8-4.
//

#ifndef PRACTICE_PAGERANK_H
#define PRACTICE_PAGERANK_H


#include "readData.h"
#include <math.h>

//this function is written by "Calculate Weighted PageRanks" in "http://www.cse.unsw.edu.au/~cs2521/19T2/assigns/ass2/Ass2.html"
double* calculatePageRankW(graphStructure g, double d, double diffPR, int maxIteration);

//sort
void sort(double* PR, int len);

#endif //PRACTICE_PAGERANK_H

