#include "iter.hpp"
#include <iostream>	// For std::cout, std::cerr
#include <cctype>	// For std::toupper

// Helper macro to pretty-print tests
#define PP_TEST(testIndex) do{\
	std::string testName((__func__));\
	std::cout << "\033[38;2;255;128;255m- Test " << (testIndex)\
	<< " (" << testName.substr(4) << "):\033[0m" << std::endl;\
} while(0)

// No lambda functions in C++98 :c
void squareIntHelper(int& n)
{
	n *= n;
}

void	testSquareIntArray(std::size_t testIndex)
{
	PP_TEST(testIndex);

	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::size_t size = sizeof(array) / sizeof(*array);
	::iter(array, size, squareIntHelper);

	int expected[] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
	for (std::size_t i = 0; i < size; ++i)
	{
		if (array[i] != expected[i])
		{
			std::cerr << "Expected: " << expected[i] << ", but got: " << array[i] << std::endl;
		}
		else
		{
			std::cout << array[i] << std::endl;
		}
	}
}

void upperStringHelper(std::string& s)
{
	std::size_t size = s.size();

	for (std::size_t i = 0; i < size; ++i)
	{
		s[i] = static_cast<unsigned char>(std::toupper(s[i]));
	}
}

void	testUpperStringArray(std::size_t testIndex)
{
	PP_TEST(testIndex);

	std::string array[] = {
		"Hello",
		"World",
		"How",
		"aRe",
		"you",
	};
	std::size_t size = sizeof(array) / sizeof(*array);
	::iter(array, size, upperStringHelper);

	const std::string expected[] = {
		"HELLO",
		"WORLD",
		"HOW",
		"ARE",
		"YOU",
	};
	for (std::size_t i = 0; i < size; ++i)
	{
		if (array[i] != expected[i])
		{
			std::cerr << "Expected: " << expected[i] << ", but got: " << array[i] << std::endl;
		}
		else
		{
			std::cout << array[i] << std::endl;
		}
	}
}

void printStringHelper(const std::string& s)
{
	std::cout << s << std::endl;
}

void	testPrintString(std::size_t testIndex)
{
	PP_TEST(testIndex);

	std::string array[] = {
		"This",
		"Is",
		"A",
		"Really",
		"Long",
		"String",
		"Don't",
		"You",
		"Think",
		"So?",
	};
	std::size_t size = sizeof(array) / sizeof(*array);
	::iter(array, size, printStringHelper);
}

int main( void )
{
	std::size_t testIndex = 0;

	testSquareIntArray(testIndex++);
	testUpperStringArray(testIndex++);
	testPrintString(testIndex++);
}
