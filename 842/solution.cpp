#include <vector>
#include <iostream>

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int64_t> vec(std::max(3ul, n + 1), 0);

    vec[0] = 1;
    vec[1] = 1;

    for(size_t i = 2; i <= n; i++)
    {
        vec[i] = vec[i - 2] % 1'000'000 + vec[i - 1] % 1'000'000;
    }

    std::cout << vec[n] % 10 << '\n';

    return 0;
}

