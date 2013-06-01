#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;


void Problem1()
{
	int num = 0, sum = 0;
	for (int i = 0; i < 1000;i++)
	{
		num = i;
		if (num % 3 == 0 || num % 5 == 0)
			sum = num + sum;
	}
	cout << "sum: " << sum << endl;
}

int fib(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else 
		return fib(n - 1) + fib (n - 2);
}

void Problem2()
{
	/*
	int sum = 0, n = 0;
	//assume i have a func that finds fibonacci
	vector<int> fibArray;
	while (fib(n) <= 4000000)
	{
		fibArray.push_back(fib(n));
		n++;
	}
	vector<int>::iterator i;
	for (i = fibArray.begin(); i < fibArray.end(); i++)
	{
		if (*i % 2 == 0)
			sum = sum + *i;
	}
	cout << sum << endl;
	*/
	//better performance
	int first = 0;
	int second = 1;
	int total = 0;
	int totalOfPreviousTwo = 0;

	while (totalOfPreviousTwo <= 4000000)
	{
		totalOfPreviousTwo = first + second;
		if (totalOfPreviousTwo % 2 == 0)
			total = total + totalOfPreviousTwo;
		first = second;
		second = totalOfPreviousTwo;
	}
	cout << total << endl;
}

bool isPrime(long n)
{
	long i = 2;
	while (i < n)
	{
		if (n % i == 0)
			return false;
		i++;
	}
	return true;
}

void Problem3()
{
	long num = 600851475143;
	long max1 = 0;
	for (long i = 1; i <= sqrt(num); i++) //added sqrt(num) & time went down significantly
	{
		if (num % i == 0 && isPrime(i))
			max1 = max(i, max1);
	}
	cout << "Largest prime factor: " << max1 << endl;
}

int testPrime()
{
	int init(10);
	cout << init << endl;
	cin >> init;
	for (int i = 2; i < init; i++)
	{
		if (init%i == 0)
		{
			cout << "Not prime" << endl;
			return 0;
		}
		cout << "i is" << i << endl;
		cout << "Prime" << endl;
		return 0;
	}
}

//finds whether a number is a palindrome
bool isPal(int num)
{
	vector<int> arrayNum;
	int numIntoArray = 0;
	while (num > 0)
	{

		numIntoArray = num % 10;
		num = num / 10;
		arrayNum.push_back(numIntoArray);
	}

	vector<int>::iterator i;
	vector<int>::iterator k;
	k = arrayNum.end() - 1;
	for (i = arrayNum.begin(); i < arrayNum.end(); i++)
	{
		if (*i != *k)
		{
			return false;
		}
		k--;
	}
	return true;
}
void Problem4()
{
	int maxPal = 0;
	for (int i = 100; i < 999; i++)
	{
		for (int k = 100; k < 999; k++)
		{
			if (isPal(k*i))
				maxPal = max(k * i, maxPal);
		}
	}
	cout << "maxPal is :" << maxPal << endl;
}

bool divisibleByUpTo20(int num)
{
	for (int i = 1; i <= 20; i++)
	{
		if (num % i != 0)
			return false;
	}
	return true;
}

void Problem5()
{
	int smallestNum = 1;
	bool Found = false;
	while (!Found)
	{
		if (!divisibleByUpTo20(smallestNum))
			smallestNum++;
		else
			Found = true;
	}

	cout << "Smallest number is: " << smallestNum << endl;
}


double difference()
{
	double total = 0;
	double sum = 0;
	for (int i = 1; i < 101; i++)
	{
		sum = sum + i;
		total = total + i * i;
	} 
	return (pow(sum, 2) - total);
}

void Problem6()
{
	cout << fixed << setprecision(0) << "different between sum of squares and square of sum: " << difference() << endl;
}

void Problem7()
{
	long i = 0;
	int count = 0;
	while (count <= 10001)
	{
		i++;
		if (isPrime(i))
			count++;	
	}
	cout << "Prime no.: " << i << endl;
}

//find the greatest product of 5 consecutive digits
void Problem8()
{
	int maxProduct = 0, product = 0, maxNum = 0;
	string num = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
	string::iterator i;
	for (i = num.begin(); i+4 < num.end(); i++)
	{
		if (*i >= 0 && *(i+1) >= 0 && *(i+2) >= 0 && *(i+3) >= 0 && *(i+4) >=0)
		{
			product = (*i - '0')* (*(i+1) - '0')* (*(i+2)-'0')* (*(i+3)-'0')* (*(i+4) -'0');		
			maxNum = max(maxNum, product);	
		}
	}
	
	cout << maxNum << endl;
}

int main()
{	
	testPrime();
	//if (isPrime(12001 )) cout << "is Prime" << endl;
	
}