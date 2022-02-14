#pragma once
#include <string>

class Error {
public:
	Error(std::string error_name, std::string details, bool warning = false, bool add_eol = false) {
		this->error_name = error_name;
		this->details = details;
		this->warning = warning;
		this->add_eol = add_eol;
	}

	std::string str() {
		std::string result, eol_mark = (add_eol) ? " <-" : "";
		if(warning)
			result = "\033[0;34m[" + error_name + "]\033[0m : " + details + eol_mark;
		else
			result = "\033[1;31m[" + error_name + "]\033[0m : " + details + eol_mark;
		return result;
	}

private:
	std::string error_name, details;
	bool warning, add_eol;
};

class IllegalWordError : public Error {
public:
	IllegalWordError(std::string details) : Error("ILLEGAL WORD", details) { }
};

class IllegalLineEnding : public Error {
public:
	IllegalLineEnding(std::string details) : Error("ILLEGAL LINE ENDING", details, true, true) { }
};

class InvalidSyntax : public Error {
public:
	InvalidSyntax(std::string details) : Error("INVALID SYNTAX", details, false, true) { }
};
