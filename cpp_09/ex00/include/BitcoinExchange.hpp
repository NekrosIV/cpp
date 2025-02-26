/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:01:43 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/26 17:03:42 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cerrno>
#include <fstream> 
#include <cstring>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <cfloat> 

class BitcoinExchange
{
  private:
	static const std::string _databasePath;
	std::string _inputPath;
	std::map<std::string, float> _exchangeRates;
	float ft_stof(const std::string &str, bool use_it) const;
	bool isValidDate(const std::string &date) const;
	float getExchangeRate(const std::string &date) const;

  public:
	BitcoinExchange(const std::string &inPath);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void loadDatabase();
	void processInputFile() const;
};
