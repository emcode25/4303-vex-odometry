/*
*    "vmap.h" - A namespace that defines a virtual VEX field.
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

#include "vmap.h"
using namespace vmath;
using namespace vmap;

Map::Map(Robot* base, float x, float y, const float w, const float h)
{
  this->base = base;
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
}

float Map::angleToPoint(float x, float y)
{
  Vector2D v(x - this->x, y - this->y);
  return v.getAngle();
}

float Map::lengthToPoint(float x, float y)
{
  Vector2D v(x - this->x, y - this->y);
  return v.getLength();
}

Vector2D Map::vectorToPoint(float x, float y)
{
  return Vector2D(x - this->x, y - this->y);
}

void Map::goToPoint(float x, float y, uint32_t timeout)
{
  Vector2D v = vectorToPoint(x, y);
  float angle = v.getAngle();
  float length = v.getLength();
  vex::turnType t = (angle < 180) ? vex::turnType::right : vex::turnType::left;

  base->turnForT(t, angle, vex::rotationUnits::deg, timeout);
  base->driveForT(vex::directionType::fwd, length,  vex::distanceUnits::mm, timeout);

  this->x += x;
  this->y += y;
}

float Map::getX()
{
  return x;
}

float Map::getY()
{
  return y;
}

void Map::setX(float x)
{
  this->x = x;
}

void Map::setY(float y)
{
  this->y = y;
}