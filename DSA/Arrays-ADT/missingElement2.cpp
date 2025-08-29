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

    void missingElement2(int maxi){
        int H[maxi];
        for(int i=0;i<maxi;i++){
            H[i] = 0;
        }
        for(int i = 0; i<length;i++){
            H[A[i]] = 1;
        }
        for(int i=1;i<maxi;i++){
            if(H[i]==0){
                cout<<"The missing element is"<<i<<endl;
            }
        }
    }    
    
    int maximum(){
        int max;
        max = A[0];
        for(int i=0;i<length;i++){
            if(A[i]>max){
                max=A[i];
            }
        }
        // cout<<max<<endl;
        return max;
    }
};


int main() {
    int value[5] = {1,2,3,7,15};
    Array Arr(value,5);
    int max = Arr.maximum();
    // Arr.A = {1,2,3,4,6,7,8,10};
    Arr.missingElement2(max);
    return 0;
}