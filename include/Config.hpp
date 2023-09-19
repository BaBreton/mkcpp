#ifndef CONFIG_HPP
#define CONFIG_HPP

#define NL(void) cout << endl
#define HEADER() cout << this->_header << endl

class Config {
	private:
		std::string		_header;
		vector<string>	_includes;
        char            **_env;
	
	public:
        Config();
		Config(char **env);
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
        void	credits();
		
        // Random functions
		void	includes(bool customIncludes);
		int 	yesNo();
        void	programExit();

        // Menu functions
        void	displayConfigFile();
        void	choseModule();
};

#endif