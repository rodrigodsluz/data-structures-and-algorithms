#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int greaterXY(int x, int y, int z){
    int gre = 0;

    gre =  (x + y + abs(x - y)) / 2;

    return gre;
}

int main(){
    int a = 0, b = 0, c = 0, greater = 0;

    cin >> a >> b >> c;

    greater = greaterXY(a, b, c);


    cout << greater << " eh o maior" << endl; 


    return  0;
}

/*

    URI Online Judge | 1013
The Greatest
Adapted by Neilor Tonin, URI  Brazil

Timelimit: 1
Make a program that reads 3 integer values and present the greatest one followed by the message "eh o maior". Use the following formula:



Input
The input file contains 3 integer values.

Output
Print the greatest of these three values followed by a space and the message “eh o maior”.

Input Samples	Output Samples
7 14 106

106 eh o maior

217 14 6

217 eh o maior

*/