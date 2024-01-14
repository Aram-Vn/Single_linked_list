#ifndef SINGLE_LINKED_LIST_IMPL_HPP
#define SINGLE_LINKED_LIST_IMPL_HPP

//---------------------------------------------------------------||
//----------------------F_iterator-------------------------------||
//---------------------------------------------------------------||

//----------------F_iterator__Default_Constructor_---------------------//
template <class T>
my::Forward_list<T>::F_iterator::F_iterator() : ptr(nullptr)
{
}

//-----------------_F_iterator__Parameterized_Constructor-------------//
template <class T>
my::Forward_list<T>::F_iterator::F_iterator(Node* ptr1) : ptr(ptr1)
{
}

//-----------------_F_iterator__Copy_Assignment_Operator_-------------//
template <class T>
typename my::Forward_list<T>::F_iterator& my::Forward_list<T>::F_iterator::operator=(const F_iterator& other)
{
}

//------------------_F_iterator__Dereference_Operator_----------------//
template <class T>
T& my::Forward_list<T>::F_iterator::operator*()
{
    return ptr->m_val;
}

//-------------------_F_iterator__Arrow_Operator_---------------------//
template <class T>
typename my::Forward_list<T>::Node* my::Forward_list<T>::F_iterator::operator->()
{
    return ptr;
}

//--------------------_F_iterator__Pre-increment_Operator_------------//
template <class T>
typename my::Forward_list<T>::F_iterator& my::Forward_list<T>::F_iterator::operator++()
{
    ptr = ptr->m_next;
    return *this;
}

//--------------------_F_iterator__Post-increment_Operator_------------//
template <class T>
typename my::Forward_list<T>::F_iterator my::Forward_list<T>::F_iterator::operator++(int)
{
    f_itr tmp = *this;
    ptr = ptr->m_next;
    return tmp;
}

//------------------_F_iterator__Equality_Comparison_Operator_----------//
template <class T>
bool my::Forward_list<T>::F_iterator::operator==(const F_iterator& other)
{
    return (this->ptr == other.ptr);
}

//----------------_F_iterator__Inequality_Comparison_Operator_----------//
template <class T>
bool my::Forward_list<T>::F_iterator::operator!=(const F_iterator& other)
{
    return !(this->ptr == other.ptr);
}

template <class T>
typename my::Forward_list<T>::F_iterator my::Forward_list<T>::begin()
{
    return F_iterator(m_head);
}

template <class T>
typename my::Forward_list<T>::F_iterator my::Forward_list<T>::end()
{
    return F_iterator(nullptr);
}

//----------------------__Node__parameterized_constructor_-------------------//
template <class T>
my::Forward_list<T>::Node::Node(T val, Node* node_ptr) : m_val{ val }, m_next{ node_ptr }
{
}

//----------------------------------------------------------------------||
//-------------------------_Forward_list_-------------------------------||
//----------------------------------------------------------------------||

//-------------------------_Forward_list__Default_Constructor_-----------------//
template <class T>
my::Forward_list<T>::Forward_list() : m_head(nullptr)
{
}

//------------------------__Forward_list__destructor_--------------------------//
template <class T>
my::Forward_list<T>::~Forward_list()
{
    while (m_head)
    {
        Node* temp = m_head;
        m_head = m_head->m_next;
        delete temp;
    }
}

//-----------------------__Forward_list__Copy_constructor_-------------------//
template <typename T>
my::Forward_list<T>::Forward_list(const Forward_list& other) // Copy constructor for the Forward_list class
{
    if (!other.m_head) // if other is empty(head is nullptr)
    {
        return; // return
    }

    Node* current = other.m_head;                     // Pointer to traverse the other list
    this->m_head = new Node(current->m_val, nullptr); // Create the first node for the new list
    Node* this_current = this->m_head;                // Pointer to the current node in the new list
    current = current->m_next;                        // Move to the next node in the other list

    while (current) // Iterate through the other list and copy each node to the new list
    {
        this_current->m_next = new Node(current->m_val, nullptr); // Create a new node in now list with the value of other
        current = current->m_next;                                // Move to the next node in the other list
        this_current = this_current->m_next;                      // Move to the next node in the new list
    }
}

//-----------------------__Forward_list__Move_constructor__-------------------//
template <class T>
my::Forward_list<T>::Forward_list(Forward_list&& other) noexcept // Move constructor for the Forward_list class
    : m_head{ other.m_head } // Move the head pointer from the other list to the new list
{
    other.m_head = nullptr;  // Set the other list's head to nullptr
}

//--------------------__Forward_list__initializer_list_constructor------------//
template <class T>
my::Forward_list<T>::Forward_list(std::initializer_list<T> init_list) // Constructor that takes an initializer_list to initialize the Forward_list
    : m_head(nullptr) // Initialize the head pointer to nullptr as the list is currently empty
{
    for (auto it = std::rbegin(init_list); it != std::rend(init_list); ++it)  // Iterate through the elements in the reversed list in reverse order
    {
        this->push_front(*it); // Add each element to the front of the list using the push_front
    }
}

