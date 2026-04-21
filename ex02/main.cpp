/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 17:00:18 by jocalder          #+#    #+#             */
/*   Updated: 2026/04/21 12:07:12 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750

template <typename T>
void	printArray(const Array<T>& array, const std::string& name)
{
	std::cout << name << "(size = " << array.getSize() << ") ";
	for (unsigned int i = 0; i < array.getSize(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}
int main(int, char**)
{
	std::cout << "TEST 1: SUBJECT MAIN" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
	std::cout << "TEST 2: EMPTY ARRAY" << std::endl;
	Array<int>	empty;
	std::cout << "empty.size() = " << empty.getSize() << std::endl;
	try
	{
		std::cout << empty[0] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception empty[0]: " << e.what() << std::endl;
	}

	std::cout << "TEST 3: INT ARRAY TEST" << std::endl;
	Array<int>	values(5);
	
	for (unsigned int i = 0; i < values.getSize(); i++)
		values[i] = i * 10;
	printArray(values, "small array");
	
	std::cout << "TEST 4: COPY CONSTRUCTOR" << std::endl;
	Array<int>	copy(values);
	printArray(copy, "copy of values before change");

	values[0] = 42;
	printArray(values, "value after change");
	printArray(copy, "copy after original changed");

	if (copy[0] != values[0])
		std::cout << "Copy works in copy constructor." << std::endl;
	else
		std::cout << "ERROR: copy detected in copy constructor." << std::endl;
	
	std::cout << "TEST 5: ASSIGMENT OPERATOR" << std::endl;
	Array<int>	assigned;

	assigned = values;
	printArray(assigned, "assigned array before change");

	values[1] = 34;
	printArray(values, "values after change");
	printArray(assigned, "assigned after original changed");

	if (assigned[1] != values[1])
		std::cout << "Assigment works in constructor." << std::endl;
	else
		std::cout << "ERROR: copy detected in assigment constructor." << std::endl;
	
	std::cout << "TEST 6: STRING ARRAY" << std::endl;
	Array<std::string> words(4);
	words[0] = "hello ";
	words[1] = "this ";
	words[2] = "is ";
	words[3] = "42.";
	printArray(words, "words before change");

	Array<std::string> copyWords(words);
	printArray(copyWords, "copy words before change");
	
	words[0] = "hi ";
	printArray(words, "words after change");
	printArray(copyWords, "copy words after original changed");

	if (words[0] != copyWords[0])
		std::cout << "Copy works in copy constructor." << std::endl;
	else
		std::cout << "ERROR: shallow copy detected in copy constructor." << std::endl;
	
    return 0;
}