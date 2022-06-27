#include<iostream>

class Book
{
public:
	Book();


	~Book();
private:
	int ID;
	char* title;
	char* author;
	char* genre;
	int count;
	static int IDNumber;
};

int Book::IDNumber = 0;

Book::Book()
{

}

Book::~Book()
{

}