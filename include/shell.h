#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "./lexer.h"
#include "./token.h"
#include "./parser.h"
#include "./nodes.h"
#include "./interpreter.h"
class Shell {
private:
	std::string ver_string(int maj, int min, int patch) {
		std::ostringstream ss;
		ss << maj << '.' << min << '.' << patch;
		return ss.str();
	}
public:
	Shell();
	std::string printTree(struct Nodes* tree);
	void run();

	std::string cxx = 
#ifdef __clang__
	"clang++";
#else
	"g++";
#endif

	std::string cxx_ver = 
#ifdef __clang__
	ver_string(__clang_major__, __clang_minor__, __clang_patchlevel__);
#else
	ver_string(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#endif


};
