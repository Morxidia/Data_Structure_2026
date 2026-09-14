#include <iostream>
using namespace std;

void nullref(int *&ref)
{
    ref = nullptr;
    // p1 = nullptr
}

int main()
{
    int val = 100;
    int *p1;
    p1 = &val;
    nullref(p1);
    if (p1 == nullptr)
    {
        cout << "null ref" << endl;
    }
    else
    {
        cout << *p1 << endl;
    }
}