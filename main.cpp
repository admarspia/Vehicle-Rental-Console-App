#include <iostream>
#include "System.h"
#include "banksystem.h"

using namespace std;

void setColor(int colorCode) {
    cout << "\033[" << colorCode << "m";
}

void displayHeader(const string& title) {
    setColor(34); 
    cout << "=========================================================================================================================================================================" << endl;
    setColor(33); 
    cout << setw(90) << title << endl;
    setColor(34); 
    cout << "========================================================================================================================================================================="<< endl;
    setColor(0);  
}





int bankSystem() {
  displayHeader("Welcome To Bank Managment System");
    BankSystem system;
    
    int customerChoice;

    while (true) {
        displayHeader("BANK SYSTEM");
        cout << "\nExplore our services:\n\n";
        cout << "  1. Create new Account\n";
        cout << "  2. Make Deposite\n";
        cout << "  3. Make Transfer \n";
        cout << "  4. See Your Balance\n";
        cout << "  5. Change your password\n";
        cout << "  6. Back to main menu\n";
        cout << "\nEnter your choice: ";

        cin >> customerChoice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (customerChoice) {
            case 1:
                system.adduser();
                break;
            case 2:
                system.deposite();
                break;
            case 3:
                system.transfer();
                break;
            case 4:
                system.showbalance();
                break;
            case 5:
                system.changePassword();
                break;              
            case 6:
                cout << "Thank You For Using Our App.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}


int car_renal() {
        displayHeader("CAR RENTAL SYSTEM");
    System system;
    
    int customerChoice;

    while (true) {

        cout << "\nExplore our services:\n\n";
        cout << "  1. Register as a New Customer\n";
        cout << "  2. View Available Cars\n";
        cout << "  3. Rent a Car\n";
        cout << "  4. Return a Car\n";
        cout << "  5. pay with bank\n";
        cout << "  6. See Your Porfile and Payment Status\n";
        cout << "  7. Back to main menu\n";
        cout << "\nEnter your choice: ";

        cin >> customerChoice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (customerChoice) {
            case 1:
                system.addUser();
                break;
            case 2:
                system.availebleCars();
                break;
            case 3:
                system.rentCar();
                break;
            case 4:
                system.returnCar();
                break;
            case 5:
                system.payWithBank();
                break;
            case 6:
                system.showProfile();
                break;
            case 7:
                cout << "Thank You For Using Our App.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}


int main () {
      int customerChoice;
      while (true) {
        displayHeader("WELCOME TO OUR APP");
        cout << "\nExplore our services:\n\n";
        cout << "  1. Car Rental Service\n";
        cout << "  2. Banking Service\n";
        cout << "  3. Close the app\n";
        cout << "\nEnter your choice: ";

        cin >> customerChoice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (customerChoice) {
            case 1:
                car_renal();
                break;
            case 2:
                bankSystem();
                break;              
            case 3:
                cout << "Thank You For Using Our App.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}


