//
// Created by robot on 19-8-4.
//

#ifndef PRACTICE_READDATA_H
#define PRACTICE_READDATA_H

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <string.h>

char **urlArr = NULL;  // store url
char url[200];         // assume max length: 200
int urlNum = 0;
//read data from collection.txt
void readData()
{
    FILE* fp = fopen("collection.txt", "r");
    //use fscanf (suggested) to read from file and store into urlArr.
    while(fscanf(fp, "%200s", url) != EOF)
    {
        urlArr = realloc(urlArr, (urlNum+1)* sizeof(char*));
        urlArr[urlNum] = malloc(strlen(url)+1);   //be careful: +1 !
        strcpy(urlArr[urlNum], url);
        urlNum++;
    }
    fclose(fp);
}

//after store url into urlArr, build graph.
graphStructure buildGraph()
{
    char url1[200];
    graphStructure g = createGraph(urlNum);  //url == vertex, so urlNum == vertexNum
    for(int i=0; i<g->v; i++)
    {
        char* ulrName = strcat(urlArr[i], ".txt");
        FILE* fp = fopen(ulrName, "r");
        while (fscanf(fp, "%s", url1) != EOF)
        {
            int flag=0;
            int j = 0;
            for(j=0; j<urlNum; j++)
            {
                if(strcmp(url1, urlArr[j]) == 0)
                    flag = 1;
            }
            if(flag)      //if find url in .txt,  build edge
                buildEdge(g, i, j, 1);
        }
        fclose(fp);
    }
    //a special situation !!! self-loops
    for(int i=0, j=0; i<urlNum; i++, j++)
    {
        if(g->w[i][j])
        {
            g->w[i][j] = 0;
            g->e--;
        }
    }
    // release memory
    for(int i=0; i<urlNum; i++)
        free(urlArr[i]);
    free(urlArr);

    return g;
}

#endif //PRACTICE_READDATA_H
