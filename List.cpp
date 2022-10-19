#include <iostream>
#include <string>
#include "Polish.h"
#include "Node.h"
#include "List.h"
using namespace std;

Node* List::getHead(){
    return this->head;
}

void List::pushNode(Node* data){
    data->next = this->head;
    this->head = data;
}

Node* List::pop(){
    Node* temp = this->head;
    this->head = this->head->next;
    return temp;
}

void List::printNodes(){
    Node* aux = this->head;
    while(aux){
        aux->showData();
        aux = aux->next;
    }
}

bool List::evaluateExpresion(string str){
    char delim = ' ';
    int values = 0;

    if(str[0] == delim){
        str = str.substr(1,str.length());
    }
    if(str[str.length()] == delim){
        str = str.substr(0, str.length()-1);
    }

    for(int i=0;i<str.length();i++){
        if(str[i]!=delim){
            values++;
        }
    }

    int count = 0;
    int valueCount = 0;
    char validChars[14] = {'1','2','3','4','5','6','7','8','9','0','+','-','*','/'};
    for(int i=0;i<str.length();i++){
        for(int j=0;j<14;j++){
            if(str[i]==validChars[j]){
                count++;
                valueCount++;
                break;
            }else if(str[i]==delim){
                continue;
            }
        }
    }

    if(count!=0 && values == valueCount && (str[str.length()-1] == '+' || str[str.length()-1] == '-' || str[str.length()-1] == '*' || str[str.length()-1] == '/')){
        return true;
    }else{
        return false;
    }
}

void List::split(string str){
    char delim = ' ';
    string temp = "";
    for(int i=0; i<=(int)str.size(); i++){
        if(str[i] == delim || i == str.length()){
            this->pushNode(new Node(new Polish(temp), NULL));
            temp = "";
        }else{
            temp += str[i];
        }
    }
}

void List::reverseList(List* aux){
    Node* temp;
    while(this->head){
        temp = this->pop();
        aux->pushNode(temp);
    }
}

string List::solveNotation(){
    try{
        string answerString = "";
        float answer;
        float firstMainNumber = stof(this->pop()->getData()->getNotation());

        while(this->getHead() != NULL){
            float secondNumber = stof(this->pop()->getData()->getNotation());
            string symbol = this->pop()->getData()->getNotation();
            answer = operation(firstMainNumber, secondNumber, symbol);
            firstMainNumber = answer;
        }
        answerString = to_string(answer);
        answerString = answerString.substr(0, answerString.find(".")+3);
        return "Answer: " + answerString;
    }catch(exception e){
        e.what();
        return "Invalid expression";
    }
}

float List::operation(float num1, float num2, string symbol){
    if(symbol == "+"){
        return num1 + num2;
    }else if(symbol == "-"){
        return num1 - num2;
    }else if(symbol == "*"){
        return num1 * num2;
    }else if(symbol == "/"){
        return num1 / num2;
    }else{
        return 0;
    }
}