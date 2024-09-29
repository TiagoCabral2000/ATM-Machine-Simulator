#include <iostream>
#include <numeric>
#include "Account.h"
#include "UserInterface.h"

using namespace std;

int main() {
    Account account(1000.00);
    int startOption, menuOption;
    int menu = 1;
    int system = 1;
    float amount;
    string usernames[] = {};

    //unique_ptr<Account> acc1 {new Account {"Tiago"}};
    //acc1-> withdraw (500)
    //acc1-> deposit (500)

    //unique_ptr<Account> acc2 = make_unique<Account>("Tiago",1000);

    //std::vector<int> values;
    //values.push_back(0);
    //values.push_back(1);

    while (system != 0) {

        //IMPLEMENTAR LOGICA DO MENU INICIAL
        startOption = startInputValidation();

        switch(startOption) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
        }

        
        while (menu != 0) {
            menuOption = menuInputValidation();

            switch (menuOption) {
                case 1:
                    cout << "\nYour current balance is " << account.getBalance() << " EUR." << endl;
                menu = endOperation();
                break;

                case 2:
                    cout << "\nHow much money would you like to withdraw? > ";

                while (!(cin >> amount)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\nInvalid input! Please insert a valid number > ";
                }
                if(account.withdraw(amount))
                    cout << "\nOPERATION SUCESSFULL!\nThe updated balance is " << account.getBalance() << " EUR" << endl;
                else
                    std::cout << "\nInsufficient balance! You only have " << account.getBalance() << " left!" << std::endl;
                menu = endOperation();
                break;

                case 3:
                    cout << "\nHow much money would you like to deposit? > ";

                while (!(cin >> amount)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\nInvalid input! Please insert a valid number > ";
                }
                account.deposit(amount);
                cout << "\nOPERATION SUCESSFULL!\nThe updated balance is " << account.getBalance() << " EUR" << endl;
                menu = endOperation();
                break;

                case 4:
                    menu = 0;  // Exit menuOption
                break;

                default:
                    cout << "\nInvalid menuOption. Please try again." << endl;
                break;
            }
        }
    }

    return 0;
}
