#include <iostream>
#include "Lexer.h"

using namespace std;

int main() {
    cout << "Entry in Main" << endl;
    Lexer *lex = new Lexer("C:\\Users\\jonathan\\ClionProjects\\Lexer_proj1\\test.txt");
    string total = lex->getProgramToText();
    cout << total << endl;
    //int nextToken = lex->getToken();

    Lexer::Token nextToken = lex->getToken();
    /*
    if(nextToken.id == ""){
        cout << "**NextToken Int: " << nextToken.num << endl;
    }else if(nextToken.num == 0){
        cout << "**NextToken string: " << nextToken.id<<endl;
    }

    nextToken = lex->getToken();
    if(nextToken.id == ""){
        cout << "**NextToken Int: " << nextToken.num << endl;
    }else if(nextToken.num == 0){
        cout << "**NextToken string: " << nextToken.id<<endl;
    }

    nextToken = lex->getToken();
    if(nextToken.id == ""){
        cout << "**NextToken Int: " << nextToken.num << endl;
    }else if(nextToken.num == 0){
        cout << "**NextToken string: " << nextToken.id<<endl;
    }
    nextToken = lex->getToken();
    if(nextToken.id == ""){
        cout << "**NextToken Int: " << nextToken.num << endl;
    }else if(nextToken.num == 0){
        cout << "**NextToken string: " << nextToken.id<<endl;
    }
     */
    //cout << "NextToken string: " << nextToken.id<<endl;
    //cout << "NextToken Int:" << nextToken.num << endl;
    //cout << "Pre entry in while" << endl;

    while(nextToken.token_type != Lexer::tok_eof){
        //cout << nextToken.num << "";
        if(nextToken.id == ""){
            cout << "**NextToken Int   : " << nextToken.num << endl;
        }else if(nextToken.num == 0){
            cout << "**NextToken string: " << nextToken.id<<endl;
        }

        nextToken = lex->getToken();
    }

    //cout <<"Post exit of while" << endl;
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