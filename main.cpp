#include <iostream>
#include "Lexer.h"

using namespace std;

int main() {
    cout << "Entry in Main" << endl;
    Lexer *lex = new Lexer("C:\\Users\\jonathan\\ClionProjects\\Lexer_proj1\\test.txt");
    string total = lex->getProgramToText();
    cout << total << endl;
    //int nextToken = lex->getToken();

//    Lexer nextToken = lex->getToken();
//    while (nextToken.TOK_type != Lexer::tok_eof){

   // }
    return 0;
}


/* //Create and test Lexer is producing expected tokens
    Lexer * lex = new Lexer("./resource/text.prog");
    Lexer::Token nxtToken = lex->GetToken();
    while (nxtToken.token_type != Lexer::TOK_EOF)
    {
        cout << nxtToken.ToString() << " ";
    }
    cout << nxtToken.ToString() << endl;
    */