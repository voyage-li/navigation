#include "dijkstra.h"

void dijkstra_n2(AGraph &G, int x, int y)
{
    int visited[G.get_vex()];
    memset(visited, 0, sizeof(visited));
    int dis[G.get_vex()];
    memset(dis, 0xe, sizeof(dis));
    int pre[G.get_vex()];
    memset(pre, -1, sizeof(pre));

    std::priority_queue<node> q;
    dis[G.map[x]] = 0;
    q.push(node(G.map[x], dis[G.map[x]]));

    while (!q.empty())
    {
        struct node now = q.top();
        q.pop();
        if (visited[now.begin] == 1)
            continue;
        visited[now.begin] = 1;
        if (now.begin == G.map[y])
            break;
        struct ArcNode *p = G.data[now.begin]->firstarc;
        while (p != nullptr)
        {
            if (visited[p->adjvex] == 1)
            {
            }
            else if (dis[p->adjvex] > dis[now.begin] + p->weight)
            {
                dis[p->adjvex] = dis[now.begin] + p->weight;
                q.push(node(p->adjvex, dis[p->adjvex]));
                pre[p->adjvex] = now.begin;
            }
            p = p->nextarc;
        }
    }
    std::cout << "Output:\n"
              << dis[G.map[y]] << "\n\n";
    int road = G.map[y];
    while (road != -1)
    {
        std::cout << G.data[road]->vex_data;
        road = pre[road];
        if (road != -1)
            std::cout << " <- ";
        else
            std::cout << "\n";
    }
}

void dijkstra_nlogn(AGraph &G, int x, int y)
{
}