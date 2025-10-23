/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:29:13 by kbarru            #+#    #+#             */
/*   Updated: 2025/10/21 18:58:24 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP
# define FRAGTRAP

# include "ClapTrap.hpp"

# define FRAG_BASE_HP 100
# define FRAG_BASE_EP 100
# define FRAG_BASE_AP 30

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(const FragTrap &other);
	FragTrap(const std::string name);
	FragTrap &operator=(const FragTrap &other);
	~FragTrap();
	FragTrap &operator=(FragTrap &other);
	void highFiveGuys(void);
};

#endif
