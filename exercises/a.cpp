/*

    The program should display two random numbers that are to be added, such as

  247
 +129
 ----

The program should wait for the student to enter the answer. If the answer is correct, message of congratulations should be printed. If the answer is incorrect, a message should be printed showing the correct answer.

*/

#include <iostream>
#include <ctime>
#include <cstdlib>
//#include <iomanip>

using namespace std;

void add(int num1, int num2){
    int user_total{0}, computer_total{0};
    
    int seed = time(0);
    srand(seed);

    num1 = 1 + rand() % 100;
    num2 = 1 + rand() % 100;

    cout << " " << num1 << endl << "+" << num2 << endl << "----" << endl;

    computer_total = num1 + num2;

    cout << "Enter the asnwer:" << endl;
    cin >> user_total;

    if(user_total == computer_total){
        cout << "Congratulations! It's right!!!" << endl;
    }else{
        cout << "Sorry, the answer is incorrect!!!" << endl << "The right answer is " << computer_total << endl;
    }

    
}

int main(){
    int rand_n1{0}, rand_n2{0};

    add(rand_n1, rand_n2);

    return 0;
}