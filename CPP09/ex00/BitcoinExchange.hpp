/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 01:47:04 by kederhet          #+#    #+#             */
/*   Updated: 2025/12/01 01:47:04 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, float> _database;

	bool isValidDate(const std::string &date);
	bool isValidValue(const std::string &value, float &result);
	float getExchangeRate(const std::string &date);

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange &operator=(const BitcoinExchange &src);
	~BitcoinExchange();

	bool loadDatabase(const std::string &filename);
	void processInputFile(const std::string &filename);
};

#endif