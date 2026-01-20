#include <iostream>
using namespace std;

int main() {
    int hours, minutes, seconds;

    cout << "Enter total seconds: ";
    cin >> seconds;

    hours = seconds / 3600;          
    minutes = (seconds % 3600) / 60; 
    seconds = seconds % 60;          

    cout << "HH:MM:SS = " << hours << " : " << minutes << " : " << seconds << endl;

    cout << "Enter hours: ";
    cin >> hours;

    cout << "Enter minutes: ";
    cin >> minutes;

    cout << "Enter seconds: ";
    cin >> seconds;

    int totalSeconds = hours * 3600 + minutes * 60 + seconds;
    cout << "Total seconds: " << totalSeconds << endl;
}