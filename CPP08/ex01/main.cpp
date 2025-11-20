/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kderhet <kderhet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 00:15:46 by kderhet           #+#    #+#             */
/*   Updated: 2025/11/20 00:20:06 by kderhet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Span.hpp"

int main()
{
    std::cout << "Test du Sujet" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest: " << sp.longestSpan() << std::endl;

    std::cout << "\nTest Beaucoup d'elements" << std::endl;
    try {
        std::vector<int> randomVec;
        std::srand(std::time(NULL));
        for (int i = 0; i < 15000; ++i) {
            randomVec.push_back(std::rand());
        }
        Span bigSpan(15000);
        bigSpan.addNumber(randomVec.begin(), randomVec.end());

        std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest: " << bigSpan.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\nTest Erreurs (Span plein)" << std::endl;
    try {
        Span errSpan(2);
        errSpan.addNumber(1);
        errSpan.addNumber(2);
        errSpan.addNumber(3);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}