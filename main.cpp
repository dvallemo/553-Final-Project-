#include <iostream>

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


};




int main() {

    int choice, value;
    std::cout << "The Towers of Hanoi" << std::endl;
    std::cout << "--------------------" << std::endl;

    while (1) {
        std::cout << "Press 1 to start " << std::endl;
        std::cout << "Press 2 to view statistics" << std::endl;
        std::cout << "Press 3 to exit the game" << std::endl;
        std::cin >> choice;


        switch (choice) {
            case 1:
                std::cout << "starting game" << std::endl;

                break;

            case 2:
                std::cout << "statistics:" << std::endl;
                break;
            case 3:
                std::cout << "Quiting...." << std::endl;
                exit(1);


                return 0;
        }
    }
}
