#include <iostream>
#include <cmath>

#define edge 10

using namespace std;
long double fact(int N){
    if (N < 0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N * fact(N - 1);
}
double get_x(){

    double x;

    while (true){
        cout << "Input x >>> ";
        cin >> x;
        if (cin.fail()){
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Incorrect x passed \n";
        }
        else{
            return x;
        }
    }
}
double get_cos(double x)
{

    double cos = 0;

    for (double n = 0; n < edge; ++n){
        cos += (pow(-1,n)*pow(x,2*n))/fact(2*n);
    }

    return cos;
}
int main(){
    double x = get_x();
    double cos = get_cos(x);

    cout << "Cos >>> " << cos;
}
