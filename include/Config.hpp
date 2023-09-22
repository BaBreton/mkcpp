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
		vector<string>	_creation;
        char            **_env;
	
	public:
        Config();
		Config(char **env);
		~Config();

		// Setup functions
		void	start();
		void	initHeader();
		void	firstConfig();

		// Display functions
		void	displayPersonalIncludesMenu() const;
		void    displayInvalidCreationInput();
		void	displayInvalidIncludeInput() const;
		void	displayInvalidCanonInput() const;
		void	displayModuleMenu() const;
		void	displayMenu() const;
		void	centerText(std::string const text);
        void	displayConfigFile();
        void	credits();
		
        // Random functions
		void	includes(bool customIncludes);
		int 	yesNo(int statut);
        void	programExit();
		bool	getInput(istream & flow, string & input);

        // Menu functions
        void	navigationMenu();
        void    moduleMenu();
        void    makeConfigFile();

		// Creation
		void	userOptions();
};

#endif