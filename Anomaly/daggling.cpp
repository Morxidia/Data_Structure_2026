#include <iostream>
using namespace std;

void jackTheRam(int n){
  int arr[n];
  for(size_t i = 0; i < n; ++i){
    arr[i] = (i + 1) * 100;
  }
  return;
}

void signTheVar(int*& a){
  // firts
  int var1 = 10;
  a = &var1;
  // second method
  // int* var2 = (int*)malloc(sizeof(int));
  // *var2 = 10;
  // a = var2;
  return;
}

int main(void){
  int* var = (int*)malloc(sizeof(int));
  *var = 5;
  signTheVar(var);
  jackTheRam(100000);
  cout << *var << endl;
}