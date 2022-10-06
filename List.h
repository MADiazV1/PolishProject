#include <iostream>
#include <string>
#include "Polish.h"
#include "Node.h"
#pragma once
using namespace std;

class List{
    private:
        Node* head;
    public:
        List(){
            this->head = NULL;
        }
        void pushNode(Node* data);
        Node* pop();
        void printNodes();
        void split(string str);
        void reverseList(List* list);
};