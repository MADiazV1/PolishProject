#include <iostream>
#include <string>
#include "Polish.h"
using namespace std;

class Node{
    private:
        Polish* data;
    public:
        Node* next;
        Node(Polish* data, Node* next);
        void showData();
};