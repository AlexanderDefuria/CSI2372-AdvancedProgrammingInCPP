#include <iostream>
#include "kiloToGrams.h"
#include "convertClass.h"
#include "farenToCelsius.h"

using namespace std;

int main()
{
	convertClass *p;
	
	// kiloToGrams class implements the convertClass abstract class 
	kiloToGrams kilo(50);
	
	p = &kilo;
	p -> compute();
	cout << p ->getInitial() << " kilo is "
		 << p ->getConverted() << " grams ." << endl;
	
	// farenToCelsius class  implements the convertClass abstract class 
	farenToCelsius faren(55);
	p = &faren;
	p -> compute();
	cout << p ->getInitial() << " farenheit is "
		 << p ->getConverted() << " celsius ." << endl;

}