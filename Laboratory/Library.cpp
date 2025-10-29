
#include "Library.h"
#include <iostream>
using namespace std;

Book::Book(string name1, string author1, string genre1, bool onthehand, Human* holder1) : holder(holder1)
{
    name = name1;
    author = author1;
    genre = genre1;
    on_the_hand = onthehand;
}

Book::Book()
{
    name = "-";
    author = "-";
    genre = "-";
    on_the_hand = false;
}

void Book::Show_Book()
{
    cout << "Name: " << name << endl;
    cout << "Author: " << author << endl;
    cout << "Genre: " << genre << endl;
    cout << "Is the book on_the_hand? " << on_the_hand << endl;
    cout << endl;

    if (on_the_hand)
    {
        holder->Show();
    }
}

void Book::AddCount()
{
    holder->PlusCount();
}

void Book::ReturnBook()
{
    on_the_hand = false;
}

Human::Human(string name1, string surname1, int id1)
{
    name = name1;
    surname = surname1;
    id = id1;
}

Human::Human()
{
    name = "-";
    surname = "-";
    id = 0;
}

void Human::Show()
{
    cout << "Reader: " << name << " " << surname << " (ID: " << id << ")" << endl;
    cout << "Количество книг на руках человека: " << count << endl;
    cout << endl;
    cout << endl;
}


void Library::AddBook(Book& b)
{
    if (book_count < 25)
    {
        books[book_count] = b;
        book_count++;
    }
    else
    {
        cout << "Слишком много книг!" << endl;
    }
}

void Library::ShowAllBooks()
{
    for (int i = 0; i < book_count; i++)
    {
        cout << "Книга №" << i + 1 << ":" << endl;
        books[i].Show_Book();
        cout << endl;
    }
}

void Library::ByName(const string& name)
{
    bool found = false;
    cout << endl;
    cout << "<--Поиск книги по имени-->" << endl;
    for (int i = 0; i < book_count; i++)
    {
        if (books[i].GetName() == name)
        {
            cout << "Книга найдена, ее индекс: " << i << endl;
            books[i].Show_Book();
            found = true;
        }
    }

    if (!found)
    {
        cout << "Такой книги не найдено!" << endl;
    }
}

void Library::ByAuthor(const string& author)
{
    bool found = false;
    cout << endl;
    cout << "<--Поиск книги по автору-->" << endl;
    for (int i = 0; i < book_count; i++)
    {
        if (books[i].GetAuthor() == author)
        {
            cout << "Книга найдена, ее индекс: " << i << endl;
            books[i].Show_Book();
            found = true;
        }
    }

    if (!found)
    {
        cout << "Такой книги не найдено!" << endl;
    }
}

void Library::ByGenre(const string& genre)
{
    bool found = false;
    cout << endl;
    cout << "<--Поиск книги по жанру-->" << endl;
    for (int i = 0; i < book_count; i++)
    {
        if (books[i].GetGenre() == genre)
        {
            cout << "Книга найдена, ее индекс: " << i << endl;
            books[i].Show_Book();
            found = true;
        }
    }

    if (!found)
    {
        cout << "Такой книги не найдено!" << endl;
    }
}

void Library::CloseLibrary()
{
    for (int i = 0; i < book_count; i++)
    {
        books[i].ReturnBook();
    }

    cout << "<--------------------------------------->" << endl;
    cout << "Все книги возвращены. Библиотека закрыта." << endl;
    cout << "<--------------------------------------->" << endl;
}

void Library::TotalBooks(Human& h)
{
    cout << "Читатель " << h.GetName() << ", прочитал за день " << h.GetTotalBooks() << " книг" << endl;
}
