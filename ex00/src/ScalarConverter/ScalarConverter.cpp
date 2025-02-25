/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:34:17 by tnakas            #+#    #+#             */
/*   Updated: 2025/02/25 12:59:39 by tnakas           ###   ########.fr       */
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
	std::cout << "float: " << std::fixed << std::setprecision(1) << floatVal << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << doubleVal << std::endl;
}

void ScalarConverter::charOverFlow(const std::string& literal)
{
			long long tempInt = std::stoll(literal);
			int intVal = static_cast<int>(tempInt);
			float floatVal = std::stof(literal);
			double doubleVal = static_cast<double>(floatVal);
			std::cout << "char: Not Displayable" << std::endl;
			std::cout << "int: " << intVal << std::endl;
			std::cout << "float: " << std::fixed << std::setprecision(1) << floatVal << "f" << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(1) << doubleVal << std::endl;
}
void ScalarConverter::intOverFlow(const std::string& literal)
{
	std::cout << "char: Not Displayable" << std::endl;
	std::cout << "int: overflow" << std::endl;
	float floatVal = std::stof(literal);
	double doubleVal = static_cast<double>(floatVal);
	std::cout << "float: " << std::fixed << std::setprecision(1) << floatVal << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << doubleVal << std::endl;
}

void ScalarConverter::floatOverFlow(const std::string& literal)
{
			if (literal == "+inff")
			{
				std::cout << "char: Not Displayable" << std::endl;
				std::cout << "int: overflow" << std::endl;
				std::cout << "float: +inff" << std::endl;
				std::cout << "float: +inf" << std::endl;
			}
			else if (literal == "-inff")
			{
				std::cout << "char: Not Displayable" << std::endl;
				std::cout << "int: overflow" << std::endl;
				std::cout << "float: -inff" << std::endl;
				std::cout << "float: -inf" << std::endl;
			}
			else if (literal == "nanf")
			{
				std::cout << "char: Not Displayable" << std::endl;
				std::cout << "int: overflow" << std::endl;
				std::cout << "float: nanf" << std::endl;
				std::cout << "float: nan" << std::endl;
			}
			else if (literal == "+inf")
			{
				std::cout << "char: Not Displayable" << std::endl;
				std::cout << "int: overflow" << std::endl;
				std::cout << "float: +inff" << std::endl;
				std::cout << "float: +inf" << std::endl;
			}
			else if (literal == "-inf")
			{
				std::cout << "char: Not Displayable" << std::endl;
				std::cout << "int: overflow" << std::endl;
				std::cout << "float: -inff" << std::endl;
				std::cout << "float: -inf" << std::endl;
			}
			else if (literal == "nan")
			{
				std::cout << "char: Not Displayable" << std::endl;
				std::cout << "int: overflow" << std::endl;
				std::cout << "float: nanf" << std::endl;
				std::cout << "float: nan" << std::endl;
			}
			else 
			{
				std::cout << "char: Not Displayable" << std::endl;
				std::cout << "int: overflow" << std::endl;
				std::cout << "float: overflow" << std::endl;
				double doubleVal = std::stof(literal);
				std::cout << "double: " << std::fixed << std::setprecision(1) << doubleVal << std::endl;
			}
}
void ScalarConverter::convert(const std::string& literal)
{
	char charVal = 0;
	int intVal = 0;
	float floatVal = 0.0f;
	double doubleVal = 0.0;
	//limits
	//int
	int min_int = std::numeric_limits<int>::min();
	int max_int = std::numeric_limits<int>::max();
	//float
	float min_float = std::numeric_limits<float>::min();
	float max_float = std::numeric_limits<float>::max();

	if (isChar(literal))
	{
		charVal = literal[0];
		intVal = static_cast<int>(charVal);
		floatVal = static_cast<float>(charVal);
		doubleVal = static_cast<double>(charVal);
	}
	else if(isInt(literal))
	{
		long long tempInt = std::stoll(literal);
		if (tempInt > max_int || tempInt < min_int)
		{
			intOverFlow(literal);
			return ;
		}
		intVal = static_cast<int>(tempInt);
		if (intVal > 127 || intVal < 0)
		{
			charOverFlow(literal);
			return ;
		}
		charVal = static_cast<char>(intVal);
		floatVal = static_cast<float>(intVal);
		doubleVal = static_cast<double>(intVal);
	}
	else if(isFloat(literal))
	{
		//bigger than float
		if(std::stod(literal) > max_float || std::stod(literal) < min_float || literal == "nanf")
		{
			floatOverFlow(literal);
			return ;
		}
		else
		{
			floatVal = std::stof(literal);
			doubleVal = static_cast<double>(floatVal);
			long long tempInt = std::stoll(literal);
			if (tempInt > max_int || tempInt < min_int)
			{
				intOverFlow(literal);
				return ;
			}
		}
		intVal = std::stoi(literal);
		if (intVal > 127 || intVal < 0)
		{
			charOverFlow(literal);
			return ;
		}
		charVal = static_cast<char>(intVal);
		floatVal = static_cast<float>(intVal);
		doubleVal = static_cast<double>(intVal);
	}
	else if(isDouble(literal))
	{
		if(std::stod(literal) > max_float || std::stod(literal) < min_float || literal == "nan")
		{
			floatOverFlow(literal);
			return ;
		}
		else
		{
			floatVal = std::stof(literal);
			doubleVal = static_cast<double>(floatVal);
			long long tempInt = std::stoll(literal);
			if (tempInt > max_int || tempInt < min_int)
			{
				intOverFlow(literal);
				return ;
			}
		}
		intVal = std::stoi(literal);
		if (intVal > 127 || intVal < 0)
		{
			charOverFlow(literal);
			return ;
		}
		charVal = static_cast<char>(intVal);
		floatVal = static_cast<float>(intVal);
		doubleVal = static_cast<double>(intVal);
	}
	else
	{
		std::cerr << "Error: Invalid input format" << std::endl;
		return;
	}

	printConversion(charVal, intVal, floatVal, doubleVal);
}