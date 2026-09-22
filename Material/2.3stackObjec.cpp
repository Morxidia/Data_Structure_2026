#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    int nim;
    string nama;
};

template <typename T>
struct Stack{
	int top;
	const int size;
	T* data;

	Stack(int size):top(-1),size(size),data(new T[size]){};

	bool push(const T& input){
		if(isFull())
			return false;
		data[++top] = input;
		return true;
	}

	bool pop(T& output) {
    if (isEmpty()) {
        cerr << "Stack Underflow!\n";
        return false;
    }
    output = data[top--];
    return true;
	}

	T peek(){
		if(isEmpty()) return T();
		return data[top];
	}

	// fungsi ini tidak dapat melakukan print untuk object khusus tanpa default ouput stream
	void printMember(){
		if(isEmpty()){
			cout << "stack Kosong" << endl;
			return;
		}
		cout << "Isi stack Top -> bottom" << endl;
		for(int i = top; i>=0 ; i--){
			cout << "data - " << i+1 << " : " << data[i] << endl;
		}
		cout << "end of stack" << endl;
	}
	
	bool isEmpty(){
		return top < 0;
	}

	bool isFull(){
		return top >= size-1;
	}

	~Stack(){
		delete[] data;
	}
};

int main(void){
  // ini adalah cara menggunakan nya
  // Stack<dataType> var_name(size)
  const int size{10};
  Stack<int> stackInt(size);
  Stack<string> stackString(size);
	
  // untuk penempatan stack pada Heap
  Stack<int>* stackHeapInt = new Stack<int>(size);
  // access method pada struct
  stackHeapInt->push(10);
  // harus melakukan manual delete
  delete stackHeapInt;
}