#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <iostream>
#include <optional>

namespace my {
    template <class T>
    class Forward_list
    {
    private:
        struct Node // Node structure to represent nodes in the linked lis, which holdes value and pointer to next node
        {
        public:
            Node(T val, Node* node_ptr); // Node parameterized constructor
            ~Node() = default;

        public:
            T m_val;                // Value of the node
            Node* m_next = nullptr; // Pointer to the next node in the list
        };

    public:
        class F_iterator // nested forward iterator for the linked list
        {
        public:
            ~F_iterator() = default;
            F_iterator();                                   // Default constructor
            F_iterator(Node* ptr1);                         // F_iterator parameterized constructor
            F_iterator& operator=(const F_iterator& other); // copy assignment operator
            T& operator*();                                 // Dereference operator to access the value of the node
            Node* operator->();                             // Arrow operator to access the members of the node
            F_iterator& operator++();                       // Prefix increment operator to move to the next node
            F_iterator operator++(int);                     // Postfix increment operator
            bool operator==(const F_iterator& other);       // Equality operator
            bool operator!=(const F_iterator& other);       // Inequality operator

        private:
            Node* ptr; // Pointer to the current node
        };

    public:
        using f_itr = F_iterator; // Type alias for the F_iterator
        f_itr begin();            // Returns an iterator pointing to the first element
        f_itr end();              // return nullptr

    public:
        // destructor
        ~Forward_list(); // Destructor to deallocate memory used by the linked list nodes

        // Constructor
        Forward_list(); //  Default constructor to create an empty linked list, m_head = nullprt
        Forward_list(const Forward_list& other);     // Copy constructor to create a new list as a copy of another list
        Forward_list(Forward_list&& other) noexcept; //	Move constructor to efficiently transfer ownership of resources
        Forward_list(std::initializer_list<T> init_list); // Constructor to initialize the list with elements from an
                                                          // initializer list

        // Opreators
        Forward_list& operator=(const Forward_list& other);     // Copy assignment operator to assign the contents of
                                                                // another list
        Forward_list& operator=(Forward_list&& other) noexcept; // Move assignment operator to efficiently transfer
                                                                // ownership of resources

    public:
        // Element access
        T front() const;          // Retrieve the value of the first element
        T back() const;           // Retrieve the value of the last element
        void print();             // Print the elements of the list
        f_itr find(const T& val); // find and return the val if it exists

        // Capacity
        bool empty() const;  // Check if the list is empty, if empty returnde true, else false
        size_t size() const; // Get the number of elements in the list

        // Modifiers
        void clear();                           // Remove all elements from the list, m_head = nullptr;
        void insert(int index, const T& value); // Insert an element ( value ) at the specified index
        void erase(int index);                  //  Erase the element at the specified index (if index >= 0 && < size())
        void erase(f_itr pos);                  //  Erase the element at the specified index (if index >= 0 && < size())
        void push_back(T data);                 // Add an element to the end of the list
        void pop_back();                        // Remove the last element from the list
        void push_front(T data);                // Add an element to the beginning of the list
        void pop_front();                       // Remove the first element from the list
        void swap(Forward_list& other);         // Swap the contents of two lists
        void assign(int count, const T& value); // removes all prevues value, Assign a specified value to a specified
                                                // number of elements,
        void assign(const std::initializer_list<T>& init_list); //  removes all prevues value, Assign elements from an
                                                                //  initializer list

        // Operations
        void reverse();       // Reverse the order of elements in the list
        void insertionSort(); // surtes list by using insertion Sort algorithm
        void reverse_rec();   // recursively Reverse the order of elements in the list
    
    private:
        void reverse_rec(Node* prev, Node* current); // reverse_rec helper

    private:
        Node* m_head;
    };

#include "Single_linked_list_impl.hpp"
} // namespace my

#endif // SINGLE_LINKED_LIST_H
