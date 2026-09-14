#include <iostream>

using namespace std;

void nullref(int *&p1)
{ // bukan p1 sama seperti di main
    cout << *p1 << endl;
    p1 = nullptr;
    if (p1 == nullptr)
    {
        cout << "null pointer reference" << endl;
    }
    else
    {
        cout << *p1 << endl;
    }
}

void changeval(int &ref, int val)
{
    ref = val;
    cout << ref << endl;
}

int main()
{
    int val = 150;
    int *ref = &val;
    cout << *ref << endl;
    nullref(ref);
    if (ref == nullptr)
    {
        cout << "null pointer reference" << endl;
    }
    else
    {
        cout << *ref << endl;
    }
}
