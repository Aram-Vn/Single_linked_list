#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

namespace my {
	template <class T>
	class Forward_list
	{
	public:
		~Forward_list();
		Forward_list() = default;

	public:
		void push_front(int data);
		void push_back(int data);
		void pop_front();
		void pop_back();

		T front() const;
		T back() const;
		bool empty() const;
		size_t size() const;
		
		void clear();
		void swap();

	private:
		struct Node
		{
		public:
			Node(T val, Node* node_ptr);
			~Node();			

		public:
			T m_val;
			Node* m_next = nullptr;		
		};
		Node* m_head;

	};

	#include "Single_linked_list_impl.hpp"
}

		
#endif //SINGLE_LINKED_LIST_H
