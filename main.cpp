#include <iostream>
#include "Lexer.h"

using namespace std;

int main() {
    cout << "Entry in Main" << endl;
    Lexer *lex = new Lexer("C:\\Users\\jonathan\\ClionProjects\\Lexer_proj1\\test.txt");
    string total = lex->getProgramToText();
    //cout << total << endl;
    //int nextToken = lex->getToken();

    Lexer::Token nextToken = lex->getToken();

    while(nextToken.token_type != Lexer::TOK_eof){
        /*
        if(nextToken.id == ""){
            cout << "**NextToken Int   : " << nextToken.num << endl;
        }else if(nextToken.num == 0){
            cout << "**NextToken string: " << nextToken.id<<endl;
        }
         */
        cout << nextToken.toString() << endl;
        nextToken = lex->getToken();
        //cout << charIndex << endl;
    }
    cout << nextToken.toString() << endl;
    return 0;
}