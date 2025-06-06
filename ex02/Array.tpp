/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:05:44 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/06/06 00:40:38 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"
#include <iostream>		// For std::cout
#include <exception>	// For std::exception
#include <sstream>		// For std::streamstring

// Helper macro to turn off OCF messages
#ifdef QUIET
# define OCF_MESSAGE(X)
#else
# define OCF_MESSAGE(X) std::cout << (X) << std::endl
#endif

template <typename T>
Array<T>::Array(unsigned int size) :
	elements(new T[size]()),
	elementsSize(size)
{
	OCF_MESSAGE("Array constructor called");
}

template <typename T>
Array<T>::Array() :
	elements(new T[0]()),
	elementsSize(0)
{
	OCF_MESSAGE("Array Default constructor called");
}

template <typename T>
Array<T>::~Array()
{
	OCF_MESSAGE("Array Destructor called");
	delete[] elements;
}

template <typename T>
Array<T>::Array(const Array& that)
{
	OCF_MESSAGE("Array Copy constructor called");
	elements = new T[that.elementsSize];

	for (std::size_t i = 0; i < that.elementsSize; ++i)
	{
		elements[i] = that.elements[i];
	}

	elementsSize = that.elementsSize;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& that)
{
	OCF_MESSAGE("Array Assigment operator constructor called");
	if (this != &that)
	{
		delete[] elements;

		elements = new T[that.elementsSize];
		for (std::size_t i = 0; i < that.elementsSize; ++i)
		{
			elements[i] = that.elements[i];
		}

		elementsSize = that.elementsSize;
	}
	return (*this);
}

template <typename T>
const T&	Array<T>::operator[](const unsigned int index) const
{
	if (index >= elementsSize)
	{
		throw(OutOfBoundsException(index, elementsSize));
	}
	return (elements[index]);
}

template <typename T>
T&	Array<T>::operator[](const unsigned int index)
{
	if (index >= elementsSize)
	{
		throw(OutOfBoundsException(index, elementsSize));
	}
	return (elements[index]);
}

template <typename T>
void*	Array<T>::operator new[](const std::size_t size)
{
	return (new T[size]);
}

template <typename T>
std::size_t	Array<T>::size() const
{
	return (elementsSize);
}

template <typename T>
Array<T>::OutOfBoundsException::OutOfBoundsException(const int newIndex, const int newElementsSize) :
	index(newIndex),
	elementsSize(newElementsSize)
{
	OCF_MESSAGE("OutOfBoundsException constructor called");
}

template <typename T>
Array<T>::OutOfBoundsException::~OutOfBoundsException() throw()
{
	OCF_MESSAGE("OutOfBoundsException Destructor called");
}

template <typename T>
const char*	Array<T>::OutOfBoundsException::what() const throw()
{
	static std::string message;

	std::stringstream ss;

	ss << "Index out of bounds! Expected index [0, " << elementsSize << "). ";
	ss << "Received index " << index;
	message = ss.str();

	return message.c_str();
}

#endif
