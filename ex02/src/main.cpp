/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:44:46 by tnakas            #+#    #+#             */
/*   Updated: 2025/02/20 23:18:46 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identifier/Identifier.hpp"

int main()
{
	Base *obj = generate();
	std::cout << "Identifying using pointer:" << std::endl;
	identify(obj);

	std::cout << "Identifying using reference:" << std::endl;
	identify(*obj);

	delete obj;
	return 0;
}