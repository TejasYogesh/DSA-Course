// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Book{
    public: int id;
    public: string name;
    public: string author;
    Book(int i, string n, string a){
        this->id = i;
        this->name = n;
        this->author = a;
    }
    void display(){
        cout<<"Book ID is"<<id<<"Book name is"<<name<<endl;
    }
};
class Library{
    vector<Book>booklist;
    int incrementValue = 100;
    
    public: void addBook(string n, string a){
        booklist.push_back(Book(incrementValue++, n, a));
        cout<<"Book is added"<<endl;
    }
    public: void deleteBook(int id){
        for(int i = 0; i < booklist.size(); i++){
            if(booklist[i].id == id){
                booklist.erase(booklist.begin() + i);
                cout<<"deleted"<<endl;
            }
        }
    }
    public: void updateBook(int id, string n, string a){
        for(int i = 0; i < booklist.size(); i++){
            if(booklist[i].id == id){
                booklist[i].name = n;
                booklist[i].author = a;
            }
        }
        cout<<"Updated"<<endl;
    }
    public: void showBooks(){
        for(auto &b: booklist){
            cout<<b.id<<b.name<<b.author<<endl;
        }
    }
 
};
int main() {
    Library l1;
    l1.addBook("C++ fundamentals", "Tejas");
    l1.showBooks();
    l1.updateBook(100, "C basics", "Yogesh");
    l1.showBooks();
    l1.deleteBook(100);
    

    return 0;
}