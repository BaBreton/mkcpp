#include "../include/mkcpp.hpp"

string	Config::privateValues() {
	string	inputUser;
	string	value;

one:
	(system("clear"), HEADER(), NL());
	cout << "Please write the type of your variable: ";
	this->getInput(cin, inputUser);
	if (inputUser.empty())
		goto one;
	value = "pv-" + inputUser + "\t";
two:
	(system("clear"), HEADER(), NL());
	cout << "Please write the name of your variable: ";
	this->getInput(cin, inputUser);
	if (inputUser.empty())
		goto two;
	value += inputUser + ";";
	(system("clear"), HEADER(), NL());
	cout << "Do you need a getter for this variable ? [Y/N] ";
	yesNo(6) == 1 ? value += " G" : value;
	(system("clear"), HEADER(), NL());
	cout << "Do you need a setter for this variable ? [Y/N] ";
	yesNo(7) == 1 ? value += " S" : value;
	return value;
}

void	Config::userOptions() {
	string	inputUser;
	bool	moreVars;

	system("clear");
	(HEADER(), NL());
fl:
	cout << "Type a name for the folder: ";
	this->getInput(cin, inputUser);
	if (inputUser.empty()) {
		displayInvalidCreationInput(0); goto fl; }
	_creation.push_back("fl-" + inputUser);
	(system("clear"), HEADER(), NL());
ex:
	cout << "Type a name for the executable: ";
	this->getInput(cin, inputUser);
	if (inputUser.empty()) {
		displayInvalidCreationInput(0); goto ex; }
	_creation.push_back("ex-" + inputUser);
ob:
	(system("clear"), HEADER(), NL());
	cout << "Please type your class names, one by one, and type \033[1;31mEND\033[0m when you're done" << endl;
	while (getline(cin, inputUser) && inputUser != "END") {
		if (inputUser.empty())
			goto ob;
		_creation.push_back("ob-" + inputUser);
		(system("clear"), HEADER(), NL());
		cout << "Do you want to create private variable ? [Y/N] ";
		yesNo(5) == 1 ? moreVars = 1 : moreVars = 0;
		while (moreVars) {
    		_creation.push_back(privateValues());
   			cout << "Do you want to create one more private variable? [Y/N] ";
    		yesNo(5) == 1 ? moreVars = 1: moreVars = 0;
	}
	goto ob;
	}
	
	for (const string& str : _creation)
		cout << str << endl;
}