#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithddrawals = 0;

Account:Account(int initial_deposit)
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
              << std::setq(2) << timeinfo->tm_min
              << std::setw(2) << timeinfo->tm_sec
              << "] ";
    std::cout << std:setfill(' ');
}

Account::~Account(void)
{

}

void    Account::makeDeposit(int deposit)
{

}

void    Account:makeWithdrawal(int withdrawal)
{

}

int Account::checkAmount(void) const
{

}