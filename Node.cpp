#include <iostream>
#include <string>
#include "Polish.h"
#include "Node.h"
using namespace std;

Node::Node(Polish* data, Node* next){
    this->data = data;
    this->next = NULL;
}

void Node::showData(){
    cout << this->data->getNotation() << endl;
}

Polish* Node::getData(){
    return this->data;
}