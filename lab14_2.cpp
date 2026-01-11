#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double A[N][N]){
    for(int i = 0; i < N; i++){
        cout << "Row " << i + 1 << ": ";
        for(int j = 0; j < N; j++){
            cin >> A[i][j];
        }
    }
}

void findLocalMax(double A[N][N], bool B[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            // ขอบ matrix = false
            if(i == 0 || i == N-1 || j == 0 || j == N-1){
                B[i][j] = false;
            }
            else{
                B[i][j] =
                    A[i][j] >= A[i-1][j] &&   // บน
                    A[i][j] >= A[i+1][j] &&   // ล่าง
                    A[i][j] >= A[i][j-1] &&   // ซ้าย
                    A[i][j] >= A[i][j+1];     // ขวา
            }
        }
    }
}

void showMatrix(bool B[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

//Do not modify source code above this line 
