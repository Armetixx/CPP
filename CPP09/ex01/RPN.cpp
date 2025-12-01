/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 02:32:08 by kederhet          #+#    #+#             */
/*   Updated: 2025/12/01 02:32:46 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <stdexcept>
#include <cctype>

RPN::RPN() 
{
}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return *this;
}

RPN::~RPN() {}

static long applyOperation(long a, long b, char op)
{
	switch (op)
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			if (b == 0)
				throw std::runtime_error("division by zero");
			return a / b;
		default:
			throw std::runtime_error("invalid operator");
	}
}

long RPN::compute(const std::string &expression) const
{
	std::stack<long> values;

	for (size_t i = 0; i < expression.length(); ++i)
	{
		char c = expression[i];
		if (std::isspace(static_cast<unsigned char>(c)))
			continue;
		if (std::isdigit(static_cast<unsigned char>(c)))
		{
			long value = 0;
			while (i < expression.length() && std::isdigit(static_cast<unsigned char>(expression[i])))
			{
				value = value * 10 + (expression[i] - '0');
				++i;
			}
			values.push(value);
			--i;
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (values.size() < 2)
				throw std::runtime_error("insufficient operands");
			long right = values.top();
			values.pop();
			long left = values.top();
			values.pop();
			values.push(applyOperation(left, right, c));
		}
		else
			throw std::runtime_error("invalid token");
	}

	if (values.size() != 1)
		throw std::runtime_error("invalid expression");

	return values.top();
}
