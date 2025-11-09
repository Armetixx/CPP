/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kderhet <kderhet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:43:04 by kderhet           #+#    #+#             */
/*   Updated: 2025/11/09 23:46:47 by kderhet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data originalData;
    originalData.id = 42;
    originalData.name = "Test Data";
    originalData.value = 3.14159;
    
    std::cout << "Original Data:" << std::endl;
    std::cout << "Address: " << &originalData << std::endl;
    std::cout << "ID: " << originalData.id << std::endl;
    std::cout << "Name: " << originalData.name << std::endl;
    std::cout << "Value: " << originalData.value << std::endl;
    std::cout << std::endl;
    
    uintptr_t serialized = Serializer::serialize(&originalData);
    std::cout << "Serialized value: " << serialized << std::endl;
    std::cout << std::endl;
    
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "Address: " << deserialized << std::endl;
    std::cout << "ID: " << deserialized->id << std::endl;
    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << "Value: " << deserialized->value << std::endl;
    std::cout << std::endl;
    
    if (deserialized == &originalData)
        std::cout << "SUCCESS: Deserialized pointer matches original pointer" << std::endl;
    else
        std::cout << "ERROR: Pointers don't match" << std::endl;
    
    return 0;
}
