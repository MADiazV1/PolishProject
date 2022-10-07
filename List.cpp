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
    float answer;
    string number1 = this->pop()->getData()->getNotation();
    float firstMainNumber = stof(number1);
    string number2;
    float secondNumber;

    while(this->getHead() != NULL){
        number2 = this->pop()->getData()->getNotation();
        secondNumber = stof(number2);

        Node* symbol;
        answer = operation(firstMainNumber, secondNumber, symbol);
        if(answer == -1){
            return "Systax Error";
            break;
        }
        firstMainNumber = answer;
    }
    return to_string(answer);
}

float List::operation(float num1, float num2, Node* symbol){
    string charStr = symbol->getData()->getNotation();
    if(charStr == "+"){
        return num1 + num2;
    }else if(charStr == "-"){
        return num1 - num2;
    }else if(charStr == "*"){
        return num1 * num2;
    }else if(charStr == "/"){
        return num1 / num2;
    }else{
        return -1;
    }
}