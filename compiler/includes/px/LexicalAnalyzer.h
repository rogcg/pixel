#ifndef LEXICAL_ANALYZER_CPP_H
#define LEXICAL_ANALYZER_CPP_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <array>

#include "Token.h"
#include "StaticTables.h"
#include "SymbolsTable.h"

namespace LA
{

	class LexicalAnalyzer
	{
	    public:
	        std::ifstream& indata;
	        std::vector<TK::Token> tokens;
	        std::vector<std::string> errors;
	        ST::StaticTables staticTables;
    		SYT::SymbolsTable symbolsTable;
    		std::array<int, 2> quotePositions{{-1,-1}};
		    
		    LexicalAnalyzer(std::ifstream&);
		    void analyze();
		    bool hasError();
		    std::vector<std::string> processImage(std::string image);
		    void processString(std::string currentLine);
		    void processImage(std::string image, int lineNumber);
		    void showErrors();
		    static void printError(std::string error);
		    void showTokens();
		    static void printToken(TK::Token token);
	};

}

#endif // LEXICAL_ANALYZER_CPP_H

