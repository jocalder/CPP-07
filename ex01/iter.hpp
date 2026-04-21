/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:14:02 by jocalder          #+#    #+#             */
/*   Updated: 2026/04/21 11:28:50 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T, typename F>
void	iter(T *array, const int lenght, F function)
{
	if (!array || lenght < 0)
		return ;
	for (int i = 0; i < lenght; i++)
		function(array[i]);
}

template <typename T, typename F>
void	iter(const T *array, const int lenght, F function)
{
	if (!array || lenght < 0)
		return ;
	for (int i = 0; i < lenght; i++)
		function(array[i]);
}

#endif