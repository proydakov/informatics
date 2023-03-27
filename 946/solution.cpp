#include <vector>
#include <cstdint>
#include <iostream>

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int64_t>> dp(n + 2, std::vector<int64_t>(m + 2, 0));
    dp[0][0] = 1;

    for(size_t ni = 0; ni < n; ni++)
    {
        for(size_t mi = 0; mi < m; mi++)
        {
            if (dp[ni][mi] > 0)
            {
                dp[ni + 1][mi + 2] += dp[ni][mi];
                dp[ni + 2][mi + 1] += dp[ni][mi];
            }
        }
    }
    std::cout << dp[n - 1][m - 1] << std::endl;

    return 0;
}
