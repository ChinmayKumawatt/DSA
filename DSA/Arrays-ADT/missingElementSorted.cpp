// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Array{
private:    
    int *A;
    int size;
    int length;
public:
    Array(){
        size = 10;
    }
    Array(int Arr[],int l){
        length = l;
        A = new int[length];
        for(int i= 0;i<length;i++){
            A[i]=Arr[i];
        }
    }
    
    void missingElement(){
        int diff = A[0];
        for(int i =0;i<length;i++){
            if(A[i]-i!=diff){
                while(diff<A[i]-i){
                cout<<"The missing Element is "<<i+diff<<endl;
                diff ++;
            }
        }
    }
    }
    
};

int main() {
    int value[7] = {1,2,3,4,7,8,10};
    Array Arr(value,7);
    // Arr.A = {1,2,3,4,6,7,8,10};
    Arr.missingElement();
    

    return 0;
}