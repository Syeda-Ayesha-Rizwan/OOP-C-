#include <iostream>
using namespace std;
class Media {
    public :
    virtual void play(){
        cout<< "base class"<<endl;

    }
};
class Audio : public  Media {
public:
 void play () override {
    cout<< "audio playing "<<endl; 
 }
};
class Music : public  Media {
    public:
    void play() override{
        cout<< "music playing"<<endl;
    }
};
int main (){
    Media* a;
    int choice ;
    cout << "enter choice " << endl;
    cin >> choice;
    switch(choice){
        case 1 :
        a = new Audio();

    
    case 2 :
        a = new Music();
        
    }

a-> play();
delete a;
}