#include "pagerank.h"

int main(int argc, char* argv[])
{
    //strtod: transfer str to double
    double d = 0.85;
    double diffPR = 0.00001;
    int maxIterations = 1000;
    readData();
    graphStructure g = buildGraph();
    double* pageRank = calculatePageRankW(g, d, diffPR, maxIterations);

    //sort urls in descending order of Weighted PageRank values
    sort(pageRank, urlNum);
    //result are written into pagerankList.txt
    FILE* fp = fopen("pagerankList.txt", "w");
    for(int i=0; i<urlNum; i++)
        fprintf(fp, "%s, %d, %.7f\n", urlArr[i], outDegree[i], *(pageRank+i));
    fclose(fp);
    return 0;
}

//this function is written by "Calculate Weighted PageRanks" in "http://www.cse.unsw.edu.au/~cs2521/19T2/assigns/ass2/Ass2.html"
double* calculatePageRankW(graphStructure g, double d, double diffPR, int maxIteration)
{
    double *PR  = malloc(urlNum* sizeof(double));
    double fontPR[urlNum];
    for(int i=0; i<urlNum; i++)
        PR[i] = (double)1/urlNum;
    int iteration = 0;
    double sumDiff = 0;
    double sum = 0;
    double diff = diffPR;
    while(iteration<maxIteration && diff>=diffPR)
    {
        sumDiff = 0;
        for(int k=0; k<urlNum; k++)
            fontPR[k] = PR[k];
        for(int i=0; i<urlNum; i++)
        {
            sum = 0;
            for(int j=0; j<urlNum; j++)
            {
                if(g->w[j][i] && i!=j)
                    sum += (fontPR[j] * (inLinks(g, i)/sumIn(g,j)) * (outLinks(g, i)/sumOut(g,j)));
            }
            PR[i] = (1.0-d)/urlNum + d*sum;
        }
        for(int i=0; i<urlNum; i++)
            sumDiff += fabs(PR[i] - fontPR[i]);
        diff = sumDiff;
        iteration++;
    }
    return PR;
}


//sort
void sort(double* PR, int len)
{
    //bubble sort
    double t;
    char tStr[100];
    int tOut;
    for(int i=0; i<len; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(*(PR+i)<*(PR+j))
            {
                t = *(PR+i);
                *(PR+i) = *(PR+j);
                *(PR+j) = t;

                strcpy(tStr, urlArr[i]);
                strcpy(urlArr[i],urlArr[j]);
                strcpy(urlArr[j],tStr);

                tOut = outDegree[i];
                outDegree[i] = outDegree[j];
                outDegree[j] = tOut;
            }
        }
    }
}