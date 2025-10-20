#include <iostream>
using namespace std;
class Rectangle {
    public:
    int width ;
    int height;
    Rectangle(){
        width = 0 ;
        height = 0;
    }
    Rectangle(int width , int height ){
        this -> width = width ;
        this -> height = height ;

    }
    void display(){
        cout << "width : " << width << endl;
        cout << "height : " << height << endl;
    }
};
    int main (){
        Rectangle r1(22 , 33 );
        Rectangle r2;
        r1.display();
        r2.display();
        Rectangle r3(44 , 55 );
        r3.display();
    }


