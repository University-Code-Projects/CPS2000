//
// Created by jonathan on 02/03/2016.
//

#ifndef LEXER_PROJ2_LEXER_H
#define LEXER_PROJ2_LEXER_H

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Lexer {
public:
    /*
     * Constructor
     */
    Lexer(string p_filename);

    /*
     * Deconstuctor
     */
    virtual ~Lexer();

    enum Tok_Type { tok_eof = -1, tok_extern = -2, tok_def = -3, tok_number = -4, tok_identifier = -5,};
    //struct Token{
    //    Tok_Type token_type;
    //    string id;
    //    double num;

        //Token(){
        //    token_type = tok_eof;
        //    id = "";
        //    num = 0;
        //}

    //};

    /*
     * struct Token{
            enum TOK_TYPE{TOK_EOF =-1, TOK_NUMBER=-2, TOK_ARITHOP = -3, TOK_BOOLOP =-4};

            if(token_type = file.eof()){

            }else if(){

            }else if(){

            }
            //string float token_type
        };
        */

        string getLine();

        //Token getToken();

        int getToken();

    private:
        ifstream file;
        //Token token_type;
        string identifierStr;
        double num;
};



#endif //LEXER_PROJ2_LEXER_H