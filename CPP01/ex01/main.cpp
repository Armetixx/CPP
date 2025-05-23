/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armetix <armetix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:09:45 by armetix           #+#    #+#             */
/*   Updated: 2025/04/21 13:23:11 by armetix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int i;
	int N;
	Zombie	*horde;

	N = 5;
	i = 0;
	horde = zombieHorde(N, "Blub");
	if (horde)
	{
		while(i < N)
		{
			horde[i].announce();
			i++;
		}
		delete[] horde;
	}
	return (0);
}