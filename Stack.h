#include <iostream>
using namespace std;

class Stack {
public:
	Stack();
	~Stack();

	void push(string val);
	void pop();
	void clear();
	bool IsEmpty();
	void BracketsBalanced(string text);

private:
	struct Node {
		Node* prev;
		string value;

		Node(string val) {
			value = val;
			prev = nullptr;
		}
		~Node() = default;
	};
	Node* Top;
};
