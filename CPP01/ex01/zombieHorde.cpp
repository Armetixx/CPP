/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armetix <armetix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:00:11 by armetix           #+#    #+#             */
/*   Updated: 2025/04/21 13:26:10 by armetix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	int i;
	if (N <= 0)
		return (NULL);
	Zombie	*horde;
	
	horde = new Zombie[N];
	i = 0;
	while(i < N)
	{
		horde[i].setName(name);
		i++;
	}
	return (horde);
}