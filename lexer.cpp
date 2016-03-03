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

string Lexer::getProgramToText() {
    cout << "Entry in program to text function" << endl;
    string currentLine = "";
    inputText = "";//initializing the private var that stores the entire project as a string/char
    charIndex = 0;
    bool eoffound = false;

    while(getline(file, currentLine)){
        if(file.eof()) {
            eoffound = true;
            break;
        }
        if(eoffound == true){
            break;
        }
        if(eoffound == false){
            int size = currentLine.length();
            int curr=0;
            curr++;
            if(curr < size-1){
                inputText += currentLine;
            }
            if((currentLine.length()-1) == '\n' || '\r'|| '\t') {
                inputText += ' ';
            }
        }
    }
    cout << "Exit from text function " << endl;
    return inputText;
}

Lexer::Token Lexer::getToken() {
    char lastChar;

    if((unsigned int) charIndex == inputText.length() - 1) {

        cout << "Returning an EOF token" << endl;
        return (Lexer::Token(tok_eof,"End of File",-1));//not sure about the id to be stored
        //return (Lexer::Token(tok_eof));
    }

    lastChar = inputText[charIndex];

    while(charIndex != inputText.length()-1){

        while(isspace(lastChar)){//skipping any whitespaces
            charIndex++;
            lastChar = inputText[charIndex];
        }

        if (isdigit(lastChar) || lastChar == '.'){//in the case of a floating number example 0.__
            string curr;
            //string::size_type sz;
            //float toStoreNum;

            do{
                curr += lastChar;
                charIndex++;
                lastChar = inputText[charIndex];
            }while(isdigit(lastChar)||lastChar == '.');

            //toStoreNum = stof(curr, &sz);
            return (Lexer::Token(tok_number,curr,-4));//not sure about the id which will be stored in the structure
        }

        if(isalpha(lastChar)){//used to identifiers
            string word = "";
            //word += lastChar;

            while(isalnum((lastChar = inputText[charIndex]))){
                word += lastChar;
                charIndex++;
                lastChar = inputText[charIndex];
            }

            if(word == "def"){
                return Lexer::Token(tok_def, word,-3);//to change , uncertain about this result(id and num)
            }else if(word == "extern") {
                return Lexer::Token(tok_extern, word, -2);//to change , uncertain about this result
            }else{
                return Lexer::Token(tok_identifier, word, -5);//to change , uncertain about this result(num)
            }

        }

        if(lastChar == '/'){//for comments
            string comm = "";
            int i =0;
            bool flag= false, integ=false;
            do{
                i++;
                comm += lastChar;
                charIndex++;
                lastChar = inputText[charIndex];;
                if(i==2) {
                    if (lastChar == '/') {
                        comm += lastChar;
                        flag = true;// can be removed, kept if want to do something with comment

                    }else{
                        // only the 1st char was a /
                        if(isdigit(lastChar)){
                            integ = true;
                        }
                        break;

                    }
                }
                comm += lastChar;
            }while(lastChar != EOF && lastChar != '\n' && lastChar != '\r');

            if(integ == true){
                //value after / was a number .... do something with it (division)
            }

            //cout <<"Returning Comment: " << comm << endl;
            return Lexer::Token(tok_comment,comm,-6);//uncertain about num for this case
            //if(lastChar != EOF){
            //    return getToken();
            //}
        }

        if(lastChar == '+' || '-' ||'*' ||'/'){
            string oper= "";
            oper += lastChar;
            charIndex++;
            lastChar = inputText[charIndex];
            return (Lexer::Token(tok_arithop,oper,-7));   //not sure about the num return
        }
        //charIndex++;
        //lastChar = inputText[charIndex];


    }
}

/*
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
*/
