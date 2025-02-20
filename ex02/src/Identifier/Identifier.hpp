/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identifier.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakas <tnakas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:44:43 by tnakas            #+#    #+#             */
/*   Updated: 2025/02/20 22:54:57 by tnakas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_HPP
#define DEFINE_HPP

#include "../Base/Base.hpp"
#include "../Derived/A.hpp"
#include "../Derived/B.hpp"
#include "../Derived/C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif