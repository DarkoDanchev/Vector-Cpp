#include "Vector.h"

using namespace std;

int main()
{

    Vector<int> a(5);
    for(unsigned i = 0; i < 6; i++)
    {
        a.add(i+1);
    }
    a.Print();
    return 0;
}
