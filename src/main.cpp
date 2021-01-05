#include <iostream>
#include <array>

using namespace std; 

int main() 
{    
    int line=0;  
    cout << "몇 줄 할겁니까? ";
    cin >> line; 

    for (int i=0; i < line; i++)
    {  
        for (int j=i; j < line-1; j++) 
        {
            cout  << "-"; 
        } 
        for (int k=line-i ; k <line+1 ; k++)
        {
            cout  << "*";
        } 
        cout << endl;
    }
    return 0;
}