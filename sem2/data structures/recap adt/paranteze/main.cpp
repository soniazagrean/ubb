#include <iostream>
#include <stack>
#include <string>


int main() {
    char str[101];
    std::cin >> str;
    std::stack<char> s;
    if (str[0] == ')') {
        std::cout << "invalid";
        return 0;
    }

    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == ')') {
            if (s.empty()) {
                std::cout << "invalid";
                return 0;
            }
            s.pop();
        }
        if (str[i] == '(')
            s.push(str[i]);
    }
    if (s.empty())
        std::cout << "valid";
    else std::cout << "invalid";
    return 0;
}
