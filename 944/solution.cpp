#include <vector>
#include <cstdint>
#include <iostream>

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int64_t>> mat(n, std::vector<int64_t>(m));
    for(size_t ni = 0; ni < n; ni++)
    {
        for(size_t mi = 0; mi < m; mi++)
        {
            std::cin >> mat[ni][mi];
        }
    }

    for(size_t i = 1; i < m; i++)
    {
        mat[0][i] += mat[0][i - 1];
    }

    for(size_t i = 1; i < n; i++)
    {
        mat[i][0] += mat[i - 1][0];
    }

    for(size_t ni = 1; ni < n; ni++)
    {
        for(size_t mi = 1; mi < m; mi++)
        {
            mat[ni][mi] += std::min(mat[ni - 1][mi], mat[ni][mi - 1]);
        }
    }

    std::cout << mat[n - 1][m - 1] << '\n';

    return 0;
}
