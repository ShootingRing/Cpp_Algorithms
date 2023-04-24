//
// Created by 沃沃圈 on 2023/4/14.
//

#ifndef ALGORITHM_GRAPH_H
#define ALGORITHM_GRAPH_H
#include "matrix.h"

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

#endif //ALGORITHM_GRAPH_H
