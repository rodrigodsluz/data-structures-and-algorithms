#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;



int main(){
    int X = 0;
    float Y = 0, average = 0;

    cin >> fixed >> setprecision(1) >> X >> Y;

    average = (X/Y);

    cout << fixed << setprecision(3) << average << " km/l" << endl;

    return 0;
}


/*
URI Online Judge | 1014
Consumption
Adapted by Neilor Tonin, URI  Brazil

Timelimit: 1
Calculate a car's average consumption being provided the total distance traveled (in Km) and the spent fuel total (in liters).

Input
The input file contains two values: one integer value X representing the total distance (in Km) and the second one is a floating point number Y  representing the spent fuel total, with a digit after the decimal point.

Output
Present a value that represents the average consumption of a car with 3 digits after the decimal point, followed by the message "km/l".

Input Sample	Output Sample
500
35.0

14.286 km/l

2254
124.4

18.119 km/l

4554
464.6

9.802 km/l

*/