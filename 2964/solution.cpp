#include <vector>
#include <cstdint>
#include <iostream>

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::int64_t>> mat(n, std::vector<std::int64_t>(m, 0));
    for(size_t ni = 0; ni < n; ni++)
    {
        for(size_t mi = 0; mi < m; mi++)
        {
            std::cin >> mat[ni][mi];
        }
    }

    for(size_t ni = 1; ni < n; ni++)
    {
        if (mat[ni - 1][0] == 0)
        {
            mat[ni][0] = 0;
        }
    }

    for(size_t mi = 1; mi < m; mi++)
    {
        if (mat[0][mi - 1] == 0)
        {
            mat[0][mi] = 0;
        }
    }

    for(size_t ni = 1; ni < n; ni++)
    {
        for(size_t mi = 1; mi < m; mi++)
        {
            auto& v = mat[ni][mi];
            if (v == 1)
            {
                v = mat[ni - 1][mi] + mat[ni][mi - 1];
            }
        }
    }

    auto const r = mat[n - 1][m - 1];
    if (r > 0)
    {
        std::cout << r;
    }
    else
    {
        std::cout << "Impossible";
    }
    std::cout << std::endl;

    return 0;
}

