#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &) {}

RPN &RPN::operator=(const RPN &) {return *this;}

RPN::~RPN() {}

double RPN::calculateRPN(std::string expression) {
    std::stack<double> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0]) && token.size() == 1) {
            stack.push(token[0] - '0');
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2)
                throw std::runtime_error("Invalid expression: not enough operands");
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
			if (token == "+") stack.push(a + b);
			else if (token == "-") stack.push(a - b);
			else if (token == "*") stack.push(a * b);
			else if (token == "/") {
				if (b == 0)
					throw std::runtime_error("Division by zero");
				stack.push(a / b);
			}
        } else {
            throw std::runtime_error("Invalid token: " + token);
        }
    }
    if (stack.size() != 1)
        throw std::runtime_error("Invalid expression: too many operands");
    return stack.top();
}