#include "Canvas.h"
#include <iostream>

Canvas::Canvas(int width, int height)
{
	this->Width = width;
	this->Height = height;
	this->matrix= new char* [height];
	for (int i = 0; i < height; ++i)
		matrix[i] = new char[width];

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			matrix[i][j] = ' ';
}

int Canvas::GetWidth()
{
	return this->Width;
}

int Canvas::GetHeight()
{
	return this->Height;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < Canvas::GetHeight(); i++)
		for (int j = 0; j < Canvas::GetWidth(); j++)
			if ((i - x) * (i - x) + (j - y) * (j - y) == ray*ray)
				this->matrix[i][j] = ch;
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < Canvas::GetHeight(); i++)
		for (int j = 0; j < Canvas::GetWidth(); j++)
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
				this->matrix[i][j] = ch;
}

void Canvas::DrawRect(int x1, int y1, int x2, int y2, char ch)
{
	for (int i = y1; i <= y2; i++) {
		this->matrix[x1][i] = ch;
		this->matrix[x2][i] = ch;
	}
	for (int i = x1; i <= x2; i++) {
		this->matrix[i][y1] = ch;
		this->matrix[i][y2] = ch;
	}
}

void Canvas::FillRect(int x1, int y1, int x2, int y2, char ch)
{
	for (int i = 0; i < Canvas::GetHeight(); i++)
		for (int j = 0; j < Canvas::GetWidth(); j++)
			if(i>=x1 && i<=x2 && j>=y1 && j<=y2)
				this->matrix[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch)
{
	this->matrix[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = x2 - x1;
	int dy = y2 - y1;

	int sx, sy;
	if (dx > 0) sx = 1;
	else sx = -1;
	if (dy > 0) sy = 1;
	else sy = -1;

	if (dx < 0)dx = dx * (-1);
	if (dy < 0)dy = dy * (-1);

	int err = dx - dy;

	while (true) {
		this->matrix[y1][x1] = ch;
		if (x1 == x2 && y1 == y2) break;
		int e2 = 2 * err;
		if (e2 > -dy) {
			err = err - dy;
			x1 = x1 + sx;
		}
		if (e2 < dx) {
			err = err + dx;
			y1 = y1 + sy;
		}
	}
}

void Canvas::Printt()
{
	for (int i = 0; i < Canvas::GetHeight(); i++) {
		for (int j = 0; j < Canvas::GetWidth(); j++)
			std::cout << this->matrix[i][j] << ' ';
		std::cout << '\n';
	}
}

void Canvas::Clear()
{
	for (int i = 1; i < Canvas::GetHeight(); i++) {
		for (int j = 1; j < Canvas::GetWidth(); j++)
			this->matrix[i][j] = ' ';
	}
}
