#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
    std::time_t now;
    std::tm *timeinfo;

    now = std::time(NULL);
    timeinfo = std::localtime(&now);
    std::cout << "["
              << std::setfill('0') << std::setw(4) <<timeinfo->tm_year + 1900
              << std::setw(2) << timeinfo->tm_mon + 1
              << std::setw(2) << timeinfo->tm_mday
              << "_"
              << std::setw(2) << timeinfo->tm_hour
              << std::setw(2) << timeinfo->tm_min
              << std::setw(2) << timeinfo->tm_sec
              << "] ";
    std::cout << std::setfill(' ');
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
    std::cout << "index:" << _accountIndex
             << ";amount:" << _amount
             << ";created" << std::endl;
}

Account::~Account(void)
{

}

void Account::makeDeposit(int deposit)
{
    int previous;

    previous = _amount;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    _displayTimestamp();
    std::cout << "index" << _accountIndex
              << ";p_amount:" << previous
              << ";deposit:" << deposit
              << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits
              << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    int previous;

    previous = _amount;
    _displayTimestamp();
    std::cout << "" << _accountIndex
              << "" << previous;

    if (withdrawal > _amount)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return (false);
    }

    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    std::cout << "" << withdrawal
              << "" << _amount
              << "" << _nbWithdrawals
              << std::endl;
    return (true);
}

int Account::checkAmount(void) const
{
    return (_amount);
}