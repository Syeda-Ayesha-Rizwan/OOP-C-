/* Consider a scenario in which you have to construct a transcript of semesters that you have
 studied so far. Make a class TranscriptSemester1 and furthermore till the semester you are
 currently studying in and provide the Semester GPA of each semester and Commulative GPA
 of all the semesters BY overriding relevant functions and displaying the information*/
 #include <iostream>
 using namespace std;
 class Transcript{
    private :
    string name ;
    int semester ;
    string courses[5];
    float gpa;
    public:
    Transcript(){
        name = "unknown";
        semester = 0;
        for (int i = 0 ; i < 5 ;i++){
            courses[i]="unknown";
        }
        gpa = 0;


    }
    Transcript(string name , int semester , string courses[5] , float gpa){
        this -> name = name ;
        this-> semester = semester;
       for(int i = 0; i< 5 ; i++ ){
       this-> courses[i]=courses[i];
       }
        this-> gpa = gpa;
    }
    void display(){
        cout<<"name : "<<name<<endl;
        cout<<"sem : "<< semester<<endl;
        for (int i = 0 ; i < 5; i++ ){
            cout<<"courses : "<< i +1 <<endl;
        }
        cout<<"gpa : "<<gpa <<endl;
    
 }
 };
int main(){
    string mycourses[5] = {"oop" , "dld" , "ds" , "math" ," SE "};
    Transcript t1(  "ayesha " , 2, mycourses , 3.6);
    t1.display();
}