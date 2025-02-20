/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identifier.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:44:40 by tnakas            #+#    #+#             */
/*   Updated: 2025/02/20 23:30:25 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identifier.hpp"

Base* generate()
{
	srand(time(0) + clock());
	int random =rand() % 3;

	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

//-------BY POINTER---------
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type: C" << std::endl;
	else
		std::cout << "Unkown type" << std::endl;
	
}

//-------BY ADRESS----------
void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Type: A" << std::endl;
		return; 
	}
	catch(...){}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Type: B" << std::endl;
		return;
	}
	catch(...){}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Type: C" << std::endl;
		return;
	}
	catch(...){}
	std::cout << "Unkown type" << std::endl;
}