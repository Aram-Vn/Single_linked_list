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

---

## Implementation Details

- The forward list dynamically allocates memory for its nodes and automatically deallocates when elements are removed.
- Memory allocation strategy involves allocating memory for each node individually.
- The `erase` method efficiently removes the element at the specified index. If the index is out of bounds, no action is taken.

---

## Usage

To use the `my::Forward_list` class, copy both `Forward_list.h` and `Forward_list_impl.hpp` files into your project directory. Include the "Forward_list.h" header file in your C++ project.

```cpp
#include "Forward_list.h"
```

## Compiling:

``bash
g++ -o <your_program_name> main.cpp
``

---

# function usege examples 
Once the forward list is integrated into your project, you can use the provided functions to work with the forward list.

- [Constructors and Destructors](#Constructors-and-examples)
- [Operators](#Operators-examples)
- [Element Access](#Element-Access-examples)
- [Capacity](#Capacity-examples)
- [Modifiers](#Modifiers_examples)

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

## Move Assignment Operator
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

# Element Access examples 

## Front
```cpp
// Front
my::Forward_list<int> intList = {1, 2, 3};
int frontElement = intList.front(); // frontElement will be 1
```

## Back
```cpp
// Back
my::Forward_list<int> intList = {1, 2, 3};
int backElement = intList.back(); // backElement will be 3
```

## Print
```cpp
// Print
my::Forward_list<int> intList = {1, 2, 3};
intList.print(); // Output: 1 2 3
```
---

# Capacity examples

## Empty
```cpp
// Empty
my::Forward_list<int> emptyList;
bool isEmpty = emptyList.empty(); // isEmpty will be true
```

## Size
```cpp
// Size
my::Forward_list<int> intList = {1, 2, 3};
size_t listSize = intList.size(); // listSize will be 3
```
---

# Modifiers examples

## Clear
```cpp
// Clear
my::Forward_list<int> intList = {1, 2, 3};
intList.clear(); // intList is now an empty list
```

## Insert
```cpp
// Insert
my::Forward_list<int> intList = {1, 2, 3};
intList.insert(1, 10); // Insert 10 at index 1, resulting in: 1 10 2 3
```

## Erase
```cpp
// Erase
my::Forward_list<int> intList = {1, 2, 3};
intList.erase(1); // Erase element at index 1, resulting in: 1 3
```

## Push Back
```cpp
// Push Back
my::Forward_list<int> intList = {1, 2, 3};
intList.push_back(4); // Add 4 to the end, resulting in: 1 2 3 4
```

## Pop Back
```cpp
// Pop Back
my::Forward_list<int> intList = {1, 2, 3};
intList.pop_back(); // Remove the last element, resulting in: 1 2
```

## Push Front
```cpp
// Push Front
my::Forward_list<int> intList = {1, 2, 3};
intList.push_front(0); // Add 0 to the beginning, resulting in: 0 1 2 3
```

## Pop Front
```cpp
// Pop Front
my::Forward_list<int> intList = {1, 2, 3};
intList.pop_front(); // Remove the first element, resulting in: 2 3
```

## Swap
```cpp
// Swap
my::Forward_list<int> list1 = {1, 2, 3};
my::Forward_list<int> list2 = {4, 5, 6};

list1.swap(list2); // list1 becomes {4, 5, 6}, list2 becomes {1, 2, 3}
```

## Assign (Count)
```cpp
// Assign (Count)
my::Forward_list<int> intList = {1, 2, 3};
intList.assign(4, 0); // Assign 0 to 4 elements, resulting in: 0 0 0 0
```

## Assign (Initializer List)
```cpp
// Assign (Initializer List)
my::Forward_list<int> intList = {1, 2, 3};
intList.assign({4, 5, 6}); // Assign elements from initializer list, resulting in: 4 5 6
```
---

# Operations

## Reverse
```cpp
// Reverse
my::Forward_list<int> intList = {1, 2, 3};
intList.reverse(); // Reverses the list, resulting in: 3 2 1
```
