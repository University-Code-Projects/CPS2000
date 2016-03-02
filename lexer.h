//
// Created by jonathan on 01/03/2016.
//
/*
 * Header file used to read char from file and sort into tokens respectively
 */
#ifndef LEXER_PROJ1_LEXER_H
#define LEXER_PROJ1_LEXER_H

using namespace std;
#include <string>
#include <fstream>
#include <iostream>

class Lexer{
    public:
        /*
         * Constructor, opens file given by filename
         *  program exists with an error message if file does not exist.
         *  @param filename - a C string naming the fle to read
         */
        Lexer(const string&);

        virtual ~Lexer();




        Token(const string&);

        /*
         * Closes the file opened
         */
        void close();

        /*
         * Returns the next line for the file
         * @return - string - line
         */
        string getNextLine();

        /*
         * Returns a string, being the next word from the line
         * @return - string - next word.
         */
        string getNextString();

        /*
         * Returns true if there is more lines in file, else false if EOF is reached
         * @return - bool - !eof
         */
        bool isNextLine();

        /*
         * Returns true if the next string is a whitespace, newline or a tab
         */
    //to create a new function

    private:
        ifstream filevar;
        bool eoffound;
        string nextline;
        string nexttoken;

};
#endif //LEXER_PROJ1_LEXER_H
