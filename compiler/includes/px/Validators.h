#ifndef VALIDATORS_CPP_H
#define VALIDATORS_CPP_H

#include <string>

namespace VLD
{
	class Validators
	{
		public:
			static bool isAlphaNumeric(std::string);
			static bool isStr(std::string);
			static bool isReal(std::string);
			static bool isInt(std::string);
	};

}

#endif // VALIDATORS_CPP_H