#include <iostream>
#include "lexer.h"

using namespace std;

int main() {
    string name;
    cout << "Enter file name and .txt"<<endl;
    cin >> name;


    Lexer * filevar;
    filevar = new Lexer(name);
    Lexer &lexe = *filevar;

    while(lexe.isNextLine()){
        string current,word;
        current = lexe.getNextLine();
        word = lexe.getNextString();
        cout << "Line: " << current << endl;
        cout << "Word: "<< word << endl;
    }

    Lexer *lex = new Lexer("C:\\Users\\jonathan\\ClionProjects\\Lexer_proj1\\test.txt");
    Lexer::Token nextToken = lex->getToken();

    /* //Create and test Lexer is producing expected tokens
    Lexer * lex = new Lexer("./resource/text.prog");
    Lexer::Token nxtToken = lex->GetToken();
    while (nxtToken.token_type != Lexer::TOK_EOF)
    {
        cout << nxtToken.ToString() << " ";
    }
    cout << nxtToken.ToString() << endl;
    */

    /* //Create and test Parser is producing expected parse tree
   `Parser * parser = new Parser(lex);
    auto rootNode = parser->Parse();
    rootNode->PrintInfo(0);   //Print parser tree using PrintInfo function in each node, recursively
    */

    /* //Create PrintInfo Visitor and Check it is producing the same output as above
    PrintInfoVisitor * pv = new PrintInfoVisitor();
    rootNode->Accept(pv);
    */

    return 0;
}