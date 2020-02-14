#include <iostream>

using namespace std;

void favoriteNumber(int x)
{
    cout << "Amazing!! That's my favorite number too!" << endl;
    cout << "No really!!, " << x << " is my favorite number!" << endl;
}

int main()
{
    int number = 0;

    cout << "Enter your favorite number between 1 and 100" << endl;

    while (number < 1 || number > 100)
    {
        cin >> number;
        system("clear");
        cout << "Enter your favorite number between 1 and 100" << endl;
    }

    favoriteNumber(number);

    return 0;
}