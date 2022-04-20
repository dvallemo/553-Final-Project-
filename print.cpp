
#include <iostream>
using namespace std;


void print(int *point_left, int *point_mid, int *point_right, int n){
        for(int j=0; j < n; j++){
            for(int i=0; i < 2*n - 2*(*(point_left +j)); i++){
                cout<<" ";
            }
            for(int i=0; i < 2*(*(point_left +j)); i++){
                cout<<"H";
            }
            cout<<"||";
            for(int i=0; i < 2*(*(point_left +j)); i++){
                cout<<"H";
            }
            for(int i=0; i < 2*n - 2*(*(point_left +j)); i++){
                cout<<" ";
            }
            //left layer printed
            for(int i=0; i < 2*n - 2*(*(point_mid +j)); i++){
                cout<<" ";
            }
            for(int i=0; i < 2*(*(point_mid +j)); i++){
                cout<<"H";
            }
            
            cout<<"||";
            
            for(int i=0; i < 2*(*(point_mid +j)); i++){
                cout<<"H";
            }
            for(int i=0; i < 2*n - 2*(*(point_mid +j)); i++){
                cout<<" ";
            }
            //middle layer printed
            for(int i=0; i < 2*n - 2*(*(point_right +j)); i++){
                cout<<" ";
            }
            for(int i=0; i < 2*(*(point_right +j)); i++){
                cout<<"H";
            }
            cout<<"||";
            for(int i=0; i < 2*(*(point_right +j)); i++){
                cout<<"H";
            }
            for(int i=0; i < 2*n - 2*(*(point_right +j)); i++){
                cout<<" ";
            }
            cout<<endl;
            ////////////////////////////////////////////
            for(int i=0; i < 2*n - 2*(*(point_left +j)); i++){
                cout<<" ";
            }
            for(int i=0; i < 2*(*(point_left +j)); i++){
                cout<<"H";
            }
            cout<<"||";
            for(int i=0; i < 2*(*(point_left +j)); i++){
                cout<<"H";
            }
            for(int i=0; i < 2*n - 2*(*(point_left +j)); i++){
                cout<<" ";
            }
            //left layer printed
            for(int i=0; i < 2*n - 2*(*(point_mid +j)); i++){
                cout<<" ";
            }
            for(int i=0; i < 2*(*(point_mid +j)); i++){
                cout<<"H";
            }
            
            cout<<"||";
            
            for(int i=0; i < 2*(*(point_mid +j)); i++){
                cout<<"H";
            }
            for(int i=0; i < 2*n - 2*(*(point_mid +j)); i++){
                cout<<" ";
            }
            //middle layer printed
            for(int i=0; i < 2*n - 2*(*(point_right +j)); i++){
                cout<<" ";
            }
            for(int i=0; i < 2*(*(point_right +j)); i++){
                cout<<"H";
            }
            cout<<"||";
            for(int i=0; i < 2*(*(point_right +j)); i++){
                cout<<"H";
            }
            for(int i=0; i < 2*n - 2*(*(point_right +j)); i++){
                cout<<" ";
            }
            cout<<endl;
            
    }
    for(int i=0; i<((12 * n)+6); i++){
        cout<<"=";
    }
}



int main()
{
    int n;
    cout<<"enter an int: ";
    cin>>n;
    int *point_left = new int[n];
    int *point_mid = new int[n];
    int *point_right = new int[n];
    
    for(int i=0; i<n; i++){
        *(point_left+i) = i+1;

    }
    for(int i=0; i<n; i++){
         *(point_mid+i) = 0;
    }
    for(int i=0; i<n; i++){
         *(point_right+i) = 0;
    }
    
    print(point_left, point_mid, point_right, n);
    
    
    delete[] point_left;
    delete[] point_mid;
    delete[] point_right;
    return 0;
}
