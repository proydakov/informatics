#include <cmath>
#include <vector>
#include <iostream>

struct node
{
    int64_t count{};
    int64_t zeroes{};
    int64_t d1{};
};

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<node> vec(std::max(4ul, n + 1));
    vec[0] = {0, 0, 0};
    vec[1] = {2, 1, 0};
    vec[2] = {4, 2, 1};
    vec[3] = {7, 4, 1};

    for(size_t i = 4; i <= n; i++)
    {
        vec[i] = {vec[i - 1].count * 2 - vec[i - 1].d1, vec[i - 1].count, vec[i - 2].zeroes};
    }

    std::cout << vec[n].count << '\n';

    return 0;
}

