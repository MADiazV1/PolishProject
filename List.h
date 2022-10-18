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
        bool evaluateExpresion(string str);
        void split(string str);
        void reverseList(List* list);
        float solveNotation();
        float operation(float num1, float num2, string symbol);
};