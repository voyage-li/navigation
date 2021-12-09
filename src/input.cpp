#include "input.h"

input::input()
{
    std::cout << "请输入数据文件路径:" << std::endl;
    getline(std::cin, data_info);
    auto loc = data_info.find('.');
    out_info = data_info.substr(0, loc) + "_.txt";
    std::ifstream infile(data_info.c_str(), std::ios::in);
    std::ofstream outfile(out_info.c_str(), std::ios::out | std::ios::binary);
    if (!infile || !outfile)
    {
        return;
    }
    std::unordered_map<int, int> map;
    int num1, num2;

    printf("\033[?25l");
    std::string line;
    while (getline(infile, line))
    {
        std::cout << "\r\t\t\t\t\t\t\r" << line;
        auto linestream = std::istringstream(line);
        line += "\n";
        outfile.write((char *)line.c_str(), sizeof(char) * line.length());
        linestream >> num1 >> num2;
        if (map.find(num1) == map.end())
        {
            map[num1] = 1;
            fre++;
        }
        if (map.find(num2) == map.end())
        {
            map[num2] = 1;
            fre++;
        }
    }
    printf("\033[?25h");
    infile.close();
    outfile.close();
}

std::string input::get_infile()
{
    return out_info;
}

int input::get_fre()
{
    return fre;
}