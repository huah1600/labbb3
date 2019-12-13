#ifndef PRIO_QUE_H_
#define pPRIO_QUE_H_

#include <iostream>

#include <vector>

#include <algorithm> 

#include <functional>

template<class T,class lesse>
class p_queue { 
public:
	p_queue();

	T pop();
	void push(T e);
	int size();
	bool empty();
	void print();
	

private:

	std::vector<T> queue;



	
	


};
template<class T, class lesse>
inline p_queue<T, lesse>::p_queue()
{
	
}



template<class T, class lesse>
inline T p_queue<T, lesse>::pop()
{
	T value = queue.front();

	queue.erase(queue.begin());

	return value;
}

template<class T, class lesse>
inline void p_queue<T, lesse>::push(T e)
{
	
	//auto pos = find(queue.begin(), queue.end(), e);

   //queue.insert(pos,e);


	
	lesse comp; //
	 // Use the find_if function and a lambda expression to find the
	// first even number in the list.
	//Comp , vi går igenom listan tills value är mindre än e då tar vi den postitionen och interstar int .
	auto pos = std::find_if(queue.begin(), queue.end(), [&]( T value) {return comp(e, value); });

	queue.insert(pos, e);


		//queue.push_back(e);
	//std::sort(queue.begin(), queue.end() );
}

template<class T, class lesse>
inline int p_queue<T, lesse>::size()
{
	return queue.size();
}

template<class T, class lesse>
inline bool p_queue<T, lesse>::empty()
{ 
	return queue.size()==0;
}
template<class T, class lesse>
inline void p_queue<T, lesse>::print()
{
	for (int i= queue.size()-1; i>=0;  i--) {
		std::cout << queue[i] << std::endl;
	;
	}
	
}
#endif