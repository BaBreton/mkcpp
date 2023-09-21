#include "../include/mkcpp.hpp"

void	Config::makeConfigFile() {
	string		input;
	ofstream	file("./.assets/stateFile");
	string		allInput;

	login :
		system("clear");
		HEADER();
		cout << "Please type your login: ";
		this->getInput(cin, input);
		if (input.empty())
			goto login;
		allInput += "lo-" + input + "\n";
	
	mail :
		system("clear");
		HEADER();
		cout << "Please type your email: ";
		this->getInput(cin, input);
		if (input.empty())
			goto mail;
		allInput += "ml-" + input + "\n";
	
	// includes
	system("clear");
	HEADER();
	cout << "Do you want personilized includes [Y/N] ?" << endl << "Default includes are <iostream> and <string> ";
	yesNo(2) == 1 ? includes(true) : includes(false);
	for (const string& inc : _includes)
		allInput += "##-" + inc;
	
	// canonical form
	system("clear");
	HEADER();
	cout << "Do you want your class in canonical form ? [Y/N] ";
	allInput += yesNo(3) == 1 ? "ca-YES" : "ca-NO";
	system("clear");
	HEADER();
	
	if (file.is_open())
		file << allInput << endl;

	file.close();

	start(); // Restart the program
}

void Config::moduleMenu() {
	displayModuleMenu();

	string input;
	this->getInput(cin, input);
	if (input.length() < 1)
		moduleMenu();

	int option = stoul(input);

	switch (option) {
		case 1:
			cout << "You chose option 1" << endl;
			break;
		case 2:
			cout << "You chose option 2" << endl;
			break;
		case 3:
			cout << "You chose option 3" << endl;
			break;
		case 4:
			cout << "You chose option 4" << endl;
			break;
		case 5:
			cout << "You chose option 5" << endl;
			break;
		case 6:
			cout << "You chose option 6" << endl;
			break;
		case 7:
			cout << "You chose option 7" << endl;
			break;
		case 8:
			cout << "You chose option 8" << endl;
			break;
		case 9:
			cout << "You chose option 9" << endl;
			break;
		default:
			moduleMenu();
	}
}