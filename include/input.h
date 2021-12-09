#pragma once

#include <bits/stdc++.h>

class input
{
private:
    int fre; //记录总的点数
    std::string data_info;
    std::string out_info;

public:
    input();
    std::string get_infile();
    int get_fre();
};