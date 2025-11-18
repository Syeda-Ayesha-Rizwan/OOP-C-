#include <iostream>
using namespace std;
class Shape{
    public:
   virtual void draw(){
cout<<"drawing shape"<<endl;

   }
};
   class Circle : public Shape{
    public:
    void draw() override {
cout<<"drawing circle"<<endl;

   }

};
class Rectangle : public Shape{
    public:
    void draw() override {
        cout << "drawing rectangle" << endl;
    }
};

int main(){
    Shape* a;
   int choice ;
   cout << "enter choice "<< endl;
   cin>> choice;
   switch(choice){
    //case 1 :
   // a = new Draw(); break;

    case 1: 
    a = new Circle();
break;
 case 2:
 a= new Rectangle();
   }
a->draw();1

}
