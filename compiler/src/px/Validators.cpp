#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <string>
#include <vector>
#include <exception>

#include <boost/regex.hpp>

#include "../../includes/px/Validators.h"

// check the image is alpha numeric (often identifiers)
bool VLD::Validators::isAlphaNumeric(std::string image)
{
	if(boost::regex_match(image, boost::regex("[a-z][a-z0-9]*")))
		return true;
	else
		return false;
}

// check the image is a string
bool VLD::Validators::isStr(std::string image)
{
	//std::cout << "is str: " << image << std::endl;

	if(boost::regex_match(image, boost::regex("\"[0-9a-zA-z.\" ]*")))
		return true;
	else
		return false;
}

// check the image is of 'real' type. e.g.: 8.888
bool VLD::Validators::isReal(std::string image)
{
	if(boost::regex_match(image, boost::regex("[0-9]+.[0-9]*[0-9]*.[0-9]+")))
		return true;
	else
		return false;
}

// check the image is an int
bool VLD::Validators::isInt(std::string image)
{
	if(boost::regex_match(image, boost::regex("[0-9]+")))
		return true;
	else
		return false;
}
