#ifndef CONFIG_HPP
#define CONFIG_HPP

#define NL(void) cout << endl
#define HEADER() cout << this->_header << endl

class Config {
	private:
		std::string		_header;
		vector<string>	_includes;
	
	public:
		Config();
		~Config();

		// Setup functions
		void	start();
		void	initHeader();
		void	firstConfig();
		void	makeConfigFile();

		// Display functions
		void	navigationMenu();
		void	displayMenu() const;
		void	centerText(std::string const text);
		

		void	includes(bool customIncludes);
		bool	yesNo() const;
};

#endif