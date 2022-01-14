#include "dijkstra.h"
#include "Heap.cpp"      //模板不支持分离编译
#include "pair_heap.cpp" //模板不支持分离编译
#include "fibheap.cpp"   //模板不支持分离编译
#include <ext/pb_ds/priority_queue.hpp>

clock_t dijkstra_pair_heap_0(AGraph &G, int x, int y)
{
    int *visited = new int[100000000];
    memset(visited, 0, sizeof(int) * 100000000);
    int *dis = new int[100000000];
    memset(dis, 127, sizeof(int) * 100000000);
    int *pre = new int[100000000];
    memset(pre, -1, sizeof(int) * 100000000);

    pair_heap<struct node> q;
    dis[x] = 0;
    q.push(node(x, dis[x]));

    while (!q.empty())
    {
        struct node now = q.top();
        q.pop();
        if (visited[now.begin] == 1)
            continue;
        visited[now.begin] = 1;
        if (now.begin == y)
            break;
        struct ArcNode *p = G.data[now.begin]->firstarc;
        while (p != nullptr)
        {
            if (visited[p->adjvex] != 1 && dis[p->adjvex] > dis[now.begin] + p->weight)
            {
                dis[p->adjvex] = dis[now.begin] + p->weight;
                q.push(node(p->adjvex, dis[p->adjvex]));
                pre[p->adjvex] = now.begin;
            }
            p = p->nextarc;
        }
    }

    clock_t endtime = clock();

    if (visited[y] != 1)
    {
        std::cout << "不能到达!" << std::endl;
        delete[] visited;
        delete[] dis;
        delete[] pre;
        return endtime;
    }

    int road = y;
    while (road != -1)
    {
        printf("\033[0;30;47m%d\033[0m ", road);
        road = pre[road];
        if (road != -1)
            std::cout << "<- ";
        else
            printf("\n");
    }
    std::cout << "\nOutput:\n"
              << dis[y] << std::endl;
    delete[] visited;
    delete[] dis;
    delete[] pre;
    return endtime;
}

clock_t dijkstra_pair_heap(AGraph &G, int x, int y)
{

    int *visited = new int[100000000];
    memset(visited, 0, sizeof(int) * 100000000);
    int *dis = new int[100000000];
    memset(dis, 127, sizeof(int) * 100000000);
    int *pre = new int[100000000];
    memset(pre, -1, sizeof(int) * 100000000);

    pair_heap<struct node> q;
    dis[x] = 0;
    q.push(node(x, dis[x]));

    while (!q.empty())
    {
        struct node now = q.top();
        q._pop();
        if (visited[now.begin] == 1)
            continue;
        visited[now.begin] = 1;
        if (now.begin == y)
            break;
        struct ArcNode *p = G.data[now.begin]->firstarc;
        while (p != nullptr)
        {
            if (visited[p->adjvex] != 1 && dis[p->adjvex] > dis[now.begin] + p->weight)
            {
                dis[p->adjvex] = dis[now.begin] + p->weight;
                q.push(node(p->adjvex, dis[p->adjvex]));
                pre[p->adjvex] = now.begin;
            }
            p = p->nextarc;
        }
    }

    clock_t endtime = clock();

    if (visited[y] != 1)
    {
        std::cout << "不能到达!" << std::endl;

        delete[] visited;
        delete[] dis;
        delete[] pre;
        return endtime;
    }

    int road = y;
    while (road != -1)
    {
        printf("\033[0;30;47m%d\033[0m ", road);
        road = pre[road];
        if (road != -1)
            std::cout << "<- ";
        else
            printf("\n");
    }
    std::cout << "\nOutput:\n"
              << dis[y] << std::endl;
    delete[] visited;
    delete[] dis;
    delete[] pre;
    return endtime;
}

clock_t dijkstra_heap(AGraph &G, int x, int y)
{
    int *visited = new int[100000000];
    memset(visited, 0, sizeof(int) * 100000000);
    int *dis = new int[100000000];
    memset(dis, 127, sizeof(int) * 100000000);
    int *pre = new int[100000000];
    memset(pre, -1, sizeof(int) * 100000000);

    Heap<struct node> q;
    dis[x] = 0;
    q.push(node(x, dis[x]));

    while (!q.empty())
    {
        struct node now = q.top();
        q.pop();
        if (visited[now.begin] == 1)
            continue;
        visited[now.begin] = 1;
        if (now.begin == y)
            break;
        struct ArcNode *p = G.data[now.begin]->firstarc;
        while (p != nullptr)
        {
            if (visited[p->adjvex] != 1 && dis[p->adjvex] > dis[now.begin] + p->weight)
            {
                dis[p->adjvex] = dis[now.begin] + p->weight;
                q.push(node(p->adjvex, dis[p->adjvex]));
                pre[p->adjvex] = now.begin;
            }
            p = p->nextarc;
        }
    }

    clock_t endtime = clock();

    if (visited[y] != 1)
    {
        std::cout << "不能到达!" << std::endl;
        delete[] visited;
        delete[] dis;
        delete[] pre;

        return endtime;
    }

    int road = y;
    while (road != -1)
    {
        printf("\033[0;30;47m%d\033[0m ", road);
        road = pre[road];
        if (road != -1)
            std::cout << "<- ";
        else
            printf("\n");
    }
    std::cout << "\nOutput:\n"
              << dis[y] << std::endl;

    delete[] visited;
    delete[] dis;
    delete[] pre;

    return endtime;
}

