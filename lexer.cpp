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
        if(eoffound == false){
            int size = currentLine.length();
            int curr=0;
            curr++;
            if(curr < size-1){
                inputText += currentLine;
            }
            if((currentLine.length()-1) ==  '\r'|| '\t') {
                inputText += ' ';
            }
            if(file.peek() != EOF){
                inputText += '\n';

            }else{
                break;
            }
        }

    }
    //cout << "Length of Text: " << inputText.length()<<endl;
    return inputText;
}

Lexer::Token Lexer::getToken() {
    char lastChar;
    if((unsigned int) charIndex == inputText.length() - 1) {
        //cout << "Returning an EOF token" << endl;
        return (Lexer::Token());//not sure about the id to be stored
        //return (Lexer::Token(tok_eof));
    }
    lastChar = inputText[charIndex];

    while(charIndex != inputText.length()-1){

        while((isspace(lastChar)||lastChar=='\n') && lastChar != EOF){//skipping any whitespaces
            charIndex++;
            lastChar = inputText[charIndex];
        }

        if(lastChar == EOF){
            return (Lexer::Token());
        }

        if (isdigit(lastChar) || lastChar == '.'){//in the case of a floating number example 0.__
            string curr;
            string::size_type sz;
            float toStoreNum;

            do{
                curr += lastChar;
                charIndex++;
                lastChar = inputText[charIndex];
            }while(isdigit(lastChar)||lastChar == '.');

            toStoreNum = stof(curr, &sz);
            return (Lexer::Token(TOK_number,toStoreNum));//not sure about the id which will be stored in the structure
        }

        if(isalpha(lastChar)){//used get strings
            string word = "";

            while(isalnum((lastChar = inputText[charIndex]))){
                word += lastChar;
                charIndex++;
                lastChar = inputText[charIndex];
                /*
                if((lastChar == '_')||(lastChar == '(')||(lastChar == ')')){
                    word += lastChar;
                    charIndex++;
                }
                 */
            }

            if(word == "def"){
                return Lexer::Token(TOK_def, word);
            }else if(word == "extern") {
                return Lexer::Token(TOK_extern, word);

            }else if( (word == "int") || (word == "string") || (word == "float") || (word == "char") || (word == "double") ){
                return Lexer::Token(TOK_keyword, word);

            }else if(word == "for") {
                //cout << "'" << lastChar <<"'" ;
                while (isspace(lastChar)) {//skipping any whitespaces
                    charIndex++;
                    lastChar = inputText[charIndex];
                }
                return Lexer::Token(TOK_for, word);
                if (lastChar == '(') {
                    cout << "if :" << lastChar << endl;
                    string cond1 = "", cond2 = "", cond3 = "";
                    int count = 1;
                    charIndex++;
                    lastChar = inputText[charIndex];
                    //while(lastChar != ')'){
                    //    getToken();
                    //}

                } else {

                    cout << "else :" << lastChar << endl;
                }

                return Lexer::Token(TOK_for, word);
            }else if(word == "return"){
                return (Lexer::Token(TOK_return,word));
            }else{
                return Lexer::Token(TOK_identifier, word);//to change , uncertain about this result(num)
            }
        }

        if(lastChar == '/'){//for comments
            string comm = "";
            int i =0;
            bool integ=false;
            //comm += lastChar;
            charIndex++;
            lastChar = inputText[charIndex];
            if(lastChar == '/') {
                //comm += lastChar;
                while(1){
                    charIndex++;
                    lastChar = inputText[charIndex];
                    if(lastChar != EOF && lastChar != '\n' && lastChar != '\r'){
                        comm += lastChar;
                    }else{

                        break;
                    }
                }
            }
            if(integ == true){
                //value after / was a number .... do something with it (division)
            }
            return Lexer::Token(TOK_comment,comm);//uncertain about num for this case
        }

        if((lastChar == '+') || (lastChar == '-') ||(lastChar == '*') ||(lastChar == '/')){
            string oper= "";
            char check =lastChar;
            oper += lastChar;
            charIndex++;
            lastChar = inputText[charIndex];
            if(check == '+'){
                if(lastChar == '+'){
                    oper+=lastChar;
                    charIndex++;
                }
            }else if(check == '-'){
                if(lastChar == '-'){
                    oper+=lastChar;
                    charIndex++;
                }
            }

            return (Lexer::Token(TOK_arithop,oper));   //not sure about the num return
        }

        if((lastChar == '>')||(lastChar == '<')||(lastChar == '=')){
            string boolop = "";
            boolop += lastChar;
            charIndex++;
            if (inputText[charIndex] == '='){//check for 2nd part for boolean operation if existant ( >= <= ==)
                boolop += inputText[charIndex];
                charIndex++;
                return (Lexer::Token(TOK_bool, boolop));
            }else{
                return (Lexer::Token(TOK_bool, boolop));
            }
        }

        if((lastChar == '.')||(lastChar == ';')||(lastChar == '(')||(lastChar == ')')||(lastChar == '{')||(lastChar == '}')){
            string punc ="";
            punc += lastChar;
            charIndex++;
            return (Lexer::Token(TOK_punc,punc));
        }

        if(charIndex == inputText.length()){
            return (Lexer::Token());
        }
    }
}

string Lexer::Token::toString() {
    string result = "<";
    string type;
    switch (token_type){
        case -1:
            type = "End Of File";
            break;
        case -2:
            type = "Extern";
            break;
        case -3:
            type = "Define";
            break;
        case -4:
            type = "Number";
            break;
        case -5:
            type = "Identifier";
            break;
        case -6:
            type = "Comment";
            break;
        case -7:
            type = "Arithmetic Operation";
            break;
        case -8:
            type = "String";
            break;
        case -9:
            type = "KeyWord";
            break;
        case -10:
            type = "Boolean Operation";
            break;
        case -11:
            type = "Punctuator";
            break;
        case -12:
            type = "For Loop";
            break;
        case -13:
            type = "Return";
            break;
    }
    result += type;
    result += ">";
    if(id == ""){
        result += "<";
        result += to_string(num);
        result += ">";
    }else if(num == 0){
        result += "<";
        result += id;
        result += ">";
    }else{
        result += "<";
        result += to_string(num);
        result += ", ";
        result += id;
        result += ">";
    }
    return result;
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
