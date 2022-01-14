#include <bits/stdc++.h>

typedef struct ArcNode
{
    int adjvex;
    int weight;
    struct ArcNode *nextarc;
} ArcNode;
//顶点
struct VNode
{
    int vex_data;
    ArcNode *firstarc;
};

class for_input
{
private:
    int vexnum;
    int now_vex;

public:
    std::vector<VNode *> data;
    std::unordered_map<int, int> map;
    for_input();
    ~for_input();
    bool input(int x, int y, int info); //输入数据
    int get_vex();                      //返回点数
};

for_input::for_input()
{
    now_vex = 0;
    vexnum = 0;
};

for_input::~for_input()
{
}

int for_input::get_vex()
{
    return vexnum;
}

bool for_input::input(int x, int y, int info)
{
    std::cout << "\r" << x << " " << y << " " << info;
    if (map.find(x) == map.end())
    {
        map[x] = now_vex++;
        struct VNode *first_init = new VNode;
        first_init->vex_data = x;
        first_init->firstarc = nullptr;
        data.push_back(first_init);
    }
    if (map.find(y) == map.end())
    {
        map[y] = now_vex++;
        struct VNode *first_init = new VNode;
        first_init->vex_data = y;
        first_init->firstarc = nullptr;
        data.push_back(first_init);
    }
    struct ArcNode *p = new ArcNode;
    p->nextarc = nullptr;
    p->weight = info;
    p->adjvex = map[y];

    struct ArcNode *q = data[map[x]]->firstarc;
    if (q == nullptr)
    {
        data[map[x]]->firstarc = p;
        return true;
    }
    while (q->nextarc != nullptr)
        q = q->nextarc;
    q->nextarc = p;
    vexnum = now_vex;
    return true;
}

class input
{
private:
    std::string data_info;
    std::string out_info;

public:
    input(std::string s);
    void begin_binary();
    void begin_binary_com();
};

input::input(std::string s)
{
    data_info = s;
}

void input::begin_binary()
{
    auto loc = data_info.find('.');
    out_info = data_info.substr(0, loc) + "_pre.txt";
    std::ifstream infile(data_info.c_str(), std::ios::in);
    std::ofstream outfile(out_info.c_str(), std::ios::out | std::ios::binary);
    if (!infile || !outfile)
    {
        return;
    }
    int num1, num2, info;

    printf("\033[?25l");
    std::string line;
    while (getline(infile, line))
    {
        std::cout << "\r" << line;
        auto linestream = std::istringstream(line);
        linestream >> num1 >> num2 >> info;
        outfile.write((char *)&num1, sizeof(int));
        outfile.write((char *)&num2, sizeof(int));
        outfile.write((char *)&info, sizeof(int));
    }
    printf("\033[?25h");
    infile.close();
    outfile.close();
}

void input::begin_binary_com()
{
    auto loc = data_info.find('.');
    out_info = data_info.substr(0, loc) + "_pre_com.txt";
    std::ifstream infile(data_info.c_str(), std::ios::in);
    std::ofstream outfile(out_info.c_str(), std::ios::out | std::ios::binary);
    if (!infile || !outfile)
    {
        return;
    }
    int num1, num2, info;
    for_input G;
    printf("\033[?25l");
    std::string line;
    while (getline(infile, line))
    {
        auto linestream = std::istringstream(line);
        linestream >> num1 >> num2 >> info;
        G.input(num1, num2, info);
    }
    int fre = G.get_vex();
    int tag = -1;
    putchar('\n');
    for (int i = 0; i < fre; i++)
    {
        struct ArcNode *p = G.data[i]->firstarc;
        outfile.write((char *)&G.data[i]->vex_data, sizeof(int));
        while (p != nullptr)
        {
            std::cout << "\r" << G.data[i]->vex_data << " " << G.data[p->adjvex]->vex_data << " " << p->weight;
            outfile.write((char *)&G.data[p->adjvex]->vex_data, sizeof(int));
            outfile.write((char *)&p->weight, sizeof(int));
            p = p->nextarc;
        }
        outfile.write((char *)&tag, sizeof(int));
    }

    printf("\033[?25h");
    infile.close();
    outfile.close();
}

int main()
{
    system("clear");
    printf("\033[0;30;47m需要预处理的文件路径\033[0m\n");
    std::string s;
    getline(std::cin, s);
    std::cout << "1. 二进制" << std::endl;
    std::cout << "2. 压缩" << std::endl;
    int select;
    std::cin >> select;
    input pre(s);
    if (select == 1)
        pre.begin_binary();
    else if (select == 2)
        pre.begin_binary_com();
    else
    {
        std::cout << "选择错误，使用压缩方法进行预处理" << std::endl;
        pre.begin_binary_com();
    }
    std::cout << "\n完成预处理!" << std::endl;
    return 0;
}
