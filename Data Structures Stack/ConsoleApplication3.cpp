#include <iostream>
#include <cassert>

using namespace std;
template <class Type>
struct node 
{
	int info;
	node *link;
};

template <class Type>
class stack
{
private:
	node<Type> *stackTop;
public:
	void reverseStack(stack&);
	stack();
	~stack();
	void intializeStack();
	bool isEmptyStack() const;
	bool isFullStack() const;
	void push(const Type& x);
	void print();
};

template <class Type>
stack<Type>::stack()
{
	stackTop = NULL;
}
template <class Type>
stack<Type>::~stack()
{
	intializeStack();
}
template <class Type>
bool stack<Type>::isEmptyStack() const
{
	return (stackTop == NULL);
}
template <class Type>
bool stack<Type>::isFullStack() const
{
	return false;
}
template <class Type>
void stack<Type>::intializeStack()
{
	node<Type> *temp;
	while (stackTop != NULL)
	{
		temp = stackTop;
		stackTop = stackTop->link;
		delete temp;
	}
}
template <class Type>
void stack<Type>::push(const Type& x)
{
	node<Type> *newNode;

	newNode = new node<Type>;
	newNode->info = x;
	newNode->link = stackTop;
	stackTop = newNode;
}
template <class Type>
void stack<Type>::reverseStack(stack<Type>& other)
{
	node<Type> *newNode, *current, *last;

	if (other.stackTop != NULL)
		other.intializeStack();

	if (stackTop == NULL)
		other.stackTop = NULL;
	else
	{
		current = stackTop;

		other.stackTop = new node<Type>;
		other.stackTop->info = current->info;
		other.stackTop->link = NULL;
		last = other.stackTop;
		current = current->link;

		while (current != NULL)
		{
			newNode = new node<Type>;
			newNode->info = current->info;
			newNode->link = other.stackTop;
			other.stackTop = newNode;
			current = current->link;
		}
	}
}
template <class Type>
void stack<Type>::print()
{
	if (stackTop == NULL)
		cout << "Stack is empty." << endl;
	else
	{
		node<Type> *temp;
		temp = stackTop;

		while (temp != NULL)
		{
			cout << temp->info << " ";
			temp = temp->link;
		}
		cout << endl;
	}
}

int main()
{
	stack<int> stack, other;

	stack.push(33);
	stack.push(44);
	stack.push(55);
	other.push(123);
	other.push(246);

	cout << "This is a stack:" << endl;
		stack.print();
	cout << endl;
		other.print();

	cout << "---------------------------------" << endl;
	cout << "After reversing A to B" << endl;
	stack.reverseStack(other);

	cout << "Stack A: ";
	stack.print();

	cout << endl;

	cout << "Stack B: ";
	other.print();

	return 0;
}

