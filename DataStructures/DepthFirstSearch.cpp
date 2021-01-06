#include "pch.h"
#include <iostream>
#include <list>
using namespace std;

class DFSGraph
{
    int numVertices;
    list<int>* adjLists;
    bool* visited;

public:
    DFSGraph(int V);
    void addEdge(int src, int dest);
    void DFS(int vertex);
};

DFSGraph::DFSGraph(int vertices)
{
    numVertices = vertices;
    adjLists = new list<int>[vertices];
    visited = new bool[vertices];
}

void DFSGraph::addEdge(int src, int dest)
{
    adjLists[src].push_front(dest);
}

void DFSGraph::DFS(int vertex)
{
    visited[vertex] = true;
    list adjList = adjLists[vertex];

    cout << vertex << " ";

    list<int>::iterator i;
    for (i = adjList.begin(); i != adjList.end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

int RunDepthFirstDriver()
{
    DFSGraph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.DFS(2);

    return 0;
}