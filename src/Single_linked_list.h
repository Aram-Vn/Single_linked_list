#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <iterator>
namespace my {
    template <class T>
    class Forward_list
    {
    private:
        struct Node
        {
        public:
            Node(T val, Node* node_ptr); // Node parameterized constructor
            ~Node() = default;

        public:
            T m_val;
            Node* m_next = nullptr;
        };

    public:
        class F_iterator
        {
        public:
            F_iterator();
            F_iterator(Node* ptr1);
            F_iterator& operator=(const F_iterator& other);
            Node& operator*();
            Node* operator->();
            F_iterator& operator++();
            F_iterator operator++(int);
            bool operator==(const F_iterator& other);
            bool operator!=(const F_iterator& other);

        private:
            Node* ptr;
        };

    public:
        using f_itr = F_iterator;
        f_itr begin();
        f_itr end();

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
        T front() const; // Retrieve the value of the first element
        T back() const;  // Retrieve the value of the last element
        void print();    // Print the elements of the list

        // Capacity
        bool empty() const;  // Check if the list is empty, if empty returnde true, else false
        size_t size() const; // Get the number of elements in the list

        // Modifiers
        void clear();                           // Remove all elements from the list, m_head = nullptr;
        void insert(int index, const T& value); // Insert an element ( value ) at the specified index
        void erase(int index);                  //  Erase the element at the specified index (if index >= 0 && < size())
        void push_back(int data);               // Add an element to the end of the list
        void pop_back();                        // Remove the last element from the list
        void push_front(int data);              // Add an element to the beginning of the list
        void pop_front();                       // Remove the first element from the list
        void swap(Forward_list& other);         // Swap the contents of two lists
        void assign(int count, const T& value); // removes all prevues value, Assign a specified value to a specified
                                                // number of elements,
        void assign(const std::initializer_list<T>& init_list); //  removes all prevues value, Assign elements from an
                                                                //  initializer list

        // Operations
        void reverse();       // Reverse the order of elements in the list
        void insertionSort(); // surtes list by using insertion Sort algorithm
                              /* Forward_list<T>& merge(Forward_list<T>& other); */

    private:
        Node* m_head;
    };

#include "Single_linked_list_impl.hpp"
} // namespace my

#endif // SINGLE_LINKED_LIST_H
