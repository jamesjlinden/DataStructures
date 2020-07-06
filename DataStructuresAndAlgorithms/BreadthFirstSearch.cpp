#include "pch.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

namespace BFS
{
    class Vertex
    {
    public:
        Vertex(int value) : value(value) {}
        int value;
    };

    class Edge
    {
    public:
        Edge(Vertex* u, Vertex* v) : u(u), v(v) {}
        Vertex* u;
        Vertex* v;
    };

    class Graph
    {
    public:
        Graph() {}
        ~Graph() {}
        unordered_map<Vertex*, vector<Edge>> adjacencyMap;

        void BFS()
        {
            unordered_set<Vertex*> visitedVertices;

            for (auto vertexIter = adjacencyMap.begin(); vertexIter != adjacencyMap.end(); ++vertexIter)
            {
                if (visitedVertices.find(vertexIter->first) == visitedVertices.end())
                    visitedVertices.emplace(vertexIter->first);
                else
                    continue;

                for (auto edgeIter = vertexIter->second.begin(); edgeIter != vertexIter->second.end(); ++edgeIter)
                    cout << "u = " << edgeIter->u->value << "  v = " << edgeIter->v->value << endl;
            }
        }
    };
}

void RunBreadthFirstSearchDriver()
{
    using namespace BFS;

    Vertex v1(1), v2(2), v3(3), v4(4);

    Graph g;
    g.adjacencyMap[&v1].emplace_back(&v1, &v2);
    g.adjacencyMap[&v1].emplace_back(&v1, &v3);

    g.adjacencyMap[&v2].emplace_back(&v2, &v1);
    g.adjacencyMap[&v2].emplace_back(&v2, &v3);
    g.adjacencyMap[&v2].emplace_back(&v2, &v4);

    g.adjacencyMap[&v3].emplace_back(&v3, &v1);
    g.adjacencyMap[&v3].emplace_back(&v3, &v2);
    g.adjacencyMap[&v3].emplace_back(&v3, &v4);

    g.adjacencyMap[&v4].emplace_back(&v4, &v2);
    g.adjacencyMap[&v4].emplace_back(&v4, &v3);

    g.BFS();
}
