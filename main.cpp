#include "dijkstra.h"
#include "graph.h"
#include "input.h"

int main()
{
    input for_input;
    std::string data_path = for_input.get_infile();
    AGraph G(for_input.get_fre());
    std::ifstream infile(data_path.c_str(), std::ios::in | std::ios::binary);
    char c;
    int num1, num2, info;
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
        // std::cout << num1 << num2 << info << std::endl;
        G.input(num1, num2, info);
    }
    infile.close();
    return 0;
}