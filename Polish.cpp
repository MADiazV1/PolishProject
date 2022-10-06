#include <iostream>
#include <string>
#include "Polish.h"
using namespace std;

Polish::Polish(string polish){
    this->expPolish = polish;
}

string Polish::getNotation(){
    return this->expPolish;
}