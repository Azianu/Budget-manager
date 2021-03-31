#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<ctime>
using namespace std;
void sign_up();
void login();
void menu();
void add_expense();
void view_expense();
void bill();

string active_user;
time_t timetoday;

struct users
{
	string user_name;
	string password;
};
int main()
{
	
system("CLS");

char choice_access, choice;

cout << endl << endl;
cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
cout << setw(65) << "|" << "\t\tMENU   \t " << setw(13) << " | " << endl;
cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
cout << setw(65) << "|" << setw(37) << " | " << endl;
cout << setw(65) << "|" << "\tLogin\t\t1" << setw(13) << " | " << endl;
cout << setw(65) << "|" << "\tSign Up\t\t2" << setw(13) << " | " << endl;
cout << setw(65) << "|" << "\tLogout\t\t3" << setw(13) << " | " << endl;
cout << setw(65) << "|" << "\tEXIT\t\t4" << setw(13) << " | " << endl;
cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
again:
cout << endl << setw(84) << "Enter your choice: ";
cin >> choice_access;

switch (choice_access)
{
case '1':
{
			login();
			break;
}
case '2':
{
			sign_up();
			break;
}
case '3':
{
			cout << "Are you sure you want to logout?(Y/N)";
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				active_user = " ";
				system("CLS");
				cout << "\n\n\n\n\n" << setw(90) << "Logged out\n\n";
				cout << setw(103) << "Press any key to go the main screen.";
				cin.get(); cin.get();
				main();
			}
			else
				menu();
			break;
}

case '4':
{
			cout << "Are you sure you want to Exit?(Y/N)";
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				system("CLS");
				cout << "\n\n\n\n\n";
				cout << setw(100) << "Thank you for using this software." << endl;
				cout << setw(93) << "Hope to see you again" << endl;
				cout << setw(96) << "Have a nice day\n\n\n\n\n";
				exit(0);
			}
			else
			{
				system("CLS");
				main();
			}
			break;
}
default:
{
		   cout << "Invalid choice.\n Try again.\n";
		   goto again;
}
}

cout << endl;
return 0;
}

void login()
{
	system("CLS");
	string user, pass, user_f, pass_f;
	char choice;
	//Login header
	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
	cout << setw(65) << "|" << "\t\tLOGIN \t " << setw(13) << " | " << endl;
	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
	//Inputting username and password from user
	cout << setw(85) << "Username:";
	cin >> user;
	cout << setw(85) << "Password:";
	cin >> pass;

	//Checking if account exists in "users.txt" file
	fstream file;
	file.open("users.txt", ios::in);
	if (!file)
	{
		cout << "No Account exists. Create account first.";
		cin.ignore(); cin.ignore();
		sign_up();
	}

	else
	{
		while (!file.eof())
		{
			getline(file, user_f);
			getline(file, pass_f);
			//checking if username and password are correct
			if ((user == user_f) && (pass == pass_f))
			{
				active_user = user_f;
				file.close();
				cout << endl << endl << setw(93) << "Access granted." << endl;
				cout << setw(102) << "Press any key to go the main menu.";
				cin.get(); cin.get();
				menu();
			}
			else;
		}
	}
	file.close();
	//If account does not exists then sending to the sign_up() function
	cout << endl << endl << setw(93) << "Invalid credentials." << endl;
	cout << "Do you want to create a account?(Y/N)";
	cin >> choice;
	if (choice == 'Y' || choice == 'y')
		sign_up();
	else
		main();
}

void sign_up()
{
	system("CLS");
	
	users user_account;
	fstream file;
	file.open("users.txt", ios::out | ios::app);

	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
	cout << setw(65) << "|" << "\t\tSign Up\t " << setw(13) << " | " << endl;
	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;

	cout << setw(85) << "Username:";
	cin.ignore();
	getline(cin, user_account.user_name);
	cout << setw(85) << "Password:";
	getline(cin, user_account.password);

	file << user_account.user_name << endl;
	file << user_account.password << endl;
	file.close();
	cout << endl << endl << setw(93) << "Account created." << endl;
	cout << setw(100) << "Press any key to go to Login.";
	cin.ignore();
	login();
}

