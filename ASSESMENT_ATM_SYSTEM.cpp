#include <iostream>
#include <ctime>

using namespace std;

class ATM {
private:
    int pin;
    int balance;

public:
    ATM(int a) {
        pin = a;
        balance = 0; // Initialize balance to 0
    }

    void dis_welcome_screen();

    void dis_Help() 
	{
        cout << "\n\n\tHelp Screen";
        cout << "\n\n\tPlease enter your 5-digit ATM PIN to access your account.";
        cout << "\n\n\tIf you forget your PIN, please contact your bank.";
    }

    void Pin();

    void dis_Menu() 
	{
        cout << "\n\n\t Main Menu";
        cout << "\n\n\t 1. Deposit";
        cout << "\n\n\t 2. Withdraw";
        cout << "\n\n\t 3. Check Balance";
        cout << "\n\n\t 4. Exit";
    }

    void Deposit();
    
    void Withdraw();

    void Display() 
	{
        cout << "\n\n\t Your current balance is: " << balance;
    }
};

void ATM :: dis_welcome_screen() 
{
        cout << "\n\n\t------------------- Welcome to ATM---------------------------";
        cout << "\n\t\t*******************************************";
        time_t timestamp;
        time(&timestamp);
        cout << "\n\n\t Menu:";
        cout << "\n\n\t 1. Enter ATM PIN";
        cout << "\n\n\t 2. Help";
}

void ATM :: Pin()
{
        int inputPin;
        cout << "\n\n\t Enter your pin: ";
        cin >> inputPin;
        if (inputPin == pin) 
		{
            dis_Menu();
        } 
		else 
		{
            cout << "\n\t::::::::::::::Thank You:::::::::::::::::::::::::::";
            cout << "\n\t You had made your attempt which failed!!!! No More attempts allowed!! Sorry!!";
            cout << "\n\t::::::::::::::::::::::::::::::::::::::::::::::::::::";
            cout << "\n\t Press any key to continue.....";
        }
}
void ATM :: Withdraw() 
{
        int amount;
        cout << "\n\n\t Enter Amount to withdraw: ";
        cin >> amount;
        if (balance >= amount) 
		{
            balance -= amount;
            cout << "\n\n\t Withdrawal Successful. Your new balance is: " << balance;
        } 
		else 
		{
            cout << "\n\n\t Balance is not enough for withdrawal amount: ";
        }
}

void ATM :: Deposit() 
{
        int amount;
        cout << "\n\n\t Enter an Amount to Deposit: ";
        cin >> amount;
        balance += amount;
        cout << "\n\n\t Deposit Successful. Your new balance is: " << balance;
}


main() 
{
    ATM A(12345); // Create an ATM instance with PIN 12345

    int choice;
    A.dis_welcome_screen();
    cout << "\n\n\t Choose what would you like to do (1 or 2): ";
    cin >> choice;

    if (choice == 1) 
	{
        A.Pin(); // Get the user's PIN
    } 
	else if (choice == 2) 
	{
        A.dis_Help();
        A.dis_welcome_screen();
        cout << "\n\n\t Choose what would you like to do (1 or 2): ";
    	cin >> choice;
    	if (choice == 1) 
		{
           A.Pin(); // Get the user's PIN
        } 
    } 
	else 
	{
        cout << "\n\n\t invalid choice!!";
    }

    cout << "\n\n\t Choose what would you like to do: ";
    cin >> choice;

    switch (choice) 
	{
        case 1:
            A.Deposit();
            break;
        case 2:
            A.Withdraw();
            break;
        case 3:
            A.Display();
            break;
        case 4:
            cout << "\n\n\t Thank you for using our ATM system. Goodbye!";
            return 0;
        default:
            cout << "\n\n\t Invalid choice !!!!!";
            break;
    }

    return 0;
}
