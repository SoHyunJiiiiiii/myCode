#ifndef __BANK_ACCOUNT_HPP__
#define __BANK_ACCOUNT_HPP__

#include <string>
#include <vector>
using namespace std;
//checking account
class Account {
public:
	Account(const std::string& name, unsigned int balance, double interest_rate);
	virtual ~Account();
	void Deposit(unsigned int amount);
	bool Withdraw(unsigned int amount);
	virtual unsigned int ComputeExpectedBalance( unsigned int n_years_later) const;
	virtual const char* type() const { return "checking"; }
	const unsigned int& balance() const { return balance_; }
	const std::string& name() const { return name_; }
	const double& interest_rate() const { return interest_rate_; }
protected:
	std::string name_;
	unsigned int balance_;
	double interest_rate_; // 기본 계좌는 단리로 계산.
};

//saving account
class SavingAccount : public Account {
public:
	SavingAccount(const std::string& name, int balance, double interest_rate);
	virtual ~SavingAccount();
	virtual const char* type() const { return "saving"; }
	// 이 타입의 계좌는 복리로 계산.
	virtual unsigned int ComputeExpectedBalance( unsigned int n_years_later) const;
};

//Account* CreateAccount(const std::string& type, const std::string& name, unsigned int balance, double interest_rate);
//bool SaveAccounts(const vector<Account*>& accounts, const string& filename);
//bool LoadAccounts(vector<Account*>* accounts,const string& filename);

#endif
