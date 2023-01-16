/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:01:22 by mriant            #+#    #+#             */
/*   Updated: 2023/01/16 12:40:13 by mriant           ###   ########.fr       */
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

void printFloat(double d, int const &precision)
{
	float f;

	if (d == -INFINITY || d == +INFINITY || isnan(d))
	{
		f = static_cast<float>(d);
		std::cout << "float: " << f << "f" << std::endl;
		return;
	}
	if (static_cast<float>(d) == -INFINITY || d > FLT_MAX)
	{
		std::cout << "float: impossible" << std::endl;
		return;
	}
	f = static_cast<float>(d);
	std::cout << std::fixed;
	std::cout.precision(precision);
	std::cout << "float: " << f;
	std::cout << "f" << std::endl;
	std::cout.unsetf(std::ios_base::floatfield);
}

void printDouble(double d, int const &precision)
{
	if (d == -INFINITY || d == +INFINITY || isnan(d))
	{
		std::cout << std::fixed << "double: " << d << std::endl;
		return;
	}
	std::cout << std::fixed;
	std::cout.precision(precision);
	std::cout << "double: " << d;
	std::cout << std::endl;
	std::cout.unsetf(std::ios_base::floatfield);
}

int main(int ac, char **av)
{
	double d;
	int precision = 0;

	if (ac != 2)
	{
		std::cerr << "Usage: ./convert arg1" << std::endl;
		return 1;
	}
	std::string s(av[1]);
	if (parsing(s, &d, &precision))
		return 1;
	if (precision == 0)
		precision = 1;
	printChar(d);
	printInt(d);
	printFloat(d, precision);
	printDouble(d, precision);
}
