/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:33:44 by tnakas            #+#    #+#             */
/*   Updated: 2025/02/20 21:50:07 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter/ScalarConverter.hpp"

int main(int argc, char* argv[])
{
	if (argc !=2)
	{
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}