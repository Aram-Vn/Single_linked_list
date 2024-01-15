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
    for (auto it = std::rbegin(init_list); it != std::rend(init_list); ++it)  // Iterate through the elements in the list in reverse order
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
        exit(0); // Print an error message and exit the program if given position is invalid
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
void my::Forward_list<T>::erase(int index) // Remove the node at the specified index in the list
{
    if (index < 0) // Check if the index is valid (non-negative)
    {
        std::cout << "In erase\nIndex must be >= 0" << std::endl;
        exit(0); // Print an error message and exit the program if given position is invalid
    }

    if (index == 0) // If removing the first node (index 0)
    {
        this->pop_front(); // call pop_front function to remove first element
        return;
    }

    int count = 0;            // to hold current position
    Node* current = m_head;   // Pointer to traverse the list
    Node* previous = nullptr; // Pointer to the node before the current node

    while (current && count < index)// Traverse the list to find the node at the position before the given position(index)
    {
        previous = current;        // Update the previous pointer to the current node
        current = current->m_next; // Move to the next node in the list
        ++count;                   // Increment the position counter
    }

    if (count == index && current) // Check if the index is valid (within the current size of the list)
    {
        if (previous) // Check if there is a node before the node to be removed
        {
            previous->m_next = current->m_next;  // Update the next pointer of the previous node to skip the node being removed
            delete current;                      // Delete the node to be removed
        }
    }
    else
    {
        std::cout << "In erase\nIndex is out of bounds" << std::endl;
        exit(0); // Print an error message and exit the program if given position is invalid
    }
}

//---------------------------__Forward_list__front__---------------------------------//
template <class T>
T my::Forward_list<T>::front() const // Get the value of the first node in the list
{
    if (!m_head) // Check if the list is empty
    {
        std::cout << "List is empty!!!\nCannot front()." << std::endl;
        exit(0); // Print an error message and exit the program if the list is emp
    }

    return m_head->m_val; // Return the value of the first node
}

//---------------------------__Forward_list__back__---------------------------------//
template <class T>
T my::Forward_list<T>::back() const // Get the value of the last node in the list
{
    if (!m_head) // Check if the list is empty
    {
        std::cout << "List is empty!!!\nCannot back()." << std::endl;
        exit(0); // Print an error message and exit the program if the list is empty
    }

    if (!m_head->m_next) // If there is only one node in the list, return its value
    {
        return m_head->m_val;
    }
    
    Node* current = m_head; // createing temprary node for traversing 

    while (current->m_next->m_next) // Traverse the list to find the last node
    {
        current = current->m_next;
    }

    return current->m_next->m_val; // Return the value of the last node
}

//---------------------------__Forward_list__empty__---------------------------------//
template <class T>
bool my::Forward_list<T>::empty() const // Check if the linked list is empty 
{
    return !(m_head); // Return true if m_head is nullptr, otherwise, return false
}

//---------------------------__Forward_list__size__---------------------------------//
template <class T>
size_t my::Forward_list<T>::size() const // Get the size of the linked list
{
    if (!m_head) // Check if the list is empty
    {
        return 0; // Return 0 if empty list is empty
    }

    size_t size = 1; // for holding list's size

    Node* tmp_ptr = m_head; // createing temprary node for traversing

    while (tmp_ptr->m_next) // Traverse the list
    {
        tmp_ptr = tmp_ptr->m_next;
        ++size; // count the number of nodes
    }

    return size;
}

//---------------------------__Forward_list__clear__---------------------------------//
template <class T>
void my::Forward_list<T>::clear() // for Clearing the linked list by deleting all nodes
{
    while (m_head) // Traverse the list
    {
        Node* temp = m_head;     // Save the current head in a temporary pointer
        m_head = m_head->m_next; // Move the head to the next node, effectively removing the curr
        delete temp;             // Delete the old head using the temporary pointer
    }
    m_head = nullptr;            // Set the head to nullptr after all nodes are deleted, indicating an empty list
}

//---------------------------__Forward_list__swap__---------------------------------//
template <class T>
void my::Forward_list<T>::swap(Forward_list& other) // Swap the contents of two lists
{
    std::swap(this->m_head, other.m_head); // swaping this and other list's heades
}

//---------------------------__Forward_list__assign__---------------------------------//
template <class T>
void my::Forward_list<T>::assign(int count, const T& value)// Assign a specific value to a specified number of nodes in the linked list
{
    if (count < 0) // Check if the count is valid (non-negative)
    {
        std::cout << "in assign(int count, const T& value)" << std::endl;
        std::cout << "count must be >= 0" << std::endl;
        exit(0); // Print an error message and exit the program ifcount is invalid
    }

    this->clear(); // Clear the existing content of the list

    for (int i = 0; i < count; ++i) // Add nodes to the list in count ammount
    {
        this->push_front(value); // Add nodes to the list with the specified value
    }
}

//-----------------------__Forward_list__assign(init_list)__----------------------------//
template <class T>
void my::Forward_list<T>::assign(const std::initializer_list<T>& init_list)
{
    this->clear();

    for (auto it = std::rbegin(init_list); it != std::rend(init_list); ++it)  // Iterate through the elements in the list in reverse order
    {
        this->push_front(*it); // Add each element to the front of the list using the push_front
    }
}

