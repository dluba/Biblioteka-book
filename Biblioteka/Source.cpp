#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstring>



using namespace std;

class Book
{

public: Book(string sA, string nB, string izd, int kol_str, int yoe)
{
	setlocale(LC_ALL, "rus");
	surnameAutor = sA;
	nameBook = nB;
	izdanie = izd;
	kolizestvo = kol_str;
	year = yoe;

}
	  Book() {};
	  string surnameAutor;
	  string nameBook;
	  string izdanie;
	  int kolizestvo;
	  int year;
	  vector<Book> prs;
	  virtual vector<Book> sortup(vector<Book> book)
	  {
		  return prs;
	  }
	  virtual vector<Book> sortdown(vector<Book> book)
	  {
		  return prs;
	  }
	  virtual vector<Book> purge(vector<Book> book)
	  {
		  return prs;
	  }
	  virtual vector<Book> edit(vector<Book> book)
	  {
		  return prs;
	  }
	  virtual vector<Book> vyvod(vector<Book> book)
	  {
		  return prs;
	  }
	  virtual vector<Book> add(vector<Book> book)
	  {
		  return prs;
	  }
	  virtual vector<Book> poisk(vector<Book> book)
	  {
		  return prs;
	  }

};


class Bibl : public Book
{

public: Bibl(string sA, string nB, string izd, int kol_str, int yoe) :Book(sA, nB, izd, kol_str, yoe)
{}
	  Bibl() :Book()
	  {}

	  vector<Book> sortup(vector<Book> book) override //сортировка по алфавиту
	  {
		  Book x;
		  short left;
		  short right;
		  short sred;

		  for (short i = 1; i < book.size(); i++)
			  if (book.at(i - 1).surnameAutor > book.at(i).surnameAutor) {
				  x = book.at(i);
				  left = 0;
				  right = i - 1;
				  do {
					  sred = (left + right) / 2;
					  if (book.at(sred).surnameAutor < x.surnameAutor) left = sred + 1;
					  else  right = sred - 1;
				  } while (left <= right);
				  for (short j = i - 1; j >= left; j--)
					  book.at(j + 1) = book.at(j);
				  book.at(left) = x;
			  }return book;
	  }

	  vector<Book> sortdown(vector<Book> book) override
	  {
		  Book x;
		  short left;
		  short right;
		  short sred;


		  for (short i = 1; i < book.size(); i++)
			  if (book.at(i - 1).surnameAutor < book.at(i).surnameAutor) {
				  x = book.at(i);
				  left = 0;
				  right = i - 1;
				  do {
					  sred = (left + right) / 2;
					  if (book.at(sred).surnameAutor > x.surnameAutor) left = sred + 1;
					  else  right = sred - 1;
				  } while (left <= right);
				  for (short j = i - 1; j >= left; j--)
					  book.at(j + 1) = book.at(j);
				  book.at(left) = x;
			  }return book;
	  }
	  vector<Book> purge(vector<Book> book) override
	  {
		  ofstream os; os.open("./output.txt", ios::app);
		  string purgablenameBook;
		  string p;
		  cout << " " << endl;
		  getline(cin, p);
		  cout << "Enter the title of the book to delete: " << endl;
		  getline(cin, purgablenameBook);
		  bool exist = false;
		  for (int j = 0; j < book.size(); j++) {
			  if (purgablenameBook == book[j].nameBook) {
				  exist = true;
				  book.erase(book.begin() + j);
			  }
		  }
		  os.close();
		  return book;
		  if (exist == false) {
			  cout << "There is no such book!" << endl;
			  return book;
		  }
		  os.close();
		  return book;
	  }

	  vector<Book> edit(vector<Book> book) override
	  {
		  ofstream os; os.open("./output.txt", ios::app);
		  if (!os) { cerr << "output.txt not readable" << endl; }
		  string editablebook;
		  string pop;
		  cout << " " << endl;
		  getline(cin, pop);
		  cout << "Enter the title of the book to edit: " << endl;
		  getline(cin, editablebook);
		  bool exists = false;
		  for (int i = 0; i < book.size(); i++)
			  if (book[i].nameBook == editablebook)
			  {
				  exists = true;
				  string pop;
				  cout << " ";
				  getline(cin, pop);
				  cout << "Enter the title of the book: " << endl;
				  getline(cin, book[i].nameBook);
				  //cin >> book[i].nameBook;
				  cout << "Enter the author of the book: " << endl;
				  getline(cin, book[i].surnameAutor);
				  //cin >> book[i].surnameAutor;
				  cout << "Enter publisher: " << endl;
				  getline(cin, book[i].izdanie);
				  //cin >> book[i].izdanie;
				  cout << "Enter the year of publication" << endl;
				  cin >> book[i].year;
				  cout << "Enter the number of pages: " << endl;
				  cin >> book[i].kolizestvo;
				  cout << endl;
				  return book;
				  break;
			  }
		  if (exists == false) {
			  cout << "There is no such book!" << endl;

		  }
		  os.close();
		  return book;
	  }


