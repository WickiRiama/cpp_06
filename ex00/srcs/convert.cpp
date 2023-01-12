/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:01:22 by mriant            #+#    #+#             */
/*   Updated: 2023/01/12 11:40:23 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

void parsing(std::string s, char *c, double *d, float *f, int *i)
{
	(void)f;
	(void)i;

	if (s.size() == 1 && !isdigit(s[0]))
	{
		*c = s[0];
		*d = static_cast<double>(*c);
	}
}

int main(int ac, char **av)
{
	char c;
	double d;
	float f;
	int i;

	if (ac != 2)
	{
		std::cerr << "Usage: ./convert arg1" << std::endl;
		return 1;
	}
	std::string s(av[1]);
	parsing(s, &c, &d, &f, &i);
	std::cout << "c: " << c << " d: " << d << std::endl;
}