#include "../include/mkcpp.hpp"

void	Config::displayConfigFile() {
    ifstream	file("./assets/stateFile");
    string		line;

    system("clear");
    HEADER();
    while (getline(file, line))
        cout << line << endl;
    file.close();
}

void    Config::choseModule() {
    std::cout << "You chose option 4" << std::endl;

    std::cout << "Endless void here (:" << std::endl;
    cin.get();
}

void	Config::makeConfigFile() {
	string		input;
	ofstream	file("./assets/stateFile");
	string		tmp;

	system("clear");
	HEADER();
	cout << "Please type your login: ";
	getline(cin, input);
	file << input << endl;
	system("clear");
	HEADER();
	cout << "Please type your email: ";
	getline(cin, input);
	file << input << endl;
	system("clear");
	HEADER();
	cout << "Do you want personilized includes [Y/N] ?" << endl << "Default includes are <iostream> and <string> ";
	yesNo() == 1 ? includes(true) : includes(false);
	system("clear");
	HEADER();
	cout << "Do you want your class in canonical form ? [Y/N] ";
	getline(cin, input); /*Enjection + fonction*/
	system("clear");
	HEADER();
}