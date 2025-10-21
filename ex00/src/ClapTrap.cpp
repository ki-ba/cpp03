/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:37:27 by kbarru            #+#    #+#             */
/*   Updated: 2025/10/21 11:37:38 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "[ClapTrap]	" << this->_name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) 
	: _name(other._name),
	_hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage)
{
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;

	return (*this);
}


ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap]	" << this->_name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << "'s carcass still moves its arm in a faint movement, as if trying to hit something." << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << this->_name << " sorely raises its arm, but is to tired to hit anything." << std::endl;
	else
	{
		std::cout << "ClapTrap attacks " << target << ", causing " << this->_attackDamage << " points of damage !" << std::endl;
		--this->_energyPoints;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
		std::cout << this->_name << "'s remains farther disintegrates." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage." << std::endl;
		this->_hitPoints -= amount;
		if (this->_hitPoints <= 0)
			std::cout << this->_name << " falls with a chilling scream." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
		std::cout << this->_name << " frenetically throws its own metallic remains on what's left of its body, in a vain attempt to repair itself." << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << this->_name << " is too tired to even lift its screwdriver." << std::endl;
	else if (this->_hitPoints >= 10)
		std::cout << this->_name << " removes the dust from its shoulders. It is so shiny now!" << std::endl;
	else
	{
		std::cout << this->_name << " repairs itself for" << amount << " hit points." << std::endl;
		this->_hitPoints += amount;
		--this->_energyPoints;
	}
}

std::string ClapTrap::getName() const
{
	return (this->_name);
}

unsigned int ClapTrap::getAttackDamage() const
{
	return (this->_attackDamage);
}


unsigned int ClapTrap::getEnergyPoints() const
{
	return (this->_energyPoints);
}

unsigned int ClapTrap::getHitPoints() const
{
	return (this->_hitPoints);
}
