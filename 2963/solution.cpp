#include <limits>
#include <vector>
#include <iostream>

int main()
{
    size_t val;
    std::cin >> val;

    std::vector<int64_t> vec(val + 1, std::numeric_limits<int64_t>::max());

    size_t ssize = vec.size();

    vec[0] = 0;
    vec[1] = 0;

    for(size_t i = 1; i < val; i++)
    {
        size_t i1 = i + 1;
        size_t i2 = i * 2;
        size_t i3 = i * 3;

        vec[i1] = std::min(vec[i1], vec[i] + 1);

        if (i2 < ssize && vec[i2] > vec[i] + 1)
        {
            vec[i2] = vec[i] + 1;
        }

        if (i3 < ssize && vec[i3] > vec[i] + 1)
        {
            vec[i3] = vec[i] + 1;
        }
    }

    std::cout << vec[val] << '\n';

    return 0;
}

