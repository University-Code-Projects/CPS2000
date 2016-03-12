//
// Created by jonathan on 02/03/2016.
//

#ifndef LEXER_PROJ2_LEXER_H
#define LEXER_PROJ2_LEXER_H

#include <string>
#include <string.h>
#include <fstream>
#include <iostream>
//#include <stdio>
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
    enum TOK_Type { TOK_eof = -1, TOK_extern = -2, TOK_def = -3, TOK_number = -4, TOK_identifier = -5,TOK_comment =-6, TOK_arithop=-7,TOK_string =-8, TOK_keyword =-9, TOK_bool =-10, TOK_punc =-11,TOK_for=-12,TOK_return =-13};

    struct Token{
        TOK_Type token_type;
        string id;//check what we have to store
        float num;//check what we have to store

        Token(){
            token_type = TOK_eof;
            id = '"';
            num = 0;
        }

        Token(TOK_Type p_type, string p_id, float p_num ){
            token_type = p_type;
            id = p_id;
            num = p_num;
        }
        Token(TOK_Type p_type, string p_id){
            token_type = p_type;
            id = p_id;
            num = 0;
        }
        Token(TOK_Type p_type, float p_num ){
            token_type = p_type;
            id = "";
            num = p_num;
        }

        string toString();

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