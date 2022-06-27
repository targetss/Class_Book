#include<iostream>

class Book
{
public:
	Book(const char*, const char*, const char*, int);
	Book(int, char*, char*, char*, int);
	Book(const Book&);

	int GetID();

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

Book::Book(const char* title_, const char* author_, const char* genre_, int count_)
{
	this->ID = IDNumber;
	if (title == nullptr || author == nullptr || genre == nullptr)
	{
		delete title, author, genre;
		title = new char[strlen(title_) + 1];
		author = new char[strlen(author_) + 1];
		genre = new char[strlen(genre_) + 1];
	}

	strcpy_s(title, strlen(title_)+1, title_);
	strcpy_s(author, strlen(author_) + 1, author_);
	strcpy_s(genre, strlen(genre_) + 1, genre_);
	this->count = count_;
	IDNumber++;
}

Book::Book(int ID_, char* title_, char* author_, char* genre_, int count_)
{
	if (title == nullptr || author == nullptr || genre == nullptr)
	{
		delete title, author, genre;
		title = new char[strlen(title_) + 1];
		author = new char[strlen(author_) + 1];
		genre = new char[strlen(genre_) + 1];
	}

	strcpy_s(title, strlen(title_) + 1, title_);
	strcpy_s(author, strlen(author_) + 1, author_);
	strcpy_s(genre, strlen(genre_) + 1, genre_);
	this->count = count_;
	this->ID = ID_;
}

Book::Book(const Book& other)
{

}

int Book::GetID()
{
	return ID;
}

Book::~Book()
{
	delete title, author, genre;
	title = nullptr;
	author = nullptr;
	genre = nullptr;
}

int main(int argc, char* argv[])
{
	const char *ame = "hello";
	std::cout << strlen(ame) << std::endl;

	Book b1("name", "author", "genre", 2);
	Book b2("name1", "author1", "genre1", 1);

	std::cout << b1.GetID() << std::endl;
	std::cout << b2.GetID() << std::endl;

	return 0;
}