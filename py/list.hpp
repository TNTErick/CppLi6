/*
 * Implements double linked list like the one used in python.
 */

#ifndef __PY_LIST_
#define __PY_LIST_

namespace py
{
	class object {};

	template<typename T>
	struct __py_list_node: T
	{
	public:
		__py_list_node(__py_list_node* previous, ...)
		{
			//TODO: learn ellipsis in C++11
		}
		__py_list_node* previous = nullptr;
		__py_list_node* next = nullptr;
	};

	template<typename T>
	__py_list_node* __py_make_list_node(T vlaue)
	{
		auto tmp = new __py_list_node<T>(value);
	}
}

#endif//__PY_LIST_
