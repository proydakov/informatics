#include <cstdint>
#include <iostream>

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::uint64_t dp[n][m];
    for(size_t i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    for(size_t i = 0; i < m; i++)
    {
        dp[0][i] = 1;
    }

    for(size_t ni = 1; ni < n; ni++)
    {
        for(size_t mi = 1; mi < m; mi++)
        {
            dp[ni][mi] = dp[ni - 1][mi] + dp[ni][mi - 1];
        }
    }

    std::cout << dp[n - 1][m - 1] << std::endl;

    return 0;
}
