#include <iostream>
#include <string>
#include "Polish.h"
#pragma once
using namespace std;

class Node{
    private:
        Polish* data;
    public:
        Node* next;
        Node(Polish* data, Node* next);
        void showData();
        Polish* getData();
};