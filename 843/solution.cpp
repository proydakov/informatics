#include <vector>
#include <cstdint>
#include <iostream>

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int64_t> vec(std::max(n + 1, 3ul));
    vec[0] = 1;
    vec[1] = 1;

    for(size_t i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            size_t t = i / 2;
            vec[i] = vec[t] + vec[t - 1];
        }
        else
        {
            size_t t = i / 2;
            vec[i] = vec[t] - vec[t - 1];
        }
    }

    std::cout << vec[n] << '\n';

    return 0;
}
