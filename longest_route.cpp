#include <iostream>
#include "graph.h"

using namespace std;

int longest_route(Graph g, int endVertex){
    int res = 0;
    int point = 0;
    for (int i = 0; i < g.vertexNumber; ++i) {
        if(g.edge.data[i][endVertex] != 0){
            int temp = g.edge.data[i][endVertex] + longest_route(g, i);
            if(res < temp){
                point = i;
                res = temp;
            }
        }
    }
    cout<<point<<endl;
    return res;
}

//5->2->0->1->4
//5->2->0->1->3->4

int main(){
    /*
     *   A B C D E S
     * A   6
     * B       1 2
     * C 4     3
     * D         1
     * E
     * S 1   2
     */

    Edge edges[8] = {
      Edge(0, 1, 6),
      Edge(1, 4, 2),
      Edge(1, 3, 1),
      Edge(3, 4, 1),
      Edge(2, 0, 4),
      Edge(2, 3, 3),
      Edge(5, 0, 1),
      Edge(5, 2, 2)
    };

    Graph g(6, edges, 8);

    //show g.edge.data
    for (int i = 0; i < g.vertexNumber; ++i) {
        for (int j = 0; j < g.vertexNumber; ++j) {
            cout<<g.edge.data[i][j]<<" ";
        }
        cout<<endl;
    }

    int len = longest_route(g, 4);

    cout<<endl<<len<<endl;
}