#include<iostream>
using namespace std;
class BankAccount {
private:
    string accountHolderName;
    string accountNumber;
protected:    
    double balance;
public:
    BankAccount(string name, string number, double initialBalance) {
        accountHolderName = name;
        accountNumber = number;
        balance = initialBalance;
    }
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount <<" in the account " << accountNumber << endl;
    }
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrew: " << amount << " from the account " << accountNumber << endl;
        }
    }
    void displayAccountInfo() {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: Rs" << balance << endl;
    }
    void calculateInterest(double rate, int years) {
        double interest = balance * rate * years / 100;
        cout << "Interest for " << years << " years at " << rate << "%: Rs" << interest << endl;
    }
};
class SavingsAccount : public BankAccount {
public:    SavingsAccount(string name, string number, double initialBalance) : BankAccount(name, number, initialBalance) {}
    void calculateInterest(double rate, int years) {
        double interest = (balance * rate * years) / 100;
        cout << "Savings Account Interest for " << years << " years at " << rate << "%: Rs" << interest << endl;
    }
};
class CurrentAccount : public BankAccount {
public:
    CurrentAccount(string name, string number, double initialBalance) : BankAccount(name, number, initialBalance) {}
    void calculateInterest(double rate, int years) {
        cout << "Current accounts do not earn interest." << endl;
    }
};


int main() {
    BankAccount account1("dayyan", "123456789", 1000.0);

    account1.deposit(500.0);
    SavingsAccount account2("dayyan", "987654321", 2000.0);
    account2.deposit(1000.0);
    CurrentAccount account3("dayyan", "543219876", 3000.0);
    account3.deposit(1500.0);
    account1.displayAccountInfo();
    account2.displayAccountInfo();
    account3.displayAccountInfo();
    account1.calculateInterest(5.0, 2);
    account2.calculateInterest(5.0, 2);
    account3.calculateInterest(5.0, 2);

    return 0;
}