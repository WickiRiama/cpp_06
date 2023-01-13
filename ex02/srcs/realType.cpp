/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realType.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:08:59 by mriant            #+#    #+#             */
/*   Updated: 2023/01/13 17:43:46 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <exception>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	Base *result;
	int randBase;

	randBase = rand() % 3;
	if (randBase == 0)
	{
		result = new A();
		std::cout << "A" << std::endl;
	}
	else if (randBase == 1)
	{
		result = new B();
		std::cout << "B" << std::endl;
	}
	else
	{
		result = new C();
		std::cout << "C" << std::endl;
	}
	return result;
}

void identify(Base* p)
{
	A *a;
	B *b;
	C *c;

	a = dynamic_cast<A *>(p);
	if (a)
	{
		std::cout << "The type is A" << std::endl;
		return ;
	}
	b = dynamic_cast<B *>(p);
	if (b)
	{
		std::cout << "The type is B" << std::endl;
		return ;
	}
	c = dynamic_cast<C *>(p);
	if (c)
		std::cout << "The type is C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "The type is A" << std::endl;
	}
	catch (std::exception &e)
	{
		try
		{
			B b = dynamic_cast<B&>(p);
			std::cout << "The type is B" << std::endl;
		}
		catch (std::exception &e)
		{
			try
			{
				C c = dynamic_cast<C&>(p);
				std::cout << "The type is C" << std::endl;
			}
			catch (std::exception &e)
			{
				
			}
		}
	}
}

int main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 4; i++)
	{
		Base *base = generate();
		identify(base);
		identify(*base);
		delete base;
	}
}