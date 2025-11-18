/*In the Distance class, create an overloaded * operator so that two distances can be multiplied
together. Make it a friend function so that you can use such expressions as Wdist1 = 7.5 * dist2;*/
#include <iostream>
using namespace std;
class Distance2;
 class Distance {
 private :
 int dis1 ;
 public : 
Distance () {
    dis1 = 7.5;
} 
friend int frifunc(Distance , Distance2 ); 
 };
 class Distance2{
 private : 
  int dis2 ;
 public :
  Distance2(){
    dis2 = 10;
  }
 friend int frifunc (Distance , Distance2 ); 
 };
 int frifunc ( Distance a , Distance2 b) {
 return ( a.dis1 * b.dis2 );
 }
 int main () { 
 Distance aa;
 Distance2 bb;
 cout << frifunc (aa , bb)  ; 
 }
