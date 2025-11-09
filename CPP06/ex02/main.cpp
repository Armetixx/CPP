/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kderhet <kderhet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 00:09:44 by kderhet           #+#    #+#             */
/*   Updated: 2025/11/10 00:10:52 by kderhet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
    int random = rand() % 3;
    
    if (random == 0)
    {
        std::cout << "Generated: A" << std::endl;
        return new A();
    }
    else if (random == 1)
    {
        std::cout << "Generated: B" << std::endl;
        return new B();
    }
    else
    {
        std::cout << "Generated: C" << std::endl;
        return new C();
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    }
    catch(const std::exception& e) {}
    
    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    }
    catch(const std::exception& e) {}
    
    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    }
    catch(const std::exception& e) {}
}

int main()
{
    srand(time(NULL));
    
    std::cout << "Test 1:" << std::endl;
    Base* obj1 = generate();
    std::cout << "Identify with pointer: ";
    identify(obj1);
    std::cout << "Identify with reference: ";
    identify(*obj1);
    delete obj1;
    
    std::cout << std::endl << "Test 2:" << std::endl;
    Base* obj2 = generate();
    std::cout << "Identify with pointer: ";
    identify(obj2);
    std::cout << "Identify with reference: ";
    identify(*obj2);
    delete obj2;
    
    std::cout << std::endl << "Test 3:" << std::endl;
    Base* obj3 = generate();
    std::cout << "Identify with pointer: ";
    identify(obj3);
    std::cout << "Identify with reference: ";
    identify(*obj3);
    delete obj3;
    
    return 0;
}