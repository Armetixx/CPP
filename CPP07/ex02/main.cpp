/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kderhet <kderhet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:33:14 by kderhet           #+#    #+#             */
/*   Updated: 2025/11/19 01:35:30 by kderhet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

int main(void)
{
    std::cout << "Test 1: Empty array" << std::endl;
    Array<int> empty;
    std::cout << "Size: " << empty.size() << std::endl;
    
    std::cout << "\nTest 2: Array with size" << std::endl;
    Array<int> numbers(5);
    std::cout << "Size: " << numbers.size() << std::endl;
    std::cout << "Default values: ";
    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;
    
    std::cout << "\nTest 3: Modification" << std::endl;
    for (unsigned int i = 0; i < numbers.size(); i++)
        numbers[i] = i * 10;
    std::cout << "Modified values: ";
    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;
    
    std::cout << "\nTest 4: Copy constructor" << std::endl;
    Array<int> copy(numbers);
    std::cout << "Copy size: " << copy.size() << std::endl;
    std::cout << "Copy values: ";
    for (unsigned int i = 0; i < copy.size(); i++)
        std::cout << copy[i] << " ";
    std::cout << std::endl;
    
    std::cout << "\nTest 5: Deep copy verification" << std::endl;
    copy[0] = 999;
    std::cout << "Original[0]: " << numbers[0] << std::endl;
    std::cout << "Copy[0]: " << copy[0] << std::endl;
    std::cout << "Arrays are independent: " << (numbers[0] != copy[0] ? "YES" : "NO") << std::endl;
    
    std::cout << "\nTest 6: Assignment operator" << std::endl;
    Array<int> assigned;
    assigned = numbers;
    std::cout << "Assigned size: " << assigned.size() << std::endl;
    std::cout << "Assigned values: ";
    for (unsigned int i = 0; i < assigned.size(); i++)
        std::cout << assigned[i] << " ";
    std::cout << std::endl;
    
    std::cout << "\nTest 7: Out of bounds exception" << std::endl;
    try
    {
        std::cout << "Trying to access index 10..." << std::endl;
        std::cout << numbers[10] << std::endl;
        std::cout << "ERROR: Should have thrown exception!" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught successfully!" << std::endl;
    }
    
    std::cout << "\nTest 8: Array of strings" << std::endl;
    Array<std::string> strings(3);
    strings[0] = "Hello";
    strings[1] = "World";
    strings[2] = "!";
    std::cout << "String array: ";
    for (unsigned int i = 0; i < strings.size(); i++)
        std::cout << strings[i] << " ";
    std::cout << std::endl;
    
    std::cout << "\nTest 9: Const array" << std::endl;
    Array<int> const constArray(numbers);
    std::cout << "Const array values: ";
    for (unsigned int i = 0; i < constArray.size(); i++)
        std::cout << constArray[i] << " ";
    std::cout << std::endl;
    
    std::cout << "\nTest 10: Self assignment" << std::endl;
    assigned = assigned;
    std::cout << "Self assignment OK, size: " << assigned.size() << std::endl;
    
    return 0;
}