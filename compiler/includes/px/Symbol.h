#ifndef SYMBOL_CPP_H
#define SYMBOL_CPP_H

#include "Token.h"

#include <string>

namespace SY
{
	class Symbol
	{
		private:
			TK::Token token;
			std::string type;
			std::string nick;
		
		public:
			Symbol();
			Symbol(TK::Token, std::string);
			std::string getNick();
			void setNick(std::string nick);
			TK::Token getToken();
			void setToken(TK::Token token);
			std::string getType();
			void setType(std::string type);
	};
}

#endif // SYMBOL_CPP_H