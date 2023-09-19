

#include "../include/mkcpp.hpp"

/*
	** Constructors and destructors
*/
Config::Config() { initHeader(); }
Config::~Config() {};


/*
	** Setup functions
*/
void Config::start() {
	if (this->_header.empty())
		this->_header = "/*\n\t* Project name : mkCPP\n\t* Contibutors : BaBreton, cparras\n\t* Creation date : 19/09/2023\n*/";
	system("clear");
	ifstream("./assets/stateFile") ? speak() : firstConfig();
}

void	Config::initHeader() {
	ifstream	input(".maybeHeader.txt");
	string line;

	if (input)
		(cerr << "Error opening file." << endl, return);
	
	while (getline(input, line))
		_header += "\t" + line + "\n";
	
	input.close();
}

void	Config::includes(bool customIncludes) {
	_includes.push_back("<iostream>\n");
	_includes.push_back("<string>\n");

	if (!customIncludes)
		return;
	cout << "Please type your includes, one by one, and type END when you're done" << endl;
	while (getline(cin, s) && s != "END")
		_includes.push_back("<" + s + ">" + '\n');
}

/*
	** Random functions
*/

void	Config::navigationMenu() {
	string		inputUser;

	restart :
		(HEADER(), NL());
		(centerText("Welcome in your fancy CPP sources file creator"), NL());
		(centerText("-- Please select one --"), NL());
		displayMenu();
	
	cout << endl << "Your choice: ";
	getline(cin, inputUser);
	if (inputUser.length() < 1)
		(system("clear"), goto here);

	int option = stoul(inputUser);

	switch (option) {
		case 1:
			std::cout << "You chose option 1" << std::endl;
			break;
		case 2:
			makeConfigFile();
			break;
		case 3:
			displayConfigFile();
			break;
		case 4:
			choseModule();
			break;
		case 5:
			credits();
			break;
		case 6:
			programExit();
			break;
		default:
			(system("clear"), goto restart);
	}
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
	getline(cin, input);
	file << this->includes();
	system("clear");
	HEADER();
	cout << "Do you want your class in canonical form ? [Y/N] ";
	getline(cin, input); /*Enjection + fonction*/
	system("clear");
	HEADER();
}

void	Config::firstConfig()
{
	string response;

	start:
		system("clear");
		HEADER();
		this->centerText("Welcome in your fancy CPP sources file creator");
		this->centerText("This helper will automatically create file tree for your projects");
		this->centerText("Would you like to continue? [Y/N]");
		
	// parse response
	getline(cin, response);
	if (response.length() < 1)
		goto start;
	response = toupper(response[0]);

	if (response != "Y")
		(cout << "Goodbye!" << endl, exit(1));
	makeConfigFile();
}
