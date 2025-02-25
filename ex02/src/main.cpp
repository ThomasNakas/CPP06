/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:44:46 by tnakas            #+#    #+#             */
/*   Updated: 2025/02/25 13:41:48 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identifier/Identifier.hpp"

int main()
{
	D d;
	Base *obj = generate();
	std::cout << "Identifying using pointer:" << std::endl;
	identify(obj);

	std::cout << "Identifying using reference:" << std::endl;
	identify(*obj);
	
	std::cout << "Unknown type: " << std::endl;
	identify(d);
	delete obj;
	return 0;
}