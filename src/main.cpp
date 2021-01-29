#include <iostream>
#include <fstream>

using namespace std; 

int main()  
{ 
    char automobile[50];
    int year;
    double a_price;
    double d_price;

    ofstream outFile;
    outFile.open("carinfo.txt");

    cout << "자동차 메이커와 차종을 입력하세요 :";
    cin.getline(automobile, 50);
    cout << "연식을 입력하세요 : ";
    cin >> year;
    cout << "구입가를 입력하세요 : ";
    cin >> a_price; 
    d_price = a_price * 0.913;

    cout << fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    cout << "차종 :" << automobile <<"\n";
    cout << "연식 :" << year <<"\n";  
    cout << "구매가 : " << a_price << "\n";
    cout << "햔재가 : " << d_price << "\n";
    
    outFile << fixed;
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile << "차종 :" << automobile <<"\n";
    outFile << "연식 :" << year <<"\n";  
    outFile << "구매가 : " << a_price << "\n";
    outFile << "햔재가 : " << d_price << "\n";
    return 0;
}