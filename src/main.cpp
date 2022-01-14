#include "dijkstra.h"

int main()
{
    int for_system;
    for_system = system("clear");
    printf("\033[0;30;47m请输入文件路径\033[0m\n");
    std::string data_path;
    getline(std::cin, data_path);

    printf("\033[0;30;47m选择文件预处理的方式\033[0m\n");
    std::cout << "\e[1m1.\e[0m 二进制" << std::endl;
    std::cout << "\e[1m2.\e[0m 压缩" << std::endl;
    char for_input_select;
    std::cin >> for_input_select;

    AGraph G;
    std::ifstream infile(data_path.c_str(), std::ios::in | std::ios::binary);

    clock_t begin, end;
    begin = clock();

    if (for_input_select == '1')
    {
        int num1, num2, info;
        printf("\033[?25l");
        while (!infile.eof())
        {
            infile.read((char *)&num1, sizeof(int));
            infile.read((char *)&num2, sizeof(int));
            infile.read((char *)&info, sizeof(int));

            G.input(num1, num2, info);
        }
        printf("\033[?25h");
    }
    else if (for_input_select == '2')
    {
        int tag;
        int num1, num2, info;
        printf("\033[?25l");
        while (!infile.eof())
        {
            tag = 0;
            infile.read((char *)&num1, sizeof(int));
            infile.read((char *)&num2, sizeof(int));
            while (num2 != -1)
            {
                infile.read((char *)&info, sizeof(int));
                if (tag == 0)
                {
                    G.input(num1, num2, info);
                    tag = 1;
                }
                else
                    G.input_(num1, num2, info);
                infile.read((char *)&num2, sizeof(int));
            }
        }
        printf("\033[?25h");
    }

    end = clock();

    std::cout << "\n\033[0;30;47m输入用时:\033[0m" << std::endl;
    std::cout << double(end - begin) / CLOCKS_PER_SEC << "s" << std::endl;

    getchar();
    getchar();

    infile.close();

    while (1)
    {
        for_system = system("clear");
        printf("\r                                                                    ");
        printf("\r\033[0;30;47m请输入起点终点:\033[0m\n");
        int road_begin, road_to;
        std::cin >> road_begin >> road_to;
        if (road_begin == -1)
            break;
        double time_record[8];
        memset(time_record, 0, sizeof(time_record));
        for_system = system("clear");
        while (1)
        {
            for_system = system("clear");
            printf("\033[0;30;47m搜索路径:\033[0m\n");
            std::cout << road_begin << " -> " << road_to << std::endl;

            if (road_begin < 0 || road_to < 0 || !G.data[road_begin] || !G.data[road_to])
            {
                std::cout << "没有数据" << std::endl;
                getchar();
                getchar();
                break;
            }

            printf("\033[0;30;47m请选择搜索方式:\033[0m\n");
            std::cout << "\e[1m0.\e[0m 朴素法(n^2)                " << time_record[0] << "s" << std::endl;
            std::cout << "\e[1m1.\e[0m 堆优化(Heap)               " << time_record[1] << "s" << std::endl;
            std::cout << "\e[1m2.\e[0m 堆优化(pair_heap,递归)     " << time_record[2] << "s" << std::endl;
            std::cout << "\e[1m3.\e[0m 堆优化(pair_heap,队列)     " << time_record[3] << "s" << std::endl;
            std::cout << "\e[1m4.\e[0m 堆优化(Fibonacii)          " << time_record[4] << "s" << std::endl;
            std::cout << "\e[1m5.\e[0m 堆优化(priority_que)       " << time_record[5] << "s" << std::endl;
            std::cout << "\e[1m6.\e[0m 堆优化(pairing_heap_tag)   " << time_record[6] << "s" << std::endl;
            std::cout << "\e[1m7.\e[0m 堆优化(thin_heap_tag)      " << time_record[7] << "s" << std::endl;
            std::cout << "\e[1m8.\e[0m 下一组数据" << std::endl;
            std::cout << "\e[1m9.\e[0m 退出程序" << std::endl;
            int select;
            std::cin >> select;
            clock_t startTime, endTime;
            startTime = clock();
            if (select == 1)
                endTime = dijkstra_heap(G, road_begin, road_to);
            else if (select == 0)
                endTime = dijkstra(G, road_begin, road_to);
            else if (select == 2)
                endTime = dijkstra_pair_heap(G, road_begin, road_to);
            else if (select == 3)
                endTime = dijkstra_pair_heap_0(G, road_begin, road_to);
            else if (select == 4)
                endTime = dijkstra_fibheap(G, road_begin, road_to);
            else if (select == 5)
                endTime = dijkstra_heap_gnu(G, road_begin, road_to);
            else if (select == 6)
                endTime = dijkstra_pair_heap_gnu(G, road_begin, road_to);
            else if (select == 7)
                endTime = dijkstra_thin_heap_gnu(G, road_begin, road_to);
            else if (select == 8)
                break;
            else if (select == 9)
            {
                return 0;
            }
            else
            {
                std::cout << "选择错误! 使用Heap" << std::endl;
                endTime = dijkstra_heap(G, road_begin, road_to);
                select = 1;
            }

            time_record[select] = double(endTime - startTime) / CLOCKS_PER_SEC;
            std::cout << "\nrun time: " << time_record[select] << "s" << std::endl;
            getchar();
            getchar();
        }
    }

    return 0;
}
