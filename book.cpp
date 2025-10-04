#include <iostream>
using namespace std;
class Book{
    public:
    string title ;
    string author;

    void setbook(string title , string author){
    this->title = title;
    this->author = author;
}
    void display(){
    cout<<"book title: "<< title<< endl;
    cout<< "author : " << author<< endl;

}
    void getbook(string title , string authur){
        cin>> title ;
        cin>> author;

    }
};
int main (){
   Book b1;
   Book b2;
   Book b3;


b1.setbook("halim " , "nimra ahmed ");
b1.display();
//b2.getbook();
b2.setbook("namal" , "nimra ahmed");
b2.display();
//b3.getbook();
b3.setbook("jkp" , "nimra");
b3.display();

}
