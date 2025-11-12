/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:40:14 by kbarru            #+#    #+#             */
/*   Updated: 2025/10/21 19:19:06 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("Default_Diamond_clap_name"),  ScavTrap("Default_Diamond"), FragTrap("Default_Diamond"), _name("Default_Diamond")
{
	std::cout << "[DiamondTrap]	" << this->_name << " default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	this->_maxHp = FRAG_BASE_HP;
	this->_hitPoints = FRAG_BASE_HP;
	this->_energyPoints = SCAV_BASE_EP;
	this->_attackDamage = FRAG_BASE_AP;

	std::cout << "[DiamondTrap]	" << this->_name << " string constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "[DiamondTrap]	" << this->_name << " copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_name = other._name;
	}
	std::cout << "[DiamondTrap]	" << " copy assignment operator called" << std::endl;
	return (*this);
}
DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap]	" << this->_name << " destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "[DiamondTrap]	I am " << this->_name << ", aka " << this->ClapTrap::_name << std::endl;
}

std::string DiamondTrap::getName() const
{
	return(this->_name);
}
