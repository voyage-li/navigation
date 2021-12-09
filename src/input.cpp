#include "input.h"

input::input()
{
    char_size = 0;
    std::cout << "请输入数据文件路径:" << std::endl;
    getline(std::cin, data_info);
    auto loc = data_info.find('.');
    out_info_0 = data_info.substr(0, loc) + "_.txt";
    std::ifstream infile(data_info.c_str(), std::ios::in);
    std::ofstream outfile(out_info_0.c_str(), std::ios::out | std::ios::binary);
    if (!infile || !outfile)
    {
        return;
    }
    std::unordered_map<int, int> dis_map;
    int num1, num2;
    std::cout << "二进制处理:" << std::endl;
    printf("\033[?25l");
    std::string line;
    while (getline(infile, line))
    {
        std::cout << "\r\t\t\t\t\t\t\r" << line;
        auto linestream = std::istringstream(line);
        line += "\n";
        outfile.write((char *)line.c_str(), sizeof(char) * line.length());
        linestream >> num1 >> num2;
        if (dis_map.find(num1) == dis_map.end())
        {
            dis_map[num1] = 1;
            fre++;
        }
        if (dis_map.find(num2) == dis_map.end())
        {
            dis_map[num2] = 1;
            fre++;
        }
    }
    printf("\033[?25h");
    infile.close();
    outfile.close();

    out_info = data_info.substr(0, loc) + "_con.txt";
    std::cout << "\n压缩处理:" << std::endl;
    compress_input();
    compress_output();
}

std::string input::get_infile()
{
    return out_info_0;
}

std::string input::get_infile_con()
{
    return out_info;
}

int input::get_fre()
{
    return fre;
}

bool input::compress_input()
{
    std::cout << "正在压缩..." << std::endl;
    std::ifstream infile(data_info.c_str(), std::ios::in | std::ios::binary);
    if (!infile)
    {
        std::cout << "文件打开错误!" << std::endl;
        getchar();
        return false;
    }

    char c;
    int every = 8;            //单位 bit
    long long int tt_key = 0; //用来记录 key
    int now_bit = 0;          //用来记录当前读入了多少个bit
    int char_now = 0;         //用来记录当前读取的字符使用到的 bit
    std::unordered_map<long long int, int> temp_map;
    while (infile.get(c))
    {
        char_size++;
        char_now = 0;
        while (char_now < 8)
        {
            while (char_now < 8)
            {
                tt_key += (long long int)(((int)c >> (7 - char_now)) & 1) << (every - 1 - now_bit);
                char_now++;
                now_bit++;
                if (now_bit == every)
                    break;
            }
            if (now_bit == every)
            {
                if (temp_map.count(tt_key) == 0)
                {
                    map[tt_key] = 1;
                    temp_map[tt_key] = 1;
                }
                else
                    map[tt_key]++;
                now_bit = 0;
                tt_key = 0;
            }
        }
    }
    if (now_bit != 0)
    {
        if (temp_map.count(tt_key) == 0)
            map[tt_key] = 1;
        else
            map[tt_key]++;
    }

    infile.close();

    HC = new char *[(long long)pow(2, every)];
    init(HT, map, HC, 2); //生成 Huffman 树以及 Huffman 编码

    return true;
}

void input::compress_output()
{
    std::ifstream infile(data_info.c_str(), std::ios::in | std::ios::binary);

    std::ofstream outfile(out_info.c_str(), std::ios::out | std::ios::binary);
    if (!outfile)
    {
        std::cout << "文件打开错误!" << std::endl;
        return;
    }
    //输出文件格式 huffman树元数压缩的单位以及总字符
    std::string type = "txt";
    outfile << type << ' ';
    outfile << 2 << '|';
    outfile << char_size << '|';
    outfile.put(2 + '0');
    outfile.put('|');

    int out_for_map = 0;
    int now_bit_for_map = 1;
    long long int fre = map.size();
    for (int i = 1; i <= fre; i++)
    {
        out_for_map = 0;
        now_bit_for_map = 1;
        //换一种方式输出key
        for (int j = 0; j < 8; j++)
        {
            out_for_map += ((HT[i].key >> (8 - j - 1)) & 1) << (8 - now_bit_for_map);
            now_bit_for_map++;
            if (now_bit_for_map == 9)
            {
                outfile.put(out_for_map);
                out_for_map = 0;
                now_bit_for_map = 1;
            }
        }
        if (2 % 2 == 1)
            outfile.put(out_for_map);

        outfile << '|' << HT[i].weight;
        if (i != fre)
            outfile.put('|');
    }

    outfile.put('-');

    int num = 0;
    int i = 0;
    int tt = 0;

    //主要输出部分
    char c;
    int every = 8;    //单位 bit
    int tt_key = 0;   //用来记录 key
    int now_bit = 0;  //用来记录当前读入了多少个bit
    int char_now = 0; //用来记录当前读取的字符使用到的 bit
    int now_byte = 0;
    while (infile.get(c))
    {
        now_byte++;
        char_now = 0;
        while (char_now < 8)
        {
            while (char_now < 8)
            {
                tt_key += (((int)c >> (7 - char_now)) & 1) << (every - 1 - now_bit);
                char_now++;
                now_bit++;
                if (now_bit == every)
                    break;
            }
            if (now_bit == every)
            {
                i = 0;
                while (HC[tt_key][i] != '\0')
                {
                    tt += (HC[tt_key][i] - '0') << (7 - num);
                    i++;
                    num++;
                    if (num == 8)
                    {
                        outfile.put((char)tt);
                        num = 0;
                        tt = 0;
                    }
                }
                now_bit = 0;
                tt_key = 0;
            }
        }
    }
    //输出最后一个可能没有到达一个单位的字符
    if (now_bit != every && now_bit != 0)
    {
        i = 0;
        while (HC[tt_key][i] != '\0')
        {
            tt += (HC[tt_key][i] - '0') << (7 - num);
            i++;
            num++;
            if (num == 8)
            {
                outfile.put((char)tt);
                num = 0;
                tt = 0;
            }
        }
    }

    infile.close();
    outfile.close();
}