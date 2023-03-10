#include <vector>
#include <cstdint>
#include <iostream>

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<std::int64_t>> triangle(std::max(n, 2ul));
    triangle[0] = {1};
    triangle[1] = {1, 1};

    for(size_t i = 2; i < n; i++)
    {
        auto const& prev = triangle[i - 1];

        std::vector<std::int64_t> line(i + 1);
        line.front() = 1;
        line.back() = 1;
        for(size_t j = 1; j < i; j++)
        {
            line[j] = prev[j - 1] + prev[j];
        }

        triangle[i] = std::move(line);
    }

    for(size_t i = 0; i < n; i++)
    {
        auto const& line = triangle[i];
        for(auto const e : line)
        {
            std::cout << e << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
