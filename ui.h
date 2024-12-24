#ifndef UI_H
#define UI_H

// Make sure this file is in the same folder as raylib.h
#include "raylib.h"

typedef struct Slider {
	float value; // between 0 and 1
	Vector2 pos;
	float length;
	bool isDragging;
	Vector2 dragStartPos;
	float dragStartValue;
} Slider;

Slider NewSlider(float initValue, int posX, int posY, float length);
void DrawSlider(Slider slider);
Vector2 GetSliderPos(Slider slider);
void UpdateSlider(Slider *slider);

#endif // !UI_H
