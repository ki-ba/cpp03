/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:37:27 by kbarru            #+#    #+#             */
/*   Updated: 2025/10/21 16:33:38 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "[ClapTrap]	" << this->_name << " default constructor called" << std::endl;
}	
ClapTrap::ClapTrap(const std::string name)
	: _name(name), _maxHp(CLAP_BASE_HP), _hitPoints(CLAP_BASE_HP), _energyPoints(CLAP_BASE_EP), _attackDamage(CLAP_BASE_AP)
{
	std::cout << "[ClapTrap]	" << this->_name << " string constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name, unsigned int maxHp, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage)
	: _name(name),
	_maxHp(maxHp),
	_hitPoints(hitPoints),
	_energyPoints(energyPoints),
	_attackDamage(attackDamage)
{
	std::cout << "[ClapTrap]	" << this->_name << " paremeterized constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &other)
	: _name(other._name),
	_maxHp(other._maxHp),
	_hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage)
{
	std::cout << "[ClapTrap]	" << this->_name << " created by copy" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	this->_name = other._name;
	this->_maxHp = other._maxHp;
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
		std::cout << "[ClapTrap]	" << this->_name << "'s carcass still moves its arm in a faint movement, as if trying to hit something." << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << "[ClapTrap]	" << this->_name << " sorely raises its arm, but is to tired to hit anything." << std::endl;
	else
	{
		std::cout << "[ClapTrap]	" << this->_name <<" attacks " << target << ", causing " << this->_attackDamage << " points of damage !" << std::endl;
		--this->_energyPoints;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
		std::cout << "[ClapTrap]	" << this->_name << "'s remains farther disintegrates." << std::endl;
	else
	{
		std::cout << "[ClapTrap]	" << this->_name << " takes " << amount << " damage." << std::endl;
		if (amount > this->_hitPoints)
		{
			std::cout << "[ClapTrap]	" << this->_name << " falls with a chilling scream." << std::endl;
			this->_hitPoints = 0;
		}
		else
			this->_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
		std::cout << "[ClapTrap]	" << this->_name << " frenetically throws its own metallic remains on what's left of its body, in a vain attempt to repair itself." << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << "[ClapTrap]	" << this->_name << " is too tired to even lift its screwdriver." << std::endl;
	else if (this->_hitPoints >= this->_maxHp)
		std::cout << "[ClapTrap]	" << this->_name << " removes the dust from its shoulders. It is so shiny now!" << std::endl;
	else
	{
		std::cout << "[ClapTrap]	" << this->_name << " repairs itself for " << amount << " hit points." << std::endl;
		if (this->_hitPoints + amount > this->_maxHp)
			this->_hitPoints = this->_maxHp;
		else
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
