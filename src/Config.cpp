

#include "../include/mkcpp.hpp"

/*
	** Constructors and destructors
*/
Config::Config(char **env) : _env(env) { initHeader(); }
Config::~Config() {};


/*
	** Setup functions
*/
void Config::start() {
	if (this->_header.empty())
		this->_header = "/*\n\t* Project name : mkCPP\n\t* Contibutors : BaBreton, cparras\n\t* Creation date : 19/09/2023\n*/";
	system("clear");
	ifstream("./.assets/stateFile") ? navigationMenu() : firstConfig();
}

void	Config::initHeader() {
	ifstream	input("maybeHeader.txt");
	string line;

	if (!input)
		return;
	
	while (getline(input, line))
		_header += "\t" + line + "\n";
	
	input.close();
}

void	Config::includes(bool customIncludes) {
	_includes.push_back("<iostream>\n");
	_includes.push_back("<string>\n");

	if (!customIncludes)
		return ;

	cout << "Please type your includes, one by one, and type \033[1;31mEND\033[0m when you're done" << endl;

	string userLibrary;
	while (getline(cin, userLibrary) && userLibrary != "END") {
		_includes.push_back("<" + userLibrary + ">" + '\n');
		displayPersonalIncludesMenu();
	}
	return ;
}

/*
	** Random functions
*/

void	Config::navigationMenu() {
	string		inputUser;

	restart :
		system("clear");
		(HEADER(), NL());
		(centerText("Welcome in your fancy CPP sources file creator"), NL());
		(centerText("-- Please select one --"), NL());
		displayMenu();
	
	cout << endl << "Your choice: ";
	this->getInput(cin, inputUser);
	if (inputUser.length() < 1)
		goto restart;

	int option = stoul(inputUser);

	switch (option) {
		case 1:
			userOptions();
			break;
		case 2:
			makeConfigFile();
			break;
		case 3:
			displayConfigFile();
			goto restart;
		case 4:
			moduleMenu();
			break;
		case 5:
			credits();
			goto restart;
		case 6:
			programExit();
			break;
		default:
			goto restart;
	}
}

void	Config::firstConfig()
{
	string response;

	start :
		system("clear");
		HEADER();
		this->centerText("Welcome in your fancy CPP sources file creator");
		this->centerText("This helper will automatically create file tree for your projects");
		this->centerText("Would you like to continue? [Y/N]");
	
	// get the user response
	int yesOrNo = this->yesNo(1);

	if (yesOrNo == -1) // is not yes or no
		goto start;

	else if (yesOrNo == 0) // is no
		navigationMenu();

	makeConfigFile(); // is yes
}

int Config::yesNo(int statut) {
	std::string response;

	here :
		this->getInput(cin, response);
	if (response.length() >= 2 || (toupper(response[0]) != 'Y' && toupper(response[0]) != 'N'))
	{
		switch (statut) {
			case 1:
				return -1;
			case 2:
				displayInvalidIncludeInput();
				goto here;
			case 3:
				displayInvalidCanonInput();
				goto here;
			default:
				break;
		}
		goto here;
	}
	if (response.length() < 1 && toupper(response[0]) != 'Y' && toupper(response[0]) != 'N')
		return -1;
	response = toupper(response[0]);

	return response == "Y" ? 1 : 0;
}

bool	Config::getInput(istream & flow, string & input) {
	getline(flow, input);
	if (flow.eof())
		exit(1);
	else
		return true;
}

void	Config::programExit()
{
	system("clear");
	HEADER();
	centerText("Thank you for using mkCPP");
	centerText("See you soon");
	this->~Config();
	exit(0);
}