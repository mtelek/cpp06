/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:27:09 by mtelek            #+#    #+#             */
/*   Updated: 2025/07/29 18:48:24 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data original = {42, "Test Object"};

	// Serialize the pointer
	uintptr_t serialized = Serializer::serialize(&original);
	std::cout << "Serialized: " << serialized << std::endl;

	// Deserialize back to a pointer
	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized: " << deserialized << std::endl;

	// Verify pointer equality
	// TEST 1
	if (deserialized == &original)
		std::cout << "Pointers match" << std::endl;
	else
		std::cout << "Pointers differ" << std::endl;
	// TEST 2
	assert(deserialized == &original);

	// Verify data integrity
	std::cout << "Data: value=" << deserialized->value 
				<< ", name=" << deserialized->name << std::endl;

	return (0);
}