void menu()
{
	char choice, logout_choice;
	string sticky_data;
	string quote[20], data;
	int counter = 0;

	//random number generation
	time(&timetoday);
	srand((unsigned)time(0));
	int randomNumber;
	randomNumber = (rand() % 19) + 1;

	system("CLS");


	//Menu
	cout << endl;
	cout << setw(56) << "|" << setw(52) << setfill('-') << "|" << setfill(' ') << endl;
	cout << setw(56) << "|" << "\t\t\tMENU\t " << setw(20) << " | " << endl;
	cout << setw(56) << "|" << setw(52) << setfill('-') << "|" << setfill(' ') << endl;
	cout << setw(56) << "|" << setw(53) << " | " << endl;
	cout << setw(56) << "|" << "\tAdd expenses\t\t1" << setw(20) << " | " << endl;
	cout << setw(56) << "|" << "\tView expenses\t\t2" << setw(20) << " | " << endl;
	cout << setw(56) << "|" << "\tTOTAL\t\t\t3" << setw(20) << " | " << endl;
	cout << setw(56) << "|" << "\tLogout\t\t\t4" << setw(20) << " | " << endl;
	cout << setw(56) << "|" << "\tEXIT\t\t\t5" << setw(20) << " | " << endl;
	cout << setw(56) << "|" << setw(51) << setfill('-') << "-" << "|" << setfill(' ') << endl;

	cout << endl << setw(88) << "Enter your choice=";
	cin >> choice;

	switch (choice)
	{
	case '1':
	{
				add_expense();
				break;
	}
		
	case '2':
	{
				view_expense();
				break;
	}
		
	case '3':
	{
				bill();
				break;
	}
	
	case '4':
	{//log out
				cout << "Are you sure you want to logout?(Y/N)";
				cin >> logout_choice;
				if (logout_choice == 'Y' || logout_choice == 'y')
				{
					active_user = " ";
					system("CLS");
					cout << "\n\n\n\n\n" << setw(90) << "Logged out\n\n";
					cout << setw(103) << "Press any key to go the main screen.";
					cin.ignore(); cin.ignore();
					main();
				}
				else
					menu();
				break;
	}
	case '5':
	{
				//exit
				cout << "Are you sure you want to Exit?(Y/N)";
				cin >> logout_choice;
				if (logout_choice == 'Y' || logout_choice == 'y')
				{
					system("CLS");
					cout << "\n\n\n\n\n";
					cout << setw(100) << "Thank you for using this software." << endl;
					cout << setw(93) << "Hope to see you again" << endl;
					cout << setw(96) << "Have a nice day\n\n\n\n\n";
					exit(0);
				}
				else
					menu();
				break;
	}

	default:
	{
			   cout << "Invalid choice.Try Again" << endl;
			   menu();
	}
	}

}

void add_expense()
{
	char choice; int i = 0;
	system("CLS");
	

	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
	cout << setw(65) << "|" << "\t      Add Expense " << setw(13) << " | " << endl;
	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;

	
	long int expenses;
	string data;
	cout << "Today:" << asctime(localtime(&timetoday)) << endl;
	

	fstream file;

	file.open(active_user+" expenses", ios::out|ios::app);
	cout << "Add todays expenses:" << endl;
	do{
		i += 1;
		cout << "\nEnter expense " << i << ":\n";
		cin.ignore();
		cout << "Place of expeniture: "; 
		getline(cin, data);
		cout << "Amount of expeniture: "; 
		cin >> expenses;
		file << data<<endl;
		file << expenses<<endl;
		cout << "Again?(Y/N)";
		cin >> choice;

	} while (choice == 'y' || choice == 'Y');
	
	cout << endl << endl << "Expenses written..." << endl;
	file.close();

	////Adding name of record in a user specific file for record keeping
	//file.open(active_user, ios::out | ios::app);
	//file << day_date << endl;
	//file.close();

	cout << "Press any key to go back to menu";
	cin.ignore();	cin.ignore();
	system("CLS");
	menu();
}

void view_expense()
{
	system("CLS");
	
	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
	cout << setw(65) << "|" << "\t     View        " << setw(13) << " | " << endl;
	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;

	string data;
	fstream file;
	file.open(active_user+" expenses");

	if (file.fail())
	{
		cout << endl << endl << "ERROR.Failed to open file.\nTry again";
		cin.ignore();
		menu();
	}
	
	else
	{
		while (!file.eof())
		{
			getline(file, data);
			cout << data <<":";
			getline(file, data);
			cout << data <<endl;
		} 
	}
	file.close();

	cout << endl << endl << "Press any key to go back to menu.";
	cin.ignore(); cin.ignore();
	menu();
}

void bill()
{
	system("CLS");
	
	string disc[50];
	int exp[50];
	string disc_2;
	int bill=0;
	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
	cout << setw(65) << "|" << "\t      TOTAL " << setw(13) << " | " << endl;
	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;

	fstream file;
	file.open (active_user + " expenses", ios::in);
	int i = 0;
	if (!file)
	{
		cout << "No Account exists. Create account first.";
		cin.ignore(); cin.ignore();
		sign_up();
	}

	else
	{
		while (!file.eof())
		{
			file >> disc[i];
			file >> disc_2;
			i += 1;
		}
		
	}
	
	for (int j = 1; j <i-1 ; j++)
	{
		exp[j] = stoi(disc[j]);
		bill += exp[j];
		
	}

	cout <<"Total of all the entries is: "<< bill;
		file.close();
		system("pause");
		menu();
}
