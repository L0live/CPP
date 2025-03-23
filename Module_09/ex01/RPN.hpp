#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cmath>
#include <stdexcept>

class RPN {
private:
	RPN();
	RPN(const RPN &rpn);
	RPN &operator=(const RPN &rpn);
	~RPN();
public:
	static int calculateRPN(std::string expression);
};


#endif