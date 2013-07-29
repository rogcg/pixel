#ifndef STATIC_TABLES_CPP_H
#define STATIC_TABLES_CPP_H

#include <string>

class ParameterizedValues
{
	public:
		// Reservated words
		static std::string def = "def";
		static std::string main = "main";
		static std::string int_ = "int";
		static std::string str = "str";
		static std::string ret = "ret";
		static std::string if_ = "if";
		static std::string while_ = "while";
		static std::string read = "read";
		static std::string print = "print";
		static std::string real = "real";

		// Delimiters
		static std::string open_parenth = "(";		
		static std::string close_parenth = ")";		
		static std::string open_bracket = "[";		
		static std::string close_bracket = "]";		

		// Operators
		static std::string equal = "=";
		static std::string plus = "+";
		static std::string minus = "-";
		static std::string greater_than = ">";
		static std::string lesser_than = "<";
		static std::string lesser_equal_to = "<=";
		static std::string greater_equal_to = ">=";
		static std::string equal_to = "==";
		static std::string diff_to = "!=";
};

#endif STATIC_TABLES_CPP_H