#include <iostream>
using namespace std;

class ATM{
private:
    float balance;
public:
    ATM(){ //Constructor without arguments
        cout << "Please define an initial balance: ";
        cin >> balance;     //Check errors??
    }

    ATM(float amount){
        balance = amount;
    }

    int getBalance() const{
        return balance;
    }
    void withdraw(float amount){
        if (amount > balance){
            cout << "\nInsuficient balance! You only have " << balance << " left!" << endl;
            return;
        }
        balance -= amount;
    }
    void deposit(float amount){
        balance += amount;
    }
};

int UI(){
    int option;

   /* cout << "\n----------------------" << endl;*/
    cout << "\n\n1. View Balance" << endl;   //CREATE ACCOUNT ????????
    cout << "2. Cash Withdraw" << endl;
    cout << "3. Cash Deposit" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice > ";

    while (!(cin >> option)) {  // Check if input is not an integer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return 0; //will be handled at main
    }


    return option;
}

int endOperation() {
    int option;

    while (true) {
        cout << "\nPress 1 to make more operations\nPress 0 to close the app > ";
        cin >> option;

        // Check if the input is valid (an integer) and either 0 or 1
        if (cin.fail()) {
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            cout << "\nInvalid input. Please enter 0 or 1." << endl;
        }
        else if (option == 0 || option == 1) {
            break;  // Exit loop if input is valid (0 or 1)
        }
        else {
            cout << "\nInvalid option. Please enter 0 or 1." << endl;
        }
    }

    if (option == 0) {
        cout << "\nClosing the app..." << endl;
        return 0;
        // Add app closing logic here if needed
    } else if (option == 1) {
        cout << "\nPerforming more operations..." << endl;
        return 1;
        // Add logic to continue operations here if needed
    }
}


int main() {
    ATM atm(1000.00);

    int option;
    int valid_options[4] = {1, 2, 3, 4};
    int is_valid;
    int system = 1;

    while (system == 1){
        do {
            option = UI();
            is_valid = 0;

            for (int i = 0; i < 4; ++i) {
                if (valid_options[i] == option){
                    is_valid = 1;
                    break;
                }
            }
            if (is_valid == 0){
                cout << "\nInvalid input! Please insert a valid option!\n" << endl;
            }

        }while (is_valid == 0);

        //Now we have a valid option. Let's handle all cases


        switch (option){
            case 1:
                cout << "\nYour current balance is " << atm.getBalance() << " EUR." << endl;
                system = endOperation(); //return 0 if user wants to close. 1 if wants to continue
                break;

            case 2:
                cout << "\nHow much money would you like to withdraw? > ";
                float amount;


                while (!(cin >> amount)) {  // Check if input is not an integer
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\nInvalid input! Please insert a valid number > ";
                }
                atm.withdraw(amount);
        }
    }



    return 0;
}


