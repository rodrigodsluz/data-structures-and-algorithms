#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double A = 0, B = 0, C = 0, average = 0;

    cin >> fixed >> setprecision(1) >> A >> B >> C;
    if(!(A < 0.0 || A>10.0 || B < 0.0 || B > 10.0 || C < 0.0 || C > 10.0)){
        average = (((A * 2) + (B * 3) + (C * 5)) / 10);
        cout << fixed << setprecision(1) << "MEDIA = " << average << endl;
    }else{
        cout << "Each grade must be from zero to ten!" << endl;
    }

    return  0;
}



/*
    URI Online Judge | 1006
Average 2
Adapted by Neilor Tonin, URI  Brazil

Timelimit: 1
Read three values (variables A, B and C), which are the three student's grades. Then, calculate the average, considering that grade A has weight 2, grade B has weight 3 and the grade C has weight 5. Consider that each grade can go from 0 to 10.0, always with one decimal place.

Input
The input file contains 3 values of floating points with one digit after the decimal point.

Output
Print MEDIA(average in Portuguese) according to the following example, with a blank space before and after the equal signal.

Input Samples	Output Samples
5.0
6.0
7.0

MEDIA = 6.3

5.0
10.0
10.0

MEDIA = 9.0

10.0
10.0
5.0

MEDIA = 7.5

*/