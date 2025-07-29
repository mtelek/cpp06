/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:52:13 by mtelek            #+#    #+#             */
/*   Updated: 2025/07/29 18:16:59 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void testConversion(const std::string& input)
{
	std::cout << "Testing: " << input << "\n";
	std::cout << "--------------------------------\n";
	ScalarConverter::convert(input);
	std::cout << "--------------------------------\n\n";
}


int main()
{
	// Test character literals
	testConversion("a");
	testConversion("Z");
	testConversion(" ");
	testConversion("~");

	// Test integer literals
	testConversion("0");
	testConversion("42");
	testConversion("-42");
	testConversion("2147483637");
	testConversion("2147483648");
	testConversion("2147483648");  // INT_MAX + 1
	testConversion("-2147483649"); // INT_MIN - 1

	// Test float literals
	testConversion("0.0f");
	testConversion("42.5f");
	testConversion("-42.5f");
	testConversion("3.40282e38f");   // Near FLT_MAX
	testConversion("3.40283e38f");   // Exceeds FLT_MAX
	testConversion("-3.40283e38f");  // Exceeds -FLT_MAX

	// Test double literals
	testConversion("0.0");
	testConversion("42.5");
	testConversion("-42.5");
	testConversion("1.79769e308");   // Near DBL_MAX
	testConversion("1.7977e308");    // Exceeds DBL_MAX
	testConversion("-1.7977e308");   // Exceeds -DBL_MAX

	// Test special float values
	testConversion("nanf");
	testConversion("inff");
	testConversion("-inff");
	testConversion("+inff");

	// Test special double values
	testConversion("nan");
	testConversion("inf");
	testConversion("-inf");
	testConversion("+inf");

	// Test invalid inputs
	testConversion("");
	testConversion("hello");
	testConversion("123abc");
	testConversion("12.34.56");
	testConversion("--42");

	// Test non-printable characters
	testConversion("\12");  // ASCII 1
	testConversion("\127"); // ASCII 127

	return (0);
}
