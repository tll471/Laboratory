#include <iostream>
#include "Library.h"
using namespace std;

int main()
{

	Library lib;
	Human person1("Alex", "Brown", 3721);
	Book obj1("Black Hole", "Gerni Smith", "Scientific", true, &person1);
	obj1.AddCount();
	obj1.Show_Book();

	Human person2("Glib", "Luibimov", 1487);
	Book obj2("How to be cool", "Glib Luibimov", "Fantastic", true, &person2);
	Book obj3("How to be cool", "Glib Luibimov", "Fantastic", true, &person2);
	obj2.AddCount();
	obj2.Show_Book();
	obj3.AddCount();
	obj3.Show_Book();

	lib.AddBook(obj1);
	lib.AddBook(obj2);
	lib.AddBook(obj3);
	lib.ShowAllBooks();

	lib.ByName("How to be cool");
	lib.ByAuthor("Gerni Smith");
	lib.ByGenre("Fantastic");

	int choise;
	cout << "Do you want to create book and a human? 1-yes" << endl;
	cin >> choise;
	if (choise == 1)
	{
		
		try 
		{
			string name1, surname;
			int id;
			cout << "Enter name: " << endl;
			cin >> name1;
			cout << "Enter surname: " << endl;
			cin >> surname;
			cout << "Enter id: " << endl;
			cin >> id;
			if (id == 0)
			{
				throw id;
			}

		Human person3(name1, surname, id);

		string name, author, genre;
		bool on_thehand;
		cout << "Enter name for a book: " << endl;
		cin >> name;
		cout << "Enter author for a book: " << endl;
		cin >> author;
		cout << "Enter genre for a book: " << endl;
		cin >> genre;
		cout << "Do you have this book on the hand? 1-yes, 0-no" << endl;
		cin >> on_thehand;

		Book obj3(name, author, genre, on_thehand, &person3);
		lib.AddBook(obj3);
		}
		catch (...)
		{
			cout << "Error! " << endl;
		}

	}


	Human person4("Oleg", "Brown", 3721);
	Book obj4("Again to 1939", "Pavlo Cherkasov", "Romance", true, &person4);
	Book obj5("Hello USA", "Renat Koshkin", "Mystery", true, &person4);
	Book obj6("The Great Gatsby", "Harper Lee", "Adventure", true, &person4);
	Book obj7("War and Peace", "Leo Tolstoy", "Historical", true, &person4);

	obj4.AddCount();
	obj5.AddCount();
	obj6.AddCount();
	obj7.AddCount();

	lib.AddBook(obj4);
	lib.AddBook(obj5);
	lib.AddBook(obj6);
	lib.AddBook(obj7);

	lib.ShowAllBooks();

	lib.CloseLibrary();
	lib.ShowAllBooks();

	lib.TotalBooks(person1);
	lib.TotalBooks(person2);
	lib.TotalBooks(person4);

}