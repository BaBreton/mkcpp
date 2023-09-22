#include "../include/mkcpp.hpp"

void	Config::userOptions() {
	string	inputUser;
	string	tmp;

	system("clear");
	(HEADER(), NL());
fl:
	cout << "Type a name for the folder: ";
	this->getInput(cin, inputUser);
	if (inputUser.empty()) {
		displayInvalidCreationInput(); goto fl; }
	_creation.push_back("fl-" + inputUser);
	(system("clear"), HEADER(), NL());
ex:
	cout << "Type a name for the executable: ";
	this->getInput(cin, inputUser);
	if (inputUser.empty()) {
		displayInvalidCreationInput(); goto ex; }
	_creation.push_back("ex-" + inputUser);
ob:
	(system("clear"), HEADER(), NL());
	cout << "Please type your objects names, one by one, and type \033[1;31mEND\033[0m when you're done" << endl;
	while (getline(cin, inputUser) && inputUser != "END") {
		if (inputUser.empty())
			goto ob;
		_creation.push_back("ob-" + inputUser);
	}
	(system("clear"), HEADER(), NL());
	/*valeurs prives(Y/N) type - nom - geter(Y/N) - setter(Y/N) - END*/
	for (const string& str : _creation)
		cout << str << endl;
}