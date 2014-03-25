#ifndef STATIC_TABLES_CPP_H
#define STATIC_TABLES_CPP_H

#include "Token.h"

#include <vector>
#include <string>

namespace ST
{
	class StaticTables
	{
		public:
			std::vector<std::string> reservedWords;
			std::vector<std::string> operators;
			std::vector<std::string> delimiters;
			std::vector<TK::Token> tokens;

			std::vector<std::string> initializeReservedWords();
			std::vector<std::string> initializeDelimiters();
			std::vector<std::string> initializeOperators();
			bool isReservedWord(std::string image);
			bool isDelimiter(std::string image);
			bool isOperator(std::string image);
	};
}



#endif // LEXICAL_ANALYZER_CPP_H