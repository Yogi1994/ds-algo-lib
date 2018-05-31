#include<iostream>

using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

class MinHeap {
	int *hp;
	int size;
	int current_length;
	public:
		MinHeap(int size);

		void insert(int key);
		void popMin();
		void heapify(int pos);
		void print();
		int getMin() { return hp[0]; }
		~MinHeap();

};
MinHeap::MinHeap(int size){
	this->hp = new int[size];
	this->size = size;
	current_length = 0;
}
MinHeap::~MinHeap(){
	delete this->hp;
}
void MinHeap::insert(int key){
	if(current_length < size){
		this->hp[current_length++] = key;
		int pos = current_length-1;
		int parent = (pos-1)/2;
		while(pos != 0 && this->hp[pos] < this->hp[parent]){
			swap(&hp[pos], &hp[parent]);
			pos = parent;
			parent = (parent-1)/2;
			// print();
		}
		 print();
	} else {
		cout<<"overflow"<<endl;
	}
	
}
void MinHeap::popMin(){
	if(current_length == 0){
		return;
	}
	if(current_length == 1){
		current_length--;
		return;
	}
	current_length--;
	hp[0] = hp[current_length];
	heapify(0);

}
void MinHeap::heapify(int pos){
	
	int left = pos*2 +1;
	int right = pos*2 +2;
	int smallest = pos;
	if(left < current_length && this->hp[pos] > hp[left])
		smallest = left;
	if(right < current_length && this->hp[pos] > hp[right])
		smallest = right;
	if(pos != smallest) {
		swap(&hp[pos], &hp[smallest]);
		heapify(smallest);
	}
}
void MinHeap::print() {
	for(int i = 0; i < current_length; i++) {
		cout<<hp[i]<<",";
	}
	cout<<endl;
}

int main() {

	MinHeap minHeap(5);
	minHeap.insert(3);
	minHeap.insert(5);
	minHeap.insert(6);
	minHeap.insert(2);
	minHeap.insert(1);
	minHeap.print();
	cout<<minHeap.getMin()<<endl;
	minHeap.popMin();
	minHeap.print();

	return 0;
}