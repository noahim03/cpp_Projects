//Noah Im ID:923109389

#include <iostream>
#include "Angle.h"
using namespace std;

Angle::Angle(){
    theta = 30;
}

void Angle::set(int t){
    if(t < -60) {
        theta = -60;
    } 
    else if(t > 120) {
        theta = 120;
    } 
    else {
        theta = t;
    }
}

 int Angle::get(){
        return theta;
 }

 void Angle::change(int dt){
        set(theta + dt);
 }

 void Angle::print(){
        cout << "angle: " << theta << endl;
 }



