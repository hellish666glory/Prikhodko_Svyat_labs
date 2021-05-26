#include <iostream>
#include <cmath>

#define g 9.80665
#define Pi 3.1416

using namespace std;
double get_height()
{
    double height;

    while (true){
        cout << "Enter the height: ";
        cin >> height;
        if (cin.fail() || height < 0){
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Incorrect height passed \n";
        }
        else{
            return height;
        }
    }
}
double get_length()
{
    double length;

    while (true){
        cout << "Enter the length: ";
        cin >> length;
        if (cin.fail() || length < 0){
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Incorrect length passed \n";
        }
        else{
            return length;
        }
    }
}
double get_alpha(double height, double length){
    return atan (4*height/length) * 180 / Pi;
}
double get_velocity(double height, double length){
    return sqrt (((g*((length*length) +  (16*height*height))/(8*height))));
}



int main(){
    double height = get_height();
    double length = get_length();
    double alpha = get_alpha(height, length);
    double velocity = get_velocity(height, length);

    cout << "Starting velocity equals >>> " << velocity;
    cout << "\nAlpha equals >>> " << alpha;
}
