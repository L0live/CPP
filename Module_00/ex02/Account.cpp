#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account() {}

int Account::getNbAccounts(void) {return (_nbAccounts);}

int Account::getTotalAmount(void) {return (_totalAmount);}

int Account::getNbDeposits(void) {return (_totalNbDeposits);}

int Account::getNbWithdrawals(void) {return (_totalNbWithdrawals);}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:\033[0;34m" << getNbAccounts();
	std::cout << "\033[0m;total:\033[0;34m" << getTotalAmount();
	std::cout << "\033[0m;deposits:\033[0;34m" << getNbDeposits();
	std::cout << "\033[0m;withdrawals:\033[0;34m" << getNbWithdrawals();
	std::cout << "\033[0m\n";
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:\033[0;34m" << _accountIndex;
	std::cout << "\033[0m;amount:\033[0;34m" << _amount;
	std::cout << "\033[0m;deposits:\033[0;34m" << _nbDeposits;
	std::cout << "\033[0m;withdrawals:\033[0;34m" << _nbWithdrawals;
	std::cout << "\033[0m\n";
}

Account::Account(int initial_deposit)
{
	_accountIndex = getNbAccounts();
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts += 1;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:\033[0;34m" << _accountIndex;
	std::cout << "\033[0m;amount:\033[0;34m" << _amount;
	std::cout << "\033[0m;created\n";
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << " index:\033[0;34m" << _accountIndex;
	std::cout << "\033[0m;p_amount:\033[0;34m" << _amount;
	std::cout << "\033[0m;deposit:\033[0;34m" << deposit;
	_amount += deposit;
	_nbDeposits += 1;
	std::cout << "\033[0m;amount:\033[0;34m" << _amount;
	std::cout << "\033[0m;nb_deposits:\033[0;34m" << _nbDeposits;
	std::cout << "\033[0m\n";

	_totalAmount += deposit;
	_totalNbDeposits += 1;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << " index:\033[0;34m" << _accountIndex;
	std::cout << "\033[0m;p_amount:\033[0;34m" << _amount;
	if (withdrawal > _amount)
	{
		std::cout << "\033[0m;withdrawal:refused\n";
		return (0);
	}
	_amount -= withdrawal;
	_nbWithdrawals += 1;
	std::cout << "\033[0m;amount:\033[0;34m" << _amount;
	std::cout << "\033[0m;nb_withdrawals:\033[0;34m" << _nbWithdrawals;

	_totalAmount -= withdrawal;
	_totalNbWithdrawals += 1;
	std::cout << "\033[0m\n";
	return (1);
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:\033[0;34m" << _accountIndex;
	std::cout << "\033[0m;amount:\033[0;34m" << _amount;
	std::cout << "\033[0m;closed\n";
}

void	Account::_displayTimestamp(void)
{
	time_t rawtime;
	struct tm * timeinfo;
	char	ptr[18];

	time(&rawtime);
	timeinfo = localtime (&rawtime);
	strftime(ptr, 18, "[%Y%m%C_%H%M%S]", timeinfo);
	std::cout << ptr;
}
