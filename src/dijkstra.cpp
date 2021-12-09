#include "dijkstra.h"
#include "Heap.cpp" //模板不支持分离编译

void dijkstra_pri(AGraph &G, int x, int y)
{
    int visited[G.get_vex()];
    memset(visited, 0, sizeof(visited));
    int dis[G.get_vex()];
    memset(dis, 127, sizeof(dis));
    int pre[G.get_vex()];
    memset(pre, -1, sizeof(pre));

    Heap<struct node> q;
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
    std::cout << "\nOutput:\n"
              << dis[G.map[y]] << "\n\n";
    int road = G.map[y];
    while (road != -1)
    {
        printf("\033[0;30;47m%d\033[0m ", G.data[road]->vex_data);
        road = pre[road];
        if (road != -1)
            std::cout << "<- ";
        else
            printf("\n");
    }
}

int find_min(int dis[], int len, int vis[])
{
    int min = INT_MAX;
    int loc = -1;
    for (int i = 0; i < len; i++)
    {
        if (vis[i] == 1)
            continue;
        else if (min > dis[i])
        {
            min = dis[i];
            loc = i;
        }
    }
    return loc;
}

void dijkstra(AGraph &G, int x, int y)
{
    int len = G.get_vex();
    int visited[len];
    memset(visited, 0, sizeof(visited));
    int dis[len];
    memset(dis, 127, sizeof(dis));
    int pre[len];
    memset(pre, -1, sizeof(pre));

    dis[G.map[x]] = 0;

    int vex = len;
    while (vex > 0)
    {
        int now = find_min(dis, len, visited);
        if (now != -1)
        {
            visited[now] = 1;
            vex--;
        }
        else
            break;
        struct ArcNode *p = G.data[now]->firstarc;
        while (p != nullptr)
        {
            if (dis[p->adjvex] > dis[now] + p->weight)
            {
                dis[p->adjvex] = dis[now] + p->weight;
                pre[p->adjvex] = now;
            }
            p = p->nextarc;
        }
        if (visited[G.map[y]] == 1)
            break;
    }

    std::cout << "\nOutput:\n"
              << dis[G.map[y]] << "\n\n";
    int road = G.map[y];
    while (road != -1)
    {
        printf("\033[0;30;47m%d\033[0m", G.data[road]->vex_data);
        road = pre[road];
        if (road != -1)
            std::cout << " <- ";
        else
            printf("\n");
    }
}