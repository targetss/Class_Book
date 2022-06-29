#include<iostream>

class Book
{
public:
	Book(int, const char*, const char*, const char*, int);
	Book(const Book&);

	int GetID();
	void SetID(int);

	~Book();
private:
	int ID;
	char* title;
	char* author;
	char* genre;
	int count;
};

Book::Book(int ID_, const char* title_, const char* author_, const char* genre_, int count_)
{
	//IDNumber++;

	if (title == nullptr || author == nullptr || genre == nullptr)
	{
		//delete title, author, genre;
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
	if (this->title != nullptr || this->author != nullptr || this->genre != nullptr)
	{
		delete title, author, genre;
		title = new char[strlen(other.title) + 1];
		author = new char[strlen(other.author) + 1];
		genre = new char[strlen(other.genre) + 1];
	}
	strcpy_s(this->title, strlen(other.title) + 1, other.title);
	strcpy_s(this->author, strlen(other.author) + 1, other.author);
	strcpy_s(this->genre, strlen(other.genre) + 1, other.genre);
	this->ID = other.ID;
	this->count = other.count;

}

int Book::GetID()
{
	return ID;
}

void Book::SetID(int num)
{
	this->ID = num;
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

	Book b1(0, "name", "author", "genre", 2);
	Book b2(1, "name1", "author1", "genre1", 1);

	std::cout << b1.GetID() << std::endl;
	std::cout << b2.GetID() << std::endl;

	return 0;
}
