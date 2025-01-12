#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) : _accountIndex( Account::_nbAccounts ),
                                            _amount( initial_deposit ),
                                            _nbDeposits( 0 ),
                                            _nbWithdrawals( 0 ) {

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;

    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;

}

Account::~Account( void ) {

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;

}

void	Account::makeDeposit( int deposit ) {

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit;

    this->_amount += deposit;
    Account::_totalAmount += deposit;
    this->_nbDeposits++;
    Account::_totalNbDeposits++;

    std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;

}

bool	Account::makeWithdrawal( int withdrawal ) {

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:" << withdrawal;

    if ( withdrawal > this->_amount ) {

        std::cout << ";refused" << std::endl;
        return false;
    }

    this->_amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    this->_nbWithdrawals++;
    Account::_totalNbWithdrawals++;

    std::cout << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;

    return true;

}

int		Account::checkAmount( void ) const {

    return this->_amount;

}

void	Account::displayStatus( void ) const {

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;

}

void	Account::displayAccountsInfos( void ) {

    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;

}

void	Account::_displayTimestamp( void ) {

    time_t		t;
    struct tm	*tm;

    t = time( NULL );
    tm = localtime( &t );

    std::cout << "[" << tm->tm_year + 1900
              << std::setw(2) << std::setfill('0') << tm->tm_mon + 1
              << std::setw(2) << std::setfill('0') << tm->tm_mday << "_"
              << std::setw(2) << std::setfill('0') << tm->tm_hour
              << std::setw(2) << std::setfill('0') << tm->tm_min
              << std::setw(2) << std::setfill('0') << tm->tm_sec << "] ";

}

int		Account::getNbAccounts( void ) {

    return Account::_nbAccounts;

}

int		Account::getTotalAmount( void ) {

    return Account::_totalAmount;

}

int		Account::getNbDeposits( void ) {

    return Account::_totalNbDeposits;

}

int		Account::getNbWithdrawals( void ) {

    return Account::_totalNbWithdrawals;

}
