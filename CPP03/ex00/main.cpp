/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kderhet <kderhet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 00:20:26 by kderhet           #+#    #+#             */
/*   Updated: 2025/08/21 00:30:59 by kderhet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap clap1("Rob1");
    ClapTrap clap2("Rob2");

    clap1.attack("dummy");
    clap2.takeDamage(5);
    clap2.beRepaired(4);
    clap1.takeDamage(10);
    clap1.beRepaired(10);
    clap1.attack("dummy");
    for (int i = 0; i < 10; i++)
        clap2.attack("dummy");
    
    return 0;
}
