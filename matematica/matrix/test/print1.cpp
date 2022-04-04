#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
bool is_even(int n){
    return n % 2 == 0;
};
void print ( std::vector<std::vector<long int>>a){
    std::vector<int> distance;
    std::string n;
    for (int i=0; i< a.size();i++){
        std::vector<int> temp;
        for(int j=0; j< a[0].size();j++){
            n=std::to_string(a[j][i]);            
            temp.push_back(n.size());        
        }
        std::sort(temp.begin(), temp.end());
        distance.push_back(temp[temp.size()-1]);
        temp.clear();
        
    }
    for (int j=0; j<a.size();j++ ){
        std::cout <<"| ";
        for(int i=0;i<a[0].size();i++){
            n=std::to_string(a[j][i]);
                if(is_even(abs(n.size()-distance[i]))){
                    for(int q=0;q<(abs(n.size()-distance[i])/2);q++){
                        std::cout <<" ";
                    }   
                }
                else{
                    for(int q=0;q<((1+abs(n.size()-distance[i]))/2);q++){
                        std::cout <<" ";
                    } 
                }
            std::cout << a[j][i];
                for(int q=0; q<=(abs(n.size()-distance[i])/2);q++){
                    std::cout <<" ";
                }
        }
        std::cout <<"|"<< '\n';
    }
};


int main(){
    std::vector<std::vector<long int>> A;
    std::vector <long int> riga{124252,263435,233,4};
    std::vector <long int> riga1{1,3,265,4};
    A.push_back(riga);
    A.push_back(riga1);
    A.push_back(riga);
    A.push_back(riga1);

    print(A);
}