/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:05:44 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2025/06/05 23:27:17 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T> void swap(T& n1, T& n2)
{
	T temp = n1;
	n1 = n2;
	n2 = temp;
}

template <typename T> T min(T& n1, T& n2)
{
	if (n1 < n2)
	{
		return (n1);
	}
	return (n2);
}

template <typename T> T max(T& n1, T& n2)
{
	if (n1 > n2)
	{
		return (n1);
	}
	return (n2);
}

#endif
