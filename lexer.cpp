//
// Created by jonathan on 02/03/2016.
//
#include "Lexer.h"
/*
 * Constructor, exit if file is not unacceptable
 */
Lexer::Lexer(string p_filename) {
    file.open(p_filename);
    if(file){
        cout << "File '" << p_filename << "' was opened successfully." << endl;


    }else{
        cout << "File '" << p_filename << "' could no be opened." << endl;
    }
}

Lexer::~Lexer() {
    cout << "Object was deconstructed" << endl;
}

string Lexer::getLine() {

}

//Lexer::Token Lexer::getToken() {
    //if((unsigned int) a_charIndex == a_inputProgram.length()-1 return Lexer::Token(TOK_EOF));


//}

int Lexer::getToken() {
    int LastChar = ' ';

    while(isspace(LastChar)){//skipping any whitespaces
        LastChar = getchar();
    }
    if(isalpha(LastChar)){//used to identifiers
        identifierStr = LastChar;
        while(isalnum((LastChar = getchar()))){
            identifierStr += LastChar;
        }

        if(identifierStr == "def")
            return tok_def;
        if(identifierStr == "extern")
            return tok_extern;
        cout << "Returning identifier" << endl;
        return tok_identifier;
    }
    //for double
    if(isdigit(LastChar)|| LastChar == '.'){//can be a 0.___ thus the lastchar =='.'
        string curr;
        do{
            curr += LastChar;
            LastChar = getchar();
        }while(isdigit(LastChar)||LastChar == '.');

        num = strtod(curr.c_str(),0);
        cout <<"Returning Number" << endl;
        return tok_number;
    }

    if(LastChar == EOF){//for eof
        cout <<"Returning EOF" << endl;
        return tok_eof;
    }

    if(LastChar == '/'){//for comments
        string comm;
        int i =0;
        bool flag= false;
        comm += LastChar;
        do{
            i++;
            LastChar = getchar();
            if(i==2) {
                if (LastChar == '/') {
                    comm += LastChar;
                    flag = true;// can be removed, kept if want to do something with comment

                }else{
                    // only the 1st char was a /
                    break;
                }
            }
            comm += LastChar;
        }while(LastChar != EOF && LastChar != '\n' && LastChar != '\r');

        if(LastChar != EOF){
            return getToken();
        }
    }
    int charac = LastChar;
    LastChar = getchar();
    cout << "Returning char: " << charac << endl;
    return charac;


}

