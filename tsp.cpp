#include <iostream>
#include <cstring>
#include "graph.h"

using namespace std;

/**
 * @brief
 *
 * @param graph
 * @param start
 * @param p
 * @param num
 * @return
 */
int tsp(Graph graph, int start, bool* p, int num){
    if(num == 1) return graph.edge.data[start][0];

    int ans = INT_MAX;

    for (int i = 1; i < graph.vertexNumber; ++i) {
        if(i != start && !p[i]){
            p[i] = true;
            ans = min(ans, tsp(graph, i, p, num-1) + graph.edge.data[start][i]);
        }
    }

    return ans;
}

int doTsp(Graph graph, int start){
    bool p[graph.vertexNumber];
    memset(p, 0, sizeof(p));

    int num = graph.vertexNumber;

    return tsp(graph, start, p, num);
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

    cout<<doTsp(graph, 0)<<endl;
}