#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    string employeeName;
    double sellerSalary = 0, soldTotal = 0;

    getline(cin, employeeName); 

    cin >> sellerSalary >> soldTotal;

    sellerSalary += 0.15 * soldTotal;

    cout << fixed << setprecision(2) << "TOTAL = R$ " << sellerSalary << endl;

    return  0;
}

/*
    URI Online Judge | 1009
Salary with Bonus
Adapted by Neilor Tonin, URI  Brazil

Timelimit: 1
Make a program that reads a seller's name, his/her fixed salary and the sale's total made by himself/herself in the month (in money). Considering that this seller receives 15% over all products sold, write the final salary (total) of this seller at the end of the month , with two decimal places.

- Don’t forget to print the line's end after the result, otherwise you will receive “Presentation Error”.

- Don’t forget the blank spaces.

Input
The input file contains a text (employee's first name), and two double precision values, that are the seller's salary and the total value sold by him/her.

Output
Print the seller's total salary, according to the given example.

Input Samples	Output Samples
JOAO
500.00
1230.30

TOTAL = R$ 684.54

PEDRO
700.00
0.00

TOTAL = R$ 700.00

MANGOJATA
1700.00
1230.50

TOTAL = R$ 1884.58

*/