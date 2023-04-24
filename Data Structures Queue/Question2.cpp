#include <iostream>
#include <cassert>

using namespace std;

struct node
{
	int info;
	node *link;
};
class queue
{
private:
	node *queueFront, *queueRear;
	int count=0;
public:
	queue();
	~queue();
	bool isEmptyQueue() const;
	bool isFullQueue() const;
	void initializeQueue();
	int front() const;
	int back() const;
	void addQueue(const int& x);
	void deleteQueue();
	int queueCount();
};
queue::queue()
{
	queueFront = NULL;
	queueRear = NULL;
}
queue::~queue()
{
	initializeQueue();
}
bool queue::isEmptyQueue() const
{
	return(queueFront == NULL);
}
bool queue::isFullQueue() const
{
	return false;
}
void queue::initializeQueue()
{
	node *temp;
	while (queueFront != NULL)
	{
		temp = queueFront;
		queueFront = queueFront->link;

		delete temp;
	}
	queueRear = NULL;
	count = 0;
}
void queue::addQueue(const int& x)
{
	count++;
	node *newNode;
	newNode = new node;
	newNode->info = x;
	newNode->link = NULL;

	if (queueFront == NULL)
	{
		queueFront = newNode;
		queueRear = newNode;
	}
	else
	{
		queueRear->link = newNode;
		queueRear = queueRear->link;
	}
}
int queue::front() const
{
	assert(queueFront != NULL);
	return (queueFront->info);
}
int queue::back() const
{
	assert(queueFront != NULL);
	return (queueRear->info);
}
void queue::deleteQueue()
{
	node *temp;
	if (!isEmptyQueue())
	{
		count--;
		temp = queueFront;
		queueFront = queueFront->link;
		delete temp;
		if (queueFront == NULL)
			queueRear = NULL;
	}
	else
		cout << "Cannot remove from an empty queue." << endl;
}
int queue::queueCount()
{
	return count;
}
int main()
{
	queue q1;
	q1.initializeQueue();
	int x, y;
	x = 4;
	y = 5;

	q1.addQueue(x);
	q1.addQueue(y);
	q1.addQueue(y);
	q1.addQueue(y);

	cout << "Queue size before printing the elements: " << q1.queueCount() << endl;
	cout << "Queue elements are: " << endl;
	while (!q1.isEmptyQueue())
	{
		cout << q1.front() << " ";
		q1.deleteQueue();
	}
	cout << endl;
	cout << "Queue size after printing the elements: " << q1.queueCount() << endl;
	return 0;
}
