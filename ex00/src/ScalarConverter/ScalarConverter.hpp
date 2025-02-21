/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:34:07 by tnakas            #+#    #+#             */
/*   Updated: 2025/02/21 16:17:15 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <iomanip>

class ScalarConverter
{
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	//helpers
	static bool isChar(const std::string& str);
	static bool isInt(const std::string& str);
	static bool isFloat(const std::string& str);
	static bool isDouble(const std::string& str);
	//Overflow handlers
	static void charOverFlow(const std::string& literal);
	static void intOverFlow(const std::string& literal);
	static void floatOverFlow(const std::string& literal);
	//Conversion
	static void printConversion(char charVal, int intVal, float floatVal, double doubleVal);
	public:
		static void convert(const std::string& literal);
};
#endif