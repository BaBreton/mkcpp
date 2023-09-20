#include "../include/mkcpp.hpp"

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
	file << "lo-" + input << endl;
	system("clear");
	HEADER();
	cout << "Please type your email: ";
	getline(cin, input);
	file << "ml-" + input << endl;
	system("clear");
	HEADER();
	cout << "Do you want personilized includes [Y/N] ?" << endl << "Default includes are <iostream> and <string> ";
	yesNo(2) == 1 ? includes(true) : includes(false);
	for (const string& inc : _includes) {
		file << "##-" + inc; }
	system("clear");
	HEADER();
	cout << "Do you want your class in canonical form ? [Y/N] ";
	yesNo(3) == 1 ? file << "ca-YES" : file << "ca-NO";
	system("clear");
	HEADER();
	file.close();
	/*UNE AUTRE FONCTION A METTRE ICI*/
	system("./mkcpp");
}