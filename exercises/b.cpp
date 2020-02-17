/*
   A country club, which currently charges $2,500 per year for membership, has announced it will increase its membership fees by 4% each year for the next six years. Write a program that uses a loop to display the projected rates for the next six years. 

*/

#include <iostream>
// #include <string>
// #include <vector>
// #include <iomanip>
// #include <ctime>
// #include <cstdlib>

using namespace std;

double projected_rates(const double ch, const double in)
{
    double membership[]{};

    for (int i{0}; i < 6; i++)
    {
        membership[i] += (ch * 1.04);
    }

    return membership;
}

int main()
{
    const double charge{2.5};
    const double increase_fees{0.04};

    double result{0};

    result = projected_rates(charge, increase_fees);

    for(int i{0}; i<6; i++){
        cout << result[i] << endl;
    }

    return 0;
}