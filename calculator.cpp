#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    double calculate(std::string s) {
        std::vector<double> stack;
        double n = 0.0;
        char sign = '+';
        for (size_t i = 0; i < s.size(); ++i) {
            char c = s[i];

            if (isdigit(c)) {
                n = n * 10.0 + (c - '0');
            }

            if (!isspace(c) && !isdigit(c) || i == s.size() - 1) {
                if (sign == '+') {
                    stack.push_back(n);
                } else if (sign == '-') {
                    stack.push_back(-n);
                } else if (sign == '*') {
                    stack.back() *= n;
                } else {
                    stack.back() /= n;
                }
                sign = c;
                n = 0;
            };
        }

        double result = 0.0;
        for (double num : stack) {
            result += num;
        }
        return result;
    }
};

int main() {
    Solution sol;
    std::string input;
    std::cout << "Please enter the expression (e.g., \"3+2*2\"): ";
    std::cin >> input;
    std::cout << "Result: " << sol.calculate(input) << std::endl;
    return 0;
}
