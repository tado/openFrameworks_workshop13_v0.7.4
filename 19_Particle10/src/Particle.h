#pragma once

#include "ofMain.h"

class Particle {
public:
	
    ofVec3f pos; //位置
    ofVec3f vel; //速度
    ofVec3f frc; //力(加速度)
    float damping; //摩擦力
    
    Particle();
    virtual ~Particle(){};
    void resetForce();
    void addForce(float x, float y, float z);
    void addDampingForce();
    void setInitialCondition(float px, float py, float pz, float vx, float vy, float vz);
    void update();
    void draw();
    
protected:
private:
};