#include "../../includes/px/Token.h"

#include <string>
#include <iostream>
#include <typeinfo>

TK::Token::Token()
{ 
	// default ctor 
}

TK::Token::Token(std::string img, std::string cls, int idx, int ln, int cl) :  image(img), class_(cls), index(idx), line(ln), column(cl)
{
	
}


std::string TK::Token::getImage()
{
	return this->image;
}

void TK::Token::setImage(std::string image)
{
	this->image = image;
}

std::string TK::Token::getClass_()
{
	return this->class_;
}

void TK::Token::setClass_(std::string class_)
{
	this->class_ = class_;
}

int TK::Token::getIndex()
{
	return this->index;
}

void TK::Token::setIndex(int index)
{
	this->index = index;
}

int TK::Token::getLine()
{
	return this->line;
}

void TK::Token::setLine(int line)
{
	this->line = line;
}

int TK::Token::getColumn()
{
	return this->column;
}

void TK::Token::setColumn(int column)
{
	this->column = column;
}

std::string TK::Token::showTokenParams()
{
	std::cout << "Token  [class=" << this->class_ << ", column=" << this->column << ", image=" << this->image << ", index=" << this->index << ", line=" << this->line << "]" << std::endl;
}

unsigned int TK::Token::generateHash(const char * string, size_t len)
{
	unsigned int hash = 0;
    for(size_t i = 0; i < len; ++i) 
        hash = 65599 * hash + string[i];
    return hash ^ (hash >> 16);
}

// Overloads the compare method
template<typename T>
bool TK::Token::compare(T& obj)
{
	if(this == obj)
		return true;
	if(obj == NULL)
		return false;
	if(typeid(Token).name() != typeid(obj).name())
		return false;

	// Cast the value of T obj to Token object
	TK::Token other = (TK::Token) obj;
	if(class_.empty())
	{
		if(other.class_.empty())
			return false;
	}
	else if(!(class_ == other.class_))
		return false;
	if(image.empty())
	{
		if(other.image.empty())
			return false;
	}
	else if(!(image == other.image))
	{
		return false;
	}

	return true;
}