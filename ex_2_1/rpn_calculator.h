#ifndef RPN_CALCULATOR_H_
#define RPN_CALCULATOR_H_

#include "fraction.h"
#include <iostream>
#include <vector>

class rpn_calculator
{

	std::vector<fraction> stack;

	void check();

public:

	rpn_calculator();

	void push(fraction f);
	fraction pop();
	void reset();
	void print();

	void add();
	void sub();
	void mul();
	void div();

	void min();
	void max();
	void swap();

};

#endif  // RPN_CALCULATOR_H_