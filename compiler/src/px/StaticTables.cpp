#include "../../includes/px/StaticTables.h"

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
    
// Initialize the reservated words
std::vector<std::string> ST::StaticTables::initializeReservedWords()
{
	//std::cout<< "Initializing reserved words.." << std::endl;

	reservedWords.push_back("def");
	reservedWords.push_back("main");
	reservedWords.push_back("int");
	reservedWords.push_back("str");
	reservedWords.push_back("real");
	reservedWords.push_back("ret");
	reservedWords.push_back("if");
	reservedWords.push_back("else");
	reservedWords.push_back("while");
	reservedWords.push_back("read");
	reservedWords.push_back("print");

	return reservedWords;
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
bool ST::StaticTables::isReservedWord(std::string image)
{
	reservedWords = initializeReservedWords();

	if(std::find(reservedWords.begin(), reservedWords.end(), image) != reservedWords.end())
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