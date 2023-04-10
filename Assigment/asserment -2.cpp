#include <iostream>
#include <string>
using namespace std;

// Publication class
class Publication {
protected:
    string title;
    float price;
public:
    void getData() {
        cout << "Enter the title: ";
        getline(cin, title);
        cout << "Enter the price: ";
        cin >> price;
        cin.ignore();
    }
    void putData() {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

// Book class derived from Publication
class Book : public Publication {
private:
    int pageCount;
public:
    void getData() {
        Publication::getData();
        cout << "Enter the page count: ";
        cin >> pageCount;
        cin.ignore();
    }
    void putData() {
        Publication::putData();
        cout << "Page count: " << pageCount << endl;
    }
};

// Tape class derived from Publication
class Tape : public Publication {
private:
    float playingTime;
public:
    void getData() {
        Publication::getData();
        cout << "Enter the playing time in minutes: ";
        cin >> playingTime;
        cin.ignore();
    }
    void putData() {
        Publication::putData();
        cout << "Playing time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    Book b;
    Tape t;

    // Get data from the user
    cout << "Enter book details:" << endl;
    b.getData();
    cout << endl << "Enter tape details:" << endl;
    t.getData();

    // Display the data
    cout << endl << "Book details:" << endl;
    b.putData();
    cout << endl << "Tape details:" << endl;
    t.putData();

    return 0;
}