clock_t dijkstra_pair_heap_gnu(AGraph &G, int x, int y)
{
    int *visited = new int[100000000];
    memset(visited, 0, sizeof(int) * 100000000);
    int *dis = new int[100000000];
    memset(dis, 127, sizeof(int) * 100000000);
    int *pre = new int[100000000];
    memset(pre, -1, sizeof(int) * 100000000);

    __gnu_pbds::priority_queue<struct node, cmp, __gnu_pbds::pairing_heap_tag> q;
    dis[x] = 0;
    q.push(node(x, dis[x]));

    while (!q.empty())
    {
        struct node now = q.top();
        q.pop();
        if (visited[now.begin] == 1)
            continue;
        visited[now.begin] = 1;
        if (now.begin == y)
            break;
        struct ArcNode *p = G.data[now.begin]->firstarc;
        while (p != nullptr)
        {
            if (visited[p->adjvex] != 1 && dis[p->adjvex] > dis[now.begin] + p->weight)
            {
                dis[p->adjvex] = dis[now.begin] + p->weight;
                q.push(node(p->adjvex, dis[p->adjvex]));
                pre[p->adjvex] = now.begin;
            }
            p = p->nextarc;
        }
    }

    clock_t endtime = clock();

    if (visited[y] != 1)
    {
        std::cout << "不能到达!" << std::endl;
        delete[] visited;
        delete[] dis;
        delete[] pre;
        return endtime;
    }

    int road = y;
    while (road != -1)
    {
        printf("\033[0;30;47m%d\033[0m ", road);
        road = pre[road];
        if (road != -1)
            std::cout << "<- ";
        else
            printf("\n");
    }
    std::cout << "\nOutput:\n"
              << dis[y] << std::endl;

    delete[] visited;
    delete[] dis;
    delete[] pre;
    return endtime;
}

clock_t dijkstra_heap_gnu(AGraph &G, int x, int y)
{
    int *visited = new int[100000000];
    memset(visited, 0, sizeof(int) * 100000000);
    int *dis = new int[100000000];
    memset(dis, 127, sizeof(int) * 100000000);
    int *pre = new int[100000000];
    memset(pre, -1, sizeof(int) * 100000000);

    __gnu_pbds::priority_queue<struct node> q;
    dis[x] = 0;
    q.push(node(x, dis[x]));

    while (!q.empty())
    {
        struct node now = q.top();
        q.pop();
        if (visited[now.begin] == 1)
            continue;
        visited[now.begin] = 1;
        if (now.begin == y)
            break;
        struct ArcNode *p = G.data[now.begin]->firstarc;
        while (p != nullptr)
        {
            if (visited[p->adjvex] != 1 && dis[p->adjvex] > dis[now.begin] + p->weight)
            {
                dis[p->adjvex] = dis[now.begin] + p->weight;
                q.push(node(p->adjvex, dis[p->adjvex]));
                pre[p->adjvex] = now.begin;
            }
            p = p->nextarc;
        }
    }

    clock_t endtime = clock();

    if (visited[y] != 1)
    {
        std::cout << "不能到达!" << std::endl;
        delete[] visited;
        delete[] dis;
        delete[] pre;
        return endtime;
    }

    int road = y;
    while (road != -1)
    {
        printf("\033[0;30;47m%d\033[0m ", road);
        road = pre[road];
        if (road != -1)
            std::cout << "<- ";
        else
            printf("\n");
    }
    std::cout << "\nOutput:\n"
              << dis[y] << std::endl;
    delete[] visited;
    delete[] dis;
    delete[] pre;
    return endtime;
}

