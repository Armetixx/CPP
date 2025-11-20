/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kderhet <kderhet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 00:15:57 by kderhet           #+#    #+#             */
/*   Updated: 2025/11/20 00:17:18 by kderhet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator> 

class Span {
private:
    unsigned int        _maxSize;
    std::vector<int>    _numbers;

public:
    Span();
    Span(unsigned int N);
    Span(const Span &src);
    ~Span();

    Span &operator=(const Span &src);

    void addNumber(int n);
    
    template <typename Iterator>
    void addNumber(Iterator begin, Iterator end) {
        if (std::distance(begin, end) + _numbers.size() > _maxSize) {
            throw std::length_error("Span is full (range add)");
        }
        _numbers.insert(_numbers.end(), begin, end);
    }

    unsigned int shortestSpan();
    unsigned int longestSpan();
};

#endif