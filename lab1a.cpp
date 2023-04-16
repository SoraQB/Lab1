#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Type {
    ART, TECH
};


class Book {
public:
    Book(const string& _author, const string& _title, const Type& _type) : m_author(_author), m_title(_title), m_type(_type) {

    }

    Type getType() const {
        return m_type;
    }

    ~Book() {}

private:
    const string m_author;
    const string m_title;
    const Type m_type;
};

class Library {
public:
    void addBook(const string& _author, const string& _title, const Type& _type) {
        if (_author.empty() || _title.empty())
        {
            cout << "Book must have a non-empty author and title" << endl;
        }
        else
        {
            m_books.push_back(Book(_author, _title, _type));
        }
    }

    void printCountsByType(const vector<Book>& library) {
        int artCount = countByType(library, Type::ART);
        int techCount = countByType(library, Type::TECH);
        cout << "Count by type (without using switch):" << endl;
        cout << "Art: " << artCount << endl;
        cout << "Tech: " << techCount << endl;
    }

    void printCountsByTypeWithSwitch(const vector<Book>& library) {
        int artCount = 0, techCount = 0;
        for (const Book& book : library) {
            switch (book.getType()) {
            case Type::ART:
                ++artCount;
                break;
            case Type::TECH:
                ++techCount;
                break;
            }
        }
        cout << "Count by type (using switch):" << endl;
        cout << "Art: " << artCount << endl;
        cout << "Tech: " << techCount << endl;
    }

    const vector<Book>& getBooks() const {
        return m_books;
    }

private:
    vector<Book> m_books;

    int countByType(const vector<Book>& library, Type type) {
        int count = 0;
        for (const Book& book : library) {
            if (book.getType() == type) {
                ++count;
            }
        }
        return count;
    }
};

int main() {
    Library library;

    try {
        library.addBook("", "Empty Author Book", Type::ART);
        library.addBook("Gogol", "Dead Souls", Type::ART);
        library.addBook("Tolstoy", "War and Peace", Type::ART);
        library.addBook("Kernighan, Ritchie", "The C Programming Language", Type::TECH);
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    library.printCountsByType(library.getBooks());
    library.printCountsByTypeWithSwitch(library.getBooks());

    return 0;
}
