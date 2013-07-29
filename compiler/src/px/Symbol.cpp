#include "../../includes/px/Symbol.h"
#include "../../includes/px/Token.h"

#include <string>
#include <iostream>
#include <cstdlib>

SY::Symbol::Symbol(TK::Token tk, std::string tp) : token(tk), type(tp)
{
}

std::string SY::Symbol::getNick()
{
	return nick;
}

void SY::Symbol::setNick(std::string nk)
{
	nick = nk;
}

TK::Token SY::Symbol::getToken()
{
	return token;
}

void SY::Symbol::setToken(TK::Token tk)
{
	token = tk;
}

std::string SY::Symbol::getType()
{
	return type;
}

void SY::Symbol::setType(std::string tp)
{
	type = tp;
}
