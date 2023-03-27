#include <vector>
#include <iostream>

int main()
{
    int64_t x, y;
    std::cin >> x >> y;

    std::vector<std::vector<int>> dp(10, std::vector<int>(10, 0));
    dp[y][x] = 1;

    for(;y < 8; y++)
    {
        auto& curr = dp[y + 0];
        auto& line = dp[y + 1];
        for(size_t i = 1; i <= 8; i++)
        {
            line[i - 1] += curr[i];
            line[i + 1] += curr[i];
        }
    }

    int res{};
    for(size_t i = 1; i <= 8; i++)
    {
        res += dp[8][i];
    }
    std::cout << res << std::endl;

    return 0;
}

