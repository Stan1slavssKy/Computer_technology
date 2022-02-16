#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <string>
#include <unordered_map>
#include <cstring>

//=====================================================================

class Text
{
public:
    Text() = default;
    Text(const Text& other) = delete;
    ~Text() = default;

    void split();
    void input();
    void prepare();
    void parsing();

private:
    std::string input_str_  = "";
    std::string parsed_str_ = "";

    std::vector<std::string> lexems;
};

//=====================================================================

int main()
{
    Text test;
    test.input();
    test.prepare();
}

//=====================================================================

void Text::input()
{
    std::cout << "Please write your message: ";
    std::getline(std::cin, input_str_, ',');
    parsed_str_ = input_str_;
}

void Text::prepare()
{
    for(size_t i = 0; i < static_cast<size_t>(input_str_.size()); ++i)
    {
        if(input_str_[i] == ',' || input_str_[i] == ';' || input_str_[i] == '!' || input_str_[i] == '?')
        {
            parsed_str_[i] = ' ';
        }
        else
        {
            parsed_str_[i] = static_cast<char>(std::tolower(input_str_[i]));
        }
    }
    std::cout << parsed_str_ << std::endl;
}

void Text::parsing()
{
}