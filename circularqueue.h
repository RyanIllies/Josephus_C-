// Author: Ryan Illies
// Class: CSIS 352
// Assignment: 7
// EXE: prog7



template <class T>
class CircularQueue {
	public:
		// you write lots of stuff here
		// you may write more, but at a minimum,
		// you need to flesh out the following:
		CircularQueue() {}; //const
		~CircularQueue(); //deconst
		CircularQueue(CircularQueue<T> & circ); //copier
		CircularQueue<T> & operator=(CircularQueue<T> & circ); //operator- look to the site with code 
		void next(); //function to move forward one if the person is alive (for execute)
		void prev(); //same but reverse as stated above(gets last)
		T& curr(); //gets current I think 
		bool is_empty();//checks to see if the circque is empty or not BOOLEAN
		// the following two are similar,
		// in that they both create a new node
		void add_before(T&); // puts it before the current
		void add_after(T&); // puts it after the current
		
	private:
		// you also write lots of stuff here
		// you must keep the following,
		// and use it for your implementation
	struct node;
	struct node {
		node * next;
		node * prev;
		T item;
	};
	struct node * current;
		/* a few notes:
			if (current) {
				assert(current->next->prev == current);
				assert(current->prev->next == current);
			} else {
				assert(is_empty());
			};
		*/
	struct node * front;
	struct node * back;
};


template <class T>
bool CircularQueue<T>::is_empty(){//func
   	if(current == NULL){//f1
		return true;
	}//f1
	else{return false;}
}//func


template <class T>
void CircularQueue<T>::next(){//func
   	current = current->next;
}//func


template <class T>
void CircularQueue<T>::prev(){//func
   	current = current->prev;
}//func


template <class T>
void CircularQueue<T>::add_after(T& name){//func
struct node* tmp = new node;
tmp->item = name;
	if(is_empty()){//f1
	tmp->next = tmp;
	tmp->prev = tmp;
	current = tmp;
	front = current;
	back = current;	
	}//f1
	else{//e1
		tmp->prev = current;
		tmp->next = current->next;
		current->next->prev = tmp;
		current->next = tmp;
		//current next stays same 
		if(current->next == front){//f2
			tmp->next = front;
			front->prev = tmp;
			back = tmp;
		}//f2
	}//e1
}//func


template <class T>
void CircularQueue<T>::add_before(T& name){//func
struct node* tmp = new node;
tmp->item = name;
   	if(is_empty()){//f1
		tmp->next = tmp;
		tmp->prev = tmp;
		current = tmp;
		front = current;
		back = current;	
	}//f1
	else{//e1
		tmp->next = current;
		tmp->prev = current->prev;
		current->prev->next = tmp;
		current->prev = tmp;
		//current next stays same 
		if(current->prev == back){//f2
			tmp->prev = back;
			back->next = tmp;
			front = tmp;
		}//f2
	}//e1
}//func




template <class T>
CircularQueue<T>::~CircularQueue()
{//func
	struct node* tmp = new node;
	tmp = current;
	while(current != NULL){//w1
		delete tmp;
		current = current->next;
		tmp = current;
}//w1	

}//end


template <class T>
CircularQueue<T>& CircularQueue<T>::operator = (CircularQueue<T>& circ)
{	
	if(circ.current != NULL){//f1
		current = front;
		while(current!=back){//w1
			circ.current = circ.next();
			current = circ.current;
			current = next();
		}//w1
	}//f1
	else{//e1
		front = NULL;
		back = NULL;
	}//e1
	circ.~CircularQueue();
	return (*this);
}//end


template <class T>
CircularQueue<T>::CircularQueue(CircularQueue<T> & circ)
{
	*this = circ;		
}//end


template <class T>
T& CircularQueue<T>::curr()
{
	return current->item;

}