//-------------------__Forward_list__Copy_assignment_operator__---------------//
template <class T>
my::Forward_list<T>& my::Forward_list<T>::operator=(const Forward_list& other) // Copy assignment operator for the Forward_list class
{
    if (this != &other) // Check for self-assignment
    {
        this->clear(); // Clear the existing content of the list

        Node* current = other.m_head;                     // Pointer to traverse the other list
        this->m_head = new Node(current->m_val, nullptr); // Create the first node for the new list
        Node* this_current = this->m_head;                // Pointer to the current node in the new list
        current = current->m_next;                        // Move to the next node in the other list

        while (current) // Iterate through the other list and copy each node to the new list
        {
            this_current->m_next = new Node(current->m_val, nullptr); // Create a new node in the new list with the value of the current node in the other list
            current = current->m_next;                                // Move to the next node in the other list
            this_current = this_current->m_next;                      // Move to the next node in the new list
        }
    }

    
    return *this; // Return a reference to the modified object to allow chaining assignments
}

//-------------------__Forward_list__Move_assignment_operator__----------------------------//
template <class T>
my::Forward_list<T>& my::Forward_list<T>::operator=(Forward_list&& other) noexcept// Move assignment operator for the Forward_list class
{
    if (this != &other) // Check for self-assignment
    {
        this->clear(); // Clear the existing content of the list

        this->m_head = other.m_head; // Transfer ownership of the nodes from the other list to the current list
        other.m_head = nullptr;      // Set the other list's head to nullptr to indicate ownership transfer
    }

    return *this; // Return a reference to the modified object to allow chaining assignm
}

//--------------------------__Forward_list__push_front__-----------------------------------//
template <class T>
void my::Forward_list<T>::push_front(T data) // Add value(data) at the front of list
{
    Node* new_node = new Node{ data, m_head };  // Create a new node with the specified data and the current head as the next nod
    m_head = new_node;                          // Update the head to point to the new node
}

//---------------------------__Forward_list__push_back__---------------------------------//
template <class T>
void my::Forward_list<T>::push_back(T data) // Add value(data) at the end of list
{
    if (!m_head) // Check if the list is empty
    {
        m_head = new Node{ data, nullptr }; // If empty, create a new node with the specified data as the head
        return;
    }

    Node* current = m_head; // create pointer at the head of list to not lost the head

    while (current->m_next) // Iterate through the list to find the last node
    {
        current = current->m_next;
    }

    current->m_next = new Node{ data, nullptr }; // Create a new node with the specified data as the next node of the last
}

//---------------------------__Forward_list__pop_pront__---------------------------------//
template <class T>
void my::Forward_list<T>::pop_front() // Remove the node at the front of the lis
{
    if (!m_head) // Check if the list is empty
    {
        std::cout << "List is empty!!!\nin pop_front()" << std::endl;
        exit(0); // Print an error message and exit the program if the list is empty
    }

    Node* tmp_ptr = m_head;  // Temporary pointer to the current head
    m_head = m_head->m_next; // Update the head to point to the next node,
    delete tmp_ptr;          // Delete the old head using the temporary pointer
}

//---------------------------__Forward_list__pop_back__---------------------------------//
template <class T>
void my::Forward_list<T>::pop_back() // Remove the last node from the list
{
    if (!m_head) // Check if the list is empty
    {
        std::cout << "List is empty!!!\nCannot pop_back()." << std::endl;
        exit(0); // Print an error message and exit the program if the list is empty
    }

    if (!m_head->m_next) // Check if there is only one node in the list
    {
        delete m_head;    // If only one node, delete it
        m_head = nullptr; // set head to nullptr
        return;
    }

    Node* current = m_head; // create pointer at the head of list to not lost the head

    while (current->m_next->m_next) // Traverse the list to find the second-to-last node
    {
        current = current->m_next;
    }

    delete current->m_next;    // Delete the last node
    current->m_next = nullptr; // set the next pointer of the second-to-last node to nullptr
}

//---------------------------__Forward_list__insert__---------------------------------//
template <class T>
void my::Forward_list<T>::insert(int pos, const T& value) // insert value at specific position(pos)
{
    if (pos < 0) // Check if the position is valid (non-negative)
    {
        std::cout << "In insert\nFirst argument must be >= 0" << std::endl;
        exit(0);
    }

    if (pos == 0) // If inserting at the beginning (position 0)
    {
        this->push_front(value); // call push_front to insert at the front of list
        return;
    }

    int count = 0;           // to hold current position
    Node* current = m_head;  // create pointer at the head of list to not lost the head

    while (current->m_next && count < pos - 1) // Traverse the list to find the node at the position before given position(pos)
    {
        current = current->m_next;
        ++count;
    }

    if (count == pos - 1) // Check if the position is valid (within the current size of the list)
    {
        Node* new_node = new Node(value, current->m_next); // Create a new node with given value
        current->m_next = new_node;                        // insert it into the list
    }
    else
    {
        std::cout << "In insert\nThere is no such index" << std::endl;
        exit(0); // Print an error message and exit the program if given position is invalid
    }
}

