#include <iostream>
using namespace std;
/*
*   hasil perubahan strucktur Queue by Morxidia
*/

template <typename T>
struct Queue {
    T* data;
    int front;
    int rear;
    int count;
    const int size;

    Queue(const int size):data(new T[size]), front(0), rear(-1), count(0), size(size){};

    
    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == size;
    }

    bool enqueue(T nilai) {
        if (isFull()) 
            return false;

        rear = (rear + 1) % size;
        data[rear] = nilai;
        ++count;
        return true;
    }

    bool dequeue(T& nilaiKeluar) {
        if (isEmpty())
            return false;
            
        nilaiKeluar = data[front];
        front = (front + 1) % size;
        --count;
        return true;
    }

    bool peek(T& nilaiDepan) {
        if (isEmpty()) return false;
        nilaiDepan = data[front];
        return true;
    }

    void tampilkan() {
        if (isEmpty()) {
            std::cout << "Queue kosong\n";
            return;
        }
        for (int i = 0; i < count; ++i) {
            int indeks = (front + i) % size;
            std::cout << data[indeks] << ' ';
        }
        std::cout << '\n';
    }

    ~Queue(){
        delete[] data;
    }
};

int main(void) {
    // ini adalah cara menggunakan nya
    // Queue<dataType> var_name(size)
    const int size{10};
    Queue<int> queueInt(size);
    Queue<string> queueString(size);

    // Penggunaan pada Stack Memory (int)
    queueInt.enqueue(10);
    queueInt.enqueue(20);
    queueInt.tampilkan(); // Output: 10 20 

    int valOut;
    if (queueInt.dequeue(valOut)) {
        cout << "Dequeued: " << valOut << endl; // Output: 10
    }

    // Penggunaan pada Stack Memory (string)
    queueString.enqueue("Geoinformatika");
    queueString.enqueue("UPNYK");
    queueString.tampilkan(); // Output: Geoinformatika UPNYK 

    // untuk penempatan queue pada Heap
    Queue<int>* queueHeapInt = new Queue<int>(size);
    
    // access method pada struct via pointer (->)
    queueHeapInt->enqueue(100);
    queueHeapInt->enqueue(200);
    queueHeapInt->tampilkan(); // Output: 100 200

    // harus melakukan manual delete (akan otomatis memanggil ~Queue())
    delete queueHeapInt;

    return 0;
}