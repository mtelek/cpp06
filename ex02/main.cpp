/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:30:47 by mtelek            #+#    #+#             */
/*   Updated: 2025/07/31 22:26:47 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	Base* obj = generate();

	std::cout << "Pointer type: ";
	identify(obj);

	std::cout << "Reference type: ";
	identify(*obj);

	delete (obj);
	return (0);
}
