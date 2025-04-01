#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <climits>

class RPN {
private:
	RPN();
	RPN(const RPN &rpn);
	RPN &operator=(const RPN &rpn);
	~RPN();
public:
	static double calculateRPN(std::string expression);
};


#endif