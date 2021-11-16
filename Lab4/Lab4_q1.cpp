
#include <iostream>
using namespace std;

void inputData(int *, int);
void bubbleSort(int *, int);
void median(int *, int, float *);
void outputData(int *, int);

int main()
{
  int n, *p;
  float mead;
  cout << " Enter number of items(n) : ";
  cin >> n;
  p = new int[ n ];
  if(!p)
  {
       cout << " Allocation failure!";
       exit(1);
  }
  inputData(p, n);   //read data
  bubbleSort(p, n); //sort data
  cout << "\n Sorted data are : ";
  outputData(p, n);  //output sorted data
  median(p, n, &mead);
  cout << "\n Median = " << mead;
  delete p;
  cin.get();
}
//*****************************
void inputData(int  *p, int n)
{
    for (int i=0; i < n; i++ ) {
        std::cin>>p[i];
    }
}
//*****************************
void bubbleSort(int  *temp, int len)
{
    int swap;
    for (int i =0; i<len-1; i++) {
        for (int k = 0; k < len-i-1; ++k) {
            if (temp[k] > temp[k+1]) {
                swap = temp[k];
                temp[k] = temp[k+1];
                temp[k+1] = swap;
            }
        }
    }
}
//*************************
void median(int *x, int n, float *mead)
{
   if(n % 2 == 0)  //if n is even
       *mead = static_cast <float> ( ( *(x + ((n - 1) / 2) ) + *( x + (n / 2)) ) / 2);
  else  //if n is odd
       *mead = *( x + (n - 1) / 2);
}
//****************
void outputData(int *p, int n)
{
  for(int i = 0; i < n; i ++)
	{
	  cout << *(p + i)  <<  " ";
	  cout << endl;
	}
}

