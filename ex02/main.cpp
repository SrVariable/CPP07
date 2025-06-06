/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 02:56:39 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/06/06 09:30:51 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>	// For std::cout, std::cerr
#include <cctype>	// For std::toupper
#include <cstdlib>	// For srand, rand, time

// Helper macro to pretty-print tests
#define PP_TEST(testIndex) do{\
	std::string testName((__func__));\
	std::cout << "\033[38;2;255;128;255m- Test " << (testIndex)\
	<< " (" << testName.substr(4) << "):\033[0m" << std::endl;\
} while(0)

// Helper macro to pretty-print caught exceptions
#define PP_EXCEPTION(exception) do{\
	std::cerr << "\033[31m" << (__FILE__) << ":" << (__LINE__) << "\033[0m"\
	<< ": Exception caught. Reason:\033[0m " << (exception).what() << std::endl;\
} while(0)

#define MAX_VAL 750
void	testDefault(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		//std::cerr << e.what() << '\n';
		PP_EXCEPTION(e);
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		//std::cerr << e.what() << '\n';
		PP_EXCEPTION(e);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//

}
#undef MAX_VAL

void	testEmptyIntArray(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Array<int> array;
	std::cout << "Array size: " << array.size() << std::endl;
}

void	testIntArrayOfFive(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Array<int> array(5);
	std::cout << "Array size: " << array.size() << std::endl;

	for (std::size_t i = 0; i < array.size(); ++i)
	{
		std::cout << "Array[" << i << "]: " << array[i] << std::endl;
	}
}

void	testCopyArray(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Array<int> array;
	std::cout << "Array size: " << array.size() << std::endl;

	Array<int> array2(array);
	std::cout << "Array size: " << array.size() << std::endl;
	for (std::size_t i = 0; i < array2.size(); ++i)
	{
		std::cout << "Array[" << i << "]: " << array2[i] << std::endl;
	}
}

void	testAssignArray(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Array<int> array;
	std::cout << "Array size: " << array.size() << std::endl;

	array = Array<int>(5);
	std::cout << "Array size: " << array.size() << std::endl;
	for (std::size_t i = 0; i < array.size(); ++i)
	{
		std::cout << "Array[" << i << "]: " << array[i] << std::endl;
	}
}

void	testAssignArrayValues(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Array<int> array(20);
	std::cout << "Array size: " << array.size() << std::endl;

	for (std::size_t i = 0; i < array.size(); ++i)
	{
		array[i] = i * i;
		std::cout << "Array[" << i << "]: " << array[i] << std::endl;
	}
}

void	testAssignArrayValuesOutOfBounds(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Array<int> array(20);
	std::cout << "Array size: " << array.size() << std::endl;

	std::size_t i = 0;
	for (; i < array.size(); ++i)
	{
		array[i] = i * i;
		std::cout << "Array[" << i << "]: " << array[i] << std::endl;
	}

	try
	{
		array[i] = 1;
	}
	catch (const std::exception& e)
	{
		PP_EXCEPTION(e);
	}
}

void	testIndexArray(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Array<int> array(20);
	std::cout << "Array size: " << array.size() << std::endl;

	std::cout << "Array[5]: " << array[5] << std::endl;
}

void	testIndexArrayOutOfBounds(std::size_t testIndex)
{
	PP_TEST(testIndex);

	Array<int> array(20);
	std::cout << "Array size: " << array.size() << std::endl;

	try
	{
		std::cout << "Array[25]: " << array[25] << std::endl;
	}
	catch (const std::exception& e)
	{
		PP_EXCEPTION(e);
	}
}

int main()
{
	std::size_t testIndex = 0;

	testDefault(testIndex++);
	testEmptyIntArray(testIndex++);
	testIntArrayOfFive(testIndex++);
	testCopyArray(testIndex++);
	testAssignArray(testIndex++);
	testAssignArrayValues(testIndex++);
	testAssignArrayValuesOutOfBounds(testIndex++);
	testIndexArray(testIndex++);
	testIndexArrayOutOfBounds(testIndex++);

	return (0);
}
