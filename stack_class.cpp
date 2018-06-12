#include<iostream>

class Stack
{
	public:
		Stack (const int size = 100);
		~Stack();
		void push(int number);
		int pop();
		void print();
	private:
		int* _stack;
		int _top;
		int _size;
};

int main () {
	Stack* s = new Stack;
	s->push(1);
	s->push(2);
	s->push(3);
	s->push(4);
	s->push(5);
	s->push(6);
	s->push(7);
	s->pop();
	s->print();
}

Stack::Stack(const int size) {
	this->_size = size;
	if (this->_size < 1) {
		std::cout<<"kokos"<<std::endl;
		return;
	}
	this->_stack = new int[this->_size];
	this->_top = -1;
}

void Stack::push (int number) {
	if (this->_top == this->_size - 1) {
		int* new_stack = new int[this->_size * 2];
		for (int i = 0; i < this->_size; ++i) {
			new_stack[i] = this->_stack[i];
		}
	delete [] this->_stack;
	this->_size = this->_size * 2;
	this->_stack = new_stack;
	}
	++this->_top;
	this->_stack[this->_top] = number;
		
}

int Stack::pop() {
	if (this->_top == -1) {
		std::cout<<"Stack is empty"<<std::endl;
		return -1;
	}	
	--this->_top;
	return this->_stack[this->_top];
}

void Stack::print() {
	for(int i = 0; i < this->_top + 1; i++) {
		std::cout<<this->_stack[i]<<std::endl;
	}
}

Stack::~Stack () {
	delete [] this->_stack;
}
