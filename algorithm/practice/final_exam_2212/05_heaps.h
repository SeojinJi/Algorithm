#include <vector>
#include <iostream>
#include <algorithm>
#define MAX_NUM 100000

using namespace std;

class Heap{
    private:
        vector<pair<int, int>> Arr;
    public:
        Heap();
        ~Heap();
        void push(int e, int v);
        int top();
        int topvalue();
        void pop();
        bool empty() {return Arr.empty();};
        void Build_Heap();
        void Heapify(int index);
        int indexOf(int v);
        void fixKey(int key, int v);
        void make_empty();
};

Heap::Heap() {}
Heap::~Heap() {}
void Heap::push(int e, int v){
    Arr.push_back(make_pair(e,v));
    Build_Heap();
}

int Heap::top(){
    return Arr[0].second;
}

int Heap::topvalue(){
    return Arr[0].first;
}

void Heap::pop(){
    swap(Arr[Arr.size()-1], Arr[0]);
    Arr.pop_back();
    Heapify(0);
}

void Heap::Build_Heap(){
    for(int i = (Arr.size()/2) - 1; i>=0; i--){
        Heapify(i);
    }
}

void Heap::Heapify(int index){
    int l = (index+1)*2 -1;
    int r = (index+1)*2;
    int tmp = index;
    if((Arr.size()>l) && Arr[l] < Arr[tmp]){
        tmp = l;
    }
    if((Arr.size()>r) && Arr[r] < Arr[tmp]){
        tmp = r;
    }
    if(tmp != index){
        swap(Arr[index], Arr[tmp]);
        Heapify(tmp);
    }
}

int Heap::indexOf(int v){
    for(int i = 0; i < Arr.size(); i++){
        if(Arr[i].second == v){
            return i;
        }
    }
    return -1;
}

void Heap::fixKey(int key, int v){
    int i = indexOf(v);
    Arr[i].first = key;
    while( i > 0 && (Arr[i] < Arr[(i-1)/2])){
        swap(Arr[i], Arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

void Heap::make_empty(){
    while(!Arr.empty()){
        Arr.pop_back();
    }
}