/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:57:44 by jocalder          #+#    #+#             */
/*   Updated: 2026/04/01 16:23:58 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
void	swap(T &a, T &b)
{
	T	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T const	&min(T const &a, T const &b)
{
	if (a < b)
		return a;
	return b;
}

template <typename T>
T const	&max(T const &a, T const &b)
{
	if (a > b)
		return a;
	return b;
}

#endif