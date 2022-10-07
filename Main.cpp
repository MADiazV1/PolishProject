#include <iostream>
#include <string>
#include "Polish.h"
#include "Node.h"
#include "List.h"
using namespace std;

int main(){
    List* list = new List();
    List* auxiliaryList = new List();
    string polishExpression;

    cout << "Enter a polish notation expression in postorder:" << endl;
    getline(cin, polishExpression);
    
    list->split(polishExpression);
    list->reverseList(auxiliaryList);

    string result = auxiliaryList->solveNotation();
    cout << result << endl;

    return 0;
}