#include <iostream>
#include <cmath>

#define edge 10

using namespace std;
double get_x(){

    double x;

    while (true){
        cout << "Input x >>> ";
        cin >> x;
        if (cin.fail() || abs(x) >= 1){
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Incorrect x passed \n";
        }
        else{
            return x;
        }
    }
}
double get_sum(double x)
{

    double sum = 0;

    for (double n = 0; n < edge; ++n){
        sum += (n+1)*pow(x,n);
    }

    return sum;
}
int main(){
    double x = get_x();
    double sum = get_sum(x);

    cout << "Sum >>> " << sum;
}
