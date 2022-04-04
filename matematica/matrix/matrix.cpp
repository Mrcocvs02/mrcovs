#include <iostream>
#include <vector>

class matrix{
    public:
        long double insert_value(void){
            long double a;
            std::cin >>a;
                while(std::cin.fail()) {
                    std::cout << "Wrong type of input, try again" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(256,'\n');
                std::cin >> a;
               }    
            return a;
        };
        std::vector<std::vector<long double>> structure (long int n, long int m){
            std::vector<std::vector<long double>> matrix;
                for(int i = 0; i < n; i++){
                    std::vector <long double> line;
                        for(int i = 0; i < m; i++){
                            long double a = insert_value();
                            line.push_back(a);
                        }
                matrix.push_back(line);
                }
            return matrix;
        }
        std::vector<std::vector<long double>> multiplication (std::vector<std::vector<long double>>A, std::vector<std::vector<long double>>B){
            std::vector<std::vector<long double>> result; 
            std::vector<long double> result_line;           
                if (A[0].size()!=B.size()){
                    std::cout <<"The multiplication is not possible"<<'\n';
                };
                for (int k = 0; k <A.size(); k++){   
                    for (int j=0; j < B[0].size(); j++){
                        long double pruduct = 0; 
                        for(int i = 0; i < B.size(); i++){
                            pruduct += (A[k][i]*B[i][j]);
                        }
                        result_line.push_back(pruduct);     
                    }
                    result.push_back(result_line);
                }
            return result;
        }
};

void print (std::vector<std::vector<long double>> a){
    for (int j = 0; j < a.size(); j++){     
        std::cout <<"|";
        for (int i = 0; i < a[0].size(); i++){
            std::cout << a[j][i] << " "; 
        }
        std::cout <<"|"<< '\n';
    }
};


int main() {
    long int nA;
    long int nB;
    long int mA;
    long int mB;
    std::cin >> nA >> mA >> nB >> mB;
    matrix mtx;
    std::vector<std::vector<long double>> A = mtx.structure(nA,mA);
    std::vector<std::vector<long double>> B = mtx.structure(nB,mB);
    std::vector<std::vector<long double>> C = mtx.multiplication(A,B);
    std::cout << C[0][0]<<'\n';
    print (A);
}

