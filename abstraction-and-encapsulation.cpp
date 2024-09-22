#include <iostream>
#include <string>

using namespace std;

// Abstract base class for bank accounts
class BankAccount {
protected:
    string accountHolderName;
    double balance;

public:
    BankAccount(string name, double initialBalance) : accountHolderName(name), balance(initialBalance) {}

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful! Current balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    virtual void withdraw(double amount) = 0;  // Pure virtual function for withdrawal, implemented by subclasses

    void checkBalance() const {
        cout << "Current balance: " << balance << endl;
    }

    string getAccountHolderName() const {
        return accountHolderName;
    }

    double getBalance() const {
        return balance;
    }
};

// Savings Account class derived from BankAccount
class SavingsAccount : public BankAccount {
private:
    const double MIN_BALANCE = 1000.0;

public:
    SavingsAccount(string name, double initialBalance) : BankAccount(name, initialBalance) {}

    void withdraw(double amount) override {
        if (amount > 0 && balance - amount >= MIN_BALANCE) {
            balance -= amount;
            cout << "Withdrawal successful! Current balance: " << balance << endl;
        } else if (balance - amount < MIN_BALANCE) {
            cout << "Insufficient balance! Minimum balance of " << MIN_BALANCE << " must be maintained." << endl;
        } else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }
};

// Current Account class derived from BankAccount
class CurrentAccount : public BankAccount {
public:
    CurrentAccount(string name, double initialBalance) : BankAccount(name, initialBalance) {}

    void withdraw(double amount) override {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            cout << "Withdrawal successful! Current balance: " << balance << endl;
        } else if (balance < amount) {
            cout << "Insufficient balance!" << endl;
        } else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }
};

// Main Menu
void showMainMenu() {
    cout << "\nMain Menu\n";
    cout << "1 - Savings Account\n";
    cout << "2 - Current Account\n";
    cout << "3 - Exit\n";
    cout << "Choose an option: ";
}

// Sub Menu for Account Options
void showSubMenu() {
    cout << "\nSub Menu\n";
    cout << "1 - Deposit\n";
    cout << "2 - Withdraw\n";
    cout << "3 - Check Balance\n";
    cout << "4 - Back\n";
    cout << "Choose an option: ";
}

int main() {
    int mainChoice, subChoice;
    double amount;

    // Default account details (for example)
    SavingsAccount savingsAccount("Lebron Dimayacyac", 5000.0);
    CurrentAccount currentAccount("Lebron Dimayacyac", 3000.0);

    do {
        showMainMenu();
        cin >> mainChoice;

        switch (mainChoice) {
            case 1: // Savings Account
                do {
                    showSubMenu();
                    cin >> subChoice;

                    switch (subChoice) {
                        case 1: // Deposit
                            cout << "Enter amount to deposit: ";
                            cin >> amount;
                            savingsAccount.deposit(amount);
                            break;

                        case 2: // Withdraw
                            cout << "Enter amount to withdraw: ";
                            cin >> amount;
                            savingsAccount.withdraw(amount);
                            break;

                        case 3: // Check Balance
                            savingsAccount.checkBalance();
                            break;

                        case 4: // Back to main menu
                            break;

                        default:
                            cout << "Invalid option! Please try again.\n";
                    }
                } while (subChoice != 4);
                break;

            case 2: // Current Account
                do {
                    showSubMenu();
                    cin >> subChoice;

                    switch (subChoice) {
                        case 1: // Deposit
                            cout << "Enter amount to deposit: ";
                            cin >> amount;
                            currentAccount.deposit(amount);
                            break;

                        case 2: // Withdraw
                            cout << "Enter amount to withdraw: ";
                            cin >> amount;
                            currentAccount.withdraw(amount);
                            break;

                        case 3: // Check Balance
                            currentAccount.checkBalance();
                            break;

                        case 4: // Back to main menu
                            break;

                        default:
                            cout << "Invalid option! Please try again.\n";
                    }
                } while (subChoice != 4);
                break;

            case 3: // Exit
                cout << "Exiting the system. Thank you!\n";
                break;

            default:
                cout << "Invalid option! Please choose again.\n";
        }

    } while (mainChoice != 3);

    return 0;
}
