#include <iostream>
using namespace std;

int main()
{
    int i = 67432628;
    int iInteger = i / 10000;
    int iDecimal = i % 10000 / 100;
    int iAdd = i % 100 / 10;
    if (iAdd >= 5)
    {
         iDecimal += 1;
    }
    if (iDecimal >= 100)
    {
        iDecimal = 0;
        iInteger += 1;
    }
    
    std::cout<<"i:"<<i<<"      iIn:"<<iInteger<<"     iD:"<<iDecimal<<"   iA:"<<iAdd;
    return 0;
}
