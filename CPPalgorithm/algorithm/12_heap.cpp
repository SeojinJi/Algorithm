#include <iostream>
#include <limits>

using namespace std;

void swap(int *x, int *y);

class MaxHeap{
    int *heap_arr; // pointer to array of element in heap
    int capacity; // maximum possible size of heap
    int heap_size; // current number of elements in heap

   public:
    MaxHeap(int cap); // constructor
    void insertKey(int k); // inserts a new key 'k'
    int parent(int i){return (i-1)/2;} // get index of parent node at index i
    int left(int i){return 2*i + 1;} // get index of left child of node at index i
    int right(int i){return 2*i + 2;} // get index of right child of node at index i
    void MaxHeapify(int i);
    void BuildMaxHeap();
    void HeapSort();
    void increaseKey(int i, int new_val);
    int getMax(){return heap_arr[0];};
     
    int extractMax();
};

MaxHeap::MaxHeap(int cap){
    capacity = cap;
    heap_size = 0;
    heap_arr = new int[cap];
}

void MaxHeap::MaxHeapify(int i){
    int l = left(i);
    int r = right(i);
    int largest = i;
    if(l <= heap_size && heap_arr[l] > heap_arr[largest]){
        largest = l;
    }
    if(r <= heap_size && heap_arr[r] > heap_arr[largest]){
        largest = r;
    }
    if(largest != i){
        swap(&heap_arr[i], &heap_arr[largest]);
        MaxHeapify(largest); // recursive
    }
}

void MaxHeap::BuildMaxHeap(){
    for(int i = heap_size / 2 ; i > 0; --i){ // repeat max_heapify without leaf node
        MaxHeapify(i);
    }
}

void MaxHeap::HeapSort(){
    BuildMaxHeap();
    int n = heap_size;
    for(int i = n; i > 0; --i){
        cout << heap_arr[0] << endl; 
        if(i == 1 || i == 0){
            break;
        }
        swap(&heap_arr[i], &heap_arr[0]); // exchange heap_arr[0] with heap_arr[i]
        heap_size--;
        MaxHeapify(0);
    }
}

void MaxHeap::insertKey(int k){
    if(heap_size == capacity){
        cout << "heap overflow" << endl;
        return;
    }
    heap_size++;
    int i = heap_size - 1;
    heap_arr[i] = k;

    while(i != 0 && heap_arr[parent(i)] < heap_arr[i]){ // same method with increaseKey()
        swap(&heap_arr[i], &heap_arr[parent(i)]);
        i = parent(i);
    }
}

void MaxHeap::increaseKey(int i, int new_val){
    if(new_val < heap_arr[i]){
        cout << "new key is smaller than current key" << endl;
    }
    heap_arr[i] = new_val;
    while(i > 0 && heap_arr[parent(i)] < heap_arr[i]){
        swap(&heap_arr[parent(i)], &heap_arr[i]); // updating the information that maps priority queue objects to array indices
        i = parent(i);
    }
}

int MaxHeap::extractMax(){ 
    int a = MaxHeap::getMax();
    swap(&heap_arr[heap_size], &heap_arr[0]);
    heap_size--;
    MaxHeapify(0);
    return a;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    
    MaxHeap a(10);
    a.insertKey(1);
    a.insertKey(2);
    a.insertKey(8);
    a.increaseKey(2,16);
    a.insertKey(50);
    a.insertKey(4);
    cout<< "Extract Max Number : " << a.extractMax() << endl;
    a.HeapSort();

    return 0;
}