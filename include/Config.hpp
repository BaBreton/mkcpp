#ifndef CONFIG_HPP
#define CONFIG_HPP

#define NL(void) cout << endl
#define HEADER() cout << this->_header << endl

#define BS "\033[1m"
#define BE "\033[0m"

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
		void	displayPersonalIncludesMenu() const;
		void	displayInvalidIncludeInput() const;
		void	displayInvalidCanonInput() const;
		void	displayMenu() const;
		void	centerText(std::string const text);
        void	displayConfigFile();
        void	credits();
		
        // Random functions
		void	includes(bool customIncludes);
		int 	yesNo(int statut);
        void	programExit();

        // Menu functions
        void	choseModule();
};

#endif