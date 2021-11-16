
#include <iostream>
using namespace std;


typedef struct player
{
	string name = "";// initializing
	int score = 0; //initializing

} Athlete; // defining the new type Athlete using the structure player

void inputData(Athlete*, int);
void bubbleSort(Athlete*, int);
void median(Athlete*, int, float*);
void outputData(Athlete*, int);

int main()
{

	int n = 0;
	Athlete* p;
	float mead;
	cout << " Enter number of players (n) : ";
	cin >> n;
	p = new Athlete[n];
	if (!p)
	{
		cout << " Allocation failure!";
		exit(1);
	}
	inputData(p, n);   //read data
	bubbleSort(p, n); //sort data
	cout << "\n Sorted data are : " << std::endl;
	outputData(p, n);  //output sorted data
	median(p, n, &mead);
	cout << "\n Median = " << mead;
	
	delete [] p;
	
	
}
//*****************************
void inputData(Athlete* p, int n)
{
    for (int i=0; i < n; i++ ) {
        std::cout << "Name:  ";
        std::cin>>p[i].name;
        std::cout << "Score: ";
        std::cin>>p[i].score;
    }

}
//*****************************
void bubbleSort(Athlete* temp, int len)
{
    Athlete swap;
    for (int i =0; i<len-1; i++) {
        for (int k = 0; k < len-i-1; ++k) {
            if (temp[k].score > temp[k+1].score) {
                swap = temp[k];
                temp[k] = temp[k+1];
                temp[k+1] = swap;
            }
        }
    }




}
//*************************
void median(Athlete *x, int n, float *mead)
{
	if (n % 2 == 0)  //if n is even
		*mead = static_cast<float>(((x + ((n - 1) / 2))->score + (x + (n / 2))->score) / 2);
	else  //if n is odd
		*mead = (x + (n - 1) / 2)->score;
}
//****************
void outputData(Athlete *p, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << (p + i)-> name << " " << (p + i)-> score << " "; 
		//remember that a->b is equivalent to (*a).b
		cout << endl;
	}
}

