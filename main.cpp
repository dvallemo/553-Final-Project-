#include <iostream>
using namespace std;

class Towers{
private:


public:
    int efficient(int n){
        if (n == 1){
            return 1;
        }
        return 2*efficient(n-1) + 1;
    }


    void hanoi(int N, char S, char I, char D){  //Base case
        if (N==1){
            std::cout << "Move " << N << " from " << S << " ---->"<< D << std::endl;
        } //Drive N towards base case
        else {
            hanoi(N-1, S, D, I);
            std::cout << "Move " << N << " from " << S << " ---->"<< D << std::endl;
            hanoi (N-1, I, S, D);
        }
    }

    void left_to_mid(int *point_left, int *point_mid, int n){
        int start = 0;
        int end = 0;
        int s_ring = 0;
        int b_ring = 0;
        for(int i=0; i<n; i++){
            if (*(point_left + i) != 0){
                start = i;
                s_ring = *(point_left + i);
                break;
            }
        }
        if (s_ring == 0){ //user attempts to move ring from empty peg
            cout<< "I'm sorry but there are no rings on this peg!"<<endl;
            cout<< "Please try again, don't worry you wont be infracted for extra moves."<<endl;
            goto wrong;
        }
        for(int i=0; i<n; i++){
            b_ring = *(point_mid + i);
            if (*(point_mid + i) != 0){
                break;
            }
            end = i;
        }

        if ((s_ring < b_ring) || (b_ring == 0)){ // ring being moved is smaller than ring it will be ontop of
            *(point_mid + end) = *(point_left + start);
            *(point_left + start) = 0;
            /******************************* Add to move counter *******************/
        }
        else{ // if ring being moved would be put on smaller ring
            cout<<"I'm sorry but you can't put a large ring on a small ring!"<<endl;
            cout<< "Please try again, don't worry you wont be infracted for extra moves."<<endl;
        }
        wrong:
        s_ring=0; //arbitrary code to make goto statment work
    }//end left to middle function
    void left_to_right(int *point_left, int *point_right, int n){
        int start = 0;
        int end = 0;
        int s_ring = 0;
        int b_ring = 0;
        for(int i=0; i<n; i++){
            if (*(point_left + i) != 0){
                start = i;
                s_ring = *(point_left + i);
                break;
            }
        }
        if (s_ring == 0){ //user attempts to move ring from empty peg
            cout<< "I'm sorry but there are no rings on this peg!"<<endl;
            cout<< "Please try again, don't worry you wont be infracted for extra moves."<<endl;
            goto wrong;
        }
        for(int i=0; i<n; i++){
            b_ring = *(point_right + i);
            if (*(point_right + i) != 0){
                break;
            }
            end = i;
        }

        if ((s_ring < b_ring) || (b_ring == 0)){ // ring being moved is smaller than ring it will be ontop of
            *(point_right + end) = *(point_left + start);
            *(point_left + start) = 0;
            /******************************* Add to move counter *******************/
        }
        else{ // if ring being moved would be put on smaller ring
            cout<<"I'm sorry but you can't put a large ring on a small ring!"<<endl;
            cout<< "Please try again, don't worry you wont be infracted for extra moves."<<endl;
        }
        wrong:
        s_ring=0; //arbitrary code to make goto statment work
    }//end left to right
    void mid_to_left(int *point_mid, int *point_left, int n){
        int start = 0;
        int end = 0;
        int s_ring = 0;
        int b_ring = 0;
        for(int i=0; i<n; i++){
            if (*(point_mid + i) != 0){
                start = i;
                s_ring = *(point_mid + i);
                break;
            }
        }
        if (s_ring == 0){ //user attempts to move ring from empty peg
            cout<< "I'm sorry but there are no rings on this peg!"<<endl;
            cout<< "Please try again, don't worry you wont be infracted for extra moves."<<endl;
            goto wrong;
        }
        for(int i=0; i<n; i++){
            b_ring = *(point_left + i);
            if (*(point_left + i) != 0){
                break;
            }
            end = i;
        }

        if ((s_ring < b_ring) || (b_ring == 0)){ // ring being moved is smaller than ring it will be ontop of
            *(point_left + end) = *(point_mid + start);
            *(point_mid + start) = 0;
            /******************************* Add to move counter *******************/
        }
        else{ // if ring being moved would be put on smaller ring
            cout<<"I'm sorry but you can't put a large ring on a small ring!"<<endl;
            cout<< "Please try again, don't worry you wont be infracted for extra moves."<<endl;
        }
        wrong:
        s_ring=0; //arbitrary code to make goto statment work
    }//end middle to left
    void mid_to_right(int *point_mid, int *point_right, int n){
        int start = 0;
        int end = 0;
        int s_ring = 0;
        int b_ring = 0;
        for(int i=0; i<n; i++){
            if (*(point_mid + i) != 0){
                start = i;
                s_ring = *(point_mid + i);
                break;
            }
        }
        if (s_ring == 0){ //user attempts to move ring from empty peg
            cout<< "I'm sorry but there are no rings on this peg!"<<endl;
            cout<< "Please try again, don't worry you wont be infracted for extra moves."<<endl;
            goto wrong;
        }
        for(int i=0; i<n; i++){
            b_ring = *(point_right + i);
            if (*(point_right + i) != 0){
                break;
            }
            end = i;
        }

        if ((s_ring < b_ring) || (b_ring == 0)){ // ring being moved is smaller than ring it will be ontop of
            *(point_right + end) = *(point_mid + start);
            *(point_mid + start) = 0;
            /******************************* Add to move counter *******************/
        }
        else{ // if ring being moved would be put on smaller ring
            cout<<"I'm sorry but you can't put a large ring on a small ring!"<<endl;
            cout<< "Please try again, don't worry you wont be infracted for extra moves."<<endl;
        }
        wrong:
        s_ring=0; //arbitrary code to make goto statment work
    }//end middle to right
    void right_to_left(int *point_right, int *point_left, int n){
        int start = 0;
        int end = 0;
        int s_ring = 0;
        int b_ring = 0;
        for(int i=0; i<n; i++){
            if (*(point_right + i) != 0){
                start = i;
                s_ring = *(point_right + i);
                break;
            }
        }
        if (s_ring == 0){ //user attempts to move ring from empty peg
            cout<< "I'm sorry but there are no rings on this peg!"<<endl;
            cout<< "Please try again, don't worry you wont be infracted for extra moves."<<endl;
            goto wrong;
        }
        for(int i=0; i<n; i++){
            b_ring = *(point_left + i);
            if (*(point_left + i) != 0){
                break;
            }
            end = i;
        }

        if ((s_ring < b_ring) || (b_ring == 0)){ // ring being moved is smaller than ring it will be ontop of
            *(point_left + end) = *(point_right + start);
            *(point_right + start) = 0;
            /******************************* Add to move counter *******************/
        }
        else{ // if ring being moved would be put on smaller ring
            cout<<"I'm sorry but you can't put a large ring on a small ring!"<<endl;
            cout<< "Please try again, don't worry you wont be infracted for extra moves."<<endl;
        }
        wrong:
        s_ring=0; //arbitrary code to make goto statment work
    }//end right to left
    void right_to_mid(int *point_right, int *point_mid, int n){
        int start = 0;
        int end = 0;
        int s_ring = 0;
        int b_ring = 0;
        for(int i=0; i<n; i++){
            if (*(point_right + i) != 0){
                start = i;
                s_ring = *(point_right + i);
                break;
            }
        }
        if (s_ring == 0){ //user attempts to move ring from empty peg
            cout<< "I'm sorry but there are no rings on this peg!"<<endl;
            cout<< "Please try again, don't worry you wont be infracted for extra moves."<<endl;
            goto wrong;
        }
        for(int i=0; i<n; i++){
            b_ring = *(point_mid + i);
            if (*(point_mid + i) != 0){
                break;
            }
            end = i;
        }

        if ((s_ring < b_ring) || (b_ring == 0)){ // ring being moved is smaller than ring it will be ontop of
            *(point_mid + end) = *(point_right + start);
            *(point_right + start) = 0;
            /******************************* Add to move counter *******************/
        }
        else{ // if ring being moved would be put on smaller ring
            cout<<"I'm sorry but you can't put a large ring on a small ring!"<<endl;
            cout<< "Please try again, don't worry you wont be infracted for extra moves."<<endl;
        }
        wrong:
        s_ring=0; //arbitrary code to make goto statment work
    }//end right to middle
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

