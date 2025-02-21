/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:34:17 by tnakas            #+#    #+#             */
/*   Updated: 2025/02/21 14:08:40 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {return *this;}
ScalarConverter::~ScalarConverter() {}

//----Checking Functions----//

bool ScalarConverter::isChar(const std::string& str)
{
	return (str.length() == 1 && !isdigit(str[0]));
}

bool ScalarConverter::isInt(const std::string& str)
{
	size_t i = 0;
	if (str[i] == '-' || str[i] == '+') i++;
	while (i < str.length())
	{
		if (!isdigit(str[i])) return false;
		i++;
	}
	return !str.empty();
}

bool ScalarConverter::isFloat(const std::string& str)
{
	if (str == "+inff" || str == "-inff" || str == "nanf") return true;
	if (str.empty() || str.back() != 'f') return false;
	std::string temp = str.substr(0, str.length() - 1);
	return isDouble(temp);
}

bool ScalarConverter::isDouble(const std::string& str)
{
	if (str == "+inf" || str == "-inf" || str == "nan") return true;
	if (str.empty()) return false;
	
	bool dot_found = false;
	size_t i = 0;
	if (str[i] == '-' || str[i] == '+') i++;
	while (i < str.length())
	{
		if (str[i] == '.')
		{
			if (dot_found) return false;
			dot_found = true;
		}
		else if (!isdigit(str[i])) return false;
		i++;
	}
	return dot_found;
}

void ScalarConverter::printConversion(char charVal, int intVal, float floatVal, double doubleVal)
{
	if (isprint(charVal))
		std::cout << "char: '" << charVal << "'" << std::endl;
	else std::cout << "char: Non Displayable" << std::endl;

	std::cout << "int: " << intVal << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << floatVal << "f" << std::endl;
	std::cout << "double: " << doubleVal << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
	char charVal = 0;
	int intVal = 0;
	float floatVal = 0.0f;
	double doubleVal = 0.0;

	try
	{
		if (isChar(literal))
		{
			charVal = literal[0];
			intVal = static_cast<int>(charVal);
			floatVal = static_cast<float>(charVal);
			doubleVal = static_cast<double>(charVal);
		}
		else if(isInt(literal))
		{
			try
			{
				intVal = std::stoi(literal);
				charVal = static_cast<char>(intVal);
				floatVal = static_cast<float>(intVal);
				doubleVal = static_cast<double>(intVal);
			}
			catch (const std::out_of_range&)
			{
				std::cout << "int: overflow" << std::endl;
				return;
			}
		}
		else if(isFloat(literal))
		{
			try
			{
				floatVal = std::stof(literal);
				intVal = static_cast<int>(floatVal);
				charVal = static_cast<char>(intVal);
				doubleVal = static_cast<double>(intVal);
			}
			catch (const std::out_of_range&)
			{
				std::cout << "float: overflow" << std::endl;
				return;
			}
		}
		else if(isDouble(literal))
		{
			try
			{
				doubleVal = std::stod(literal);
				intVal = static_cast<int>(doubleVal);
				charVal = static_cast<char>(intVal);
				floatVal = static_cast<float>(doubleVal);
			}
			catch (const std::out_of_range&)
			{
				std::cout << "double: overflow" << std::endl;
				return;
			}
		}
		else
		{
			std::cerr << "Error: Invalid input format" << std::endl;
			return;
		}
		
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return;
	}
	printConversion(charVal, intVal, floatVal, doubleVal);
}