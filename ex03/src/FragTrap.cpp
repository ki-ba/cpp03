/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:32:45 by kbarru            #+#    #+#             */
/*   Updated: 2025/10/21 19:14:02 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("Default_Frag", FRAG_BASE_HP, FRAG_BASE_EP, FRAG_BASE_AP)
{
	std::cout << "[FragTrap]	" << this->_name << " default constructor called" << std::endl;
}	

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "[FragTrap]	" << this->_name << " copy constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name, FRAG_BASE_HP, FRAG_BASE_EP, FRAG_BASE_AP)
{
	std::cout << "[FragTrap]	" << this->_name << " string constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap]	" << this->_name << " destructor called" << std::endl;
}

void FragTrap::highFiveGuys(void)
{
	if (this->_hitPoints <= 0)
		std::cout << "[FragTrap]	" << this->_name << ": *underpowered synthetic voice noises*" << std::endl;
	else
		std::cout << "[FragTrap]	" << this->_name << ":	High five guys? High five? :D" << std::endl;
}
