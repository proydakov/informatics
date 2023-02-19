#include <vector>
#include <cstdint>
#include <iostream>

int main()
{
    std::size_t n;
    std::cin >> n;

    std::vector<int64_t> vec(n + 1, 0);
    for(size_t i = 1; i <= n; i++)
    {
        std::cin >> vec[i];
    }

    for(size_t i = 3; i <= n; i++)
    {
        vec[i] += std::min(vec[i - 1], vec[i - 2]);
    }
    std::cout << vec[n] << '\n';

    return 0;
}
