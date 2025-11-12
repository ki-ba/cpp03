/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:39:23 by kbarru            #+#    #+#             */
/*   Updated: 2025/10/21 13:54:27 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#define REPAIR_AMOUNT 5
#define MAX_TURNS 20

int	main(void)
{
	std::string	seed = "464711149";
	int			i = 0;
	ScavTrap	davin("Davin");
	ClapTrap	steve("Steve");
	

	std::cout << std::endl << " <-- COMBAT START --> " << std::endl << std::endl;

	while(i < MAX_TURNS && (davin.getEnergyPoints() > 0 || steve.getEnergyPoints() > 0) && davin.getHitPoints() > 0 && steve.getHitPoints() > 0)
	{
		if (i % 2 == 0)
		{
			// std::cout << i << " is even : Davin's turn" << std::endl;
			if (i < 2)
				davin.guardGate();
			else if ((seed[i % seed.length()]) % 2 == 0)
			{
				// std::cout << seed[i % seed.length()] << " is even : attack" << std::endl;
				davin.attack(steve.getName());
				steve.takeDamage(davin.getAttackDamage());
			}
			else
			{
				// std::cout << seed[i % seed.length()] << " is odd: repairs" << std::endl;
				davin.beRepaired(REPAIR_AMOUNT);
			}
		}
		else
		{
			// std::cout << i << " is odd : Steve's turn" << std::endl;
			if ((seed[i % seed.length()]) % 2 == 0)
			{
				// std::cout << seed[i % seed.length()] << " is even : attack" << std::endl;
				steve.attack(davin.getName());
				davin.takeDamage(steve.getAttackDamage());
			}
			else
			{
				// std::cout << seed[i % seed.length()] << " is odd: repairs" << std::endl;
				steve.beRepaired(REPAIR_AMOUNT);
			}
		}
		++i;
	}

	std::cout << std::endl << " <-- COMBAT END --> " << std::endl << std::endl;
}
