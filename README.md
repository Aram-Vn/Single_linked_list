# My Forward List Library

---
## Table of Contents
- [Overview](#Overview)
- [Features (Public Member Functions)](#Features)
- [Usage](#Usage)
- [function usege examples](#function-usege-examples)
---

## Overview

`my::Forward_list` is a C++ template class that provides a basic implementation of a singly linked list. This linked list supports essential operations such as insertion, deletion, access to the front and back elements, checking for emptiness, obtaining the size, and more. It is designed to be a versatile and efficient container for various data types.

---

## Features

### Constructors and Destructors

- **Default Constructor**: Creates an empty forward list.
- **Destructor**: Releases resources and cleans up the forward list.
- **Copy Constructor**: Creates a new forward list as a copy of another list.
- **Move Constructor**: Efficiently transfers ownership of resources from another list.

### Element Access

- `front()`: Returns the value of the first element.
- `back()`: Returns the value of the last element.
- `print()`: Displays all elements in the forward list.

### Capacity

- `empty()`: Returns true if the forward list is empty; otherwise, returns false.
- `size()`: Returns the current size of the forward list.

### Modifiers

- `clear()`: Removes all elements from the forward list.
- `insert(int index, const T& value)`: Inserts an element at the specified index.
- `erase(int index)`: Erases the element at the specified index.
- `push_back(int data)`: Adds an element to the end of the list.
- `pop_back()`: Removes the last element from the list.
- `push_front(int data)`: Adds an element to the beginning of the list.
- `pop_front()`: Removes the first element from the list.
- `swap(Forward_list& other)`: Swaps the contents of two lists.
- `assign(int count, const T& value)`: Assigns a specified value to a specified number of elements.
- `assign(const std::initializer_list<T>& init_list)`: Assigns elements from an initializer list.

### Operations

- `reverse()`: Reverses the order of elements in the forward list.
- `insertionSort()`: sorted list by using insertion Sort algorithm

## Iterator

### `F_iterator` (Nested Forward Iterator)

- `F_iterator()`: Default constructor.
- `F_iterator(Node* ptr1)`: Parameterized constructor.
- `F_iterator& operator=(const F_iterator& other)`: Copy assignment operator.
- `T& operator*()`: Dereference operator to access the value of the node.
- `Node* operator->()`: Arrow operator to access the members of the node.
- `F_iterator& operator++()`: Prefix increment operator to move to the next node.
- `F_iterator operator++(int)`: Postfix increment operator.
- `bool operator==(const F_iterator& other)`: Equality operator.
- `bool operator!=(const F_iterator& other)`: Inequality operator.

### Iterator Methods

- `f_itr begin()`: Returns an iterator pointing to the first element.
- `f_itr end()`: Returns an iterator pointing to the end of the list (nullptr).

---

## Implementation Details

- The forward list dynamically allocates memory for its nodes and automatically deallocates when elements are removed.
- Memory allocation strategy involves allocating memory for each node individually.
- The `erase` method efficiently removes the element at the specified index. If the index is out of bounds, no action is taken.

---

## How to Use
Clone the repository:

with ssh`
   ```bash
   git clone git@github.com:Aram-Vn/Single_linked_list.git
   cd binary-search-tree
   ```
with HTTPS`       
   ```bash
   git clone https://github.com/Aram-Vn/Single_linked_list.git
   cd binary-search-tree
   ```
or with GitHub CLI
   ```bash
   git clone gh repo clone Aram-Vn/Single_linked_list
   cd binary-search-tree
   ```

After clonning you can add main.cpp in crs/ and use cmake to compile.

## Build instruction
1. Generate the cmake build files first by executing the following command at the root directory:
```
cmake ./ -B build/
```
You will see a `build` folder in the root directory which will contain cmake's generation files.

2. Compile and build the cmake project:
```
cmake --build build/
```

3. Run the executable:
```
build/BinarySearchTree
```

#### or you can just  use the `my::Forward_list` class, by copying `Forward_list.h` and `Forward_list_impl.hpp` files into your project directory. Include the "Forward_list.h" header file in your C++ project.

```cpp
#include "Forward_list.h"
```

## Compiling:

``bash
g++ -o <your_program_name> <your_project_file>
``

---

# function usege examples 
Once the forward list is integrated into your project, you can use the provided functions to work with the forward list.

- [Constructors and Destructors](#constructors-and-destructors-examples)
- [Operators](#Operators-examples)
- [Element Access](#Element-Access-examples)
- [Capacity](#Capacity-examples)
- [Modifiers](#Modifiers-examples)
- [Operations](#Operations-examples)

## Constructors and Destructors examples

### Default Constructor
```cpp
// Default Constructor
my::Forward_list<int> intList;
```

### Copy Constructor
```cpp
// Copy Constructor
my::Forward_list<int> originalList;
originalList.push_back(1);
originalList.push_back(2);
// originalList 1 , 2

my::Forward_list<int> copiedList(originalList);

// originalList 1 , 2
// copiedList 1, 2
```

### Move Constructor
```cpp
// Move Constructor
my::Forward_list<int> sourceList;
sourceList.push_back(1);
sourceList.push_back(2);

my::Forward_list<int> destinationList(std::move(sourceList));

// sourceList empty( nullptr );
// destinationList 1 , 2;
```

### Initializer List Constructor
```cpp
// Initializer List Constructor
my::Forward_list<int> initializedList = {1, 2, 3, 4, 5};

// initializedList 1, 2, 3, 4, 5
```

### Destructor
```cpp
// Destructor
// Automatically called when the list goes out of scope
```

## Operators examples 

### Copy Assignment Operator
```cpp
// Copy Assignment Operator
my::Forward_list<int> originalList;
originalList.push_back(1);
originalList.push_back(2);
// sourceList 1, 2

my::Forward_list<int> assignedList;
assignedList = originalList;
// sourceList 1, 2
// destinationList 1, 2
```

### Move Assignment Operator
```cpp
// Move Assignment Operator
my::Forward_list<int> sourceList;
sourceList.push_back(1);
sourceList.push_back(2);
// sourceList 1, 2

my::Forward_list<int> destinationList;
destinationList = std::move(sourceList);
// sourceList empty( nullptr )
// destinationList 1, 2
```
---

## Element Access examples 

### Front
```cpp
// Front
my::Forward_list<int> intList = {1, 2, 3};
int frontElement = intList.front(); // frontElement will be 1
```

### Back
```cpp
// Back
my::Forward_list<int> intList = {1, 2, 3};
int backElement = intList.back(); // backElement will be 3
```

### Print
```cpp
// Print
my::Forward_list<int> intList = {1, 2, 3};
intList.print(); // Output: 1 2 3
```
---

## Capacity examples

### Empty
```cpp
// Empty
my::Forward_list<int> emptyList;
bool isEmpty = emptyList.empty(); // isEmpty will be true
```

### Size
```cpp
// Size
my::Forward_list<int> intList = {1, 2, 3};
size_t listSize = intList.size(); // listSize will be 3
```
---

## Modifiers examples

### Clear
```cpp
// Clear
my::Forward_list<int> intList = {1, 2, 3};
intList.clear(); // intList is now an empty list
```

### Insert

```cpp
// Insert
my::Forward_list<int> intList = {1, 2, 3};
intList.insert(1, 10); // Insert 10 at index 1, resulting in: 1 10 2 3
```
<div align="center">
  <img src="https://github.com/Aram-Vn/Queue/assets/118690340/24b17332-cf6e-4836-88a2-553013e7896a" alt="Insert">
</div>

### Erase
```cpp
// Erase
my::Forward_list<int> intList = {1, 2, 3};
intList.erase(1); // Erase element at index 1, resulting in: 1 3
```

### Push Back
```cpp
// Push Back
my::Forward_list<int> intList = {1, 2, 3};
intList.push_back(4); // Add 4 to the end, resulting in: 1 2 3 4
```
<div align="center">
  <img src="https://github.com/Aram-Vn/Single_linked_list/assets/118690340/85eacb17-dcf2-4e4a-8db6-234e0fdb647f" alt="Push_Front">
</div>


### Pop Back
```cpp
// Pop Back
my::Forward_list<int> intList = {1, 2, 3};
intList.pop_back(); // Remove the last element, resulting in: 1 2
```

### Push Front
```cpp
// Push Front
my::Forward_list<int> intList = {1, 2, 3};
intList.push_front(0); // Add 0 to the beginning, resulting in: 0 1 2 3
```
<div align="center">
  <img src="https://github.com/Aram-Vn/Single_linked_list/assets/118690340/ceeb7e1c-035a-4011-bbc7-266e5b205512" alt="Push_Front">
</div>

### Pop Front
```cpp
// Pop Front
my::Forward_list<int> intList = {1, 2, 3};
intList.pop_front(); // Remove the first element, resulting in: 2 3
```

### Swap
```cpp
// Swap
my::Forward_list<int> list1 = {1, 2, 3};
my::Forward_list<int> list2 = {4, 5, 6};

list1.swap(list2); // list1 becomes {4, 5, 6}, list2 becomes {1, 2, 3}
```

### Assign (Count)
```cpp
// Assign (Count)
my::Forward_list<int> intList = {1, 2, 3};
intList.assign(4, 0); // Assign 0 to 4 elements, resulting in: 0 0 0 0
```

### Assign (Initializer List)
```cpp
// Assign (Initializer List)
my::Forward_list<int> intList = {1, 2, 3};
intList.assign({4, 5, 6}); // Assign elements from initializer list, resulting in: 4 5 6
```
---

## Operations examples

### Insertion Sort

```cpp
//insertionSort
my::Forward_list<int> my_list = {8, 7, 6, 4, 9, 2, 7, 15, 1, 0};
my_list.insertionSort() // sorted list, resulting : 0, 1, 2, 4, 6, 7, 7, 8, 9, 15  
```

### Reverse
```cpp
// Reverse
my::Forward_list<int> intList = {1, 2, 3};
intList.reverse(); // Reverses the list, resulting in: 3 2 1
```
<div align="center">
  <img src="https://github.com/Aram-Vn/Single_linked_list/assets/118690340/6025ff5c-e95d-4d79-91f2-a3b8003f505d" alt="Reverse_Animated_GIF" width="310">
</div>




