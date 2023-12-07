# My Forward List Library

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

## Constructors and Destructors

### Default Constructor
```cpp
// Default Constructor
my::Forward_list<int> intList;
```
---

### Copy Constructor
```cpp
// Copy Constructor
my::Forward_list<int> originalList;
originalList.push_back(1);
originalList.push_back(2);

my::Forward_list<int> copiedList(originalList);
```
---

### Move Constructor
```cpp
// Move Constructor
my::Forward_list<int> sourceList;
sourceList.push_back(1);
sourceList.push_back(2);

my::Forward_list<int> destinationList(std::move(sourceList));
```
---

### Initializer List Constructor
```cpp
// Initializer List Constructor
my::Forward_list<int> initializedList = {1, 2, 3, 4, 5};
```
---

### Destructor
```cpp
// Destructor
// Automatically called when the list goes out of scope
```
---

## Operators

### Copy Assignment Operator
```cpp
// Copy Assignment Operator
my::Forward_list<int> originalList;
originalList.push_back(1);
originalList.push_back(2);

my::Forward_list<int> assignedList;
assignedList = originalList;
```
---

## Move Assignment Operator
```cpp
// Move Assignment Operator
my::Forward_list<int> sourceList;
sourceList.push_back(1);
sourceList.push_back(2);

my::Forward_list<int> destinationList;
destinationList = std::move(sourceList);
```
---

# Element Access

## Front
```cpp
// Front
my::Forward_list<int> intList = {1, 2, 3};
int frontElement = intList.front(); // frontElement will be 1
```
---

## Back
```cpp
// Back
my::Forward_list<int> intList = {1, 2, 3};
int backElement = intList.back(); // backElement will be 3
```
---

## Print
```cpp
// Print
my::Forward_list<int> intList = {1, 2, 3};
intList.print(); // Output: 1 2 3
```
---

# Capacity

## Empty
```cpp
// Empty
my::Forward_list<int> emptyList;
bool isEmpty = emptyList.empty(); // isEmpty will be true
```

