/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:56:14 by kbarru            #+#    #+#             */
/*   Updated: 2025/10/21 19:13:38 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("Default_Scav", SCAV_BASE_HP, SCAV_BASE_EP, SCAV_BASE_AP)
{
	std::cout << "[ScavTrap]	" << this->_name << " default constructor called" << std::endl;
}
ScavTrap::ScavTrap(const std::string name) : ClapTrap(name, SCAV_BASE_HP, SCAV_BASE_EP, SCAV_BASE_AP)
{
	std::cout << "[ScavTrap]	" << this->_name << " string constructor called" << std::endl;
	// std::cout << "[ScavTrap]	HP : "<< this->_hitPoints << std::endl;
	// std::cout << "[ScavTrap]	EP : "<< this->_energyPoints << std::endl;
	// std::cout << "[ScavTrap]	AP : "<< this->_attackDamage<< std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "[ScavTrap]	" << this->_name << " copy constructor called" << std::endl;
}
ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap]	" << this->_name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	std::cout << "[ScavTrap]	" << this->_name << " fires its devastating minigun at " << target << "." << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "[ScavTrap]	" << this->_name << ": Deftones shirt huh? How many songs do you know?" << std::endl;
}
