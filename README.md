pixel language
=====

this is the repository for pixel language.

i'm reimplementing the compiler from java to c++. if you want to get the last 
version of it (which is written in java) get it [here](http://github.com/rogcg/pixellang). 

remember that i'm rewriting the project to c++ based on the java implementation, so please,
if you are going to contribute, base on the [java code](http://github.com/rogcg/pixellang). as soon as the c++ version is stable, 
the java version will be deleted.

check the website.

[pixel website](http://pixellang.appspot.com/)

and

[pixel language on google+](https://plus.google.com/b/100494143910868751778/100494143910868751778/posts)

thanks.

Running the compiler
=====

to run the compiler, download the source code and build the application by running the `build.bat` file or just run the command on your terminal in the root directory of *pixel/*.

`g++ compiler/src/px/LabelGenerator.cpp compiler/src/px/Token.cpp compiler/src/px/Symbol.cpp compiler/src/px/SymbolsTable.cpp compiler/src/px/StaticTables.cpp compiler/src/px/Validators.cpp compiler/src/px/LexicalAnalyzer.cpp compiler/src/EntryPoint.cpp -o pixel -lboost_regex -std=c++0x`