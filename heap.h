#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
//---
using namespace std;

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
	// void trickleup(int index_of_the_node_to_be_moved);
	// void trickledown(int index_of_the_node_to_be_moved);
	int m; // n-ary tree, m = n
  PComparator c; // the comparator we use
  std::vector<T> myheap;
};
// helper function implementations--------------------------------------------------------------------------------------------
// template <typename T, typename PComparator>
// void Heap<T,PComparator>::trickleup(int index_of_the_node_to_be_moved)
// {
// 	if(index_of_the_node_to_be_moved != 0) {
// 		// identify the parent node index
// 		int parent = (index_of_the_node_to_be_moved - 1) / m;// index of the parent node
// 		// for a m-ary tree, index of the first child of a parent node = m*parent_node_index + 1
// 		// using this formula, we can use a for loop to deduce the index of the parent node
// 		// for(int i=0; i<=m-1; i++) {
// 		// 	if(index_of_the_node_to_be_moved % m == i) {
// 		// 		if(i == 0) {
// 		// 			parent = (index_of_the_node_to_be_moved - m) / m;
// 		// 			break;
// 		// 		}
// 		// 		else {
// 		// 			parent = (index_of_the_node_to_be_moved - i) / m;
// 		// 		  break;
// 		// 		}
// 		// 	}
// 		// }
// 		// if child is better than parent then swap, otherwise just return
// 		// note: c(myheap[child], myheap[parent]) = true if child is less than parent for a less than comparator
// 		if(c(myheap[index_of_the_node_to_be_moved], myheap[parent])) {
// 			// T temp = myheap[index_of_the_node_to_be_moved];
// 			// myheap[index_of_the_node_to_be_moved] = myheap[parent];
// 			// myheap[parent] = temp;
// 			std::swap(myheap[index_of_the_node_to_be_moved], myheap[parent]);
// 			trickleup(parent);
// 		}
// 		else {
// 			return;
// 		}
// 	}
// 	else {
// 		// if index_of_the_node_to_be_moved has no parent node then we don't need to trickle up
// 		return;
// 	}
// }
	
// template <typename T, typename PComparator>
// void Heap<T,PComparator>::trickledown(int index_of_the_node_to_be_moved)
// {
// 	if(index_of_the_node_to_be_moved*m + 1 < myheap.size()) {
// 		// identify the best child node
// 		T best = myheap[index_of_the_node_to_be_moved];
// 		int best_child; // index of the best child
// 		for(int i=index_of_the_node_to_be_moved*m + 1; i<=index_of_the_node_to_be_moved*m + m; i++) {
// 			if(i < myheap.size()) {
// 				if(c(myheap[i], best)) {
// 					best = myheap[i];
// 					best_child = i;
// 				}
// 			}
// 			// else {break;} // if this child node index is already out of bounds we just break
// 		}
// 		// if the best child is better than the parent then swap, otherwise just return
// 		if(c(best, myheap[index_of_the_node_to_be_moved])/*best != myheap[index_of_the_node_to_be_moved]*/) {
// 			//T temp = myheap[index_of_the_node_to_be_moved];
// 			//myheap[index_of_the_node_to_be_moved] = myheap[best_child];
// 			//myheap[best_child] = temp;
// 			std::swap(myheap[index_of_the_node_to_be_moved], myheap[best_child]);
// 			trickledown(best_child);
// 		}
// 		else {
// 			return;
// 		}
// 	}
// 	else {
// 		// if index_of_the_node_to_be_moved has no child node then we don't need to trickle down
// 		return;
// 	}
// }
// Add implementation of member functions here-------------------------------------------------------------------------------
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
{
	m=m;
	c=c;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  myheap.push_back(item);
  // trickle up
	// trickleup((int)size() - 1);
	// ------------------------------
	// TA's codes
	/*
	int child = size() - 1;
	int parent = (child - 1) / m;

	while(parent >= 0 && c(myheap[child], myheap[parent])) {
		int parent = (child - 1) / m;
		if(c(myheap[child], myheap[parent])) {
			std::swap(myheap[child], myheap[parent]);
			child = parent;
			parent = (child-1)/m
		}
		else {
			break; 
		}
	} 
	*/
	int child = size() - 1;
	int parent = (child - 1) / m; 
	while(parent >= 0 && c(myheap[child], myheap[parent])) {
		std::swap(myheap[child], myheap[parent]); 
		child = parent; 
		parent = (child - 1) / m;
	}
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return size() == 0;
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return myheap.size();
}
//---------------------------------------------------------------------------------------------------------
// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::out_of_range("Empty heap! No top element to be returned!");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
	return myheap[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::out_of_range("Empty heap! Cannot pop any element!");
  }
	myheap[0] = myheap[size() - 1];
	myheap.pop_back();
	// trickledown(0);
	int parent = 0;
	while(parent*m + 1 < size()) {
		T best = myheap[parent];
		int best_child;
		for(int i=parent*m+1; i<=parent*m+m; i++) {
			if(i < size()) {
				if(c(myheap[i], best)) {
					best = myheap[i];
					best_child = i;
				}
			}
			else {break;}
		}
		if(c(best, myheap[parent])) {
			std::swap(myheap[best_child], myheap[parent]);
			parent = best_child;
		}
		else {
			break;
		}
	}
}



#endif
