#include "include/ui.h"
#include "include/raymath.h"

#define SLIDER_RADIUS 6
#define SLIDER_THICK 3

Slider NewSlider(float initValue, int posX, int posY, float length) {
	return (Slider){Clamp(initValue, 0.0f, 1.0f), (Vector2){posX, posY}, length, false};
}

void DrawSlider(Slider slider) {
	Vector2 sliderEndPos = (Vector2){slider.pos.x + slider.length, slider.pos.y};
	DrawLineEx(slider.pos, sliderEndPos, SLIDER_THICK, WHITE);
	DrawCircleV(GetSliderPos(slider), SLIDER_RADIUS, RAYWHITE);
}

Vector2 GetSliderPos(Slider slider) {
	return (Vector2){slider.pos.x + slider.value * slider.length, slider.pos.y};
}

void UpdateSlider(Slider *slider) {
	Vector2 mousePos = GetMousePosition();

	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) 
		&& Vector2Distance(mousePos, GetSliderPos(*slider)) <= SLIDER_RADIUS) {
		slider->isDragging = true;
		slider->dragStartPos = mousePos;
		slider->dragStartValue = slider->value;
	}

	if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
		slider->isDragging = false;
	}

	if (slider->isDragging) {
		float clampedMouseX = Clamp(mousePos.x, slider->pos.x, slider->pos.x + slider->length);
		float delta = (clampedMouseX - slider->dragStartPos.x) / slider->length;
		slider->value = slider->dragStartValue + delta;
	}
}