	  vector<Book> firstread(vector<Book> book)
	  {
		  ifstream MyReadFile("./input.txt", ios::in); \
			  ofstream os; os.open("./output.txt", ios::app);
		  string nameBook, surnameAuthor, izdanie;
		  int year = 0;
		  int kolizestvo = 0;
		  string myText;
		  while (getline(MyReadFile, myText))
		  {
			  if (myText == "") {
				  break;
			  }
			  int a = myText.find('/');
			  nameBook = myText.substr(0, a);
			  myText = myText.substr(a + 1, myText.size());

			  int b = myText.find("/");
			  surnameAuthor = myText.substr(0, b);
			  myText = myText.substr(b + 1, myText.size());

			  int d = myText.find("/");
			  izdanie = myText.substr(0, d);
			  myText = myText.substr(d + 1, myText.size());

			  int e = myText.find("/");
			  string skol = myText.substr(0, e);
			  year = stoi(skol);
			  myText = myText.substr(e + 1, myText.size());

			  int c = myText.find("/");
			  string kol = myText.substr(0, c);
			  kolizestvo = stoi(kol);
			  Bibl* emp = new Bibl(surnameAuthor, nameBook, izdanie, kolizestvo, year);
			  book.push_back(*emp);
		  }
		  return book;
	  }



	  template <typename T1, typename T2> void poisk(T1 s, T2 book)
	  {
		  s = book.at(0).kolizestvo;
		  int index = 0;
		  for (int i = 0; i < book.size(); i++) {
			  if (s > book.at(i).kolizestvo) {
				  s = book.at(i).kolizestvo;
				  index = i;
			  }

		  }cout << "Title: " << book.at(index).nameBook << "\nAuthor: " << book.at(index).surnameAutor << "\nPublisher: " << book.at(index).izdanie << "\nYear of publication: " << book.at(index).kolizestvo << "\nNumber of pages: " << book.at(index).year << endl;

	  }



	  Book add()
	  {
		  ofstream out;
		  out.open("./output.txt", ios::app);
		  if (!out) { cerr << "Unable to read output.txt" << endl; }
		  string nameBook, surnameAutor, izdanie;
		  int year, kolizestvo;
		  string pop;
		  cout << " ";
		  getline(cin, pop);
		  cout << "\nEnter the author of the book: ";
		  getline(cin, nameBook);
		  cout << "\nEnter the title of the book: ";
		  getline(cin, surnameAutor);
		  cout << "\nEnter publisher: ";
		  getline(cin, izdanie);
		  cout << "\nEnter the year of publication: ";
		  cin >> year;
		  cout << "\nEnter the number of pages: ";
		  cin >> kolizestvo;
		  Book prs = Book(nameBook, surnameAutor, izdanie, year, kolizestvo);
		  out.close();
		  ofstream rw, err; err.open("./output.txt", ios::app);
		  if (!err) { cerr << "output.txt not available" << endl; }
		  rw.open("./input.txt", ios::app);
		  if (!rw)
		  {
			  cout << "Unable to read input.txt" << endl; err << "Unable to read input.txt" << endl;
		  }

		  rw << nameBook << "/" << surnameAutor << "/" << izdanie << "/" << year << "/" << kolizestvo << endl;
		  rw.close();

		  err.close();
		  return prs;
	  }

	  void Write(vector<Book> pemp)
	  {
		  ofstream rw, err; err.open("./output.txt", ios::app);
		  rw.open("./input.txt", ios::out);
		  if (!err) { cerr << "output.txt has a problem;" << endl; }
		  if (!rw)
		  {
			  cout << "Unable to read input.txt";
			  err << "Unable to read input.txt" << endl;
		  }
		  for (int i = 0; i < pemp.size(); i++)
		  {
			  rw << pemp.at(i).nameBook << "/" << pemp.at(i).surnameAutor << "/" << pemp.at(i).izdanie << "/" << pemp.at(i).year << "/" << pemp.at(i).kolizestvo << endl;
		  }
		  rw.close(); err.close();
	  }


};

