#include "String.h"

int main()
{
	//setlocale(0, "UKR");
	srand(time(0));
	
	String b(" hello world ");
	String c = b;
	
	b.Print();	
	b.operator+=("Smile!");
	b.Print();
	b.operator+=(c);
	cout << b << "\n";
	cout << b.operator= (c) << "\n";
	cout << b.operator==("Smile!") << "\n";	
	cout << b.operator()(c) << "\n";
	cout << "index = " << b.operator[](7) << "\n";	
	b.operator+(c);
	cout << "\n";
	b.operator+("Smile!");
	cout << "\n";
}