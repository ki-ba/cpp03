/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:53:04 by kbarru            #+#    #+#             */
/*   Updated: 2025/10/21 16:33:27 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

#define SCAV_BASE_HP 100
#define SCAV_BASE_EP 50
#define SCAV_BASE_AP 20

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const std::string name);
	ScavTrap(ScavTrap &other);
	~ScavTrap();
	void guardGate();
	void attack(const std::string &target);
};

#endif
