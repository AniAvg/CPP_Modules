#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0 ;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
	<< ";amount:" << getTotalAmount()
	<< ";deposits:" << getNbDeposits()
	<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}


Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account(void)
{
	_nbAccounts--;
	_totalAmount -= _amount;
}



void	Account::makeDeposit(int deposit)
{
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";p_amount:" << _amount - deposit
	<< ";deposit:" << deposit
	<< ";amount:" << _amount
	<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal > _amount)
	{
		std::cout << "index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";p_amount:" << _amount + withdrawal
	<< ";withdrawal:" << withdrawal
	<< ";amount:" << _amount
	<< ";nb_withdrawl:" << _nbWithdrawals << std::endl;

	return (true);
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";deposits:" << _nbDeposits
	<< ";withdrawals:" << _nbWithdrawals << std::endl;
}



Account::Account()
{}

void	Account::_displayTimestamp(void)
{
	time_t now = std::time(NULL);
	struct tm *t = std::localtime(&now);

	std::cout << "[";
	std::cout << t->tm_year + 1900;

	if (t->tm_mon + 1 < 10)
		std::cout << "0";
	std::cout << t->tm_mon + 1;

	if (t->tm_mday < 10)
		std::cout << "0";
	std::cout << t->tm_mday;

	std::cout << "_";

	if (t->tm_hour < 10)
		std::cout << "0";
	std::cout << t->tm_hour;

	if (t->tm_min < 10)
		std::cout << "0";
	std::cout << t->tm_min;

	if (t->tm_sec < 10)
		std::cout << "0";
	std::cout << t->tm_sec;

	std::cout << "] ";
}
