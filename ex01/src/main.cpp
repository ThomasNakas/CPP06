/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:15:33 by tnakas            #+#    #+#             */
/*   Updated: 2025/02/25 11:48:16 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serial/Serializer.hpp"

int main()
{
	//using the struct
	Data original;
	original.name = "John Doe";
	original.age = 30;
	original.score = 95.5;

	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "Serialized value: " << raw << std::endl;

	Data* deserialized = Serializer::deserialize(raw);

	std::cout << "\nDeserialized Data:\n\n";
    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << "Age: " << deserialized->age << std::endl;
    std::cout << "Score: " << deserialized->score << std::endl;

	if (&original == deserialized)
		std::cout << "\nSuccess: Deserialized pointer matches to the original.\n";
	else
		std::cout << "\nError: Pointers do not match!\n";
	return 0;
	
}