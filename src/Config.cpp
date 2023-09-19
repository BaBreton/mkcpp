

#include "../include/mkcpp.hpp"

Config::Config() {

	system("clear");
	ifstream("./.assets/.stateFile") ? this->speak() : this->firstConfig();
}

Config::~Config() {};

void	Config::speak() {
	string			pick;
	unsigned int	npick;

here :
	this->putHeader();
	cout << endl;
	this->centerText("Welcome in your fancy CPP sources file creator");
	cout << endl;
	this->centerText("-- Please select one --");
	cout << endl;
	this->menu();
	while (true)
	{
		cout << endl << "Your choice: ";
		getline(cin, pick);
		bool isDigit = true;
		for (char c : pick) {
			if (!isdigit(c)) {
				isDigit = false;
				break;
			}
		}
		if (!isDigit) {
			system("clear");
			goto here;
		}
		npick = stoul(pick);
		if (npick < 1 || npick > 6) {
			system("clear");
			goto here; }
		else
			// switch(pick)
			// {
			// case 1:
			// 	/* code */
			// 	break;
			
			// default:
				break;
			// }
	}
	cout << "sortie" << endl;
}

void	Config::centerText(string const text) {
    int totalWidth = 80;
    int textWidth = text.length();

    if (textWidth >= totalWidth) {
        std::cout << text << std::endl;
    } else {
        int padding = (totalWidth - textWidth) / 2;
        std::cout << std::string(padding, ' ') << text << std::endl;
    }
}

void	Config::menu() const {
	cout << "\t\033[1;32m/ 1 /\033[0m Start with your current config" << endl;
	cout << "\t\033[1;32m/ 2 /\033[0m Change config" << endl;
	cout << "\t\033[1;32m/ 3 /\033[0m Check config" << endl;
	cout << "\t\033[1;32m/ 4 /\033[0m Create files for 42 CPP modules" << endl;
	cout << "\t\033[1;33m/ 5 /\033[0m Credits" << endl;
	cout << "\t\033[1;31m/ 6 /\033[0m Exit" << endl;
}

void	Config::putHeader() {
	ifstream	input("./.assets/maybeHeader.txt");

	if (input) {
		string line;
		while (getline(input, line)) {
			cout << "\t" + line << endl;
		}
		input.close();
	}
	else {
		cout << "Error opening file." << endl;
		perror("open");
	}
}

string	Config::includes(string s) {
	string	inc;
	string	input;
	string	tmp;

	inc = "<iostream>\n<string>";
	if (!strcmp("Y", s.c_str())) {
	while (1)
	{
		getline(cin, input);
		if (!strcmp("END", input.c_str()))
			break ; 
		tmp = tmp + '<' + input + '>' + '\n';
	}
	}
	return tmp + inc;
}

void	Config::stateFile() {
	string		input;
	ofstream	file("./.assets/.stateFile");
	string		tmp;

	system("clear");
	this->putHeader();
	cout << "Please type your login: ";
	getline(cin, input);
	file << input << endl;
	system("clear");
	this->putHeader();
	cout << "Please type your email: ";
	getline(cin, input);
	file << input << endl;
	system("clear");
	this->putHeader();
	cout << "Do you want personilized includes [Y/N] ?" << endl << "Default includes are <iostream> and <string> ";
	getline(cin, input);
	file << this->includes(input);
	system("clear");
	this->putHeader();
	cout << "Do you want your class in canonical form ? [Y/N] ";
	getline(cin, input); /*Enjection + fonction*/
	system("clear");
	this->putHeader();
}

void	Config::firstConfig() {
	string response;

here:
	this->putHeader();
	this->centerText("Welcome in your fancy CPP sources file creator");
	this->centerText("This helper will automatically create file tree for your projects");
	this->centerText("Would you like to continue? [Y/N]");
	while (true) {
		getline(cin, response);
		std::transform(response.begin(), response.end(), response.begin(), ::toupper);
		if (response == "Y" || response == "N")
			break;
		else {
			system("clear");
			goto here;
		}
	}
	if (response == "Y") {
		this->stateFile();
	} else {
		exit(1);
	}
}
