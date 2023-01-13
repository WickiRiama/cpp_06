/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:29:13 by mriant            #+#    #+#             */
/*   Updated: 2023/01/13 13:57:58 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <sstream>
#include <iostream>
#include <stdlib.h>

#include "convert.h"

int parseInt(std::string const &s, double *d)
{
	std::stringstream ss(s);
	int n;

	if (ss >> n)
	{
		*d = static_cast<double>(n);
		return 0;
	}
	std::cerr << "Invalid input" << std::endl;
	return 1;
}

int parseFloat(std::string const &s, double *d)
{
	std::stringstream ss(s);
	float f;

	if (s == "+inff" || s == "-inff" || s == "nanf")
	{
		f = static_cast<float>(atof(s.c_str()));
		*d = static_cast<double>(f);
		return 0;
	}
	if (ss >> f)
	{
		*d = static_cast<double>(f);
		return 0;
	}
	std::cerr << "Invalid input" << std::endl;
	return 1;
}

int parseDouble(std::string const &s, double *d)
{
	std::stringstream ss(s);

	if (s == "+inf" || s == "-inf" || s == "nan")
	{
		*d = atof(s.c_str());
		return 0;
	}
	if (ss >> *d)
		return 0;
	std::cerr << "Invalid input" << std::endl;
	return 1;
}

int parsing(std::string const &s, double *d)
{
	size_t i = 0;
	std::stringstream ss(s);

	if (s == "-inf" || s == "+inf" || s == "nan")
	{
		parseDouble(s, d);
		return 0;
	}
	if (s == "-inff" || s == "+inff" || s == "nanf")
	{
		parseFloat(s, d);
		return 0;
	}
	if (s.size() != 0 && s[0] == '-')
		i++;
	if (s.size() == 1 && !isdigit(s[i]))
	{
		char c = s[0];
		*d = static_cast<double>(c);
		return 0;
	}
	while (i < s.size() && isdigit(s[i]))
		i++;
	if (i == s.size())
	{
		if (parseInt(s, d))
			return 1;
		return 0;
	}
	if (s[i] != '.' || i == s.size() - 1)
	{
		std::cerr << "Invalid input" << std::endl;
		return 1;
	}
	i++;
	while (i < s.size() && isdigit(s[i]))
		i++;
	if (i == s.size())
	{
		if (parseDouble(s, d))
			return 1;
		return 0;
	}
	if (s[i] == 'f' && i == s.size() - 1)
	{
		if (parseFloat(s, d))
			return 1;
		return 0;
	}
	std::cerr << "Invalid input" << std::endl;
	return 1;
}
