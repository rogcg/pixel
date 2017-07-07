#ifndef LABEL_GENERATOR_CPP_H
#define LABEL_GENERATOR_CPP_H

#include <string>

namespace LG
{
	class LabelGenerator
	{
		public:
			int i= 0;
			int n = 0;

			std::string getNextLabel();
			std::string getNextTemp();
	};
}

#endif // LABEL_GENERATOR_CPP_H
