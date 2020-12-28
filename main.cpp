#include <iostream>
#include <sstream>
#include <stack>
#include <cassert>

int main() {
    setlocale(LC_ALL, "Russian");
    try {

        std::stack<int> numbers;
        std::stack<char> ops;
        std::string ExpressionNormal;

        std::cout << "��������� � ������� ������: ";
        std::getline(std::cin, ExpressionNormal);
        std::stringstream ss(ExpressionNormal);

        std::cout << "��������� � �������� �������� ������: ";

        std::string token;
        while (!ss.eof()) {
            ss >> token;
            if (token.empty()) {
                continue;
            }
            try {
                auto v = std::stod(token);
                numbers.push(v);
                std::cout << v << ' ';
            }
            catch (...) {
                switch (token[0]) {
                case '+':
                case '-':
                case '*':
                case '/':
                    ops.push(token[0]);
                    break;
                }
            }
        }

        int finalValue = numbers.top();
        numbers.pop();
        while (!ops.empty()) 
        {
            int num = numbers.top();
            numbers.pop();
            switch (ops.top()) {
            case '+':
                finalValue = num + finalValue;
                break;
            case '-':
                finalValue = num - finalValue;
                break;
            case '*':
                finalValue = num * finalValue;
                break;
            case '/':
                if (finalValue == 0) 
{
                    throw std::runtime_error{ "������� �� 0 �� ���������" };
                }
                finalValue = num / finalValue;
                break;
            }

            std::cout << ops.top() << ' ';
            ops.pop();
        }
        std::cout << std::endl << "= " << finalValue;
    }
    catch (const std::exception& e) 
    {
        std::cout << "������: " << e.what();
        return -1;
    }


    return 0;
}