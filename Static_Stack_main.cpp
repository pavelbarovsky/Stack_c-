// Статический стек

#include <iostream>
#include <stack>
#include <string>
using namespace std;


bool BracketsBalanced(string text) {
    stack<char> s;
    char x;

    // Обход выражения
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == '(' || text[i] == '[' || text[i] == '{') {
            // Поместить элемент в стек вверх
            s.push(text[i]);
        }

        // если текущий символ не открывает скобку,
        //то он должен закрываться.
        //Таким образом, стек не может быть пустым в этот момент.
        if (s.empty()) {
            return false;
        }

        switch (text[i]) {
        case ')':
            x = s.top();
            s.pop();
            if (x == '{' || x == '[') {
                return false;
            }
            break;

        case '}':
            x = s.top();
            s.pop();
            if (x == '(' || x == '[') {
                return false;
            }
            break;

        case ']':
            x = s.top();
            s.pop();
            if (x == '(' || x == '{') {
                return false;
            }
            break;
        }
    }

    // Проверяем пустой стек
    return (s.empty());
}

int main() {

    setlocale(LC_ALL, "Russian");

    string text = "{(4+x)*}[d/5-7+19*s])";

    if (BracketsBalanced(text)) {
        cout << "В строке " << text << " скобки расставлены правильно!" << endl;
    }
    else {
        cout << "В строке " << text << " скобки расставлены не правильно!" << endl;
    }
    return 0;
}

