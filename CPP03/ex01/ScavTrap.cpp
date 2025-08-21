/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kderhet <kderhet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 01:39:07 by kderhet           #+#    #+#             */
/*   Updated: 2025/08/21 01:54:15 by kderhet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDmg = 20;
    std::cout << "ScavTrap " << this->Name << " created with default constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
{
    std::cout << "ScavTrap " << this->Name << " created with copy constructor" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return (*this);
}

ScavTrap::ScavTrap(std::string clapName) : ClapTrap(clapName)
{
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDmg = 20;
    std::cout << "ScavTrap " << this->Name << " created with constructor" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->Name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->EnergyPoints <= 0 || this->HitPoints <= 0)
    {
        std::cout << "ScavTrap " << this->Name << " has not enough EnergyPoints or HitPoints to attack." << std::endl;
        return;
    }
    this->EnergyPoints -= 1;
    std::cout << "ScavTrap " << this->Name << " attacks "<< target << ", causing " << this->AttackDmg << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->Name << " is now in Gate keeper mode" << std::endl;
}