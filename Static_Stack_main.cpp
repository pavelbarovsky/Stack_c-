// ����������� ����

#include <iostream>
#include <stack>
#include <string>
using namespace std;


bool BracketsBalanced(string text) {
    stack<char> s;
    char x;

    // ����� ���������
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == '(' || text[i] == '[' || text[i] == '{') {
            // ��������� ������� � ���� �����
            s.push(text[i]);
        }

        // ���� ������� ������ �� ��������� ������,
        //�� �� ������ �����������.
        //����� �������, ���� �� ����� ���� ������ � ���� ������.
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

    // ��������� ������ ����
    return (s.empty());
}

int main() {

    setlocale(LC_ALL, "Russian");

    string text = "{(4+x)*}[d/5-7+19*s])";

    if (BracketsBalanced(text)) {
        cout << "� ������ " << text << " ������ ����������� ���������!" << endl;
    }
    else {
        cout << "� ������ " << text << " ������ ����������� �� ���������!" << endl;
    }
    return 0;
}

