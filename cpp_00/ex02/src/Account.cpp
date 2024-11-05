/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:42:18 by kasingh           #+#    #+#             */
/*   Updated: 2024/11/05 15:27:45 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	char	buffer[20];

	std::time_t t = std::time(0);
	std::tm *now = std::localtime(&t);
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", now);
	std::cout << buffer << " ";
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "created" << std::endl;
}
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "closed" << std::endl;
}

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}
int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}
int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

int Account::checkAmount(void) const
{
	return (_amount);
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";"
				<< "total:" << _totalAmount << ";"
				<< "deposits:" << _totalNbDeposits << ";"
				<< "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";"
				<< "deposit:" << deposit << ";";
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << "amount:" << _amount << ";"
				<< "nb_deposits:" << _nbDeposits << std::endl;
}
bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";";
	if (_amount < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << "withdrawal:" << withdrawal << ";"
				<< "amount:" << _amount << ";"
				<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}
