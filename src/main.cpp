#include "dijkstra.h"
#include "graph.h"
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
    printf("\033[?25l");
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
    printf("\033[?25h");

    while (1)
    {
        std::cout << "\n请输入起点终点:" << std::endl;
        int road_begin, road_to;
        std::cin >> road_begin >> road_to;
        if (road_begin == -1)
            break;
        dijkstra_pri(G, road_begin, road_to);
    }

    infile.close();
    return 0;
}