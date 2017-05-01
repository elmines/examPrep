#include<iostream>
#include "Edge.h"
using namespace std;


int main()
{
	Edge a(3, 6);
	Edge b(4, 5, 9);
	Edge c(1, 2, 9);
	Edge d(6, 7, 12);

	cout << "Edge a = " << a << endl;
	cout << "Edge b = " << b << endl;
	cout << "Edge c = " << c << endl;
	cout << "Edge d = " << d << endl;

	cout << "a < b: " << (a < b) << endl;
	cout << "a == b: " << (a == b) << endl;
	cout << "a > b: " << (a > b) << endl;
	cout << endl;

	cout << "a < c: " << (a < c) << endl;
	cout << "a == c: " << (a == c) << endl;
	cout << "a > c: " << (a > c) << endl;
	cout << endl;

	cout << "a < d: " << (a < d) << endl;
	cout << "a == d: " << (a == d) << endl;
	cout << "a > d: " << (a > d) << endl;
	cout << endl;

	cout << "b < c: " << (b < c) << endl;
	cout << "b == c: " << (b == c) << endl;
	cout << "b > c: " << (b > c) << endl;
	cout << endl;

	cout << "b < d: " << (b < d) << endl;
	cout << "b == d: " << (b == d) << endl;
	cout << "b > d: " << (b > d) << endl;
	cout << endl;

	cout << "c < d: " << (c < d) << endl;
	cout << "c == d: " << (c == d) << endl;
	cout << "c > d: " << (c > d) << endl;
	cout << endl;

	return 0;

}
