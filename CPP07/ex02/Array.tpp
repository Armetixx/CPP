/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kderhet <kderhet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:32:31 by kderhet           #+#    #+#             */
/*   Updated: 2025/11/19 01:32:32 by kderhet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array() : _elements(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]()), _size(n)
{
}

template <typename T>
Array<T>::Array(Array const &other) : _elements(NULL), _size(0)
{
    *this = other;
}

template <typename T>
Array<T>::~Array()
{
    if (_elements)
        delete[] _elements;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
    if (this != &other)
    {
        if (_elements)
            delete[] _elements;
        
        _size = other._size;
        if (_size > 0)
        {
            _elements = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
                _elements[i] = other._elements[i];
        }
        else
            _elements = NULL;
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::exception();
    return _elements[index];
}

template <typename T>
T const &Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::exception();
    return _elements[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

#endif