    bool check_win(int *point_right, int n){
        for (int i=0; i<n; i++){
            if (*(point_right + i) != i + 1){ //if the ring does not match where it should in height return false
                return false;
            }
        }
        return true; //all of the ring's places have been checked and are in the right places
    }


};




int main() {

    Towers tower;
    int choice, n, input, right;

    std::cout << "The Towers of Hanoi" << std::endl;
    std::cout << "--------------------" << std::endl;

    while (1) {
        std::cout << "Press 1 to start " << std::endl;
        std::cout << "Press 2 to view statistics" << std::endl;
        std::cout << "Press 3 to exit the game" << std::endl;
        std::cin >> choice;


        switch (choice) {
            case 1: {
                std::cout << "starting game" << std::endl;
                cout << "How many disks" << endl;
                cin >> n;
                int *point_left = new int[n];
                int *point_mid = new int[n];
                int *point_right = new int[n];
                for (int i = 0; i < n; i++) {
                    *(point_left + i) = i + 1;

                }
                for (int i = 0; i < n; i++) {
                    *(point_mid + i) = 0;
                }
                for (int i = 0; i < n; i++) {
                    *(point_right + i) = 0;
                }

                
                tower.print(point_left, point_mid, point_right, n);

                tower.left_to_mid(point_left, point_mid, n);          //L to  M

                tower.print(point_left, point_mid, point_right, n);

                tower.left_to_right(point_left, point_right, n);        //L to R

                tower.print(point_left, point_mid, point_right, n);

                tower.mid_to_right(point_mid, point_right, n);         //M to R

                tower.print(point_left, point_mid, point_right, n);

                tower.left_to_mid(point_left, point_mid, n);           //L to M

                tower.print(point_left, point_mid, point_right, n);

                tower.right_to_left(point_right, point_left, n);         //R to L

                tower.print(point_left, point_mid, point_right, n);

                tower.right_to_mid(point_right, point_mid, n);          //R to M

                tower.print(point_left, point_mid, point_right, n);

                tower.left_to_mid(point_left, point_mid, n);         //L to M

                tower.print(point_left, point_mid, point_right, n);

                tower.mid_to_left(point_mid, point_left, n);            //M to L

                tower.print(point_left, point_mid, point_right, n);



                delete[] point_left;
                delete[] point_mid;
                delete[] point_right;

                break;
            }

            case 2: {
                std::cout << "statistics:" << std::endl;
                cout << "Efficient" << endl;
                cout << "Number of disks:" << endl;
                cin >> n;
                tower.efficient(n);

                break;
            }
            case 3: {
                std::cout << "Quiting...." << std::endl;
                exit(1);
            }


                return 0;
        }
    }
}
