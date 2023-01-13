/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriant <mriant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:31:50 by mriant            #+#    #+#             */
/*   Updated: 2023/01/13 15:14:55 by mriant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <iostream>

#include "serialize.h"
#include "colors.h"

uintptr_t serialize(Data* ptr)
{
	uintptr_t result;

	result = reinterpret_cast<uintptr_t>(ptr);
	return result;
}

Data* deserialize(uintptr_t raw)
{
	Data *result;

	result = reinterpret_cast<Data *>(raw);
	return result;
}

int main(void)
{
	Data myData;
	Data *myDataAdress;
	uintptr_t uIntPtr;

	myData.d = 0;
	myData.ata = "hello";
	myDataAdress = &myData;

	std::cout << BCYN << "Before serialization" << RES << std::endl;

	std::cout << "adress: " << myDataAdress
			  << " d: " << myDataAdress->d
			  << " ata: " << myDataAdress->ata << std::endl;
	
	uIntPtr = serialize(myDataAdress);

	std::cout << std::endl << BCYN << "During serialization" << RES << std::endl;

	std::cout << "uIntPtr: " << uIntPtr << std::endl;

	myDataAdress = deserialize(uIntPtr);
	
	std::cout << std::endl << BCYN << "After serialization" << RES << std::endl;

	std::cout << "adress: " << myDataAdress
			  << " d: " << myDataAdress->d
			  << " ata: " << myDataAdress->ata << std::endl;

}
