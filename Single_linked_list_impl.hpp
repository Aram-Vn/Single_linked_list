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

template <class T> 
my::Forward_list<T>::Node::Node(T val, Node* node_ptr) :
	m_val{val},
	m_next{node_ptr}
{}

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

	while (current->m_next->m_next) {
   		current = current->m_next;
	}

	return current->m_next->m_val;
}



#endif // SINGLE_LINKED_LIST_H
