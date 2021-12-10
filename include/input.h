#pragma once

#include <bits/stdc++.h>
#include "huffman.h"

class input
{
private:
    int fre; //记录总的点数
    int char_size;
    std::string data_info;
    std::string out_info;
    std::string out_info_0;
    std::map<long long int, int> map; //需要压缩的文件中不同字符的数量
    char **HC;                        //小数据量用数组
    HuffmanTree HT;                   // huffman树
    bool compress_input();
    void compress_output();

public:
    input();
    std::string get_infile();
    std::string get_infile_con();
    int get_fre();
};