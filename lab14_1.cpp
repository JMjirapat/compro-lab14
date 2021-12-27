#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double src[], int N, double dest[]){
    dest[2] = 1;
    dest[4] = src[0];
    dest[5] = src[0];
    double sum = 0;
    for(int i = 0; i < N; i++){
        if(src[i] > dest[4])
            dest[4] = src[i];
        if(src[i] < dest[5])
            dest[5] = src[i];
        sum += src[i];
        dest[0] += src[i];
        dest[2] *= src[i];
        dest[3] += 1/src[i];
    }
    dest[0] = dest[0]/N;
    for(int i = 0; i < N; i++){
        dest[1] += pow((src[i]-dest[0]),2);
    }
    dest[1] = sqrt(dest[1]/N);
    dest[2] = pow((dest[2]),1.0/N);
    dest[3] = N/dest[3];
}
