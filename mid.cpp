 /*Createaclassnamed’Rectangle’withtwodatamembers-lengthandbreadthandamethod
 tocalculatetheareawhichis’length*breadth’.Theclasshasthreeconstructorswhichare:1
Havingnoparameter-valuesofbothlengthandbreadthareassignedzero. 2-Havingtwo
 numbersasparameters-thetwonumbersareassignedaslengthandbreadthrespectively. 3-Havingonenumberasparameter-bothlengthandbreadthareassignedthatnumber.Now,
 createobjectsof the’Rectangle’classhavingnone,oneandtwoparametersandprint their
 areas*/
 /**/
 /*#include <iostream>
 using namespace std;
 class Rectangle{
    private :
        float length ;
        float breadth ;
    public :
        void setlength(float length){
                this -> length= length;
        }
        float getlength(){
            return length;
        }
        void setbreadth(float breadth){
                this -> breadth= breadth;
        }
        float getbreadth(){
            return breadth;
        }
         void calculateArea(){
            float area = length * breadth ;
            //return area ; 
            cout<< " area : "<< area <<endl;
         }
         Rectangle(){
            length = 0 ;
            breadth = 0 ;

         }
         Rectangle(float length , float breadth){
          this->  length = length ;
          this->  breadth = breadth ;
            
         }
         Rectangle(float length  ){
            this->length = length;
            this->length = breadth;
         }
 };
 int main(){
    Rectangle r1;
    Rectangle r2(22.2 , 33.4);
    Rectangle R3(11.1);
    
    r1.calculateArea();*/
     /*Createaclassnamed’Rectangle’withtwodatamembers-lengthandbreadthandamethod
 tocalculatetheareawhichis’length*breadth’.Theclasshasthreeconstructorswhichare:1
Havingnoparameter-valuesofbothlengthandbreadthareassignedzero. 2-Havingtwo
 numbersasparameters-thetwonumbersareassignedaslengthandbreadthrespectively. 3-Havingonenumberasparameter-bothlengthandbreadthareassignedthatnumber.Now,
 createobjectsof the’Rectangle’classhavingnone,oneandtwoparametersandprint their
 areas*/
 #include <iostream>
 using namespace std;
 class Rectangle{
    private :
        float length ;
        float breadth ;
    public :
        void setlength(float length){
                this -> length= length;
        }
        float getlength(){
            return length;
        }
        void setbreadth(float breadth){
                this -> breadth= breadth;
        }
        float getbreadth(){
            return breadth;
        }
         void calculateArea(){
            float area = length * breadth ;
            //return area ; 
            cout<< " area : "<< area <<endl;
         }
         Rectangle(){
            length = 0 ;
            breadth = 0 ;

         }
         Rectangle(float length , float breadth){
          this->  length = length ;
          this->  breadth = breadth ;
            
         }
         Rectangle(float value  ){
            this-> length = value;
            this-> breadth = value;
         }
 };
 int main(){
    Rectangle r1;
    Rectangle r2(22.2 , 33.4);
    Rectangle r3(11.1);
    
    r1.calculateArea();
    r2.calculateArea();
    r3.calculateArea();
 
 }