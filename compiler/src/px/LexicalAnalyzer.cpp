#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <string>
#include <vector>
#include <exception>
#include <array>
#include <exception>

#include <boost/regex.hpp>

#include "../../includes/px/Token.h"
#include "../../includes/px/SymbolsTable.h"
#include "../../includes/px/Symbol.h"
#include "../../includes/px/LexicalAnalyzer.h"
#include "../../includes/px/StaticTables.h"
#include "../../includes/px/Validators.h"

LA::LexicalAnalyzer::LexicalAnalyzer(std::ifstream& input) : indata(input)
{
    // ctor
}

// Makes the lexical analyzis
void LA::LexicalAnalyzer::analyze()
{
    std::string currentLine;
    int lineNumber = 0;
    std::vector<std::string> tokenizer;
    std::vector<std::string>::iterator it;

    try
    {
        while (std::getline(indata, currentLine))
        {
            lineNumber++;

            //std::cout << "current line: " << currentLine << std::endl;

            if(currentLine.find('\"') != std::string::npos)
            {                                
                processString(currentLine);        
            }
            else
            {
                std::istringstream iss(currentLine);                

                std::string image;
                while (iss >> image)
                {                
                    //std::cout << "image: " << image << std::endl;
                    processImage(image, lineNumber);
                }

                tokens.push_back(TK::Token("$", "EOF", -1, -1, -1));
            }
        }        
    }
    catch (boost::regex_error& e) 
    {
        std::cerr << "code " << e.code() << std::endl;
        if (e.code() == boost::regex_constants::error_collate)
            std::cerr << "The expression contained an invalid collating element name..\n";
        else if (e.code() == boost::regex_constants::error_ctype)
            std::cerr << "The expression contained an invalid character class name...\n";
        else if (e.code() == boost::regex_constants::error_escape)
            std::cerr << "The expression contained an invalid escaped character, or a trailing escape..\n";
        else if (e.code() == boost::regex_constants::error_backref)
            std::cerr << "The expression contained an invalid back reference...\n";
        else if (e.code() == boost::regex_constants::error_brack)
            std::cerr << "The expression contained mismatched brackets ([ and ])...\n";
        else if (e.code() == boost::regex_constants::error_paren)
            std::cerr << "The expression contained mismatched parentheses (( and ))..\n";
        else if (e.code() == boost::regex_constants::error_brace)
            std::cerr << "The expression contained mismatched braces ({ and })...\n";
        else if (e.code() == boost::regex_constants::error_badbrace)
            std::cerr << "The expression contained an invalid range between braces ({ and })..\n";
        else if (e.code() == boost::regex_constants::error_range)
            std::cerr << "The expression contained an invalid character range..\n";
        else if (e.code() == boost::regex_constants::error_space)
            std::cerr << "There was insufficient memory to convert the expression into a finite state machine.\n";
        else if (e.code() == boost::regex_constants::error_badrepeat)
            std::cerr << "The expression contained a repeat specifier (one of *?+{) that was not preceded by a valid regular expression..\n";
        else if (e.code() == boost::regex_constants::error_complexity)
            std::cerr << "The complexity of an attempted match against a regular expression exceeded a pre-set level..\n";
        else std::cerr << "Some other regex exception happened.\n";
    }    
}

// This is the main lexical processor. This method reads each token to know which symbol 
// it belongs to. In case a token is not recognized in one of its conditions, it will be 
// sent to a second processor, that will process the image deeply and return it again
// to this method.

