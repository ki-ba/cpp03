/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:39:23 by kbarru            #+#    #+#             */
/*   Updated: 2025/10/21 19:04:45 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"
// #include "FragTrap.hpp"
#include "DiamondTrap.hpp"

#define REPAIR_AMOUNT 5
#define MAX_TURNS 500

void fight(ScavTrap &f1, DiamondTrap &f2, std::string seed)
{
	int			i = 0;
	std::cout << std::endl << " <-- COMBAT START --> " << std::endl << std::endl;

	while(i < MAX_TURNS && (f1.getEnergyPoints() > 0 || f2.getEnergyPoints() > 0) && f1.getHitPoints() > 0 && f2.getHitPoints() > 0)
	{
		if (i % 2 == 0)
		{
			// std::cout << i << " is even : f1's turn" << std::endl;
			if (i < 2)
				f1.guardGate();
			else if ((seed[i % seed.length()]) % 2 == 0)
			{
				// std::cout << seed[i % seed.length()] << " is even : attack" << std::endl;
				f1.attack(f2.getName());
				f2.takeDamage(f1.getAttackDamage());
			}
			else
			{
				// std::cout << seed[i % seed.length()] << " is odd: repairs" << std::endl;
				f1.beRepaired(REPAIR_AMOUNT);
			}
		}
		else
		{
			// std::cout << i << " is odd : f2's turn" << std::endl;
			if ((seed[i % seed.length()]) % 2 == 0)
			{
				// std::cout << seed[i % seed.length()] << " is even : attack" << std::endl;
				f2.attack(f1.getName());
				f1.takeDamage(f2.getAttackDamage());
			}
			else
			{
				// std::cout << seed[i % seed.length()] << " is odd: repairs" << std::endl;
				f2.beRepaired(REPAIR_AMOUNT);
			}
		}
		++i;
	}

	std::cout << std::endl << std::endl;
	if (f1.getEnergyPoints() <= 0 && f2.getEnergyPoints() <= 0)
		std::cout << "DRAW : everyone is exhausted." << std::endl << std::endl;
	else if (f1.getHitPoints() <= 0)
		std::cout << f2.getName() << " WINS : " << f1.getName() << " is dead (" << f2.getHitPoints() << " HP left)" << std::endl << std::endl;
	else if (f2.getHitPoints() <= 0)
		std::cout << f1.getName() << " WINS : " << f2.getName() << " is dead (" << f1.getHitPoints() << "HP left)" << std::endl << std::endl;
	else if (i >= MAX_TURNS)
		std::cout << "DRAW : everyone is bored." << std::endl << std::endl;

	std::cout << std::endl << " <-- COMBAT END --> " << std::endl << std::endl;
}



int	main(void)
{
	std::string	seed = "464711149";
	ScavTrap	steve("Steve");

	std::cout << std::endl << std::endl;

	DiamondTrap	davin("Davin");
	DiamondTrap	darius("Darius");

	davin = darius;
	davin.attack("the air");
	davin.whoAmI();
	// steve.whoAmI();
	// steve.highFiveGuys();
	// steve.guardGate();

	// fight(davin, steve, seed);
	// steve.highFiveGuys();
}
