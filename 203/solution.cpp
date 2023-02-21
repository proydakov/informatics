#include <vector>
#include <cstdint>
#include <iostream>

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int64_t> vec(std::max(9ul, n + 7), 0);
    vec[0] = 1;
    vec[1] = 1;
    vec[2] = 2;

    for(size_t i = 3; i <= n; i++)
    {
        vec[i] += vec[i - 1] + vec[i - 2] + vec[i - 3];
    }

    std::cout << vec[n] << '\n';

    return 0;
}

