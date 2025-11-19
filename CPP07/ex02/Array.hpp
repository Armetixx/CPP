/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kderhet <kderhet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:30:05 by kderhet           #+#    #+#             */
/*   Updated: 2025/11/19 01:30:06 by kderhet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstddef>

template <typename T>
class Array
{
private:
    T *_elements;
    unsigned int _size;

public:
    Array();
    Array(unsigned int n);
    Array(Array const &other);
    ~Array();
    
    Array &operator=(Array const &other);
    T &operator[](unsigned int index);
    T const &operator[](unsigned int index) const;
    unsigned int size() const;
};

#include "Array.tpp"

#endif