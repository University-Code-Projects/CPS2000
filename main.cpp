#include <iostream>
#include "Lexer.h"

using namespace std;

int main() {
    cout << "Entry in Main" << endl;
    Lexer *lex = new Lexer("C:\\Users\\jonathan\\ClionProjects\\Lexer_proj1\\test.txt");
    int nextToken = lex->getToken();

    //Lexer::Token nextToken = lex->getToken();
//    while (nextToken.token_type != Lexer::TOK_EOF){

 //   }
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