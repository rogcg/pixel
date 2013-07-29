#include "../../includes/px/LabelGenerator.h"

#include <string>

std::string LG::LabelGenerator::getNextLabel()
{
	std::string label = "label" + n;
	n++;
	return label;
}

std::string LG::LabelGenerator::getNextTemp()
{
	std::string temp = "temp" + i;
	i++;
	return temp;
}