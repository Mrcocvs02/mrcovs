#include <iostream>
#include <vector>
#include <cmath>

class vettore {
    public:
    double x;
    double y;
    vettore operator+(vettore b){
        return{(x+b.x),(y+b.y)};
    };
    vettore operator-(vettore b){
        return{(x-b.x),(y-b.y)};
    };
    vettore operator*(double b){
        return {(x*b),(y*b)};
    };
    double norm (){
        return{sqrt(x*x+y*y)};
    };
    void print(){
        std::cout << x <<", "<< y<<'\n';
    }
};
class boid{
    public:
    vettore position;
    vettore velocity;
};
class flock{
    double d=0.1;
    double s=2;
    double a=0.2;
    double c=2; 
        public:
    std::vector <boid> boids;
    void structure (int n){
        for(double i=0;i<n;i++){
            vettore x{(1.3+2.45*i),(3+i)};
            vettore v{(2+2*i),(5+3.2*i)};
            boid c{x,v};
            boids.push_back(c);
            std::cout<< "Bird number "<<i+1<<" position "<<'\n';
            c.position.print();
            boids.push_back(c);
            std::cout<< "Bird number " <<i+1<<" velocity "<<'\n';
            c.velocity.print();
        }
    
    };

    vettore center_of_mass (){
        double sum_x=0;
        double sum_y=0;
        for (int i=0; i< boids.size(); i++){
            sum_x = boids[i].position.x + sum_x;
            sum_y = boids[i].position.y + sum_y ; 
        };
        return {(sum_x/boids.size()),(sum_y/boids.size())};
    };

    vettore medium_velocity (){
        double sum_vx = 0;
        double sum_vy = 0;
        for (int i=0; i< boids.size(); i++){
            sum_vx = sum_vy + boids[i].velocity.x;
            sum_vy = sum_vy + boids[i].velocity.y;
        };
        std::cout << sum_vx<<" "<<sum_vy<<'\n';
        return {(sum_vx/boids.size()),(sum_vy/boids.size())}; 
    };
    vettore v_separation_i (boid boid_j, int j){
        vettore v {0,0};
        for (int i=0; i< boids.size() && i!=j; i++){
            if((boids[i].position-boid_j.position).norm() < d){
                v=v-((boids[i].position - boid_j.position)*s);
                //(boids[i].position - boid_j.position).print();
            }
        }
        return v;
    };

    vettore v_allignement1_i (boid boid_j){
        //((medium_velocity()-boid_i.velocity)*a).print();
        //medium_velocity().print();
        return {(medium_velocity()-boid_j.velocity)*a};

    };

    vettore v_cohesion_i(boid boid_j){
        return {(center_of_mass()-boid_j.position)*c};
    };  

    void simulation (double t) {
        double i=0;
        while(i<t){
            for (int j=0; j< boids.size();j++){
                boids[j].velocity = (boids[j].velocity + v_allignement1_i(boids[j]) + v_cohesion_i(boids[j])+ v_separation_i(boids[j], j));
                boids[j].position = (boids[j].velocity*0.1)+boids[j].position;
                 
                 //boids[j].velocity.print();
            };
            //std::cout <<"center of mass:";
            //center_of_mass().print();
            //std::cout <<"medium velocity:";
            //medium_velocity().print();
            i+=0.2;
        }
    }
};
int main(){
    int n;
    double t;
    std::cout << "insert the number of birds you want in the floxk"<<'\n';
    std::cin >>n;
    std::cout << "insert for how many seconds you want the simulation to run (the simulation updates every 0.2 seconds)"<<'\n';
    std::cin >>t;
    flock q;
    q.structure(n);
    q.simulation(t);
}