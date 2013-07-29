#include <fstream>
#include <cstdlib>
#include <iostream>

#include "../includes/px/Token.h"
#include "../includes/px/Symbol.h"
#include "../includes/px/SymbolsTable.h"
#include "../includes/px/LexicalAnalyzer.h"
#include "../includes/px/StaticTables.h"

int main()
{
    std::ifstream indata;
    std::string filename = "prog2.px";

    // Reads the source .px file
    indata.open(filename.c_str());
    if(!indata)
    {
        std::cerr << "Error: file could not be opened." << std::endl;
        exit(1);
    }

    #ifndef LEXICAL_ANALYSIS

    SYT::SymbolsTable symbolsTable;
    LA::LexicalAnalyzer lexicalAnalyzer(indata);
    lexicalAnalyzer.analyze();

    // Checks if some error happened on the lexical analysis
    if(lexicalAnalyzer.hasError())
    {
        lexicalAnalyzer.showErrors();
        exit(1);
    }
    std::cout << "Lexical Analysis successfully performed! \n\n -> Tokens List" << std::endl;
    lexicalAnalyzer.showTokens(); // Show the list of tokens generated on the lexical analysis

    std::cout << "size: " << SYT::SymbolsTable::s_symbols.size() << std::endl;

    symbolsTable.showSymbolsTable();

    system("pause");

    #endif // LEXICAL_ANALYSIS

 /* #ifndef SYMBOLS_TABLE

    SymbolsTable::showSymbolsTable();
    std::cout << "\n\nLSC\n" << std::endl;
    SymbolsTable::showSymbolsTableLSC();

    #endif // Symbols Table

    #ifndef SYNTATIC_ANALYZER_TREE_GENERATOR

    SyntaticAnalyzerTreeGenerator syntaticAnalyzer = new SyntaticAnalyzerTreeGenerator(lexicalAnalyzer.mTokens);
    syntaticAnalyzer.analyze();

    if(syntaticAnalyzer.hasError())
    {
        syntaticAnalyzer.showErrors();
        exit(1);
    }
    else
    {
        cout << "\nSyntatic Analysis performed successfully!" << endl;
    }

    cout << "Generated Tree" << endl;
    syntaticAnalyzer.showTree(syntaticAnalyzer.getRoot(), " ");

    #endif // Syntatic Analyzer Tree Generator

    #ifndef SEMANTIC_ANALYZER

    SemanticAnalyzer semanticAnalyzer = new SemanticAnalyzer(syntaticAnalyzer.getRoot());
    semanticAnalyzer.semanticAnalysis(); // Perform the semantic analysis

    if(semanticAnalyzer.hasError())
    {
        semanticAnalyzer.showErrors();
    }
    else
    {
        cout  << "\nsemantic Analysis performed successfully!" << endl;
    }

    #endif // Semantic Analyzer

    #ifndef CODE_GENERATOR

    CodeGenerator generator = new CodeGenerator(syntaticAnalyzer.getRoot(), "out.asm");
    generator.generate();

    #endif // Code Generator

    cout << "Build done!" << endl;*/
}
