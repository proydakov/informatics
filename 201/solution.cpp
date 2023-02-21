#include <vector>
#include <cstdint>
#include <iostream>

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int64_t> vec(std::max(3ul, n + 1));
    vec[0] = 0;
    vec[1] = 1;
    vec[2] = 1;

    for(size_t i = 3; i <= n; i++)
    {
        vec[i] = vec[i - 2] + vec[i - 1];
    }

    std::cout << vec[n] << '\n';

    return 0;
}

