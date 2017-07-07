#ifndef SYMBOLS_TABLE_CPP_H
#define SYMBOLS_TABLE_CPP_H

#include <vector>
#include <string>

#include "Token.h"
#include "Symbol.h"

namespace SYT
{
	class SymbolsTable
	{
		public:
			static std::vector<SY::Symbol> s_symbols;
			static std::vector<SY::Symbol> s_literalStrings;
			void addToken(TK::Token, std::string type);
			int getSymbolIndex(TK::Token);
			int indexOf(std::vector<SY::Symbol>, SY::Symbol);
			void addLiteralStringToken(TK::Token, std::string type);
			void setTokenType(TK::Token, std::string);
			std::string getTokenType(TK::Token);
			std::string getTokenImage(TK::Token);
			std::string getConstantType(TK::Token);
			void showSymbolsTable();
			void showSymbolsTableSLC();
	};
}

#endif // SYMBOLS_TABLE_CPP_H
