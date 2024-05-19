#include <bits/stdc++.h>

using namespace std;

class Book
{
public:
    int bookId;
    string title;
    string author;
    string category;
    string publicationDate;
};

class GenerateSlip
{
private:
    int perDayFine = 10;
    int defaultTime = 10;
    int timePeriod = 0;

public:
    GenerateSlip(int time) : timePeriod(time) {}

    string getSlip()
    {
        if (timePeriod <= defaultTime)
            return "Returned Successfully";
        else
            return "Due Fine = " + to_string(perDayFine * (timePeriod - defaultTime));
    }
};

class RackItem
{
public:
    int rackNo;
    bool isAvailable;
    Book book;

    RackItem(int bookId, string title, string author, string category, string publicationDate, int rackNo, bool isAvailable)
    {
        book.bookId = bookId;
        book.title = title;
        book.author = author;
        book.category = category;
        book.publicationDate = publicationDate;
        this->rackNo = rackNo;
        this->isAvailable = isAvailable;
    }

    RackItem() {}
};

class Member
{
public:
    string name;
    int memberId;
    vector<RackItem> issuedBooks;

    Member(string name, int memberId)
    {
        this->name = name;
        this->memberId = memberId;
    }
};

class BookManagement
{
public:
    vector<RackItem> catalog;
    vector<pair<pair<RackItem, int>, int>> memberRecords;

    void addBook(const RackItem &book)
    {
        catalog.push_back(book);
        cout << "Book with ID " << book.book.bookId << " added to catalog." << endl;
    }

    void removeBook(const RackItem &book)
    {
        auto it = remove_if(catalog.begin(), catalog.end(), [&](RackItem &b)
                            { return b.book.bookId == book.book.bookId; });
        if (it != catalog.end())
        {
            catalog.erase(it, catalog.end());
            cout << "Book with ID " << book.book.bookId << " removed from catalog." << endl;
        }
        else
        {
            cout << "Book with ID " << book.book.bookId << " not found in catalog." << endl;
        }
    }

    RackItem *searchBook(const string &title)
    {
        for (auto &book : catalog)
        {
            if (book.book.title == title)
            {
                cout << "Book found: " << book.book.title << " by " << book.book.author << endl;
                return &book;
            }
        }
        cout << "Book with title " << title << " not found in catalog." << endl;
        return nullptr;
    }

    bool allocateBook(RackItem &book, Member &member, int checkOutDate)
    {
        int allottedBooks = count_if(memberRecords.begin(), memberRecords.end(),
                                     [&](const auto &record)
                                     { return record.second == member.memberId; });

        if (allottedBooks >= 5)
        {
            cout << "Cannot allocate more than 5 books to a single member." << endl;
            return false;
        }

        for (auto &catalogBook : catalog)
        {
            if (catalogBook.book.bookId == book.book.bookId && catalogBook.isAvailable)
            {
                catalogBook.isAvailable = false;
                memberRecords.push_back({{catalogBook, checkOutDate}, member.memberId});
                member.issuedBooks.push_back(catalogBook);
                cout << "Book allocated -- Successfully." << endl;
                return true;
            }
        }

        cout << "Book is not available." << endl;
        return false;
    }

    void returnBook(RackItem &book, Member &member, int returnDate)
    {
        auto it = find_if(memberRecords.begin(), memberRecords.end(),
                          [&](const auto &record)
                          { return record.first.first.book.bookId == book.book.bookId && record.second == member.memberId; });

        if (it != memberRecords.end())
        {
            int checkOutDate = it->first.second;
            GenerateSlip generateSlip(returnDate - checkOutDate);
            cout << "Book returned -- " << generateSlip.getSlip() << endl;

            for (auto &catalogBook : catalog)
            {
                if (catalogBook.book.bookId == book.book.bookId)
                {
                    catalogBook.isAvailable = true;
                    break;
                }
            }

            auto issuedBookIt = remove_if(member.issuedBooks.begin(), member.issuedBooks.end(),
                                          [&](RackItem &b)
                                          { return b.book.bookId == book.book.bookId; });
            member.issuedBooks.erase(issuedBookIt, member.issuedBooks.end());
            memberRecords.erase(it);
        }
        else
        {
            cout << "Book not found in member's issued records." << endl;
        }
    }
};

class UserManagement
{
private:
    vector<Member> users;

public:
    void addUser(string name, int memberId)
    {
        users.emplace_back(name, memberId);
        cout << "User with ID " << memberId << " added." << endl;
    }

    void removeUser(string name, int memberId)
    {
        auto it = remove_if(users.begin(), users.end(), [&](Member &m)
                            { return m.memberId == memberId; });
        if (it != users.end())
        {
            users.erase(it, users.end());
            cout << "User with ID " << memberId << " removed." << endl;
        }
        else
        {
            cout << "User with ID " << memberId << " not found." << endl;
        }
    }

    Member *getMember(int memberId)
    {
        for (auto &user : users)
        {
            if (user.memberId == memberId)
            {
                return &user;
            }
        }
        return nullptr;
    }
};

class LibraryManagement
{
private:
    BookManagement bookManagement;
    UserManagement userManagement;

public:
    LibraryManagement() : bookManagement(), userManagement() {}

    UserManagement &getUserManagement()
    {
        return userManagement;
    }

    BookManagement &getBookManagement()
    {
        return bookManagement;
    }
};

int main()
{
    LibraryManagement libraryManagement;
    libraryManagement.getUserManagement().addUser("Ratan", 678);
    libraryManagement.getBookManagement().addBook(RackItem(1, "One Arranged Murder", "Chetan Bhagat", "Fantasy", "2016", 98, true));

    Member *member = libraryManagement.getUserManagement().getMember(678);
    if (member)
    {
        RackItem *book = libraryManagement.getBookManagement().searchBook("One Arranged Murder");
        if (book)
        {
            libraryManagement.getBookManagement().allocateBook(*book, *member, 45);
            libraryManagement.getBookManagement().returnBook(*book, *member, 89);
        }
    }
    else
    {
        cout << "Member not found." << endl;
    }

    return 0;
}
