//Make sure this isn't included in project compile

template<typename T>
Node<T>* LinkedList<T>::GetNextNode(Node<T>* node)
{
	return node->next;
}

template<typename T>
Node<T>* LinkedList<T>::IterateToTail()
{
	Node<T>* temp = head;
	//if list is empty avoid while loop
	if (head == nullptr)
		return temp;
	while (temp->next != nullptr)
	{
		temp = GetNextNode(temp);
	}
	return temp;
}

template<typename T>
void LinkedList<T>::DeleteNextNode(Node<T>* node)
{
	if (node->next != nullptr)
		DeleteNextNode(node->next);
	delete node;
}

template<typename T>
LinkedList<T>::LinkedList()
	:count(0), head(nullptr)
{
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	if (head != nullptr)
	{
		Node<T>* temp = head;
		DeleteNextNode(temp);
	}
}

template<typename T>
void LinkedList<T>::BeginListIteration()
{
	currentIterationNode = head;
}

template<typename T>
void LinkedList<T>::NextListIteration()
{
	if (currentIterationNode->next == nullptr)
		currentIterationNode = head;
	else
		currentIterationNode = GetNextNode(currentIterationNode);
}

template<typename T>
T LinkedList<T>::GetCurrentListIterationData()
{
	return currentIterationNode->data;
}

template<typename T>
void LinkedList<T>::PushBack(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>;
		head->data = data;
		head->next = nullptr;
	}
	else
	{
		Node<T>* tail;
		tail = IterateToTail();
		Node<T>* node = new Node<T>;
		tail->next = node;
		node->data = data;
		node->next = nullptr;
	}
	count++;
}

template<typename T>
void LinkedList<T>::PushFront(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>;
		head->data = data;
		head->next = nullptr;
	}
	else
	{
		Node<T>* newHead = new Node<T>;
		newHead->next = head;
		newHead->data = data;
		head = newHead;
	}
	count++;
}

template<typename T>
void LinkedList<T>::PopFront()
{
	if (head != nullptr)
	{
		Node<T>* temp = head->next;
		delete head;
		head = temp;
		count--;
	}
}

template<typename T>
void LinkedList<T>::PopBack()
{
	Node<T>* temp = head;
	//if list is empty nothing to pop
	if (head == nullptr)
		return;
	//if the list is size of one cant use while loop
	if (head->next == nullptr)
	{
		//temp = nullptr;
		delete head;
		head = nullptr;
		count--;
		return;
	}
	//Get the node one before the tail
	while (temp->next->next != nullptr)
	{
		temp = GetNextNode(temp);
	}
	delete IterateToTail();//delete tail then set prev to nullptr
	temp->next = nullptr;
	count--;
}

//Helper functions for DisplayList
std::string DataToString(int data) { return std::to_string(data); }
std::string DataToString(long data) { return std::to_string(data); }
std::string DataToString(long long data) { return std::to_string(data); }
std::string DataToString(unsigned int data) { return std::to_string(data); }
std::string DataToString(unsigned long data) { return std::to_string(data); }
std::string DataToString(unsigned long long data) { return std::to_string(data); }
std::string DataToString(float data) { return std::to_string(data); }
std::string DataToString(double data) { return std::to_string(data); }
std::string DataToString(long double data) { return std::to_string(data); }
std::string DataToString(std::string data) { return data; }
template<typename T> std::string DataToString(T data) { return "Non primitive data type"; }

char DataToString(char data) { return data; }
unsigned char DataToString(unsigned char data) { return data; }
short DataToString(short data) { return data; }
unsigned short DataToString(unsigned short data) { return data; }

//Only works with primitve data types
template<typename T>
std::string LinkedList<T>::DisplayList()
{
	if (head == nullptr)
		return "Empty";
	
	std::string outPut;

	Node<T>* temp = head;
	while (temp != nullptr)
	{
		outPut += DataToString(temp->data);
		temp = GetNextNode(temp);
	} 

	return outPut;
}