vector<Book> book;

ostream& operator >> (ostream& os, const Book& e)
{
	os << "Title: " << e.nameBook << "\nAuthor: " << e.surnameAutor << "\nPublisher: " << e.izdanie << "\nYear of publication: " << e.kolizestvo << "\nNumber of pages: " << e.year << endl;
	cout << "\n";
	return os;
}


int main()
{

	int iwannado;
	Bibl* emp = new Bibl();
	vector<Book> pemp;
	ofstream f;
	f.open("output.txt", ios::app);
	if (!f) { cerr << "Unable to read output.txt" << endl; }

	pemp = emp->firstread(pemp);
	/*ifstream MyReadFile("./input.txt", ios::in);
	string nameBook, surnameAuthor, izdanie;
	int year = 0;
	int kolizestvo = 0;
	string myText;
	while (getline(MyReadFile, myText))
	{
		if (myText == "") {
			break;
		}
		int a = myText.find('/');
		nameBook = myText.substr(0, a);
		myText = myText.substr(a + 1, myText.size());

		int b = myText.find("/");
		surnameAuthor = myText.substr(0, b);
		myText = myText.substr(b + 1, myText.size());

		int d = myText.find("/");
		izdanie = myText.substr(0, d);
		myText = myText.substr(d + 1, myText.size());

		int e = myText.find("/");
		string skol = myText.substr(0, e);
		year = stoi(skol);
		myText = myText.substr(e + 1, myText.size());

		int c = myText.find("/");
		string kol = myText.substr(0, c);
		kolizestvo = stoi(kol);
		Bibl* emp = new Bibl(surnameAuthor, nameBook, izdanie, kolizestvo, year );
		pemp.push_back(*emp);
	}*/





	while (true) {
		cout << "---Menu---" << endl;
		cout << "1. Adding a book " << endl;
		cout << "2. Editing the book" << endl;
		cout << "3. Deleting a book" << endl;
		cout << "4. Sorting in alphabetical order" << endl;
		cout << "5. Sorting in reverse alphabetical order" << endl;
		cout << "6. View all books" << endl;
		cout << "7. Search for the oldest book" << endl;
		cout << "8. Exit" << endl;
		cout << "Specify the menu item number: ";
		f << "---Menu---" << endl;
		f << "1. Adding a book " << endl;
		f << "2. Editing the book" << endl;
		f << "3. Deleting a book" << endl;
		f << "4. Sorting in alphabetical order" << endl;
		f << "5. Sorting in reverse alphabetical order" << endl;
		f << "6. View all books" << endl;
		f << "7. Search for the oldest book" << endl;
		f << "8. Exit" << endl;
		f << "Specify the menu item number: ";



		cin >> iwannado;
		cout << endl;
		f << iwannado << endl;
		cout << endl;
		switch (iwannado)
		{
		case 1:
		{
			Book books;
			pemp.push_back(emp->add());
			break;
		}
		case 2:
		{
			pemp = emp->edit(pemp);
			emp->Write(pemp);
			break;
		}
		case 3:
		{
			pemp = emp->purge(pemp);
			emp->Write(pemp);
			break;
		}
		case 4:
		{
			pemp = emp->sortup(pemp);
			break;
		}
		case 5:
		{
			pemp = emp->sortdown(pemp);
			break;
		}
		case 6:
		{
			for (int i = 0; i < pemp.size(); i++)
			{
				cout >> pemp.at(i);
				f << "model < " << pemp.at(i).nameBook << " / place < " << pemp.at(i).surnameAutor << " / type < " << pemp.at(i).izdanie << " / year < " << pemp.at(i).year << " / cost < " << pemp.at(i).kolizestvo << endl;
			}
			break;
		}
		case 7:
		{
			int year = 0;
			emp->poisk<int, vector<Book>>(year, pemp);
			break;
		}
		case 8:
		{

			emp->Write(pemp);
			f << "Exiting..." << endl << endl << endl << endl;
			f.close();
			exit(0);
			break;
		}
		}

	}
	f.close();
	return 0;
}