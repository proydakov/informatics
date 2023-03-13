#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

int main()
{
    std::string buffer;

    std::map<int, std::vector<std::string>> map;

    while(std::getline(std::cin, buffer) and not buffer.empty())
    {
        std::stringstream sstream;
        sstream << buffer;
        int num;
        std::string name;
        sstream >> num >> name;
        map[num].push_back(name);
    }

    for(auto const& val : map)
    {
        for(auto const& e : val.second)
        {
            std::cout << val.first << ' ' << e << '\n';
        }
    }

    return 0;
}

