#include<iostream>
#include "arrayType.h"

using namespace std;

int main()
{
   const int intArraySize = 7;
   const int doubleArraySize = 10;
   arrayType <int, intArraySize> intArray;        //int array of size intArraySize
   arrayType <double, doubleArraySize> doubleArray;  //double array of size doubleArraySize
   //create intArray
   for(int i = 0; i < intArraySize; i++)
      intArray[i] = i;

   cout << "Integer array: ";
   for(int i = 0; i < intArraySize; i++)
      cout << intArray[i] << " ";
   cout << endl;
   
   //create doubleArray
   for(int i = 0; i < doubleArraySize; i++)
      doubleArray[i] = static_cast<double> (i) / 2;

   cout << "Double array: ";
   for(int i = 0; i < doubleArraySize; i++)
      cout << doubleArray[i] << " ";
   cout << endl;
   intArray[12] = 100;// print a warning to user!

}
