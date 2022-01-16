#pragma once
#include <string>

class Error {
public:
	Error(std::string error_name, std::string details) {
		this->error_name = error_name;
		this->details = details;
	}

	std::string str() {
		std::string result = "\033[1;31m[" + error_name + "]\033[0m : " + details;
		return result;
	}

private:
	std::string error_name, details;
};

class IllegalWordError : public Error {
public:
	IllegalWordError(std::string details) : Error("ILLEGAL WORD", details) {
	}
};
