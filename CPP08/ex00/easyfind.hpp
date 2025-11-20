/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kderhet <kderhet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 00:15:27 by kderhet           #+#    #+#             */
/*   Updated: 2025/11/20 00:15:30 by kderhet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>
#include <iterator> 

template <typename T>
typename T::iterator easyfind(T &container, int n) {
    typename T::iterator it = std::find(container.begin(), container.end(), n);

    if (it == container.end()) {
        throw std::runtime_error("Element not found in container");
    }
    return it;
}

#endif