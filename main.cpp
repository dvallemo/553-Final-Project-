#include <iostream>
using namespace std;


int Last_moves_used = 0;
int Last_rings_chosen = 0;

class Towers{
private:

    int moves=0;

    int *point_left;
    int *point_mid ;
    int *point_right;

public:
    int n;
    Towers(){
    moves = 0;
    }
    Towers(int N){
        n = N;
        point_right = new int[n];
        point_mid = new int[n];
        point_left = new int[n];

        for(int i = 0; i < n; i++){
            *(point_left + i) = i + 1;
        }
        for(int i = 0; i < n; i++){
            *(point_mid + i) = 0;
        }
        for(int i = 0; i < n; i++){
            *(point_right + i) = 0;
        }
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

    static bool check_win(int *point_right, int n){
        for (int i=0; i<n; i++){
            if (*(point_right + i) != i + 1){ //if the ring does not match where it should in height return false
                return false;
            }
        }
        Last_rings_chosen = n;
        return true; //all of the ring's places have been checked and are in the right places
    }

    void user_input_moves() {
        char starting_peg, ending_peg;
        print(point_left, point_mid, point_right, n);
        while (true) {

            wrong_start://move to here if invalid input for start peg
            cout << "What peg is the ring you want to move on?" << endl;
            cout << "Enter 1 for left peg, 2 for middle peg, or 3 for right peg: ";
            cin >> starting_peg;
            if(starting_peg != '1' && starting_peg != '2' && starting_peg != '3') { //check if start peg input is valid
                cout << endl << "I'm sorry, your input is invalid. Please try again" << endl;
                goto wrong_start;
            }
           
            wrong_end://move to here if invalid input for end peg
            cout << "What peg would you like to move your ring to?" << endl;
            cout << "Enter 1 for left peg, 2 for middle peg, or 3 for right peg: ";
            cin >> ending_peg;
            if (ending_peg != '1' && ending_peg != '2' && ending_peg != '3') { //check if end peg input is valid
                cout << endl << "I'm sorry, your input is invalid. Please try again" << endl;
                goto wrong_end;
            }
            if (starting_peg == ending_peg) { //check if start and end are equal
                cout << "It appears that you moved the ring to it's starting peg." << endl;
                cout << "Please try again." << endl;
                goto wrong_start;
            }
            // start moving ring
            if (starting_peg == '1' && ending_peg == '2') { // left to mid
                left_to_mid(point_left, point_mid, n);
            } else if (starting_peg == '1' && ending_peg == '3') { // left to right
                left_to_right(point_left, point_right, n);
            } else if (starting_peg == '2' && ending_peg == '1') {  // mid to left
                mid_to_left(point_mid, point_left, n);
            } else if (starting_peg == '2' && ending_peg == '3') {  // mid to right
                mid_to_right(point_mid, point_right, n);
            } else if (starting_peg == '3' && ending_peg == '1') { // right to left
                right_to_left(point_right, point_left, n);
            } else if (starting_peg == '3' && ending_peg == '2') { // right to mid
                right_to_mid(point_right, point_mid, n);
            }

            if (check_win(point_right, n)) { // check if last move caused the player to win, if so break out of while loop
                cout << "Congradulations, you compleated the puzzle!" << endl;
                break;
            }
        }
    }

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
        int s_ring = 0; //presumably small ring
        int b_ring = 0; //presumably big ring
        for(int i=0; i<n; i++){   //look for index of top ring available
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
        for(int i=0; i<n; i++){   //look for top large ring available
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
            moves++;
            cout << "# of moves: "<<moves << endl;
            print(point_left, point_mid, point_right, n);
        }
        else{ // if ring being moved would be put on smaller ring
            cout<<"I'm sorry but you can't put a large ring on a small ring!"<<endl;
            cout<< "Please try again, don't worry you wont be infracted for extra moves."<<endl;
        }
        wrong:
        s_ring=s_ring; //arbitrary code to make goto statment work
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
            moves++;
            cout <<"# of moves: "<< moves << endl;
            print(point_left, point_mid, point_right, n);
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
            moves++;
            cout <<"# of moves: "<< moves << endl;
            print(point_left, point_mid, point_right, n);
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
            moves++;
            cout << "# of moves: "<<moves << endl;
            print(point_left, point_mid, point_right, n);
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
            moves++;
            cout <<"# of moves: "<< moves << endl;
            print(point_left, point_mid, point_right, n);
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
            moves++;
            cout << "# of moves: "<<moves << endl;
            print(point_left, point_mid, point_right, n);
        }
        else{ // if ring being moved would be put on smaller ring
            cout<<"I'm sorry but you can't put a large ring on a small ring!"<<endl;
            cout<< "Please try again, don't worry you wont be infracted for extra moves."<<endl;
        }
        wrong:
        s_ring=0; //arbitrary code to make goto statment work
    }//end right to middle

    float efficiency_percent(){
        float tot;
        tot = (float(efficient(Last_rings_chosen)) / float(Last_moves_used))*100;
        return tot;
    }
    


    ~Towers(){
        delete[] point_left;
        delete[] point_mid;
        delete[] point_right;
        Last_moves_used = moves;
        moves = 0;
    }


};




int main() {

    Towers tower;
    int choice, n, N;
    char S = 'S', I = 'I', D = 'D';

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
                Towers T(n);

                T.user_input_moves();
                
               /* int *point_left = new int[n];
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
                }*/



                /*tower.print(point_left, point_mid, point_right, n);
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
                tower.print(point_left, point_mid, point_right, n);*/





                break;
            }

            case 2: {
                int choice1;
                std::cout << "statistics:" << std::endl;
                while(1){
                    cout << "Press 1 to view most efficient method algorithm" << endl;
                    cout << "Press 2 to view recent efficency with respect to algorithm of last game" << endl;
                    cout << "Press 3 to return to main menu" << endl;
                    cin >> choice1;


                    switch(choice1){
                        case 1: {
                            cout << "Efficiency..." << endl;
                            cout << "Number of disks:" << endl;
                            cin >> N;
                            tower.efficient(n);
                            tower.hanoi(N, S, I, D);
                            break;
                        }
                        case 2: {
                            if(Last_moves_used == 0){ //player has not plyed yet
                                cout<<"I'm sorry but you will have to play this game first in order to unlock this statistic."<<endl;
                                cout<<"Please enjoy the game!"<<endl; 
                            }
                            else{ //player has played
                                cout<<"Last game you chose to play with "<<Last_rings_chosen<<" rings and used "<<Last_moves_used<<" moves to complete the puzzle."<<endl;
                                cout<<"The most efficient number of moves was "<<tower.efficient(n)<<", therefore your percent efficiency was "<<tower.efficiency_percent()<<"%"<<endl;
                            }
                            
                            break;
                        }
                        case 3: {
                            cout << "Returning to main menu" << endl;
                            break;
                        }

                    }
                    break;
                }


                break;
            }
            case 3: {
                std::cout << "Quiting...." << std::endl;
                exit(1);
            }

        }
    }
    return 0;
}
