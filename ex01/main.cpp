/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:13:47 by jocalder          #+#    #+#             */
/*   Updated: 2026/04/01 16:56:20 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	printInt(const int n)
{
	std::cout << n << " ";
}

void	incrementInt(int &n)
{
	n++;
}

void	printString(const std::string &str)
{
	std::cout << str << " ";
}

void	toUpper(std::string &str)
{
	int		i = 0;
	while (str[i])
	{
		if (!str.empty() && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
}
template <typename T>
void	printGeneric(const T& value)
{
	std::cout << value << " ";
}

int	main()
{
	std::cout << "TEST 1: int aray / print" << std::endl;
	int		numbers[] = {1, 2, 3, 4, 5};
	int		numbersLen = sizeof(numbers) / sizeof(numbers[0]);
	
	iter(numbers, numbersLen, printInt);
	std::cout << std::endl;

	std::cout << "TEST 2: int array / increment" << std::endl;
	iter(numbers, numbersLen, incrementInt);
	iter(numbers, numbersLen, printInt);
	std::cout << std::endl;
	
	std::cout << "TEST 3: string array / print" << std::endl;
	std::string	words[] = {"hola", "carnal", "como estas"};
	int			wordsLen = sizeof(words) / sizeof(words[0]);

	iter(words, wordsLen, printString);
	std::cout << std::endl;
	
	std::cout << "TEST 4: string array / modify" << std::endl;
	iter(words, wordsLen, toUpper);
	iter(words, wordsLen, printString);
	std::cout << std::endl;

	std::cout << "TEST 5: const array / print generic" << std::endl;
	const double	values[] = {3.14, 4.2, 5.42, -2.0};
	int				valuesLen = sizeof(values) / sizeof(values[0]);

	iter(values, valuesLen, printGeneric<double>);
	std::cout << std::endl;

	std::cout << "TEST 6: null pointer" << std::endl;
	int		*nullpointer = NULL;
	
	iter(nullpointer, 5, printInt);
	std::cout << "No crash with Null pointer" << std::endl;
	return 0;
}