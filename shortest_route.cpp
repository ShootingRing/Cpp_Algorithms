#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "vertex number:" << endl;
    int vexnum;
    cin >> vexnum;
    vector<int> cost(vexnum, 0);			//cost[i]表示从顶点i到终点n-1的最短路径长度
    vector<int> path(vexnum, 0);			//path[i]表示从顶点i到终点n-1的路径上顶点i的下一个顶点

    cout << "edge number:" << endl;
    int edgenum;
    cin >> edgenum;

    vector<vector<int>> edge(vexnum, vector<int>(vexnum, 0));			//edge[i][j]存储多段图中的边

    cout << "start end and weight:" << endl;
    int start;
    int end;
    int length;
    for (int i = 0; i < edgenum; ++i)
    {
        cin >> start >> end >> length;
        edge[start][end] = length;
    }

    for (int i = vexnum-2; i >= 0; --i)
    {
        cost[i] = INT_MAX;
        for (int j = i; j < vexnum; ++j)
        {
            if (edge[i][j] != 0)
            {
                //等于零表示之间没有路
                if (edge[i][j] + cost[j] < cost[i])
                {
                    //此时找到一条更短的路
                    path[i] = j;						//更新path[i]
                    cost[i] = edge[i][j] + cost[j];		//更新从该节点出发的最短路径
                }
            }
        }
    }
    cout << "shortest length:" << cost[0] << endl;
    cout << "route:" << endl;
    int i = 0;
    cout << "0 ---> ";
    while (1)
    {
        cout << path[i];
        i = path[i];
        if (i == vexnum-1)
        {
            break;
        }
        cout << " ---> ";
    }
    cout << endl;

    return 0;
}