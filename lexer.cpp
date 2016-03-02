//
// Created by Jonathan Borg on 01/03/2016.
//
#include "lexer.h"

/*
 * Constructor, opens file with the given filename.
 * program exists with an error message if file does not exist.
 *  @param filename - a C string naming the fle to read
 *  After successful open the constuctor reads the first of the strings and initialises eoffound flag
 */
Lexer::Lexer(const string &filein){
    filevar.open("C:\\Users\\jonathan\\ClionProjects\\Lexer_proj1\\test.txt");//open file given by user
    if(filevar){
        cout << "File '" << filein << "' was opened successfully." << endl;
        //filevar >> nextstring;
        eoffound = false;
    }
    if(!filevar){
        cout << "File '" << filein << "' cannot be opened." << endl;
        //exit(1);
    }

}

/*
 * Closing the file
 */
void Lexer::close(){
    filevar.close();
    cout << "File was closed" << endl;
}

/*
 * Returns the next line for the file
 * @return - string - line
 */
string Lexer::getNextLine(){
    getline(filevar, nextline);
    if(filevar.eof())
        eoffound = true;
    return nextline;
}

/*
 * Returns a string, being the next word from the file
 * @return - string - next word.
 */
/*
 *

string Lexer::getNextString(){
    string line = nextline;
    int len =line.size();
    string curr = "";

    bool t = false;
    for(int i=0; i <= len; i++){
        if(line[i] == ' '){
            cout << "Word from get function: " <<curr << endl;
            return curr;
            continue;
        }else if(line[i] == '\n') {

        }else{
            curr += line[i];
        }
    }

}

*/
string Lexer::getNextString(){
    string line = nextline;
    int len = line.size();
    string curr = "";

    bool t = false;
    for(int i=0; i <=len; i++){
        if(line[i] == '\n'){
            cout <<"endline found" << endl;
            break;
        }
        if(t == true){
            curr = "";
            continue;
        }
        if(line[i] == ' '){
            cout << "space found.... new token inc" << endl;
            cout << "Word from get func: " << curr << endl;
            t = true;
        }
        curr += line[i];

    }

}


/*
 * Returns a string, being the next word from the line
 * @return - string - next word.

string getNextToken(){
    string tok;
    return tok;
}
*/
/*
 * Returns true if there is more in file, else false if EOF is reached
 * @return - bool - !eof
 */
bool Lexer::isNextLine(){
    return !eoffound;
}

Lexer::Token(const string &string1) {
    return 0;
}

Lexer::~Lexer() {

}
