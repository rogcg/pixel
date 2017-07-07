#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>

#include "../../includes/px/SymbolsTable.h"
#include "../../includes/px/Symbol.h"
#include "../../includes/px/Token.h"
#include "../../includes/px/LabelGenerator.h"

// initializing the static vectors
std::vector<SY::Symbol> SYT::SymbolsTable::s_symbols;
std::vector<SY::Symbol> SYT::SymbolsTable::s_literalStrings;

void SYT::SymbolsTable::addToken(TK::Token token, std::string type)
{
	int index = getSymbolIndex(token);

	if(index == -1)
	{
		SY::Symbol symb(token, type);
		SYT::SymbolsTable::s_symbols.push_back(symb);
		token.setIndex(indexOf(SYT::SymbolsTable::s_symbols, symb));
	}
	else
	{
		token.setIndex(index);
	}
}

void SYT::SymbolsTable::addLiteralStringToken(TK::Token token, std::string type)
{
	SY::Symbol symb(token, type);

	LG::LabelGenerator lg; // Creates a new instance of LabelGenerator class
	symb.setNick(lg.getNextTemp());
	SYT::SymbolsTable::s_literalStrings.push_back(symb);
	token.setIndex(indexOf(SYT::SymbolsTable::s_literalStrings, symb));
}

void SYT::SymbolsTable::setTokenType(TK::Token token, std::string type)
{
	SY::Symbol symb = SYT::SymbolsTable::s_symbols.at(getSymbolIndex(token));

	if(symb.getToken().getImage() != "")
	{
		symb.setType(type);
	}
	else
	{
		std::cerr << "Nonexistent symbol." << std::endl;
	}
}

std::string SYT::SymbolsTable::getTokenType(TK::Token token)
{
	SY::Symbol symb = SYT::SymbolsTable::s_symbols.at(getSymbolIndex(token));

	if(symb.getToken().getImage() != "")
	{
		symb.getType();
	}
	else
	{
		std::cerr << "Nonexistent symbol." << std::endl;
	}
}

std::string SYT::SymbolsTable::getTokenImage(TK::Token token)
{
	SY::Symbol symb = SYT::SymbolsTable::s_symbols.at(getSymbolIndex(token));

	if (symb.getToken().getImage() != "")
	{
		return symb.getToken().getImage();
	}
	else
	{
		std::cerr << "Nonexistent symbol on the table." << std::endl;
	}
}

int SYT::SymbolsTable::getSymbolIndex(TK::Token token)
{
	for(int i = 0; i < SYT::SymbolsTable::s_symbols.size(); i++)
	{
		if(SYT::SymbolsTable::s_symbols.at(i).getToken().getImage() == token.getImage())
		{
			return i;
		}
	}
	return -1;
}

int SYT::SymbolsTable::indexOf(std::vector<SY::Symbol> symbols, SY::Symbol symbol)
{
	for(std::vector<int>::size_type i = symbols.size() - 1; i != (std::vector<int>::size_type) -1; i--)
	{
		if(symbols.at(i).getNick() == symbol.getNick())
		{
			return i;
		}
	}
}

std::string SYT::SymbolsTable::getConstantType(TK::Token token)
{
	if(token.getClass_() == "ILC")
	{
		return "int";
	}
	else if(token.getClass_() == "SLC")
	{
		return "str";
	}
	else if(token.getClass_() == "RLC")
	{
		return "real";
	}

	return "";
}

void SYT::SymbolsTable::showSymbolsTable()
{
	std::cout << "Symbols List -> " << std::endl;
  for(int i = 0; i < SYT::SymbolsTable::s_symbols.size(); i++)
	{
		 std::cout << "token: " << SYT::SymbolsTable::s_symbols.at(i).getToken().getImage() << " - type: " << SYT::SymbolsTable::s_symbols.at(i).getType() << std::endl;
	}
}

void SYT::SymbolsTable::showSymbolsTableSLC()
{
	std::cout << "SLC Symbols List ->" << std::endl;
    for(std::vector<int>::size_type i = SYT::SymbolsTable::s_literalStrings.size() - 1; i != (std::vector<int>::size_type) -1; i--)
	{
		 std::cout << "token: " << SYT::SymbolsTable::s_literalStrings.at(i).getToken().getImage() << " - type: " << SYT::SymbolsTable::s_literalStrings.at(i).getType() << std::endl;
	}
}