//---------------------------__Forward_list__erase__---------------------------------//
template <class T>
void my::Forward_list<T>::erase(int index)
{
    if (index < 0)
    {
        std::cout << "In erase\nIndex must be >= 0" << std::endl;
        exit(0);
    }

    if (index == 0)
    {
        if (m_head)
        {
            Node* temp = m_head;
            m_head = m_head->m_next;
            delete temp;
        }
        return;
    }

    int count = 0;
    Node* current = m_head;
    Node* previous = nullptr;

    while (current && count < index)
    {
        previous = current;
        current = current->m_next;
        ++count;
    }

    if (count == index && current)
    {
        if (previous)
        {
            previous->m_next = current->m_next;
            delete current;
        }
    }
    else
    {
        std::cout << "In erase\nIndex is out of bounds" << std::endl;
        exit(0);
    }
}

template <class T>
T my::Forward_list<T>::front() const
{
    if (!m_head)
    {
        std::cout << "List is empty!!!\nCannot front()." << std::endl;
        exit(0);
    }

    return m_head->m_val;
}

template <class T>
T my::Forward_list<T>::back() const
{
    if (!m_head)
    {
        std::cout << "List is empty!!!\nCannot back()." << std::endl;
        exit(0);
    }

    Node* current = m_head;

    if (!m_head->m_next)
    {
        return m_head->m_val;
    }

    while (current->m_next->m_next)
    {
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
    if (!m_head)
    {
        return 0;
    }

    size_t size = 1;

    Node* tmp_ptr = m_head;
    while (tmp_ptr->m_next)
    {
        tmp_ptr = tmp_ptr->m_next;
        ++size;
    }

    return size;
}

template <class T>
void my::Forward_list<T>::clear()
{
    while (m_head)
    {
        Node* temp = m_head;
        m_head = m_head->m_next;
        delete temp;
    }
    m_head = nullptr;
}

template <class T>
void my::Forward_list<T>::swap(Forward_list& other)
{
    std::swap(this->m_head, other.m_head);
}

template <class T>
void my::Forward_list<T>::assign(int count, const T& value)
{
    if (count < 0)
    {
        std::cout << "in void assign(int count, const T& value)" << std::endl;
        std::cout << "count must be >= 0" << std::endl;
        exit(0);
    }

    this->clear();

    for (int i = 0; i < count; ++i)
    {
        this->push_back(value);
    }
}

template <class T>
void my::Forward_list<T>::assign(const std::initializer_list<T>& init_list)
{
    this->clear();

    for (const T& elem : init_list)
    {
        this->push_back(elem);
    }
}

template <class T>
void my::Forward_list<T>::print()
{
    Node* current = m_head;

    while (current->m_next)
    {
        std::cout << current->m_val << " ";
        current = current->m_next;
    }
    std::cout << current->m_val << " ";
    std::cout << std::endl;
}

template <class T>
void my::Forward_list<T>::reverse()
{
    if (!m_head || !m_head->m_next)
    {
        return;
    }

    Node* prev = nullptr;
    Node* current = m_head;
    Node* next = nullptr;

    while (current)
    {
        next = current->m_next;
        current->m_next = prev;
        prev = current;
        current = next;
    }

    m_head = prev;
}

template <class T>
void my::Forward_list<T>::insertionSort()
{
    if (!m_head || !m_head->m_next)
    {
        return;
    }

    Node* sorted = nullptr;
    Node* current = m_head;

    while (current)
    {
        Node* next = current->m_next;

        if (!sorted || current->m_val < sorted->m_val)
        {
            current->m_next = sorted;
            sorted = current;
        }
        else
        {
            Node* temp = sorted;

            while (temp->m_next && current->m_val > temp->m_next->m_val)
            {
                temp = temp->m_next;
            }

            current->m_next = temp->m_next;
            temp->m_next = current;
        }

        current = next;
    }

    m_head = sorted;
}

template <class T>
typename my::Forward_list<T>::f_itr my::Forward_list<T>::find(const T& val)
{
    for (auto itr = this->begin(); itr != this->end(); ++itr)
    {
        if (itr->m_val == val)
        {
            return itr;
        }
    }

    return nullptr;
}

template <class T>
void my::Forward_list<T>::erase(f_itr pos)
{
    if (pos == begin())
    {
        pop_front();
        return;
    }

    f_itr tmp_itr = begin();
    Node* prev = nullptr;
    Node* curr = m_head;

    while (tmp_itr != pos)
    {
        prev = curr;
        curr = curr->m_next;
        ++tmp_itr;
    }

    Node* next = curr->m_next;
    delete curr;
    prev->m_next = next;
}

#endif // SINGLE_LINKED_LIST_H
