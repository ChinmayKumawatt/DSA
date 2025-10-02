// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void toLowercase(char s[]){
    for(int i =0;s[i]!='\0';i++){
    if(s[i]>=65&&s[i]<97){
        s[i] = s[i]+32;
    }
    }
}

void toUpperCase(char s[]){
    for(int i =0;s[i]!='\0';i++){
    if(s[i]>=97&&s[i]<123){
        s[i] = s[i]-32;
    }
    }
}

void toToggle(char s[]){
    for(int i =0;s[i]!='\0';i++){
    if(s[i]>=97&&s[i]<123){
        s[i] = s[i]-32;
    }
    else if(s[i]>=65 && s[i]<97){
        s[i] = s[i]+32;
    }
    }
}


int main() {
    // Write C++ code here
    int i=0;
    char s[] = "WeLcoMe";
    // toLowercase(s);
    // toUpperCase(s);
    toToggle(s);
    for(i =0;s[i]!='\0';i++){
        cout<<s[i]<<endl;
    }
    cout<<i<<endl;
    return 0;
}