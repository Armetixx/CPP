/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kderhet <kderhet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 00:20:26 by kderhet           #+#    #+#             */
/*   Updated: 2025/08/21 02:01:03 by kderhet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap Scav1("Rob1");
    ScavTrap Scav2("Rob2");

    Scav1.attack("dummy");
    Scav1.guardGate();
    Scav2.takeDamage(5);
    Scav2.beRepaired(4);
    Scav1.takeDamage(10);
    Scav1.beRepaired(10);
    Scav1.attack("dummy");
    for (int i = 0; i < 10; i++)
        Scav2.attack("dummy");
    
    return 0;
}
