/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:05:44 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/06/06 09:24:04 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

/* @------------------------------------------------------------------------@ */
/* |                            Include Section                             | */
/* @------------------------------------------------------------------------@ */

#include <cstddef>		// For std::size_t
#include <exception>	// For std::exception

/* @------------------------------------------------------------------------@ */
/* |                             Class Section                              | */
/* @------------------------------------------------------------------------@ */

template <typename T>
class Array
{
	public:
		Array(unsigned int size);
		Array();
		~Array();
		Array(const Array& that);

		Array&			operator=(const Array& that);
		const T&		operator[](const unsigned int index) const;
		T&				operator[](const unsigned int index);
		void*			operator new[](const std::size_t size);

		std::size_t	size() const;

		class OutOfBoundsException : public std::exception
		{
			public:
				OutOfBoundsException(const int newIndex, const int newElementsSize);
				virtual ~OutOfBoundsException() throw();

				virtual const char*	what() const throw();

			private:
				const int	index;
				const int	elementsSize;
		};

	private:
		T*			elements;
		std::size_t	elementsSize;
};

#include "Array.tpp"

#endif

