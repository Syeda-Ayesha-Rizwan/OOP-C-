#include <iostream>
using namespace std;

int main() {
    float arr[5];        
    float *ptr = arr;    
    float sum = 0;       
    float average = 0;   

    cout << "Enter 5 numbers:\n";
    for (int i = 0; i < 5; i++) {
        cin >> *(ptr + i);  
    }

  
    for (int i = 0; i < 5; i++) {
        sum = sum + *(ptr + i);   
    }

    
    average = sum / 5;

  
    cout << "Average = " << average << endl;

    return 0;
}



/*#include <iostream>
using namespace std;
int main(){

   float arr[5] ;
   for (int i = 0 ; i < 5 ; i++){
    cout<<"enter numbers: "<<endl;
    cin>> *(ptr + 1);

   }
    average sum += *(ptr + i);
   float *ptr;
   //ptr = &average;

   for(int i = 0 ; i < 5; i++){
    
 int sum = arr[i +1 ];

int average = sum / 5;




    // (arr[i] +  i)/ 5 ;

}
cout<<"average : "<< average << endl;
}*/