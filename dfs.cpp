#include <iostream>
#include <vector>
#include "matrix.h"

using namespace std;

class Edge {
public:
    int from;
    int to;
    int weight;

    Edge(int from, int to, int weight){
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};

class Graph {
public:
    matrix<int> edge;
    int vertexNumber;

    void insert(Edge newEdge) const;

    /**
     *
     * @param n vertexNumber
     * @param edges
     * @param length edgeNumber
     */
    Graph(int n, Edge edges[], int length): edge(n, 0){
        this->vertexNumber = n;
        for (int i = 0; i < length; ++i) {
            insert(edges[i]);
        }
    }
};

void Graph::insert(Edge newEdge) const {
    edge.data[newEdge.from][newEdge.to] = newEdge.weight;
    edge.data[newEdge.to][newEdge.from] = newEdge.weight;
}

void DFS(Graph graph, int vertex, vector<int> colors){
    colors[vertex] = 2;

    for (int i = 0; i < graph.vertexNumber; ++i) {
        if(graph.edge.data[vertex][i] != 0 && colors[i] == 1){
            cout<<i<<endl;
            DFS(graph, i, colors);
        }
    }

    colors[vertex] = 3;
}

void doDFS(Graph graph){
    vector<int> colors(graph.vertexNumber);// 0:white 1:grey 2:black
    for (int i = 0; i < graph.vertexNumber; ++i) {
        colors[i] = 0;
    }

    for (int i = 0; i < graph.vertexNumber; ++i) {
        if(colors[i] == 0){
            cout<<i<<endl;
            DFS(graph, i, colors);
        }
    }
}

int main(){
    Edge edges[] = {
            Edge(0, 1, 10),
            Edge(0, 3, 4),
            Edge(0, 4, 12),
            Edge(1, 2, 15),
            Edge(1, 3, 8),
            Edge(1, 4, 5),
            Edge(2, 3, 7),
            Edge(2, 4, 30),
            Edge(3, 4, 6)
    };

    Graph graph(5, edges, 9);

    doDFS(graph);
}