clock_t dijkstra_thin_heap_gnu(AGraph &G, int x, int y)
{
    int *visited = new int[100000000];
    memset(visited, 0, sizeof(int) * 100000000);
    int *dis = new int[100000000];
    memset(dis, 127, sizeof(int) * 100000000);
    int *pre = new int[100000000];
    memset(pre, -1, sizeof(int) * 100000000);

    __gnu_pbds::priority_queue<struct node, cmp, __gnu_pbds::thin_heap_tag> q;
    dis[x] = 0;
    q.push(node(x, dis[x]));

    while (!q.empty())
    {
        struct node now = q.top();
        q.pop();
        if (visited[now.begin] == 1)
            continue;
        visited[now.begin] = 1;
        if (now.begin == y)
            break;
        struct ArcNode *p = G.data[now.begin]->firstarc;
        while (p != nullptr)
        {
            if (visited[p->adjvex] != 1 && dis[p->adjvex] > dis[now.begin] + p->weight)
            {
                dis[p->adjvex] = dis[now.begin] + p->weight;
                q.push(node(p->adjvex, dis[p->adjvex]));
                pre[p->adjvex] = now.begin;
            }
            p = p->nextarc;
        }
    }

    clock_t endtime = clock();

    if (visited[y] != 1)
    {
        std::cout << "不能到达!" << std::endl;
        delete[] visited;
        delete[] dis;
        delete[] pre;
        return endtime;
    }

    int road = y;
    while (road != -1)
    {
        printf("\033[0;30;47m%d\033[0m ", road);
        road = pre[road];
        if (road != -1)
            std::cout << "<- ";
        else
            printf("\n");
    }
    std::cout << "\nOutput:\n"
              << dis[y] << std::endl;
    delete[] visited;
    delete[] dis;
    delete[] pre;
    return endtime;
}

int find_min(std::unordered_map<int, int> &dis_map, int vis[])
{
    int min = INT_MAX;
    int loc = -1;
    for (auto iter : dis_map)
    {
        if (vis[iter.first] == 1)
            continue;
        if (min > dis_map[iter.first])
        {
            min = dis_map[iter.first];
            loc = iter.first;
        }
    }
    return loc;
}

clock_t dijkstra(AGraph &G, int x, int y)
{
    int *visited = new int[100000000];
    memset(visited, 0, sizeof(int) * 100000000);
    int *dis = new int[100000000];
    memset(dis, 127, sizeof(int) * 100000000);
    int *pre = new int[100000000];
    memset(pre, -1, sizeof(int) * 100000000);

    std::unordered_map<int, int> map_dis;

    map_dis[x] = 0;
    dis[x] = 0;

    int vex = G.get_vex();
    while (vex > 0)
    {
        int now = find_min(map_dis, visited);
        if (now != -1)
        {
            visited[now] = 1;
            vex--;
        }
        else
            break;
        if (visited[y] == 1)
            break;
        struct ArcNode *p = G.data[now]->firstarc;
        while (p != nullptr)
        {
            if (dis[p->adjvex] > dis[now] + p->weight)
            {
                dis[p->adjvex] = dis[now] + p->weight;
                pre[p->adjvex] = now;
                map_dis[p->adjvex] = dis[p->adjvex];
            }
            p = p->nextarc;
        }
    }

    clock_t endtime = clock();

    if (visited[y] != 1)
    {
        std::cout << "不能到达!" << std::endl;
        delete[] visited;
        delete[] dis;
        delete[] pre;
        return endtime;
    }

    int road = y;
    while (road != -1)
    {
        printf("\033[0;30;47m%d\033[0m ", road);
        road = pre[road];
        if (road != -1)
            std::cout << "<- ";
        else
            printf("\n");
    }
    std::cout << "\nOutput:\n"
              << dis[y] << std::endl;
    delete[] visited;
    delete[] dis;
    delete[] pre;
    return endtime;
}

clock_t dijkstra_fibheap(AGraph &G, int x, int y)
{
    int *visited = new int[100000000];
    memset(visited, 0, sizeof(int) * 100000000);
    int *dis = new int[100000000];
    memset(dis, 127, sizeof(int) * 100000000);
    int *pre = new int[100000000];
    memset(pre, -1, sizeof(int) * 100000000);

    FibHeap<struct node> q;
    dis[x] = 0;
    q.push(node(x, dis[x]));

    while (!q.empty())
    {
        struct node now = q.top();
        q.pop();
        if (visited[now.begin] == 1)
            continue;
        visited[now.begin] = 1;
        if (now.begin == y)
            break;
        struct ArcNode *p = G.data[now.begin]->firstarc;
        while (p != nullptr)
        {
            if (visited[p->adjvex] != 1 && dis[p->adjvex] > dis[now.begin] + p->weight)
            {
                dis[p->adjvex] = dis[now.begin] + p->weight;
                q.push(node(p->adjvex, dis[p->adjvex]));
                pre[p->adjvex] = now.begin;
            }
            p = p->nextarc;
        }
    }

    clock_t endtime = clock();

    if (visited[y] != 1)
    {
        std::cout << "不能到达!" << std::endl;
        delete[] visited;
        delete[] dis;
        delete[] pre;
        return endtime;
    }

    int road = y;
    while (road != -1)
    {
        printf("\033[0;30;47m%d\033[0m ", road);
        road = pre[road];
        if (road != -1)
            std::cout << "<- ";
        else
            printf("\n");
    }
    std::cout << "\nOutput:\n"
              << dis[y] << std::endl;
    delete[] visited;
    delete[] dis;
    delete[] pre;
    return endtime;
}