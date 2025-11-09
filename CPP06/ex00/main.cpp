/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kderhet <kderhet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 02:20:41 by kderhet           #+#    #+#             */
/*   Updated: 2025/11/06 02:20:47 by kderhet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
    
    std::cout << "Input: " << argv[1] << std::endl;
    std::cout << "----------" << std::endl;
    ScalarConverter::convert(argv[1]);
    
    return 0;
}