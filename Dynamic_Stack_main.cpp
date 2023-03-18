#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    Stack s;
    string text = "({3+x}*[7x+3s]*(x+1))*((-1)))";
    s.BracketsBalanced(text);
}



