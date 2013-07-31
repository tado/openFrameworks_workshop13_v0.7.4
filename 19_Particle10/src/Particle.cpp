#include "Particle.h"

//コンストラクタ(初期化)
Particle::Particle(){
	setInitialCondition(0,0,0,0,0,0);
	damping = 0.01f;
}

//力(加速度)をリセット
void Particle::resetForce(){
    frc.set(0,0);
}

//力を加える
void Particle::addForce(float x, float y, float z){
    frc = frc + ofVec3f(x, y, z);
}

//抵抗力の計算
void Particle::addDampingForce(){
    frc = frc - vel * damping;
}

//初期状態を設定
void Particle::setInitialCondition(float px, float py, float pz, float vx, float vy, float vz){
    pos.set(px,py,pz);
	vel.set(vx,vy,vz);
}

//更新
void Particle::update(){
	vel = vel + frc;
	pos = pos + vel;
}

//描画
void Particle::draw(){
    ofCircle(pos.x, pos.y, 3);
}

