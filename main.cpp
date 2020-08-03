#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

class Heap {
public:
    Heap() = default;
    
    void sift_down(int i) {
        int left, right, greatest_child;
        while (2 * i + 1 < heap_size){
            left = 2 * i + 1;
            right = 2 * i + 2;
            greatest_child = left;
            if (right < heap_size && array[right] > array[left])
                greatest_child = right;
            if (array[i] >= array[greatest_child])
                break;
            swap(array[i], array[greatest_child]);
            i = greatest_child;
        }    
    }
    
    void sift_up(int i){
        while (array[i] > array[(i - 1) / 2]) {
            swap(array[i], array[(i - 1) / 2]);
            i = (i - 1) / 2;
        }        
    }

    void addelem(int n) {
        array.push_back(n);
        sift_up(heap_size);
        heap_size++;
    };
    
    void getmax() {
        cout << array[0] << "\n";
        array[0] = array[heap_size - 1];
        array.pop_back();
        heap_size--;
        sift_down(0);
    }    
    /*vector<int> get() const {
        return array;  
    };*/
    
private:
    vector<int> array;
    int heap_size {0};
};
 
int main()
{
    int N;
    cin >> N;
    Heap heap;
    
    string operation;
    for (int i = 0; i < N; i++){
        cin >> operation;
        if (operation == "ExtractMax"){
            heap.getmax();
        }
        else if (operation == "Insert"){
            int q;
            cin >> q;
            heap.addelem(q);
        }
        
        /*for (auto c: heap.get()){
                cout << c << " ";
        }
        cout << "\n";*/
    } 
    
    return 0;
}
