//
// Created by robot on 19-8-4.
//

#include "readData.h"
int urlNum = 0;
char urlArr[10][10];
//read data from collection.txt
void readData()
{
    char url[100];
    FILE* fp = fopen("collection.txt", "r");
    //use fscanf (suggested) to read from file and store into urlArr.
    while(fscanf(fp, "%100s", url) != EOF)
    {
        strcpy(urlArr[urlNum++], url);
    }
    fclose(fp);
}

//after store url into urlArr, build graph.
graphStructure buildGraph()
{
    char tempUrl[100];
    outDegree = malloc(urlNum* sizeof(double));
    char url1[200];
    graphStructure g = createGraph(urlNum);  //url == vertex, so urlNum == vertexNum
    for(int i=0; i<g->v; i++)
    {
        strcpy(tempUrl, urlArr[i]);
        strcat(tempUrl, ".txt");   //bug: dest can't be urlArr[i], which will change urlArr(urlArr will be used next)
        FILE* fp = fopen(tempUrl, "r");
        while (fscanf(fp, "%s", url1) != EOF)
        {
            if(strcmp(url1, "#end") == 0)
                break;
            int flag=0;
            for(int j=0; j<urlNum; j++)
            {
                if(strcmp(url1, urlArr[j]) == 0)
                    flag = 1;
                if(flag)      //if find url in .txt,  build edge
                    buildEdge(g, i, j);
                flag = 0;
            }
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

    //calculate number of outDegree urls for each url
    for(int i=0; i<urlNum; i++)
    {
        outDegree[i] = outLinks(g, i);
    }
    /*
    // release memory
    for(int i=0; i<urlNum; i++)
        free(urlArr[i]);
    free(urlArr);
    */
    return g;
}










