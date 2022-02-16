#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <string>
#include <map>
#include <cstring>
#include <fstream>

//=====================================================================

struct Statistics
{
    std::string lexem = "";
    size_t counter   = 0;

    bool operator<(const Statistics& other) const;
    bool operator>(const Statistics& other) const;
};

//=====================================================================

bool Statistics::operator<(const Statistics& other) const
{
    return counter < other.counter;
}

bool Statistics::operator>(const Statistics& other) const
{
    return counter > other.counter;
}

std::string prepare(const std::string& str)
{
    std::string out_str;

    for(size_t i = 0; i < static_cast<size_t>(str.size()); ++i)
    {
        out_str.push_back(static_cast<char>(std::tolower(str[i])));
    }

    while(!isalpha(out_str.back()))
    {
        out_str.pop_back();
    }

    return out_str;
}

//=====================================================================

int main()
{
    std::ifstream file;
    file.open("../test");

    if(file.is_open())
    {
        std::string lexem;
        std::map<std::string, size_t> lexems;

        while(!file.eof())
        {
            file >> lexem;
            lexem = prepare(lexem);
            lexems[lexem]++;
        }
        
        std::vector<Statistics> str_stat;
        for(const auto& i : lexems)
        {
            Statistics temp = {i.first, i.second};
            str_stat.push_back(temp);
        }

        std::sort(str_stat.begin(), str_stat.end());

        for(const auto& i : str_stat)
        {            
            std::cout << i.lexem << " " << i.counter << std::endl;
        }

        file.close();
    }

    return 0;
}
