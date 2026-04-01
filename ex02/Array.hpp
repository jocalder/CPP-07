/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <jocalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:59:27 by jocalder          #+#    #+#             */
/*   Updated: 2026/04/01 17:34:37 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <ctime>

template <typename T>
class	Array
{
	private:
		T*				_data;
		unsigned int	_size;
	public:
		Array(): _data(NULL), _size(0) {}
		Array(unsigned int n): _data(NULL), _size(n)
		{
			if (_size > 0)
				_data = new T[_size];
		}
		Array(const Array& other): _data(NULL), _size(0)
		{
			*this = other;
		}
		Array&	operator=(const Array& other)
		{
			if (this != &other)
			{
				delete[] _data;
				_size = other._size;
				_data = NULL;
				if (_size > 0)
				{
					_data = new T[_size];
					for (unsigned int i = 0; i < _size; i++)
						_data[i] = other._data[i];
				}
			}
			return *this;
		}
		~Array() {delete[] _data;}

		T&	operator[](unsigned int index)
		{
			if (index >= _size)
				throw std::exception();
			return (_data[index]);
		}
		const T&	operator[](unsigned int index) const
		{
			if (index >= _size)
				throw std::exception();
			return (_data[index]);
		}
		
		unsigned int	getSize() const {return _size;}
};



#endif