#ifndef CommandReader_h
#define CommandReader_h

class CommandReader {
	public:
		CommandReader(Controller *controller);
		void readCommand();
	private:
		Controller* controller;
		std::set<std::string> commands = 
			{
				"help",
				"add",
				"dptadd",
				"remove",
				"dptremove",
				"edit",
				"dptedit",
				"edit",
				"dptedit",
				"ls",
				"dptls",
				"show"
			};
		bool invalidOrder(string command);
		void errorMessage(string command);
		void treatCommand(string command);
};

#endif