//---------------------------__Forward_list__print__---------------------------------//
template <class T>
void my::Forward_list<T>::print() // Print the values of nodes in the linked list
{
    Node* current = m_head; // createing temprary node for traversing

    while (current->m_next) // Iterate through the list and print the values of each node
    {
        std::cout << current->m_val << " "; // Print the current node's value
        current = current->m_next;          // Move to the next node
    }
    std::cout << current->m_val << " ";     // Print the value of the last node
    std::cout << std::endl;                 // Print a newline character
}

//---------------------------__Forward_list__reverse__---------------------------------//
template <class T>
void my::Forward_list<T>::reverse() // Reverse the linked list
{
    if (!m_head || !m_head->m_next) // Check if the list is empty or has only one node
    {
        return;
    }

    Node* prev = nullptr;   // Pointer to the previous node
    Node* current = m_head; // Pointer to the current node for traversing
    Node* next = nullptr;   // Pointer to the next node

    while (current) // Iterate through the list and reverse the direction of next pointers
    {
        next = current->m_next; // Save the next node (the rest of the original list)
        current->m_next = prev; // Reverse the direction of the next pointer to point to
        prev = current;         // Move to the next node in the original order
        current = next;         // Move to the next node in the original order
    }

    m_head = prev; // Set the head to the last node, which is now the first node after reversal
}

//-------------------------__Forward_list__reverse(recursive)__-----------------------------//
template <class T>
void my::Forward_list<T>::reverse_rec()
{
    if (!m_head || !m_head->m_next) // Check if the list is empty or has only one node
    {
        return;
    }

    reverse_rec(nullptr, m_head); // cal of recursive helper function
}

template <class T>
void my::Forward_list<T>::reverse_rec(Node* prev1, Node* current2)
{
    if (!current2) // When the end of the list is reached, set the head to the last node
    {
        m_head = prev1;
        return;
    }

    Node* next = current2->m_next; // Save the next node before modifying the next pointer
    current2->m_next = prev1;       // Reverse the direction of the next pointer

    reverse_rec(current, next); // Move to the next pair of nodes in the recursion
}

//-------------------------__Forward_list__insertionSort__-----------------------------//
template <class T>
void my::Forward_list<T>::insertionSort() // Sort the linked list using the Insertion Sort algorithm
{
    if (!m_head || !m_head->m_next) // Check if the list is empty or has only one node
    {
        return; 
    }

    Node* sorted = nullptr; // Pointer to the sorted part of the list
    Node* current = m_head; // Pointer to the current node

    while (current) // Traverse the list
    {
        Node* next = current->m_next; //pointer to Save the next node before modifying pointers

        if (!sorted || current->m_val < sorted->m_val) // If the sorted list is empty or the current node is smaller than the firs
        {
            current->m_next = sorted; // Insert the current node at the beginning of the sort
            sorted = current;         // Update the sorted pointer to the new head (current)
        }
        else
        {
            Node* temp = sorted; // Create a temporary pointer to traverse the sorted list

            while (temp->m_next && (current->m_val > temp->m_next->m_val))  // Traverse the sorted list to find the correct position for the current node
            {
                temp = temp->m_next;
            }

            current->m_next = temp->m_next; // Insert the current node into the sorted position
            temp->m_next = current;         // Update the next pointer of the preceding node to point to the current node
        }

        current = next; // Move to the next node in the original order
    }

    m_head = sorted; // Set the head to the sorted list
}

//-------------------------__Forward_list__find(gets and returns iterator)__-----------------------------//
template <class T>
typename my::Forward_list<T>::f_itr my::Forward_list<T>::find(const T& val)  // Find the first occurrence of a value in the linked list and return an iterator pointing on it
{

    for (auto itr = this->begin(); itr != this->end(); ++itr)// Iterate through the list using begin() and end() iterators
    {
        if (itr->m_val == val) // Check if the current node's value matches the target value
        {
            return itr; // Return an iterator pointing to the found node
        }
    }

    return nullptr; // Return nullptr if the value is not found in the list
}

//-------------------------__Forward_list__erase(gets iterator)__-----------------------------//
template <class T>
void my::Forward_list<T>::erase(f_itr pos) // Erase the node at the specified position in the linked list
{
    if (pos == begin()) // Check if the position is the beginning of the list
    {
        pop_front(); // cals function to remove first node
        return;
    }

    f_itr tmp_itr = begin(); // Create an iterator to traverse the list
    Node* prev = nullptr;    // Pointer to the previous node
    Node* curr = m_head;     // Pointer to the current node

    while (tmp_itr != pos) // Traverse the list to find the node at the specified position
    {
        prev = curr;
        curr = curr->m_next;
        ++tmp_itr;
    }

    Node* next = curr->m_next; // Save the next node
    delete curr;               // Delete the current node
    prev->m_next = next;       // Update the next pointer of the preceding node
}

#endif // SINGLE_LINKED_LIST_H
