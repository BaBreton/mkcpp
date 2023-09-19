#ifndef CONFIG_HPP
#define CONFIG_HPP

#define NL cout << 

class Config {
	public:
		Config();
		~Config();

		void	firstConfig();
		void	putHeader();
		void	speak();
		void	menu() const;
		void	centerText(string const text);
		void	stateFile();
		string	includes(string s);
		bool	yesNo() const;
	private:
};

#endif