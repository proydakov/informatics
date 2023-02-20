#include <cmath>
#include <vector>
#include <iostream>

struct item
{
    int64_t total{};
    int64_t dangs{};
};

int main()
{
    size_t v;
    std::cin >> v;

    std::vector<item> vec(std::max(2ul, v + 1));

    vec[0] = {0, 0};
    vec[1] = {3, 1};

    for(size_t i = 2; i <= v; i++)
    {
        vec[i].total = vec[i - 1].total * 3 - vec[i - 1].dangs;
        vec[i].dangs = vec[i - 1].total - vec[i - 1].dangs;
    }

    std::cout << vec[v].total << '\n';

    return 0;
}

