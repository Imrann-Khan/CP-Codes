#include<bits/stdc++.h>
using namespace std;

class mergeSort{
    int *arr;
    int size_;
public:
    mergeSort(int size_){
        this->size_ = size_;
        arr = new int[size_];
    }

    void set_(int value, int pos){
        if(pos<size_) arr[pos] = value;
    }

    int& get_(int pos){
        return arr[pos];
    }

    void input(){
        cout<<"Enter inputs: ";
        for (int i = 0; i < size_; i++){
            cin>>arr[i];
        }
    }

    void output(int p, int r){
        cout<<"Array elements: ";
        for (int i = p; i <= r; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void sort_(int p, int r){
        if (p<r){
            int q = (p+r)/2;
            cout<<q<<":"<<endl;

            sort_(p, q);
            sort_(q+1, r);
            merge_(p, q, r);
            cout<<"Combine: "<< p<< r;
            output(p, r);
        }
    }

    void merge_(int p, int q, int r){
        int n1 = q-p+1;
        int n2 = r-q;
        int left[n1+1], right[n2+1];

        for (int i = 0; i < n1; i++){
                left[i] = arr[p+i];
        }

        for (int i = 0; i < n2; i++){
                right[i] = arr[q+1+i];
        }
        left[n1] = INT_MAX;
        right[n2] = INT_MAX;

        int i = 0;
        int j = 0;

        for (int k = p; k <= r; k++){
            if (left[i] <= right [j]){
                ///cout<<"i"<<left[i]<<" ";
                arr[k] = left[i];
                i++;
            }
            else {
                ///cout<<"j"<<right[j]<<" ";
                arr[k] = right[j];
                j++;
            }
        }
    }
};

int main(){
    int s = 8;
    mergeSort a(s);
    a.input();
    a.output(0, s-1);
    a.sort_(0, s-1);
}
