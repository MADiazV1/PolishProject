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
        Node* getHead();
        void pushNode(Node* data);
        Node* pop();
        void printNodes();
        void split(string str);
        void reverseList(List* list);
        string solveNotation();
        float operation(float num1, float num2, Node* symbol);
};