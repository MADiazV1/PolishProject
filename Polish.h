#include <iostream>
#include <string>
#pragma once
using namespace std;

class Polish{
    private:
        string expPolish;
    public:
        Polish(string expPolish);
        string getNotation();
};