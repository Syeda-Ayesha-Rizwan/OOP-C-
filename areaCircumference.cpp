#include <iostream>
using namespace std;
class circle{
   private:
   float radius;
public:
circle(float r){
    radius = r;

}
void circlearea(){
   float area = 3.14 * radius * radius;
    cout<<"area of circle is: "<< area << endl;

}
void circumference(){
  float  circumference = 2 * 3.14 * radius;
    cout<<"circumference of circle is: "<< circumference << endl;
}
};
int main(){
    circle c1(5.8);
    c1.circlearea();
    c1.circumference();
    return 0;
}