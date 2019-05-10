pixel language
=====

pixel is a python/list like programming language under development.

running the compiler
=====

to run the compiler, download the source code and build the application by running the `build.bat` or `build.sh` file or just run the command below on your terminal in the root directory of *pixel/*.

`g++ compiler/src/px/LabelGenerator.cpp compiler/src/px/Token.cpp compiler/src/px/Symbol.cpp compiler/src/px/SymbolsTable.cpp compiler/src/px/StaticTables.cpp compiler/src/px/Validators.cpp compiler/src/px/LexicalAnalyzer.cpp compiler/src/EntryPoint.cpp -o pixel -lboost_regex -std=c++0x`
