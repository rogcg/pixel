#include "../../includes/px/StaticTables.h"

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
    
// Initialize the reservated words
std::vector<std::string> ST::StaticTables::initializeReservatedWords()
{
	//std::cout<< "Initializing reservated words.." << std::endl;

	reservatedWords.push_back("def");
	reservatedWords.push_back("main");
	reservatedWords.push_back("int");
	reservatedWords.push_back("str");
	reservatedWords.push_back("real");
	reservatedWords.push_back("ret");
	reservatedWords.push_back("if");
	reservatedWords.push_back("while");
	reservatedWords.push_back("read");
	reservatedWords.push_back("print");

	return reservatedWords;
}

// Initialize the delimiters
std::vector<std::string> ST::StaticTables::initializeDelimiters()
{
	//std::cout<< "Initializing delimiters.." << std::endl;

	delimiters.push_back("()"); // empty_parenth
	delimiters.push_back("("); // open_parenth
	delimiters.push_back(")"); // close_parenth
	delimiters.push_back("[]"); // empty_brackets
	delimiters.push_back("["); // open_bracket
	delimiters.push_back("]"); // close_bracket

	return delimiters;
}

// Initialize the operators
std::vector<std::string> ST::StaticTables::initializeOperators()
{
	//std::cout<< "Initializing operators.." << std::endl;

	operators.push_back("="); // equal
	operators.push_back("+"); // plus
	operators.push_back("-"); // minus
	operators.push_back(">"); // greater_than
	operators.push_back("<"); // lesser_than
	operators.push_back("<="); // lesser_equal_to
	operators.push_back(">="); // greater_equal_to
	operators.push_back("=="); // equal_to
	operators.push_back("!="); // diff_to

	return operators;
}

// Check if the image received as parameters is a reservated word
bool ST::StaticTables::isReservatedWord(std::string image)
{
	reservatedWords = initializeReservatedWords();

	if(std::find(reservatedWords.begin(), reservatedWords.end(), image) != reservatedWords.end())
	{
		//std::cout << "found!" << std::endl;
		return true;
	}
	else 
	{
		//std::cout << "not found!" << std::endl;
		return false;
	}
}

// Check if the image received as parameters is a delimiter
bool ST::StaticTables::isDelimiter(std::string image)
{
	delimiters = initializeDelimiters();

	if(std::find(delimiters.begin(), delimiters.end(), image) != delimiters.end())
	{
		//std::cout << "found!" << std::endl;
		return true;
	}
	else 
	{
		//std::cout << "not found!" << std::endl;
		return false;
	}
}

// Check if the image received as parameters is an operator
bool ST::StaticTables::isOperator(std::string image)
{
	operators = initializeOperators();

	if(std::find(operators.begin(), operators.end(), image) != operators.end())
	{
		//std::cout << "found!" << std::endl;
		return true;
	}
	else 
	{
		//std::cout << "not found!" << std::endl;
		return false;
	}
}