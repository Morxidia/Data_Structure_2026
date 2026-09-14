#include <iostream>
using namespace std;


void nullref(int a){
    int* arr = new int[a];
    for(int i = 0; i<a; ++i){
        arr[i] = (i+1)*100;
    }
}

void isiPointer1(int*& var){
    int temp = 10;
    var = &temp;
}

void isiPointer2(int*& var){
    int* temp = new int{10};
    var = temp;
}

int main(){
    int temp = 100;
    int *var = &temp;
    cout << *var << endl;
    // isiPointer1(var);
    isiPointer2(var);
    nullref(1000000);
    if(var == nullptr){
        cout << "daggling" << endl;
    }
    cout << *var << endl; // 10
}
