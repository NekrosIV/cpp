/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:33:00 by kasingh           #+#    #+#             */
/*   Updated: 2025/02/26 17:54:31 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


const std::string BitcoinExchange::_databasePath = "data.csv";

BitcoinExchange::BitcoinExchange(const std::string &inPath) : _inputPath(inPath)
{
	loadDatabase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _inputPath(other._inputPath),
	_exchangeRates(other._exchangeRates)
{
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_inputPath = other._inputPath;
		_exchangeRates = other._exchangeRates;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

float	BitcoinExchange::ft_stof(const std::string &str, bool use_it) const {
    char *endPtr;
    double value = std::strtod(str.c_str(), &endPtr);

    if (*endPtr != '\0') 
        throw std::invalid_argument("Error: Invalid float -> " + str);
    
	
    if (value < -FLT_MAX || value > FLT_MAX) 
        throw std::out_of_range("Error: Value out of float range -> " + str);
    if (use_it && (value < 0 || value > 1000))
		throw std::out_of_range("Error: Value out of subject range subject range (0-1000) -> " + str);

    return static_cast<float>(value);
}

bool	BitcoinExchange::isValidDate(const std::string &date) const 
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (size_t i = 0; i < date.length(); i++) 
	{
        if ((i != 4 && i != 7) && !isdigit(date[i]))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}

float BitcoinExchange::getExchangeRate(const std::string &date) const
{
    std::map<std::string, float>::const_iterator it = _exchangeRates.lower_bound(date);

    if (it != _exchangeRates.end() && it->first == date)
        return it->second;

 
    if (it == _exchangeRates.begin())
        return -1; 

    --it;
    return it->second;
}

void	BitcoinExchange::loadDatabase()
{
    std::ifstream file(_databasePath.c_str());
    if (!file.is_open())
    {
        throw std::ios_base::failure("Error: Could not open database file: " + _databasePath + " -> " + strerror(errno));
    }

    std::string line;
	std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, rateStr;

        if (std::getline(ss, date, ',') && std::getline(ss, rateStr))
        {
            if (isValidDate(date))
				_exchangeRates[date] = ft_stof(rateStr,false);
            else
                throw std::invalid_argument("Error: Invalid date in database -> " + line);   
        }
        else
            throw std::invalid_argument("Error: Invalid line in database -> " + line);   
    }
    file.close();
}

void	BitcoinExchange::processInputFile() const
{
	std::ifstream file(_inputPath.c_str());
	if(!file.is_open())
	{
		throw std::ios_base::failure("Error: Could not open input file: " + _inputPath + " -> " + strerror(errno));
	}
	
	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
        std::string date, valueStr;

        if (!(std::getline(ss, date, '|') && std::getline(ss, valueStr)))
        {
            std::cerr << "Warning: Malformed line in input file -> " << line << std::endl;
            continue;
        }

		date.erase(0, date.find_first_not_of(" \t\r\n"));
        date.erase(date.find_last_not_of(" \t\r\n") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t\r\n"));
        valueStr.erase(valueStr.find_last_not_of(" \t\r\n") + 1);

		try 
		{
            if (!isValidDate(date))
                throw std::invalid_argument("Invalid date");

            float btcAmount = ft_stof(valueStr, true);
            float rate =  getExchangeRate(date);

            if (rate < 0)
            {
                std::cerr << "Warning: No exchange rate available for date -> " << date << std::endl;
                continue;
            }

            std::cout << date << " => " << btcAmount << " BTC = " << (btcAmount * rate) << " $\n";

        } catch (const std::exception &e) 
		{
            std::cerr << "Warning: " << e.what() << " in input line -> " << line << std::endl;
        }
		
	}
    file.close();
}