void LA::LexicalAnalyzer::processImage(std::string image, int lineNumber)
{
    if(staticTables.isReservedWord(image))
    {
        TK::Token token(image, "RW", -1, lineNumber, 0);
        tokens.push_back(token);
        symbolsTable.addToken(token);
        std::cout << "isReservedWord (" << image << ")" << std::endl;
    }
    else if(staticTables.isDelimiter(image))
    {
        TK::Token token(image, "DE", -1, lineNumber, 0);
        tokens.push_back(token);
        symbolsTable.addToken(token);
        std::cout << "isDelimiter (" << image << ")" << std::endl;
    }
    // check the identifiers
    else if(VLD::Validators::isAlphaNumeric(image))
    {
        TK::Token token(image, "ID", -1, lineNumber, 0);
        tokens.push_back(token);
        symbolsTable.addToken(token);
        std::cout << "isAlphaNumeric (" << image << ")" << std::endl;
    }
    // check if the image is a 'str' type
    else if(VLD::Validators::isStr(image))
    {
        TK::Token token(image, "LSC", -1, lineNumber, 0);
        tokens.push_back(token);
        symbolsTable.addToken(token);
        symbolsTable.addLiteralStringToken(token);
        std::cout << "isNumericAlpha (" << image << ")" << std::endl;
    }
    // check if the image is a 'real' type
    else if(VLD::Validators::isReal(image))
    {
        TK::Token token(image, "RLC", -1, lineNumber, 0);
        tokens.push_back(token);
        symbolsTable.addToken(token);
        std::cout << "isReal (" << image << ")" << std::endl;
    }
    // check if the image is an 'int' type
    else if(VLD::Validators::isInt(image))
    {
        TK::Token token(image, "ILC", -1, lineNumber, 0);
        tokens.push_back(token);
        symbolsTable.addToken(token);
        std::cout << "isInt (" << image << ")" << std::endl;
    }
    else if(staticTables.isOperator(image))
    {
        TK::Token token(image, "OP", -1, lineNumber, 0);
        tokens.push_back(token);
        symbolsTable.addToken(token);
        std::cout << "isOperator (" << image << ")" << std::endl;
    }
    else // in case the image has not been recognized for any of the above validations
    {
        std::cout << "ENTROU AQUI!! (" << image << ")" << std::endl;

        if(image.length() > 1) // checks if the image is not empty
        {
            // sends the unrecognized image to the second processor, which will process
            // it deeply and return a vector with the symbols
            std::vector<std::string> tokens_vector = processImage(image);

            // fetch the symbols inside the vector
            for(std::vector<int>::size_type i = 0; i < tokens_vector.size(); i++) 
            {
                std::string str = ""; 
                str += tokens_vector[i];                

                // each symbol will be send again to the main lexical processor to be 
                // recognized again
                processImage(str, lineNumber);
            }            
        }
        else
        {
            std::stringstream errorMessage;
            errorMessage << "\nLexical Error: unknown symbol: " << image << ", line: " << lineNumber << "";
            errors.push_back(errorMessage.str());
        }
    }
}


// This method processes the image which have not been recognized in the main lexical 
// processor.
//
// E.g.: in case the image is something like '10)' (without the ''). The method must 
// recognize the number '10' and the delimiter ')' as two different tokens.
// 
// This method will then, generate a vector<std::string> with these tokens, and send it 
// to the parent caller, which will send this tokens again to the main lexical processor,
// so this tokens will enter the symbols table.

std::vector<std::string> LA::LexicalAnalyzer::processImage(std::string image)
{    
    ST::StaticTables staticTables;

    std::string newDelimiter = ""; // new delimiter for images with more than a char
    std::string charact = "";
    std::string nextChar = "";
    std::vector<std::string> tokens_vector;
    std::string numeric = "";
    std::string alphaNumeric = "";

    int j = 0;
    std::vector<std::string>::iterator position;

    for(int i = 0; i < image.length(); i++)
    {
        position = tokens_vector.begin() + j;
        charact += image[i]; // converts the token from char to string

        nextChar = image[i+1]; // used to store the next character when dealing
                               // with the processing of an identifier name which
                               // is concatenated with another symbol that is not 
                               // an alphaNumeric or int. e.g: r3). that's why we
                               // we get the next char. in case we are processing 
                               // the letter 'r', we check if the next is numeric
                               // or alphaNumeric, so we may contatenate it with 
                               // the current letter 'r', so we will get 'r3'.

        if(charact == " ")
        {
            break;
        }

        // check if the token is numeric
        if(VLD::Validators::isReal(charact) || VLD::Validators::isInt(charact))
        {
            if(alphaNumeric != "")
            {
                tokens_vector.insert(position, alphaNumeric);
                j++;
                alphaNumeric = "";
            }
                
            numeric += charact;
        }
        // check if the token is alpha numeric (often identifiers)
        else if (VLD::Validators::isAlphaNumeric(charact))
        {
            if(numeric != "")
            {
                tokens_vector.insert(position, numeric);
                j++;
                numeric = "";
            }
            
            // used to store the next character when dealing with the processing 
            // of an identifier name which is concatenated with another symbol 
            // that is not an alphaNumeric or int. e.g: r3). that's why we
            // we get the next char. in case we are processing the letter 'r', 
            // we check if the next is numeric or alphaNumeric, so we may 
            // contatenate it with the current letter 'r', so we will get 'r3'.
            if(nextChar != "" && (VLD::Validators::isInt(nextChar) 
                || VLD::Validators::isAlphaNumeric(nextChar)))
            {
                charact += nextChar;
                i++; // we ignore the next char, since it's already processed
            }

            alphaNumeric += charact;
        }
        // check if the token is an operator
        else if(staticTables.isOperator(charact))
        {
            if(alphaNumeric != "")
            {
                tokens_vector.insert(position, alphaNumeric);
                j++;
                alphaNumeric = "";
            }
                
            if(numeric != "")
            {
                tokens_vector.insert(position, numeric);
                j++;
                numeric = "";
            }
    
            tokens_vector.insert(position, charact);  
            j++;
        }
        // check if the token is a delimiter
        else if(staticTables.isDelimiter(charact))
        {
            if(alphaNumeric != "")
            {
                tokens_vector.insert(position, alphaNumeric);
                j++;
                alphaNumeric = "";
            }
                
            if(numeric != "")
            {
                tokens_vector.insert(position, numeric);
                j++;
                numeric = "";
            }

            tokens_vector.insert((tokens_vector.begin() + j), charact);
            j++;
        }
        // check if the token is a reserved word
        else if(staticTables.isReservedWord(charact))
        {
            if(alphaNumeric != "")
            {
                tokens_vector.insert(position, alphaNumeric);
                j++;
                alphaNumeric = "";
            }
                
            if(numeric != "")
            {
                tokens_vector.insert(position, numeric);
                j++;
                numeric = "";
            }

            tokens_vector.insert(position, charact);
        }

        charact = "";
    }
    
    return tokens_vector;
}

