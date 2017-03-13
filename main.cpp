#include "Test.h"
#include <iostream>
#include "Edge.h"

using namespace std;

int** _initGraph1(int size)
{
    int **answer = new int* [size];
    for(int i=0;i<size;i++)
    {
        answer[i]=new int[size];
        for(int j=0;j<size;j++)
        {
            answer[i][j]=-1;
        }
    }
    return answer;
}

map<int,bool> visitados;

bool formCycle(Edge* edge, vector<Edge *> edges) {
       return visitados[edge->source] && visitados[edge->destination];
}

int** mapEdgestoGraph(vector<Edge*> edges, int size) {
    int** graph = _initGraph1(size);
    for (int i = 0; i < edges.size(); ++i) {
        graph[edges[i]->source][edges[i]->destination] = edges[i]->weight;
        graph[edges[i]->destination][edges[i]->source] = edges[i]->weight;
    }
    return graph;
}

int** getKruskalMST(int** graph, int size, vector<Edge*> edges)
{
    visitados.clear();
    vector<Edge *> T;
    for (int i = 0; i < edges.size(); i++)
        if(!formCycle(edges[i],T)) {
            visitados[edges[i]->source] = true;
            visitados[edges[i]->destination] = true;
            T.push_back(edges[i]);
        }
    return mapEdgestoGraph(T,size);
}

int main ()
{

    test();
    return 0;
}
