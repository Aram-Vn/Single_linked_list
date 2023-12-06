#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

namespace my {
	template <class T>
	class Forward_list
	{
	public:
		//destructor
		~Forward_list(); //

		//Constructor
		Forward_list(); //
		Forward_list(const Forward_list& other); //
		Forward_list(Forward_list&& other) noexcept; //	
		Forward_list(std::initializer_list<T> init_list); //
	
		//Opreators
		Forward_list& operator=(const Forward_list& other); //
		Forward_list& operator=(Forward_list&& other) noexcept; //	

	public:
		//Element access
		T front() const; //
		T back() const; // 
	
		//Capacity
		bool empty() const; //
		size_t size() const; //

		//Modifiers
		void clear(); //
		void insert(int index, const T& value); //
		void erase(int index); 
		void push_back(int data); //
		void pop_back(); //
		void push_front(int data); //
		void pop_front(); //
		void swap(Forward_list& other); //
		void assign(int count, const T& value);
		void assign(const std::initializer_list<T>& init_list);

		//Operations
		void print(); //
		void reverse(); // 

	private:
		struct Node
		{
		public:
			Node(T val, Node* node_ptr); //
			~Node() = default; //			

		public:
			T m_val;
			Node* m_next = nullptr;		
		};
		Node* m_head;

	};

	#include "Single_linked_list_impl.hpp"
}

		
#endif //SINGLE_LINKED_LIST_H
