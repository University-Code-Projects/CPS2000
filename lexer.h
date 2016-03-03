//
// Created by jonathan on 02/03/2016.
//

#ifndef LEXER_PROJ2_LEXER_H
#define LEXER_PROJ2_LEXER_H

#include <string>
#include <string.h>
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

    /*
     * All possible token types and their associated value.
     */
    enum TOK_Type { tok_eof = -1, tok_extern = -2, tok_def = -3, tok_number = -4, tok_identifier = -5,};

    struct Token{
        TOK_Type token_type;
        string id;
        float num;

        Token(){
            token_type = tok_eof;
            id = '"';
            num = 0;
        }

        Token(TOK_Type p_type, string p_id, float p_num ){
            token_type = p_type;
            id = p_id;
            num = p_num;
        }
    };

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

        string getProgramToText();

        /*
         * Get token impemented using Token type
         */
        Token getToken();

        /*
        * Get token implemented using int
        */
        //int getToken();

    private:
        ifstream file;
        //Token token_type;
        //string identifierStr;
        //float num;
        int charIndex;
        string inputText;


};



#endif //LEXER_PROJ2_LEXER_H