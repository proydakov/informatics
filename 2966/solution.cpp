#include <vector>
#include <cstdint>
#include <iostream>
#include <algorithm>

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<char>  > prev(n, std::vector<char>(m, 'O'));
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
        prev[0][i] = 'R';
        mat[0][i] += mat[0][i - 1];
    }

    for(size_t i = 1; i < n; i++)
    {
        prev[i][0] = 'D';
        mat[i][0] += mat[i - 1][0];
    }

    for(size_t ni = 1; ni < n; ni++)
    {
        for(size_t mi = 1; mi < m; mi++)
        {
            if (mat[ni - 1][mi] > mat[ni][mi - 1])
            {
                prev[ni][mi] = 'D';
                mat[ni][mi] += mat[ni - 1][mi];
            }
            else
            {
                prev[ni][mi] = 'R';
                mat[ni][mi] += mat[ni][mi - 1];
            }
        }
    }

    std::cout << mat[n - 1][m - 1] << '\n';

    int64_t x = m - 1;
    int64_t y = n - 1;
    char c = prev[y][x];

    std::vector<char> vec;
    vec.reserve(n + m - 1);

    while(x != 0 || y != 0)
    {
        vec.push_back(c);
        if (c == 'D')
        {
            y--;
        }
        else if(c == 'R')
        {
            x--;
        }
        c = prev[y][x];
    }
    std::reverse(vec.begin(), vec.end());

    for(auto const e : vec)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    return 0;
}

