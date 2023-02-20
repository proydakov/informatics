#include <limits>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

int main()
{
    size_t val;
    std::cin >> val;

    std::vector<int64_t> vec(val + 1, std::numeric_limits<int64_t>::max());
    std::vector<char> prev(val + 1, ' ');

    size_t ssize = vec.size();

    vec[0] = 0;
    vec[1] = 0;

    for(size_t i = 1; i < val; i++)
    {
        size_t i1 = i + 1;
        size_t i2 = i * 2;
        size_t i3 = i * 3;

        if (vec[i1] > vec[i] + 1)
        {
            vec[i1] = vec[i] + 1;
            prev[i1] = '1';
        }

        if (i2 < ssize && vec[i2] > vec[i] + 1)
        {
            vec[i2] = vec[i] + 1;
            prev[i2] = '2';
        }

        if (i3 < ssize && vec[i3] > vec[i] + 1)
        {
            vec[i3] = vec[i] + 1;
            prev[i3] = '3';
        }
    }

    std::string res;

    for(struct {size_t index; char c;} s = { val, prev[s.index] }; s.c != ' '; s.c = prev[s.index])
    {
        res.push_back(s.c);
        switch(s.c)
        {
            case '1':
                s.index -= 1;
                break;

            case '2':
                s.index /= 2;
                break;

            case '3':
                s.index /= 3;
                break;
        }
    }

    std::reverse(res.begin(), res.end());

    std::cout << res << '\n';

    return 0;
}
