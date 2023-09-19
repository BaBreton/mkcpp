#include "../include/mkcpp.hpp"

void	Config::centerText(string const text) {
    int totalWidth = 80;
    int textWidth = text.length();

    if (textWidth >= totalWidth)
        std::cout << text << std::endl;
    else
        std::cout << std::string((totalWidth - textWidth) / 2, ' ') << text << std::endl;
}

void	Config::displayMenu() const {
	cout << "\t\033[1;32m/ 1 /\033[0m Start with your current config" << endl;
	cout << "\t\033[1;32m/ 2 /\033[0m Change config" << endl;
	cout << "\t\033[1;32m/ 3 /\033[0m Check config" << endl;
	cout << "\t\033[1;32m/ 4 /\033[0m Create files for 42 CPP modules" << endl;
	cout << "\t\033[1;33m/ 5 /\033[0m Credits" << endl;
	cout << "\t\033[1;31m/ 6 /\033[0m Exit" << endl;
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