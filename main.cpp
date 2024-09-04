#include <iostream>
#include <string>

using namespace std;

int main() {
    // My Variables
    string userId;
    string password;
    double balance = 0.0;
    bool isLoggedIn = false;    // To track if the user is logged in or not

    cout << "Hi! Welcome to the ATM Machine!" << endl;
    cout << "Please select an option from the menu below:" << endl;

    while (true) {
        // If the user is not logged in, show the initial menu
        if (!isLoggedIn) {
            cout << "l -> Login" << endl;
            cout << "c -> Create New Account" << endl;
            cout << "q -> Quit" << endl;

            char option;
            cin >> option;

            if (option == 'q') {
                break; // Exit the program
            }
            else if (option == 'c') {
                // Create new account
                if (userId.empty()) {
                    cout << "Please enter your user id: ";
                    cin >> userId;
                    cout << "Please enter your password: ";
                    cin >> password;
                    balance = 0.0;
                    cout << "Thank You! Your account has been created!" << endl;
                } else {
                    cout << "An account already exists. Please login." << endl;
                }
            }
            else if (option == 'l') {
                // Login
                string inputUserId, inputPassword;
                cout << "Please enter your user id: ";
                cin >> inputUserId;
                cout << "Please enter your password: ";
                cin >> inputPassword;

                // Check if login details match the stored credentials
                if (inputUserId == userId && inputPassword == password) {
                    cout << "Access Granted!" << endl;
                    isLoggedIn = true; // To set login status to true
                } else {
                    cout << "*** LOGIN FAILED! ***" << endl;
                }
            }
        }
        else {
            // User is logged in, shows the main menu
            cout << "d -> Deposit Money" << endl;
            cout << "w -> Withdraw Money" << endl;
            cout << "r -> Request Balance" << endl;
            cout << "q -> Quit" << endl;

            char option;
            cin >> option;

            if (option == 'q') {
                isLoggedIn = false;      // This logs out the user
            }
            else if (option == 'd') {
                                        // Deposit money
                double amount;
                cout << "Amount of deposit: $";
                cin >> amount;
                if (amount > 0) {
                    balance += amount; // Which is the same as balance = balance+amount 'amount and adds deposit to amount'
                    cout << "Deposit successful!" << endl;
                } else {
                    cout << "Invalid deposit amount." << endl;
                }
            }
            else if (option == 'w') {
                // Withdraw money
                double amount;
                cout << "Amount of withdrawal: $";
                cin >> amount;
                if (amount > 0 && balance >= amount) {
                    balance -= amount; // Which is the same as balance = balance-amount, subtracts withdrawal amount from balance
                    cout << "Withdrawal successful!" << endl;
                } else {
                    cout << "Invalid amount or insufficient balance." << endl;
                }
            }
            else if (option == 'r') {
                                    // Requests balance
                cout << "Your balance is $" << balance << "." << endl;
            }
        }
    }

    cout << "Thank you for using the ATM Machine. Goodbye!" << endl;
    return 0;
}
