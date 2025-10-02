#include <iostream>
using namespace std;
class Rectangle{
    private:
    float length;
    float width;
public:
    Rectangle(float l , float w){
    length = l;
    width = w;

}
void area (){
    float area = length * width;
    cout << "area of rectangle is: " << area << endl;
    
}
void perimeter(){
    float perimeter = 2 * (length + width);
    cout << "perimeter of rectangle is: " << perimeter << endl;
}
};
int main(){
    Rectangle r1(2.3 , 4.5);
    r1.area();
    r1.perimeter();
    return 0;
}