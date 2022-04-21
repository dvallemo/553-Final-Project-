

#include <iostream>
using namespace std;

void left_to_mid(int *point_left, int *point_mid, int n){
    int start = 0;
    int end = 0;
    for(int i=0; i<n; i++){
        if (*(point_left + i) != 0){
            start = i;
            break;
        }
    }
    for(int i=0; i<n; i++){
        if (*(point_mid + i) != 0){
            break;
        }
        end = i;
    }
    *(point_mid + end) = *(point_left + start);
    *(point_left + start) = 0;
}//end left to middle function

void left_to_right(int *point_left, int *point_right, int n){
    int start = 0;
    int end = 0;
    for(int i=0; i<n; i++){
        if (*(point_left + i) != 0){
            start = i;
            break;
        }
    }
    for(int i=0; i<n; i++){
        if (*(point_right + i) != 0){
            break;
        }
        end = i;
    }
    *(point_right + end) = *(point_left + start);
    *(point_left + start) = 0;
}//end left to right

void mid_to_left(int *point_mid, int *point_left, int n){
    int start = 0;
    int end = 0;
    for(int i=0; i<n; i++){
        if (*(point_mid + i) != 0){
            start = i;
            break;
        }
    }
    for(int i=0; i<n; i++){
        if (*(point_left + i) != 0){
            break;
        }
        end = i;
    }
    *(point_left + end) = *(point_mid + start);
    *(point_mid + start) = 0;
}//end middle to left

void mid_to_right(int *point_mid, int *point_right, int n){
    int start = 0;
    int end = 0;
    for(int i=0; i<n; i++){
        if (*(point_mid + i) != 0){
            start = i;
            break;
        }
    }
    for(int i=0; i<n; i++){
        if (*(point_right + i) != 0){
            break;
        }
        end = i;
    }
    *(point_right + end) = *(point_mid + start);
    *(point_mid + start) = 0;
}//end middle to right

void right_to_left(int *point_right, int *point_left, int n){
    int start = 0;
    int end = 0;
    for(int i=0; i<n; i++){
        if (*(point_right + i) != 0){
            start = i;
            break;
        }
    }
    for(int i=0; i<n; i++){
        if (*(point_left + i) != 0){
            break;
        }
        end = i;
    }
    *(point_left + end) = *(point_right + start);
    *(point_right + start) = 0;
}


void right_to_mid(int *point_right, int *point_mid, int n){
    int start = 0;
    int end = 0;
    for(int i=0; i<n; i++){
        if (*(point_right + i) != 0){
            start = i;
            break;
        }
    }
    for(int i=0; i<n; i++){
        if (*(point_mid + i) != 0){
            break;
        }
        end = i;
    }
    *(point_mid + end) = *(point_right + start);
    *(point_right + start) = 0;
}


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
            
            
    }
    for(int i=0; i<((12 * n)+6); i++){
        cout<<"=";
    }
    cout <<endl;
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
    
    left_to_mid(point_left, point_mid, n);          //L to  M
    
    print(point_left, point_mid, point_right, n);
    
    left_to_right(point_left, point_right, n);        //L to R
    
    print(point_left, point_mid, point_right, n);   
    
    mid_to_right(point_mid, point_right, n);         //M to R
    
    print(point_left, point_mid, point_right, n);
    
    left_to_mid(point_left, point_mid, n);           //L to M
    
    print(point_left, point_mid, point_right, n);
    
    right_to_left(point_right, point_left, n);         //R to L
    
    print(point_left, point_mid, point_right, n);
    
    right_to_mid(point_right, point_mid, n);          //R to M
    
    print(point_left, point_mid, point_right, n);
    
    left_to_mid(point_left, point_mid, n);         //L to M
    
    print(point_left, point_mid, point_right, n);
    
    mid_to_left(point_mid, point_left, n);            //M to L
    
    print(point_left, point_mid, point_right, n);
    
    
    
    delete[] point_left;
    delete[] point_mid;
    delete[] point_right;
    return 0;
}
