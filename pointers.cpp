/*#include <iostream>
using namespace std;
int main (){*/
   /* int arr[]={2 , 3 , 4 , 5 , 6} ;
    int* ptr = &arr[5];
    cout<< " &arr:  "<< &arr << endl;
    cout<< " arr: "<< arr << endl;
    cout<< " *ptr :  "<< *ptr << endl;
    cout<< " &arr  + 1: "<< &arr+1  << endl;
    cout<< "*ptr +1 : "<< *ptr +1  << endl;
    cout<< " *(arr[]) : "<< &(ptr[0]) << endl; 
    cout<< " arr[1]: "<< arr[1] << endl;
   // cout<< " *ptr[1]: "<< *ptr[1] << endl;
     cout<< " *arr: "<< *arr << endl;
    
cout << arr[5] << endl;
cout << *(arr + 1) << endl; 

cout << 2[arr] << endl; */
#include <iostream>
using namespace std;

int main() {
    int a = 10;       // Normal variable
    int *p = &a;      // Pointer to int
    int **q = &p;     // Pointer to pointer

    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;

    cout << "Value of p (address of a): " << p << endl;
    cout << "Value pointed by p (*p): " << *p << endl;

    cout << "Value of q (address of p): " << q << endl;
    cout << "Value pointed by q (*q): " << *q << endl;
    cout << "Value pointed by *q (**q): " << **q << endl;



    
    return 0;
}

