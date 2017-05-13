#include "bank_account.hpp"
#include <fstream>
#include <math.h>
using namespace std;

Account::Account(const std::string& name, unsigned int balance, double interest_rate)
		: name_(name), balance_(balance), interest_rate_(interest_rate) { }

Account::~Account() {

}

void Account::Deposit(unsigned int amount) {
    balance_ += amount;
}

bool Account::Withdraw(unsigned int amount) {
    if(amount<=0){
        return false;
    }
    balance_ -= amount;
    return true;
}
//단리계산
unsigned int Account::ComputeExpectedBalance( unsigned int n_years_later) const {
    double temp = balance_;
    temp += ( temp * interest_rate_ * n_years_later);
    return (int)temp;
}

SavingAccount::SavingAccount(const std::string& name, int balance, double interest_rate)
		: Account(name, balance, interest_rate) { }

SavingAccount::~SavingAccount() {

}
//복리 계산
unsigned int SavingAccount::ComputeExpectedBalance( unsigned int n_years_later) const {
    double temp = balance_;
    temp = temp * pow(1+interest_rate_,(double)n_years_later);
    return (int)temp;
}

//Account* CreateAccount(const std::string& type, const std::string& name, unsigned int balance, double interest_rate) {
//    if(type == "checking") {
//        Account* checkingAccount = new Account(name,balance,interest_rate);
//        return checkingAccount;
//    } else { // if(type == "saving")
//        SavingAccount* savingAccount= new SavingAccount(name,balance,interest_rate);
//        return savingAccount;
//    }
//}

//bool SaveAccounts(const std::vector<Account*>& accounts, const std::string& filename) {
///* implement here*/
//
//}
//
//bool LoadAccounts(const std::string& filename, std::vector<Account*>* accounts) {
///* implement here*/
//
//}
