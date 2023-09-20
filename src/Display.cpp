#include "../include/mkcpp.hpp"

void	Config::centerText(string const text) {
    int totalWidth = 80;
    int textWidth = text.length();

    if (textWidth >= totalWidth)
        std::cout << text << std::endl;
    else
        std::cout << std::string((totalWidth - textWidth) / 2, ' ') << text << std::endl;
}

void    Config::displayPersonalIncludesMenu() const {
    system("clear");
    HEADER();
    cout << "Do you want personilized includes [Y/N] ?" << endl << "Default includes are <iostream> and <string> y" << endl;
    cout << "Please type your includes, one by one, and type \033[1;31mEND\033[0m when you're done" << endl;
}

void    Config::displayInvalidIncludeInput() const {
    system("clear");
    HEADER();
    cout << "Do you want personilized includes [Y/N] ?" << endl << "Default includes are <iostream> and <string> ";
}

void    Config::displayInvalidCanonInput() const {
    system("clear");
    HEADER();
    cout << "Do you want your class in canonical form ? [Y/N] ";
}

void	Config::displayMenu() const {
	cout << "\t\033[1;32m/ 1 /\033[0m Start with your current config" << endl;
	cout << "\t\033[1;32m/ 2 /\033[0m Change config" << endl;
	cout << "\t\033[1;32m/ 3 /\033[0m Check config" << endl;
	cout << "\t\033[1;32m/ 4 /\033[0m Create files for 42 CPP modules" << endl;
	cout << "\t\033[1;33m/ 5 /\033[0m Credits" << endl;
	cout << "\t\033[1;31m/ 6 /\033[0m Exit" << endl;
}

void	Config::displayConfigFile() {
    ifstream	file("./assets/stateFile");
    string		line;

    system("clear");
    HEADER();
    NL();
    centerText("-- Your current configuration --");
    while (getline(file, line)) {
        if (!strncmp("lo-:", line.c_str(), 3))
            cout << BS << "Login: " << BE << line.substr(3) << endl;
        if (!strncmp("ml-:", line.c_str(), 3))
            cout << BS << "Mail: " << BE << line.substr(3) << endl;
        if (!strncmp("##-:", line.c_str(), 3))
        {
            cout << BS << "Includes:" << BE << endl;
            while (!strncmp("##-:", line.c_str(), 3)) {
                cout << "\t" << line.substr(3) << endl;
                getline(file, line);
            }
        }
        if (!strncmp("ca-:", line.c_str(), 3))
            cout << BS << "Canonical: " << BE << line.substr(3) << endl;
    }
    file.close();
	NL();
	centerText("Press enter to go back to the menu");
    cin.get();
}

void	Config::displayModuleMenu() const {
	
	system("clear");
	HEADER();
	
	cout << "Please select one of the following modules:" << endl;
	NL();

    // line 1
    cout << "\t\033[1;32m / 0 / \033[0m";
    cout << "CPP Module 00";

    cout << "\t\033[1;32m / 5 / \033[0m";
    cout << "CPP Module 05" << endl;

    // line 2
    cout << "\t\033[1;32m / 1 / \033[0m";
    cout << "CPP Module 01";

    cout << "\t\033[1;32m / 6 / \033[0m";
    cout << "CPP Module 06" << endl;

    // line 3
    cout << "\t\033[1;32m / 2 / \033[0m";
    cout << "CPP Module 02";

    cout << "\t\033[1;32m / 7 / \033[0m";
    cout << "CPP Module 07" << endl;

    // line 4
    cout << "\t\033[1;32m / 3 / \033[0m";
    cout << "CPP Module 03";

    cout << "\t\033[1;32m / 8 / \033[0m";
    cout << "CPP Module 08" << endl;

    // line 5
    cout << "\t\033[1;32m / 4 / \033[0m";
    cout << "CPP Module 04";

    cout << "\t\033[1;32m / 9 / \033[0m";
    cout << "CPP Module 09" << endl;

	cout << endl << "Your choice: ";
}

void    Config::credits() {
    system("clear");
    HEADER();
    cout << endl;
    centerText("This program was made by");
    centerText("Baptiste BRETON");
    centerText("and");
    centerText("Cyril PARRAS");
    NL();
    centerText("Thanks for using it !");
    NL();
    centerText("Press enter to go back to the menu");
    cin.get();
}