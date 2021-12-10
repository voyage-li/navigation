#include "dijkstra.h"
#include "input.h"

int main()
{
    system("clear");
    input for_input;
    std::string data_path = for_input.get_infile();
    AGraph G(for_input.get_fre());
    std::ifstream infile(data_path.c_str(), std::ios::in | std::ios::binary);

    char c;
    int num1, num2, info;
    printf("\033[0;30;47m读取处理后文件...\033[0m\n");
    int select_insert;
    std::cout << "请选择使用文件:" << std::endl;
    std::cout << "1. 普通二进制" << std::endl;
    std::cout << "2. huffman压缩后" << std::endl;
    std::cin >> select_insert;

    printf("\033[?25l");
    if (select_insert == 1)
    {
        while (infile.read((char *)&c, sizeof(char)))
        {
            std::string line;
            line.push_back(c);
            while (infile.read((char *)&c, sizeof(char)))
            {
                if (c == '\n')
                    break;
                line.push_back(c);
            }
            auto line_stream = std::istringstream(line);
            line_stream >> num1 >> num2 >> info;
            G.input(num1, num2, info);
            G.input(num2, num1, info);
        }
    }
    else
    {
        std::string out_info = for_input.get_infile_con();
        std::ifstream infile(out_info.c_str(), std::ios::in | std::ios::binary);

        std::map<long long int, int> map; //需要压缩的文件中不同字符的数量
        HuffmanTree HT;                   // huffman树

        if (!infile)
        {
            std::cout << "文件打开错误!" << std::endl;
            getchar();
            return false;
        }

        std::cout << "正在读入图的相关数据..." << std::endl;

        char tmp;
        int num;
        long long int fff;
        int char_size;

        std::string type;
        int tree_n;
        int select;
        infile >> type;             //获取解压文件格式
        infile >> tree_n >> tmp;    //获取 Huffman树元数
        infile >> char_size >> tmp; //获取压缩基本符号单元
        infile >> select >> tmp;    //获取压缩基本符号单元
        int every = select * 4;

        while (1)
        {
            fff = 0;
            char c;
            int now_get_bit = 0;
            for (int i = 0; i < (select + 1) / 2; i++)
            {
                infile.get(c);
                for (int j = 0; j < 8; j++)
                {
                    fff += (long long int)(((int)c >> (7 - j)) & 1) << (every - 1 - now_get_bit);
                    now_get_bit++;
                }
            }
            infile >> tmp >> num;
            map[fff] = num;
            infile.get(tmp);

            if (tmp != '|')
                break;
        }

        init_for_de(HT, map, tree_n);

        char ans[8];
        char c;
        int index = 0;
        int fre = map.size();
        int root_loc;
        int now;
        int now_bit = 0; //记录当前输出字符到的bit
        int out_tmp = 0; //用来记录输出的字符
        int wei = judge(tree_n);
        int wei_now = 0;
        int switch_child = 0;

        for (root_loc = 1; root_loc < 2 * fre; root_loc++)
        {
            if (HT[root_loc].parent == 0)
                break;
        }

        now = root_loc;
        std::string line;
        while (1)
        {
            infile.get(c);
            int tt = c;
            index = 0;
            for (int i = 7; i >= 0; i--)
                ans[index++] = ((tt >> i) & 1) + '0';
            index = 0;
            while (1)
            {
                switch_child += (ans[index] - '0') << (wei - 1 - wei_now);
                wei_now++;
                if (wei == wei_now)
                {
                    wei_now = 0;
                    now = HT[now].child[switch_child];
                    switch_child = 0;
                }
                index++;

                if (HT[now].child[0] == 0)
                {
                    //获取对应权值对应的 bit位
                    int int_to_char = HT[now].key;
                    char ans_[every + 1];
                    ans_[every] = '\0';
                    for (int j = 0; j < every; j++)
                        ans_[j] = ((int_to_char >> (every - 1 - j)) & 1) + '0';

                    int j = 0;
                    while (ans_[j] != '\0')
                    {
                        now_bit++;
                        out_tmp += (ans_[j] - '0') << (8 - now_bit);
                        if (now_bit == 8)
                        {
                            char_size--;
                            if (out_tmp != '\n')
                                line.push_back(out_tmp);
                            else
                            {
                                auto line_stream = std::istringstream(line);
                                line_stream >> num1 >> num2 >> info;
                                G.input(num1, num2, info);
                                G.input(num2, num1, info);
                                line.clear();
                            }
                            out_tmp = 0;
                            now_bit = 0;
                        }
                        j++;
                        if (char_size == 0)
                            break;
                    }
                    now = root_loc;
                }
                if (index == 8 || char_size == 0)
                    break;
            }
            if (char_size == 0)
                break;
        }

        infile.close();
    }
    printf("\033[?25h");

    while (1)
    {
        system("clear");
        system("clear");
        printf("\r\033[0;30;47m请输入起点终点:\033[0m\n");
        int road_begin, road_to;
        std::cin >> road_begin >> road_to;
        if (road_begin == -1)
            break;
        std::cout << "请选择搜索方式:" << std::endl;
        std::cout << "1. 朴素算法" << std::endl;
        std::cout << "2. 堆优化" << std::endl;
        int select;
        std::cin >> select;
        if (select == 2)
            dijkstra_pri(G, road_begin, road_to);
        else if (select == 1)
            dijkstra(G, road_begin, road_to);
        else
        {
            std::cout << "选择错误! 默认使用堆优化" << std::endl;
            dijkstra_pri(G, road_begin, road_to);
        }
        getchar();
        getchar();
    }

    infile.close();
    return 0;
}
