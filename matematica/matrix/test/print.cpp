#include <iostream>
#include <vector>
void print (std::vector<std::vector<long int>> a){
    for (int j = 0; j < a.size(); j++){     
        std::cout <<"| ";
        for (int i = 0; i < a[0].size(); i++){
            std::cout << a[j][i] << " "; 
        }
        std::cout <<"|"<< '\n';
    }
};
int main(){
    std::vector<std::vector<long int>> A;
    std::vector <long int> riga{1,2,3,4};
    A.push_back(riga);
    A.push_back(riga);
    A.push_back(riga);
    A.push_back(riga);

    print(A);
}