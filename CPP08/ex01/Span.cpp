/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kderhet <kderhet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 00:18:11 by kderhet           #+#    #+#             */
/*   Updated: 2025/11/20 00:23:15 by kderhet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>
#include <iostream>

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {
    _numbers.reserve(N);
}

Span::Span(const Span &src) {
    *this = src;
}

Span::~Span() {}

Span &Span::operator=(const Span &src) {
    if (this != &src) {
        this->_maxSize = src._maxSize;
        this->_numbers = src._numbers;
    }
    return *this;
}

void Span::addNumber(int n) {
    if (_numbers.size() >= _maxSize)
        throw std::length_error("Span is full");
    _numbers.push_back(n);
}

unsigned int Span::longestSpan() {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to calculate span");

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

    return (maxVal - minVal);
}

unsigned int Span::shortestSpan() {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to calculate span");

    std::vector<int> sorted = _numbers;
    
    std::sort(sorted.begin(), sorted.end());

    unsigned int minSpan = std::numeric_limits<unsigned int>::max();
    
    for (size_t i = 0; i < sorted.size() - 1; i++) {
        unsigned int diff = sorted[i + 1] - sorted[i];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}