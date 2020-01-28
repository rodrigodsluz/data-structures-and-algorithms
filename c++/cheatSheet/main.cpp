#include <iostream>

using namespace std;

int main(){
    int n1, n2, x;

    cout << "Enter the first value: " << endl;
    scanf("%d", &n1);

    cout << "Enter the second value: " << endl;
    scanf("%d", &n2);

    x = n1 + n2;
    cout << "The sum of these number is: " + x << endl;

    return  0;
}