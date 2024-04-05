#include <iostream>

using namespace std;

void swap(int *x, int *y);

class MaxHeap{
    int *heap_arr;
    int capacity;
    int heap_size;

    public :
        MaxHeap(int cap);
        void MaxHeapify(int i);
        int parent(int i){return (i-1)/2;}
        int left(int i){return (2*i + 1);}
        int right(int i){return (2*i +2);}
        void increaseKey(int i, int new_val);
        int getMax(){return heap_arr[0];}
        void insertKey(int k);
};

MaxHeap::MaxHeap(int cap){
    heap_size = 0;
    capacity = cap;
    heap_arr = new int[cap]; 
}

void MaxHeap::MaxHeapify(int i){
    int l = left(i);
    int r = right(i);
    int largest = i;

    if(l < heap_size && heap_arr[l] > heap_arr[largest]){
        largest = l;
    }
    if(r < heap_size && heap_arr[r] > heap_arr[largest]){
        largest = r;
    }
    if(largest != i){
        swap(&heap_arr[i], &heap_arr[largest]);
        MaxHeapify(largest); //recursive
    }

}

void MaxHeap::increaseKey(int i, int new_val){
    if(new_val < heap_arr[i]){
        cout << "New key is smaller than current key" << endl;
    }
    else{
        heap_arr[i] = new_val;
        while(i > 0 && heap_arr[parent(i)] < heap_arr[i]){ // MaxHeapify와 동일
            swap(&heap_arr[i], &heap_arr[parent(i)]);
            i = parent(i);
        }
    }
}

void MaxHeap::insertKey(int k){
    if(heap_size == capacity){
        cout << "heap capacity is full" << endl;
        return ;
    }
    heap_size++;
    int i = heap_size - 1;
    heap_arr[i] = k;

    while(i != 0 && heap_arr[parent(i)] < heap_arr[i]){
        swap(&heap_arr[i], &heap_arr[parent(i)]);
        i = parent(i);
    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    
    MaxHeap a(5);
    a.insertKey(1);
    a.insertKey(2);
    a.insertKey(8);
    a.increaseKey(2,16);
    cout << a.getMax() << " ";
    a.insertKey(50);
    a.increaseKey(1,9);
    cout << a.getMax() << " ";
    a.insertKey(4);
    return 0;
}