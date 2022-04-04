#include <iostream>
#include <vector>
void print (std::vector<std::vector<long double>> a){
    for (int j = 0; j < a.size(); j++){     
        std::cout <<"|";
        for (int i = 0; i < a[0].size(); i++){
            std::cout << a[j][i] << " "; 
        }
        std::cout <<"|";
    }
};
int main(){
    std::vector<std::vector<long double>> A;
    A[0] = {1,4,3,5};
    A[1] = {1,4,3,5};
    A[2] = {1,4,3,5};
    A[3] = {1,4,3,5};
//    print(A);
std::cout << A[0][2];
}