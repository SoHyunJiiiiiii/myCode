#include "bank_account.hpp"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
using namespace std;

int deleteAccount(vector<Account*> &accounts,string name) {
    int idx=0;
    vector<Account*>::const_iterator it;
    for( it= accounts.begin(); it != accounts.end(); it++){
        if( (*it)->name() == name ) {
            break;
        } else {
            idx++;
        }
    }
    if(accounts.size() < idx){
        return 0;
    } else {
        accounts.erase(accounts.begin()+idx);
        return 1;
    }

}

void showAccounts(const vector<Account*> &accounts) {
    vector<Account*>::const_iterator it;
    for( it= accounts.begin(); it != accounts.end(); it++){
        cout << (*it)->name() << " " << (*it)->type() << " " << (*it)->balance() << " " << (*it)->interest_rate()<< endl;
    }

}

void afterAccounts(const vector<Account*> &accounts,int years) {
    vector<Account*>::const_iterator it;
    for( it= accounts.begin(); it != accounts.end(); it++){
        cout << (*it)->name() << " " << (*it)->type() << " " << (*it)->ComputeExpectedBalance(years) << " " << (*it)->interest_rate()<< endl;
    }
}

bool SaveAccounts(const vector<Account*>& accounts, const char* filename) {
    vector<Account*>::const_iterator it;
    ofstream myfile(filename);
    if(myfile.is_open()) {
        for( it= accounts.begin(); it != accounts.end(); it++){
            myfile << (*it)->name() << " " << (*it)->type() << " " << (*it)->balance() << " " << (*it)->interest_rate()<< endl;
        }
        myfile.close();
        return true;
    }
    return false;
}


bool LoadAccounts(vector<Account*>& accounts,const char* filename) {
    string line,name,type;
    ifstream myfile(filename);
    int ch,count = 0,state=0,space=0;
    int balance;
    double interests;
    if(myfile.is_open()) {
        while( getline(myfile,line) ){
            //문자열로 자른뒤,
            char *cstr = new char[line.length()+1];
            char *buff = new char[20];
            strcpy(cstr,line.c_str());
            for(int idx=0; idx < strlen(cstr); idx++){
                ch = cstr[idx];
                //공백이면 버퍼초기화
                if(isspace(ch)){
                    space=1;
                    state++;
                } else {    //공백이 아니면 글자저장
                    if(space==1){
                        switch (state) {
                            case 1:
                                name = string(buff);
                                break;
                            case 2:
                                type = string(buff);
                                break;
                            case 3:
                                balance = atoi(buff);
                                break;
                            default:
                                break;
                        }
                        memset(buff, 0, sizeof(char)*20);
                        space = 0;
                        count = 0;
                    }
                    buff[count] = cstr[idx];
                    count ++;
                }
            }
                    interests = atof(buff);
                    if(type == "checking") {
                        Account* checkingAccount = new Account(name,balance,interests);
                        accounts.push_back(checkingAccount);                  
                    } else if(type == "saving") {
                        SavingAccount* savingAccount= new SavingAccount(name,balance,interests);
                        accounts.push_back(savingAccount);
                    }
        }
        myfile.close();
        return true;
    }
    return false;
}

int main() {
    string cmd;
	vector<Account*> accounts;

	do {
        string name,type;
        char *filename = new char[30];
        int amount,years;
        double interests;
        cin >> cmd;
        if(cmd=="add") {
            cin >> name >> type >> amount >> interests;
            if(type == "checking") {
                Account* checkingAccount = new Account(name,amount,interests);
                accounts.push_back(checkingAccount);
            } else if(type == "saving") {
                SavingAccount* savingAccount= new SavingAccount(name,amount,interests);
                accounts.push_back(savingAccount);
            }
        } else if(cmd=="delete") {
            cin >> name;
            deleteAccount(accounts,name);
        } else if(cmd=="show") {
            showAccounts(accounts);
        } else if(cmd=="after") {
            cin >> years;
            afterAccounts(accounts,years);
        } else if(cmd=="save") {
            cin >> filename;
            SaveAccounts(accounts,filename);
        } else if(cmd=="load") {
            cin >> filename;
            LoadAccounts(accounts,filename);
        }
	} while(cmd!="quit");

	return 0;
}
