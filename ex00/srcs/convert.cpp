/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:01:22 by mriant            #+#    #+#             */
/*   Updated: 2023/01/13 13:58:43 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <math.h>

#include "convert.h"

void printChar(double d)
{
	char c;

	if (d == -INFINITY || d == +INFINITY || isnan(d) || d < SCHAR_MIN || d > SCHAR_MAX)
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	c = static_cast<char>(d);
	if (!isprint(c))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
}

void printInt(double d)
{
	int i;

	if (d == -INFINITY || d == +INFINITY || isnan(d) || d < INT_MIN || d > INT_MAX)
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}
	i = static_cast<int>(d);
	std::cout << "int: " << i << std::endl;
}

void printFloat(double d)
{
	float f;
	float intPart;

	if (d == -INFINITY || d == +INFINITY || isnan(d))
	{
		f = static_cast<float>(d);
		std::cout << "float: " << f << "f" << std::endl;
		return ;
	}
	if (static_cast<float>(d) == -INFINITY || d > FLT_MAX)
	{
		std::cout << "float: impossible" << std::endl;
		return;
	}
	f = static_cast<float>(d);
	std::cout << "float: " << f;
	modff(f, &intPart);
	if (intPart == f)
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void printDouble(double d)
{
	double intPart;

	if (d == -INFINITY || d == +INFINITY || isnan(d))
	{
		std::cout << "double: " << d << std::endl;
		return ;
	}
	modf(d, &intPart);
	std::cout << "double: " << d;
	if (d == intPart)
		std::cout << ".0";
	std::cout << std::endl;
}

int main(int ac, char **av)
{
	double d;

	if (ac != 2)
	{
		std::cerr << "Usage: ./convert arg1" << std::endl;
		return 1;
	}
	std::string s(av[1]);
	if (parsing(s, &d))
		return 1;
	printChar(d);
	printInt(d);
	printFloat(d);
	printDouble(d);
}
