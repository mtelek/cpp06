/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:01:16 by mtelek            #+#    #+#             */
/*   Updated: 2025/07/29 15:32:59 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

enum Type { CHAR, INT, FLOAT, DOUBLE, INVALID };

Type detectType(const std::string& str)
{
	if (str == "nanf" || str == "inff" || str == "+inff" || str == "-inff") 
		return (FLOAT);
	if (str == "nan" || str == "inf" || str == "+inf" || str == "-inf") 
		return (DOUBLE);
	if (str.length() == 1 && !isdigit(str[0])) 
		return (CHAR);

	size_t f_pos = str.find('f');
	if (f_pos != std::string::npos && f_pos == str.length()-1)
		return (FLOAT);

	if (str.find('.') != std::string::npos || 
		str.find('e') != std::string::npos ||
		str.find('E') != std::string::npos)
		return (DOUBLE);
	return (INT);
}

bool convertToValue(const std::string& str, double& value)
{
	Type type = detectType(str);

	switch(type)
	{
		case CHAR:
		{
			value = static_cast<double>(str[0]);
			return (true);
		}
		case INT:
		{
			char* endPtr;
			long l = strtol(str.c_str(), &endPtr, 10);
			if (*endPtr || l > INT_MAX || l < INT_MIN)
				return (true);
			value = static_cast<double>(l);
			return (true);
		}
		case FLOAT:
		{
			char* endPtr;
			float f = strtof(str.c_str(), &endPtr);
			if ((*endPtr && *endPtr != 'f') || endPtr == str.c_str())
				return (false);
			value = static_cast<double>(f);
			return (true);
		}
		case DOUBLE:
		{
			char* endPtr;
			value = strtod(str.c_str(), &endPtr);
			if (*endPtr || endPtr == str.c_str())
				return (false);
			return (true);
		}
		case INVALID:
			return (false);
	}
	return (false);
}

bool ScalarConverter::convert(const std::string& str) 
{
	double value;

	if (!convertToValue(str, value))
		return (false);

	// CHAR conversion
	std::cout << "char: ";
	if (isnan(value) || isinf(value))
		std::cout << "impossible";
	else if (value < CHAR_MIN || value > CHAR_MAX)
		std::cout << "impossible (out of range)";
	else if (!isprint(static_cast<char>(value)))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(value) << "'";
	std::cout << std::endl;

	// INT conversion
	std::cout << "int: ";
	if (isnan(value) || isinf(value))
		std::cout << "impossible";
	else if (value < INT_MIN || value > INT_MAX)
		std::cout << "impossible (out of range)";
	else
		std::cout << static_cast<int>(value);
	std::cout << std::endl;

	// FLOAT conversion
	std::cout << "float: ";
	if (isinf(value))
		std::cout << (value > 0 ? "inff" : "-inff");
	else if (isnan(value))
		std::cout << "nanf";
	else if ((value > 0 && value > FLT_MAX) || (value < 0 && value < -FLT_MAX))
		std::cout << "impossible (overflow)";
	else
	{
		if (fabs(value) > 1e7f)
			std::cout << std::scientific << std::setprecision(8) << static_cast<float>(value) << "f";
		else
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f";
	}
	std::cout << std::endl;

	// DOUBLE conversion
	std::cout << "double: ";
	if (isinf(value))
		std::cout << (value > 0 ? "inf" : "-inf");
	else if (isnan(value))
		std::cout << "nan";
	else if ((value > 0 && (value / DBL_MAX > 1.0)) || (value < 0 && (value / -DBL_MAX > 1.0)))
		std::cout << "impossible (overflow)";
	else
	{
		if (fabs(value) > 1e15)
			std::cout << std::scientific << std::setprecision(15) << value;
		else
			std::cout << std::fixed << std::setprecision(1) << value;
	}
	std::cout << std::endl;
	return (true);
}
