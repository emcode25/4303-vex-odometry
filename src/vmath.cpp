/*
*    "vmath.cpp" - A math namespace that defines 2D vectors.
*    Copyright (C) 2020  Evan Hess
*
*    This program is free software; you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation; either version 2 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License along
*    with this program; if not, write to the Free Software Foundation, Inc.,
*    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "vmath.h"
#include <math.h>
using namespace vmath;

Vector2D::Vector2D(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2D::~Vector2D()
{
	
}

float Vector2D::getAngle()
{
	return atan2f(y, x) * RadToDeg;
}

float Vector2D::getLength()
{
	return sqrtf(x * x + y * y);
}

float Vector2D::getX()
{
	return x;
}

float Vector2D::getY()
{
	return y;
}

void Vector2D::setAngle(float angle)
{
	angle *= DegToRad;
	float length = getLength();
	x = length * cosf(angle);
	y = length * sinf(angle);
}

void Vector2D::setLength(float length)
{
	float angle = getAngle();
	x = length * cosf(angle);
	y = length * sinf(angle);
}

void Vector2D::setX(float x)
{
	this->x = x;
}

void Vector2D::setY(float y)
{
	this->y = y;
}

Vector2D Vector2D::normalize()
{
	float length = getLength();
	return Vector2D(x / length, y / length);
}



//===========Vector Math==============\\

//Addition and subtraction
Vector2D Vector2D::operator+(Vector2D v)
{
	return Vector2D(this->x + v.getX(), this->y + v.getY());
}

Vector2D Vector2D::operator+(Vector2D* v)
{
	return Vector2D(this->x + v->getX(), this->y + v->getY());
}

Vector2D Vector2D::operator-(Vector2D v)
{
	return Vector2D(this->x - v.getX(), this->y - v.getY());
}

Vector2D Vector2D::operator-(Vector2D* v)
{
	return Vector2D(this->x - v->getX(), this->y - v->getY());
}

void Vector2D::operator+=(Vector2D v)
{
	this->x += v.getX();
	this->y += v.getY();
}

void Vector2D::operator+=(Vector2D* v)
{
	this->x += v->getX();
	this->y += v->getY();
}

void Vector2D::operator-=(Vector2D v)
{
	this->x -= v.getX();
	this->y -= v.getY();
}

void Vector2D::operator-=(Vector2D* v)
{
	this->x -= v->getX();
	this->y -= v->getY();
}

//Dot product/scalar "*"
Vector2D Vector2D::operator*(float f)
{
	return Vector2D(this->x * f, this->y * f);
}

Vector2D Vector2D::operator*(Vector2D v)
{
	return Vector2D(this->x * v.getX(), this->y * v.getY());
}

Vector2D Vector2D::operator*(Vector2D* v)
{
	return Vector2D(this->x * v->getX(), this->y * v->getY());
}

void Vector2D::operator*=(float f)
{
	this->x *= f;
	this->y *= f;
}

void Vector2D::operator*=(Vector2D v)
{
	this->x *= v.getX();
	this->y *= v.getY();
}

void Vector2D::operator*=(Vector2D* v)
{
	this->x *= v->getX();
	this->y *= v->getY();
}

//Division
Vector2D Vector2D::operator/(float f)
{
	return Vector2D(this->x / f, this->y / f);
}

Vector2D Vector2D::operator/(Vector2D v)
{
	return Vector2D(this->x / v.getX(), this->y / v.getY());
}

Vector2D Vector2D::operator/(Vector2D* v)
{
	return Vector2D(this->x / v->getX(), this->y / v->getY());
}

void Vector2D::operator/=(float f)
{
	this->x /= f;
	this->y /= f;
}

void Vector2D::operator/=(Vector2D v)
{
	this->x /= v.getX();
	this->y /= v.getY();
}

void Vector2D::operator/=(Vector2D* v)
{
	this->x /= v->getX();
	this->y /= v->getY();
}
