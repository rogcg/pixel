#ifndef TOKEN_CPP_H
#define TOKEN_CPP_H

#include <string>

namespace TK
{
	class Token
	{
		public:
			Token();
			Token(std::string, std::string, int, int, int);
			
			std::string getImage();
			void setImage(std::string image);
			std::string getClass_();
			void setClass_(std::string class_);
			int getIndex();
			void setIndex(int index);
			int getLine();
			void setLine(int line);
			int getColumn();
			void setColumn(int column);
			std::string showTokenParams();
			unsigned int generateHash(const char * string, size_t len);
			template<class T> bool compare (T& obj);

			std::string image;
			std::string class_;
			int index;
			int line;
			int column;
	};
}

#endif // TOKEN_CPP_H
