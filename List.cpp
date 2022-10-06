#include <iostream>
#include <string>
#include "Polish.h"
#include "Node.h"
#include "List.h"
using namespace std;

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

