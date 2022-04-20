#include <iostream>
using namespace std;


int efficient(int n){
    if (n == 1){
        return 1;
    }
    return 2*efficient(n-1) + 1;
}


void hanoi(int N, char S, char I, char D){  //Base case 
    if (N==1){
        cout << "Move " << N << " from " << S << " ---->"<< D << endl;
    } //Drive N towards base case
    else {
        hanoi(N-1, S, D, I);
        cout << "Move " << N << " from " << S << " ---->"<< D << endl;
        hanoi (N-1, I, S, D);
    }
}

int main()
{
    int N;
    char S = 'S', I ='I', D='D';
    cout << "Give me the # of discs: " << endl;
    cin >> N;
    hanoi ( N, S, I, D);
    return 0;
}
