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
        std::cout<< "Bird number position "<<i+1<<'\n';
        c.position.print();
        boids.push_back(c);
        std::cout<< "Bird number velocity "<<i+1<<'\n';
        c.velocity.print();
    }
    
    }

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
            sum_vx+= boids[i].velocity.x;
            sum_vy+= boids[i].velocity.y;
        };
        return {(sum_vx/boids.size()),(sum_vy/boids.size())}; 
    };
    vettore v_separation_i (boid boid_i){
        vettore v {0,0};
        for (int i=0; i< boids.size(); i++){
            if((boids[i].position-boid_i.position).norm() < d){
                v=v-((boids[i].position - boid_i.position)*s);
            }
        }
        return v;
    };

    vettore v_allignement1_i (boid boid_i){
        return {(medium_velocity()-boid_i.velocity)*a};
    };

    vettore v_cohesion_i(boid boid_i){
        return {(center_of_mass()-boid_i.position)*c};
    };  

    void simulation (double t) {
        double i=0;
        while(i<t){
            for (int j=0; j< boids.size();j++){
                boids[j].position = (boids[j].velocity*0.1)+boids[j].position;
                boids[j].velocity = (boids[j].velocity + v_allignement1_i(boids[j]) + v_cohesion_i(boids[j])+ v_separation_i(boids[j])); 
            };
            std::cout <<"center of mass:";
            center_of_mass().print();
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