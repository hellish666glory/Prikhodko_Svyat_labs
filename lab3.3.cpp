#include <iostream>
#include <cstdlib>
#include <ctime>

#define N 5

using namespace std;

void trans(double A[N][N]){
    int i,j;
    double s;
    for(i=0; i < N; i++)
        for(j=i+1; j < N; j++){
            s=A[i][j];
            A[i][j]=A[j][i];
            A[j][i]=s;}
}
void input(double A[N][N]){
    int i,j;
    for(i=0; i < N; i++)
        for(j=0; j < N; j++)
            A[i][j]=rand()%100;
}

void print(double A[N][N]){
    int i,j;
    for(i=0; i < N; i++){
        for(j=0; j < N; j++)
            cout << A[i][j] << " ";
            cout << endl;}
}
int main(){
    double A[N][N];
    cout << "Initial matrix:\n";
    input(A);
    print(A);
    cout << "After transformation:\n";
    trans(A);
    print(A);
    return 0;
}
