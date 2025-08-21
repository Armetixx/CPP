/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kderhet <kderhet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 23:34:01 by kderhet           #+#    #+#             */
/*   Updated: 2025/08/21 00:19:16 by kderhet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): 
                Name("DefaultName"), HitPoints(10), EnergyPoints(10), AttackDmg(0)
{
    std::cout << "ClapTrap " << this->Name << " created with default constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other): 
                Name(other.Name), HitPoints(other.HitPoints), 
                    EnergyPoints(other.EnergyPoints), AttackDmg(other.AttackDmg)
{
    std::cout << "ClapTrap " << this->Name << " created with copy constructor" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        this->Name = other.Name;
        this->HitPoints = other.HitPoints;
        this->EnergyPoints = other.EnergyPoints;
        this->AttackDmg = other.AttackDmg;
    }
    return (*this);
}

ClapTrap::ClapTrap(std::string clapName) : 
                Name(clapName), HitPoints(10), EnergyPoints(10), AttackDmg(0)
{
    std::cout<< "ClapTrap " << this->Name << " created" << std::endl;

}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->Name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->EnergyPoints <= 0 || this->HitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->Name << " has not enough EnergyPoints or HitPoints to attack." << std::endl;
        return;
    }
    this->EnergyPoints -= 1;
    std::cout << "ClapTrap " << this->Name << " attacks "<< target << ", causing " << this->AttackDmg << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount >= this->HitPoints)
        this->HitPoints = 0;
    else
        this->HitPoints -= amount;
    std::cout << "ClapTrap " << this->Name << " took " << amount << " of damage and is now at " << this->HitPoints << "." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->EnergyPoints <= 0 || this->HitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->Name << " has not enough EnergyPoints or HitPoints to be repaired." << std::endl;
        return;
    }
    this->EnergyPoints--;
    this->HitPoints += amount;
    std::cout << "ClapTrap " << this->Name << " repaired for " << amount << " of hitpoints and is now at " << this->HitPoints << "." << std::endl;
}