// this method processes a string in the .px code. E.g: print "final test",
// by removing some reserved word contained in the statement, and also retrieving
// the string element from the statement.
void LA::LexicalAnalyzer::processString(std::string currentLine)
{
    std::vector<std::string> text;
    std::vector<std::string> newTokens;
    std::vector<std::string>::iterator position;

    try
    {
        //std::cout << "current line" << currentLine << std::endl;

        // receives the whole to be processed
        for(int i = 0; i < currentLine.length(); i++)
        {
            //std::cout << "substring: " << currentLine.substr(10, 17) << std::endl;

            // check if in the current position the character is a double quote, which means it's
            // the beginning of the string element in the statement.
            if(currentLine.at(i) == '"')
            {
                //std::cout << "inside if. value at i " << quotePositions.at(0) << std::endl;

                if(quotePositions.at(0) == -1)
                {
                    quotePositions.at(0) = i; 
                    //std::cout << ">> first if " << quotePositions.at(0) << std::endl;
                }
                else if(quotePositions.at(1) == -1)
                {
                    quotePositions.at(1) = i; 
                    //xstd::cout << ">> sec if " << quotePositions.at(1) << std::endl;
                }
            }
            else if(currentLine.at(i) == '\\') // if finds a backslash
            {
                if(currentLine.at(i+1) == '"') // check if the next char is a quotation mark
                    continue; // then, ignores the existence of the quotation mark
            }
        }

        //std::cout << "positions 1: " << quotePositions.at(0) << " " << currentLine.at(quotePositions.at(0)) << std::endl;
        //std::cout << "positions 2: " << quotePositions.at(1) << " " << currentLine.at(quotePositions.at(1)) << std::endl;

        // extract the text from the line based on the quotes position and add to the text vector on a specific position
        // based on the position iterator.
        text.insert(position, currentLine.substr(quotePositions.at(0), quotePositions.at(1)));

        // removes the string element from the statement, leaving only the other elements in the statement.
        currentLine.replace(quotePositions.at(0), quotePositions.at(1), "");    

        std::istringstream iss(currentLine);

        //std::cout << "currline: " << currentLine << std::endl;

        // here we get the rest of the elements in the statement, already with the string element removed from it,
        // and we add each one of them to the newTokens vector.
        std::string image;
        while (iss >> image)
        {
            //std::cout << "image: " << image << std::endl;            
            newTokens.insert(position, image);
            position += 1;
        }

        // here we get the string elements retrieved before into the text array, and we fetch it, and add each of 
        // these elements to the newTokens vector.
        for(int i = 0; i < text.size(); i++)
        {            
            //std::cout << "image: " << text.at(i) << std::endl;            
            newTokens.insert(position, text.at(i));            
        }

        // after this previous operations, we have a newTokens vector, with the tokens and the string elements retrieved
        // from the statement, ready to be processed as a normal Image object.
        for(int i = 0; i < newTokens.size(); i++)
        {
            std::cout << "image: " << newTokens.at(i) << std::endl;            
            processImage(newTokens.at(i));
        }
    }
    catch(std::exception e)
    {
        std::cerr << e.what() << std::endl;
    }
}

// Check if exists errors by returning the size of the errors size.
bool LA::LexicalAnalyzer::hasError()
{
    return errors.size() > 0;
}

// Fetch the errors vector with an iterator.
void LA::LexicalAnalyzer::showErrors()
{
    std::cout << "errors" << std::endl;
    std::for_each(errors.begin(), errors.end(), LA::LexicalAnalyzer::printError);
}

// Function called to print the errors in the errors vector.
void LA::LexicalAnalyzer::printError(std::string error)
{
    std::cout << " " << error;
}

// Fetch the errors vector with an iterator.
void LA::LexicalAnalyzer::showTokens()
{
    std::cout << "tokens" << std::endl;
    std::for_each(tokens.begin(), tokens.end(), LA::LexicalAnalyzer::printToken);
}

// Function called to print the errors in the errors vector.
void LA::LexicalAnalyzer::printToken(TK::Token token)
{
    std::cout << "" << token.image << std::endl;
}




