#include <cmath>
#include <vector>
#include <cstdint>
#include <iostream>
#include <algorithm>

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int64_t> vec(std::max(3ul, n + 1));
    vec[0] = 1;
    vec[1] = 2;
    vec[2] = 3;
    for(size_t i = 3; i <= n; i++)
    {
        vec[i] = vec[i - 1] + vec[i - 2];
    }

    std::cout << vec[n] << '\n';

    return 0;
}
