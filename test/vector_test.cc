#include "./../inc/adt/vector.h"

using namespace cclib;
using namespace cclib::adt;

void vectorTest() {
    vector<int>* cc = new vector<int>(10);
    delete[] cc;
}

int main(int argc, char const *argv[])
{
    /* code */
    vectorTest();
    return 0;
}
