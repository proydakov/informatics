#include <vector>
#include <cstdint>
#include <iostream>
#include <algorithm>

int main()
{
    size_t size;
    std::cin >> size;

    std::vector<int64_t> vec(size);
    for(auto& e : vec)
    {
        std::cin >> e;
    }

    std::sort(vec.begin(), vec.end());
    std::vector<int64_t> result(size);
    if (vec.size() < 2)
    {
        // pass
    }
    else if (2 == vec.size())
    {
        std::cout << (vec[1] - vec[0]) << '\n';
    }
    else
    {
        result[0] = 0;
        result[1] = vec[1] - vec[0];
        result[2] = vec[2] - vec[0];
        for(size_t i = 3; i < size; i++)
        {
            size_t const p = i - 1;
            auto const curr = vec[i] - vec[p];
            result[i] = std::min(result[i - 1] + curr, result[i - 2] + curr);
        }
        std::cout << result.back() << '\n';
    }

    return 0;
}

