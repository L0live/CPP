#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &) {}

RPN &RPN::operator=(const RPN &) {return *this;}

RPN::~RPN() {}

static int	doOperator(int a, int b, char op) {

	long long tmp = a;

	if (op == '+') {
		if (tmp + b > INT_MAX || tmp + b < INT_MIN) {
			throw std::runtime_error("Out of int range");
		} return a + b;
	}
	if (op == '-') {
		if (tmp - b > INT_MAX || tmp - b < INT_MIN) {
			throw std::runtime_error("Out of int range");
		} return a - b;
	}
	if (op == '*') {
		if (tmp * b > INT_MAX || tmp * b < INT_MIN) {
			throw std::runtime_error("Out of int range");
		} return a * b;
	}
	if (op == '/') {
		if (b == 0) throw std::runtime_error("Division by zero");
		if (tmp / b > INT_MAX || tmp / b < INT_MIN) {
			throw std::runtime_error("Out of int range");
		} return a / b;
	}
	return 0;
}

int RPN::calculateRPN(std::string expression) {
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0]) && token.size() == 1) {
            stack.push(token[0] - '0');
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2)
                throw std::runtime_error("Invalid expression: not enough operands");
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            stack.push(doOperator(a, b, token[0]));
        } else {
            throw std::runtime_error("Invalid token: " + token);
        }
    }
    if (stack.size() != 1)
        throw std::runtime_error("Invalid expression: too many operands");
    return stack.top();
}