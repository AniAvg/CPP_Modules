#include "Account.hpp"

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
	std::cout << "Accounts: " << getNbAccounts() << std::endl;
	std::cout << "Amount: " << getTotalAmount() << std::endl;
	std::cout << "Deposits: " << getNbDeposits() << std::endl;
	std::cout << "Withdrawals: " << getNbWithdrawals() << std::endl;
}


// constructor
Account::Account(int initial_deposit)
{}

// destructor
Account::~Account(void)
{}
