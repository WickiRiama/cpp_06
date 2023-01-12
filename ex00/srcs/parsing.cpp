/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:29:13 by mriant            #+#    #+#             */
/*   Updated: 2023/01/12 15:56:30 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <sstream>
#include <iostream>

#include "convert.h"

int parsing(std::string s, double *d)
{
	size_t i = 0;
	std::stringstream ss(s);

	if (s.size() == 1 && !isdigit(s[0]))
	{
		char c = s[0];
		*d = static_cast<double>(c);
		return 0;
	}
	while(i < s.size() && isdigit(s[i]))
		i++;
	if (i == s.size())
	{
		int i;
		if (ss >> i)
		{
			*d = static_cast<double>(i);
			return 0;
		}
		std::cerr << "Invalid input" << std::endl;
		return 1;
	}
	if (s[i] != '.')
	{
		std::cerr << "Invalid input" << std::endl;
		return 1;
	}
	i++;
	while(i < s.size() && isdigit(s[i]))
		i++;
	if (i == s.size())
	{
		if (ss >> *d)
			return 0;
		std::cerr << "Invalid input" << std::endl;
		return 1;
	}
	if (s[i] == 'f' && i == s.size() - 1)
	{
		float f;
		if (ss >> f)
		{
			*d = static_cast<float>(f);
			return 0;
		}
		std::cerr << "Invalid input" << std::endl;
		return 1;
	}
	std::cerr << "Invalid input" << std::endl;
	return 1;
}
