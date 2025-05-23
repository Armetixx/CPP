/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armetix <armetix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:13:05 by armetix           #+#    #+#             */
/*   Updated: 2025/04/14 12:11:51 by armetix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int contactCount;
		int	currentIndex;
		
	public:
		PhoneBook();
		
		void	addContact();
		void	searchContacts() const;
		void	displayContact(int index) const;
};

#endif