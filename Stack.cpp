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
	if (Top != nullptr) { // если вершина есть, то
		Node* temp = new Node(val); //Выделяем память для нового элемента
		temp->prev = Top; // связываем новый элемент стека с предыдущим
		Top = temp; // новый элемент стека становится его вершиной
	}
	else { // если нет вершины
		Top = new Node(val); // создаем новый элемент
		Top->value = val; // присваеваем вершине значение
	}
}

void Stack::pop() { // добавление элемента в стек
	if (!IsEmpty()) {
		Node* temp = Top; // запоминаем указатель на вершину стека
		Top = Top->prev; // вершиной становится предшествующий top элемент
		delete temp; // освобождаем память, тем самым удалили вершину
	}
}

void Stack::clear() { // удаление стека
	while (Top != nullptr) { // пока вершина не пустая
		Node* temp = Top->prev; // переменная для хранения адреса след.элемента
		delete Top; // освобождаем адрес начала
		Top = temp; // меняем адрес на следующий
	}

}

bool Stack::IsEmpty() { // проверка на пустоту стека
	return Top == nullptr;
}

void Stack::BracketsBalanced(string text) {
	int flag = 1; // флаг пустоты, сначала не пусто
	Stack* stk;
	stk = new Stack();
	for (int i = 0; i < text.size(); i++) { // перебор строки
		if (text[i] == ')') {
			if (stk->IsEmpty()) {
				flag = 0; // скобки нет, стек пуст
				break;
			}
			if (stk->Top->value == "(") { // равно ли значение верхушки стека скобке
				stk->pop(); // удаляем верхушку стека
			}
			else {
				flag = 0; // тогда пусто
				break;
			}
		}
		if (text[i] == '(') {
			ostringstream oss; // объект oss, перевод числа в строку
			oss << text[i]; // заносим в oss наш текст
			stk->push(oss.str()); // заносим в стек полученную выше строку
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
		cout << "В строке " << text << " скобки расставлены верно" << endl;
	}
	else {
		cout << "В строке " << text << " скобки расставлены не верно" << endl;;
	}
	stk->clear();
}
