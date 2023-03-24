#include <stack>
#include <string>
#include <iostream>

char flip(const char c)
{
    if (c == ')')
        return '(';

    if (c == ']')
        return '[';
    
    if (c == '}')
        return '{';
    
    return ' ';
}

int main()
{
    std::string str;
    std::cin >> str;

    std::stack<char> stack;

    for(auto const c : str)
    {
        switch(c)
        {
            case '(':
            case '[':
            case '{':
                stack.push(c);
                break;

            case ')':
            case ']':
            case '}':
            {
                auto f = flip(c);
                if (stack.empty() or stack.top() != f)
                {
                    std::cout << "no" << std::endl;
                    return 0;
                }
                stack.pop();
            }
                break;
        }
    }

    std::cout << (stack.empty() ? "yes" : "no") << std::endl;

    return 0;
}

