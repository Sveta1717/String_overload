#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

class String
{
	char* text;
	unsigned int length;
	unsigned int capacity;
public:
	String(const char* text, unsigned int capacity = 80);
	String();
	explicit String(unsigned int capacity);
	String(const String& original);
	~String();
	void SetString(const char* text);
	const char* GetCharArray() const;
	int GetLength() const;
	int GetCapacity() const;
	void Clear();
	void ShrinkToFit();
	char GetCharAt(unsigned int index);
	void Print();
	void PrintLn();
	void GetLine();
	int CompareTo(const String& text) const;
	int CompareTo(const char* line) const;
	void Concat(const String& text) const;
	void Concat(const char* line);
	void Concat(int x);
	void Concat(double y);
	String* Split(const char* separator, int& pieces) const;
	String ToLower();
	String ToUpper();
	void SortAZ();
	void SortZA();
	void Trim();
	void TrimEnd();
	void TrimStart();
	void Remove(int x);
	void Remove(int start, int count);
	bool Contains(const String& text);
	bool EndsWith(const String line) const;
	bool StartsWith(const String line) const;
	bool Equals(const String text) const;
	int IndexOf(char ch);
	int LastIndexOf(char ch);
	int IndexOf(const String text) const;
	int LastIndexOf(const String text) const;
	void Replace(char R, char Z);
	void Reverse();
	void Shuffle();
	void RandomFill();
	String& operator = (String& s);
	bool operator == (const char* s);
	bool operator > (String* second);	
	bool operator < (String* second);	
	bool operator >=(String* second);
	bool operator <=(String* second);
	bool operator !=(String* second);
	String& operator ()(String& s);
	char& operator [](int index);	
	String* operator +(String& s);	
	String* operator +(const char* s);		
	void operator+=(const char* s);
	void operator+=(String& s);
private:
	void Initialize(const char* s, int capacity = 80);
};

ostream& operator <<(ostream& out, String s);
//istream& operator >>(istream& in, String& s);
