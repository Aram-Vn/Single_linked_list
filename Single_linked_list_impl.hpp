#ifndef SINGLE_LINKED_LIST_IMPL_HPP
#define SINGLE_LINKED_LIST_IMPL_HPP

template <class T>
my::Forward_list<T>::~Forward_list()
{
	while (m_head) {
		Node* temp = m_head;
		m_head = m_head->m_next;
		delete temp;
	}
}

template <typename T>
my::Forward_list<T>::Forward_list(const Forward_list& other)
{
    if (!other.m_head) {
    	return;
	}

    Node* current = other.m_head;
    this->m_head = new Node(current->m_val, nullptr);
    Node* this_current = this->m_head;
	current = current->m_next;

   	while (current) {
        this_current->m_next = new Node(current->m_val, nullptr);
        current = current->m_next;
    	this_current = this_current->m_next;
	}
}

template <class T>
my::Forward_list<T>::Forward_list(Forward_list&& other) noexcept :
	m_head{other.m_head}
{
	other.m_head = nullptr;
}

template <class T> 
my::Forward_list<T>::Node::Node(T val, Node* node_ptr) :
	m_val{val},
	m_next{node_ptr}
{}

template <class T> 
my::Forward_list<T>::Forward_list(std::initializer_list<T> init_list) 
{
	for (const auto& elem : init_list) {
		this->push_back(elem);
    }
}


template <class T> 
my::Forward_list<T>& my::Forward_list<T>::operator=(const Forward_list& other)
{	
	if (this != &other) {
    	clear();

        Node* otherCurrent = other.m_head;
        Node* newCurrent = nullptr;

        while (otherCurrent) {
            Node* newNode = new Node(otherCurrent->m_val, nullptr);

            if (!m_head) {
                m_head = newNode;
                newCurrent = m_head;
            } else {
                newCurrent->m_next = newNode;
                newCurrent = newCurrent->m_next;
            }

            otherCurrent = otherCurrent->m_next;
        }
    }

    return *this;
}

template <class T> 
my::Forward_list<T>& my::Forward_list<T>::operator=(Forward_list&& other) noexcept
{
	if (this != &other) { 
        clear();

        m_head = other.m_head;
        other.m_head = nullptr;
    }

	return *this;
}

template <class T>
void my::Forward_list<T>::push_front(int data)
{
	Node* new_node = new Node{data, m_head};
    m_head = new_node;
}

template <class T>
void my::Forward_list<T>::push_back(int data) 
{
  	if (!m_head) {
        m_head = new Node{data, nullptr};
    	return;
    }

    Node* current = m_head;

	while (current->m_next) {
        current = current->m_next;
    }

    current->m_next = new Node{data, nullptr};
}

template <class T>   
void my::Forward_list<T>::pop_front() 
{
	if (!m_head) {
    	std::cout << "List is empty!!!\nin pop_front()" << std::endl;
   		exit(0);
	 }

    Node* tmp_ptr = m_head;
    m_head = m_head->m_next;
    delete tmp_ptr;
}

template <class T>  
void my::Forward_list<T>::pop_back() 
{
	if (!m_head) {
    	std::cout << "List is empty!!!\nCannot pop_back()." << std::endl;
		exit(0);
	}

	if (!m_head->m_next) {
    	delete m_head;
   		m_head = nullptr;
    	return;
	}

	Node* current = m_head;

	while (current->m_next->m_next) {
   		current = current->m_next;
	}

	delete current->m_next;
	current->m_next = nullptr;
}

template <class T>
void my::Forward_list<T>::insert(int pos, const T& value) {
    if (pos < 0) {
        std::cout << "In insert\nFirst argument must be >= 0" << std::endl;
        exit(0);
    }

    if (pos == 0) {
        Node* new_node = new Node(value, m_head);
        m_head = new_node;
        return;
    }

    int count = 0;
    Node* current = m_head;

    while (current->m_next && count < pos - 1) {
        current = current->m_next;
        ++count;
    }

    if (count == pos - 1) {
        Node* new_node = new Node(value, current->m_next);
        current->m_next = new_node;
    } else {
        std::cout << "In insert\nThere is no such index" << std::endl;
        exit(0);
    }
}

template <class T>
void my::Forward_list<T>::erase(int index) {
    if (index < 0) {
        std::cout << "In erase\nIndex must be >= 0" << std::endl;
        exit(0);
    }

    if (index == 0) {
        if (m_head) {
            Node* temp = m_head;
            m_head = m_head->m_next;
            delete temp;
        }
        return;
    }

    int count = 0;
    Node* current = m_head;
    Node* previous = nullptr;

    while (current && count < index) {
        previous = current;
        current = current->m_next;
        ++count;
    }

    if (count == index && current) {
        if (previous) {
            previous->m_next = current->m_next;
            delete current;
        }
    } else {
        std::cout << "In erase\nIndex is out of bounds" << std::endl;
		exit(0);
	}
}

template <class T> 
T my::Forward_list<T>::front() const
{
	if (!m_head) {
		std::cout << "List is empty!!!\nCannot front()." << std::endl;
		exit(0);
	}

	return m_head->m_val;
}

template <class T> 
T my::Forward_list<T>::back() const
{
	if (!m_head) {
		std::cout << "List is empty!!!\nCannot back()." << std::endl;
		exit(0);
	}
	
	Node* current = m_head;

	if (!m_head->m_next) {
		return m_head->m_val;
	}

	while (current->m_next->m_next) {
   		current = current->m_next;
	}

	return current->m_next->m_val;
}

template <class T> 
bool my::Forward_list<T>::empty() const
{
	return !(m_head); 
}

template <class T> 
size_t my::Forward_list<T>::size() const
{
	if (!m_head) {
		return 0;
	}

	size_t size = 1;
	
	Node* tmp_ptr = m_head;
	while (tmp_ptr->m_next) {
		tmp_ptr = tmp_ptr->m_next;
		++size;
	}

	return size;
}

template <class T> 
void my::Forward_list<T>::clear()
{
	while (m_head) {
		Node* temp = m_head;
		m_head = m_head->m_next;
		delete temp;
	}
}

template <class T> 
void my::Forward_list<T>::swap(Forward_list& other)
{
	std::swap(this->m_head, other.m_head);	
}

template <class T> 
void my::Forward_list<T>::print()
{
	Node* current = m_head;

	while (current->m_next) {
		std::cout << current->m_val << " ";
        current = current->m_next;
   	}
	std::cout << current->m_val << " ";
	std::cout << std::endl;
}

template <class T>
void my::Forward_list<T>::reverse()
{
	Node* current = m_head;

	const int SIZE = this->size();
	T arr[SIZE];	
	int i = 0;

	while (current->m_next) {
		arr[i] = current->m_val;
		++i;	
    	current = current->m_next;
    } 
	arr[i] = current->m_val;
	
	current = m_head;

	while (this->m_head) { 
		this->m_head->m_val = arr[i];
		--i;
		this->m_head = this->m_head->m_next;	
	}

	this->m_head = current;
	this->m_head->m_val = arr[SIZE - 1];
}

#endif // SINGLE_LINKED_LIST_H
