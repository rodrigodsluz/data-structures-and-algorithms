#include <iostream>

using namespace std;

int area_square_feet(int wi, int we){
    
    return (wi * we);
}

int main(){
    int room_width{0}, room_length{0}, area{0};

    cout << "Enter the width of the room: ";
    cin >> room_width;

    cout << "Enter the weight of the room: ";
    cin >> room_length;

    area = area_square_feet(room_length, room_width);

    cout << "The area is: " << area << " square feet" << endl;

    cout << sizeof(area) << endl; 

    return 0;
}