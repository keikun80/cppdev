#include <iostream>
#include <cctype> 

using namespace std;
int main()  
{   
    char ch ;
    cout << "Enter character: "; 
    cin.get(ch);
    while (true)
    { 
        if (isupper(ch))
            cout.put(tolower(ch)); 
        else if(islower(ch))
            cout.put(toupper(ch)); 
        else 
            cout << ch << endl;
        cin.get(ch);
    }
    return 0;
}