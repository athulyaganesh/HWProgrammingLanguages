#include <iostream>
#include <string>
#include "InfInt.h"

using namespace std;

class BPrime
{
	private:

		InfInt prime;

	    bool isPrime(InfInt n)
		{
			if (n <= 1)
			{
				return false;
			}
			for (InfInt i = 2; i < n; i++)
			{
				if (n % i == 0)
				{
					return false;
					break;
				}
			}
			return true;
		}

	public:
		BPrime()
		{
			prime = 2; 
		}

		BPrime(const BPrime &b)
		{
			prime = b.prime; 
		}

		BPrime(string s)
		{
			InfInt p = stoi(s);
			try
			{
				if (isPrime(p))
				{
					prime = p;
				}
				else
				{
					throw(p);
				}
			}
			catch(InfInt pr)
			{
				cout << pr << " is not a prime number!" << endl; 
			}

		}


		BPrime Increment()
		{
			InfInt temp = prime + 1;
			while (!isPrime(temp))
			{
				temp = temp + 1; 
			}
			prime = temp;  
			
			return *this; 
		}

		BPrime Decrement()
		{
			try
			{
				if (prime == 2)
				{
					throw(prime); 
				}

				InfInt temp = prime - 1;
				while (!isPrime(temp))
				{
					temp = temp - 1;
				}
				prime = temp;
				
			}
			catch (InfInt pr)
			{
				cout << "Prime number is: " << pr << " so we can't decrement" << endl; 
			}

			return *this;
			
		}

		BPrime Add(int n)
		{
			InfInt i = prime + 1;
			int counter = 0;

			while (true)
			{
				if (isPrime(i))
				{
					counter++;
				}
				if (counter == n)
				{
					prime = i;
					break;
				}
				i++; 
			}

			return *this; 
		}
		BPrime Assign(BPrime b)

		{
			try
			{
				if (!isPrime(b.prime))
				{
					throw (b.prime); 
				}
				else
				{
					prime = b.prime; 
				}
			}
			catch(InfInt pr)
			{
				cout << pr << " is not a prime!" << endl; 
			}
			

			return *this;
		}
		string ToString()
		{
			return prime.toString(); 
		}
};

int main()
{ 

	cout << "Step by step testing:" << endl << endl;
	cout << "Creating an object p1 with the default constructor.." << endl;
	BPrime p1; 
	cout << "Value in p1 is: " << p1.ToString() << endl; 
	cout << "Decrementing once.." << endl;
	p1.Decrement();
	cout << "Incrementing p1 thrice.." << endl;
	p1.Increment(); p1.Increment(); p1.Increment(); 
	cout << "Value in p1 now: " << p1.ToString() << endl;
	cout << "Decrementing p1 twice.." << endl;
	p1.Decrement(); p1.Decrement(); 
	cout << "Value in p1 now: " << p1.ToString() << endl; 
	cout << "Getting the 5th prime number from " << p1.ToString() << " now.." << endl;
	p1.Add(5); 
	cout << "Value in p1 now: " << p1.ToString() << endl << endl; 
	cout << "Creating a new object p2 using the copy constructor using the value in p1.." << endl; 
	BPrime p2(p1); 
	cout << "Value in p2 is: " << p2.ToString() << endl << endl;
	cout << "Incrementing value in p2 twice.." << endl; 
	p2.Increment(); p2.Increment(); 
	cout << endl << endl<< "Creating p3 of type BPrime using the constructor that takes in a string as one argument.." << endl;
	cout << "Enter a number of your choice: " << endl; 
	string n; 
	cin >> n; 
	BPrime p3(n); 
	cout <<endl<<endl<< "Value in p2 now: " << p2.ToString() << endl; 
	cout << "Value in p1 now: " << p1.ToString() << endl<<endl; 
	cout << "Now, Assigning the value in p2 to p1.." << endl; 
	p1.Assign(p2); 
	cout << "p1's new value is: " << p1.ToString() << endl << endl; ;

	cout << "Testing is complete" << endl; 


}