#include "Stack.h"
#include <sstream>
using namespace std;

Stack::Stack() {
	Top = nullptr;
}

Stack::~Stack() {
	clear();
}

void Stack::push(string val) {
	if (Top != nullptr) { // ���� ������� ����, ��
		Node* temp = new Node(val); //�������� ������ ��� ������ ��������
		temp->prev = Top; // ��������� ����� ������� ����� � ����������
		Top = temp; // ����� ������� ����� ���������� ��� ��������
	}
	else { // ���� ��� �������
		Top = new Node(val); // ������� ����� �������
		Top->value = val; // ����������� ������� ��������
	}
}

void Stack::pop() { // ���������� �������� � ����
	if (!IsEmpty()) {
		Node* temp = Top; // ���������� ��������� �� ������� �����
		Top = Top->prev; // �������� ���������� �������������� top �������
		delete temp; // ����������� ������, ��� ����� ������� �������
	}
}

void Stack::clear() { // �������� �����
	while (Top != nullptr) { // ���� ������� �� ������
		Node* temp = Top->prev; // ���������� ��� �������� ������ ����.��������
		delete Top; // ����������� ����� ������
		Top = temp; // ������ ����� �� ���������
	}

}

bool Stack::IsEmpty() { // �������� �� ������� �����
	return Top == nullptr;
}

void Stack::BracketsBalanced(string text) {
	int flag = 1; // ���� �������, ������� �� �����
	Stack* stk;
	stk = new Stack();
	for (int i = 0; i < text.size(); i++) { // ������� ������
		if (text[i] == ')') {
			if (stk->IsEmpty()) {
				flag = 0; // ������ ���, ���� ����
				break;
			}
			if (stk->Top->value == "(") { // ����� �� �������� �������� ����� ������
				stk->pop(); // ������� �������� �����
			}
			else {
				flag = 0; // ����� �����
				break;
			}
		}
		if (text[i] == '(') {
			ostringstream oss; // ������ oss, ������� ����� � ������
			oss << text[i]; // ������� � oss ��� �����
			stk->push(oss.str()); // ������� � ���� ���������� ���� ������
		}
	}
	for (int i = 0; i < text.size(); i++) {
		if (text[i] == '}') {
			if (stk->IsEmpty()) {
				flag = 0;
				break;
			}
			if (stk->Top->value == "{") {
				stk->pop();
			}
			else {
				flag = 0;
				break;
			}
		}
		if (text[i] == '{') {
			ostringstream oss;
			oss << text[i];
			stk->push(oss.str());
		}
	}
	for (int i = 0; i < text.size(); i++) {
		if (text[i] == ']') {
			if (stk->IsEmpty()) {
				flag = 0;
				break;
			}
			if (stk->Top->value == "[") {
				stk->pop();
			}
			else {
				flag = 0;
				break;
			}
		}
		if (text[i] == '[') {
			ostringstream oss;
			oss << text[i];
			stk->push(oss.str());
		}
	}

	if (flag == 1 && stk->IsEmpty()) {
		cout << "� ������ " << text << " ������ ����������� �����" << endl;
	}
	else {
		cout << "� ������ " << text << " ������ ����������� �� �����" << endl;;
	}
	stk->clear();
}
