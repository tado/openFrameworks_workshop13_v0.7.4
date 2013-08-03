#include "MoveCircle.h"

void MoveCircle::draw() {
	ofFill();
	ofSetColor(31,127,255);
    ofCircle(currentPos.x, currentPos.y, 20, 20);
}

void MoveCircle::update() {
	pct += 0.01f;
	if (pct > 1) {
		pct = 0;
	}
	currentPos = interpolateByPct(pct);
}

ofPoint MoveCircle::interpolateByPct(float _pct){
	ofPoint pos;
    _pct = powf(_pct, shaper);
	pos = (1.0 - _pct) * startPos + (_pct) * endPos;
	return pos;
}