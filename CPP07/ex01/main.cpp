/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kderhet <kderhet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:18:17 by kderhet           #+#    #+#             */
/*   Updated: 2025/11/19 01:18:44 by kderhet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(T const &x)
{
    std::cout << x << std::endl;
}

template <typename T>
void increment(T &x)
{
    x++;
}

void toUpper(std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
}

int main(void)
{
    std::cout << "Test 1: Array of int with print" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    iter(intArray, 5, print<int>);
    
    std::cout << "\nTest 2: Array of double with print" << std::endl;
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    iter(doubleArray, 4, print<double>);
    
    std::cout << "\nTest 3: Array of string with print" << std::endl;
    std::string strArray[] = {"hello", "world", "from", "templates"};
    iter(strArray, 4, print<std::string>);
    
    std::cout << "\nTest 4: Increment int array" << std::endl;
    std::cout << "Before: ";
    for (int i = 0; i < 5; i++)
        std::cout << intArray[i] << " ";
    std::cout << std::endl;
    
    iter(intArray, 5, increment<int>);
    
    std::cout << "After: ";
    for (int i = 0; i < 5; i++)
        std::cout << intArray[i] << " ";
    std::cout << std::endl;
    
    std::cout << "\nTest 5: toUpper on string array" << std::endl;
    std::cout << "Before: ";
    for (int i = 0; i < 4; i++)
        std::cout << strArray[i] << " ";
    std::cout << std::endl;
    
    iter(strArray, 4, toUpper);
    
    std::cout << "After: ";
    for (int i = 0; i < 4; i++)
        std::cout << strArray[i] << " ";
    std::cout << std::endl;
    
    return 0;
}