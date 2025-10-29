#pragma once
#include <iostream>
using namespace std;

class Human
{
	string name;
	string surname;
	int id;
	int count = 0;
	int total_books = 0;
public:
	Human();
	Human(string name1, string surname1, int id1);
	void Show();
	string GetName()
	{
		return name;
	}
	string GetSurname()
	{
		return surname;
	}
	int GetCount()
	{
		return count;
	}
	void PlusCount()
	{
		try
		{
			total_books++;
			if (count < 3)
			{
				count++;
				
			}
			else
			{
				throw count;
			}
		}

		catch (...)
		{
			cout << "-------------------------------" << endl;
			cout << name << " уже держит 3 книги!" << endl;
			cout << "-------------------------------" << endl;
		}
			
	}
	int GetTotalBooks()
	{
		return total_books;
	}

};

class Book
{
	string name;
	string author;
	string genre;
	bool on_the_hand;
	Human* holder;
public:
	Book();
	Book(string name1, string author1, string genre1, bool onthehand, Human* holder1);
	void Show_Book();
	void AddCount();

	string GetName()
	{
		return name;
	}
	string GetAuthor()
	{
		return author;
	}
	string GetGenre()
	{
		return genre;
	}
	Human* GetHolder() 
	{ 
		return holder; 
	}
	bool GetOnTheHand()
	{
		return on_the_hand;
	}

	bool IsAvailable()
	{
		return on_the_hand = false;
	}
	void ReturnBook();
};

class Library
{
	Book books[25];
	int book_count = 0;
public:
	void AddBook(Book& b);
	void ShowAllBooks();
	void ByName(const string& name);
	void ByAuthor(const string& author);
	void ByGenre(const string& genre);

	void CloseLibrary();

	void TotalBooks(Human& h);
};