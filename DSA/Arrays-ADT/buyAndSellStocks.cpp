// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Array{
private:     
    int*A;
    int size;
    int length;
    
public:
    Array(){
        size = 10;
    }
    Array(int val[],int l){
        length = l;
        A = new int[length]; 
        for(int i=0;i<length;i++){
            A[i] = val[i];
        }
    }
    
    void display(){
        for(int i=0;i<length;i++){
            cout<<A[i]<<endl;
        }
    }
    
    int min(){
        int min;
        int index=0;
        min = A[0];
        for(int i=0;i<length;i++){
            
            if(A[i]<min){
                min = A[i];
                index = i;
        }
    }
    
    // cout<<index<<endl;
    return index;
    }
    
    int max(int x){
        int max;
        int index=0;
        max=A[x];
        for(int i =x;i<length;i++){
            if(A[i]>max){
                max=A[i];
                index=i;
            }
        }
        // cout<<index<<endl;
        return index;
    }
    int returnDiff(int x,int y){
        cout<<A[y]-A[x]<<endl;
        return 0;
    }
};

int main() {
    // Write C++ code here
    int value[7] = {5,1,2,3,6,7,4};
    Array arr(value,7);
    // arr.display();
    int x = arr.min();
    int y = arr.max(x);
    arr.returnDiff(x,y);
    

    return 0;
}