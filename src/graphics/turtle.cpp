/*
 * Copyright (c) 2007 SIEGE Development Team
 * All rights reserved.
 *
 * This file is part of libSIEGE.
 *
 * This software is copyrighted work licensed under the terms of the
 * 2-clause BSD license. Please consult the file "license.txt" for
 * details.
 *
 * If you did not recieve the file with this program, please email
 * Tim Chas <darkuranium@gmail.com>.
 */

#include "turtle.hh"

using namespace siege::c;
namespace siege
{
	namespace graphics
	{
		void Turtle::create(float x, float y, float angle, bool draw)
		{
			handle = sgTurtleCreateDegs(x, y, angle, draw);
		}

		/// \todo overload
		Turtle::Turtle(float x, float y, float angle, bool draw)
		{
			create(x, y, angle, draw);
		}
		Turtle::Turtle(float x, float y, float angle)
		{
			create(x, y, angle, true);
		}
		Turtle::Turtle(float x, float y, bool draw)
		{
			create(x, y, 0.0, draw);
		}
		Turtle::Turtle(float x, float y)
		{
			create(x, y, 0.0, true);
		}
		Turtle::~Turtle()
		{
			sgTurtleDestroy(handle);
		}

		void Turtle::reset()
		{
			sgTurtleReset(handle);
		}
		void Turtle::push()
		{
			sgTurtlePush(handle);
		}
		void Turtle::pop()
		{
			sgTurtlePop(handle);
		}
		void Turtle::step(float dist)
		{
			sgTurtleStep(handle, dist);
		}
		void Turtle::move(float x, float y)
		{
			sgTurtleMove(handle, x, y);
		}
		void Turtle::jump(float x, float y)
		{
			sgTurtleJump(handle, x, y);
		}
		void Turtle::penUp()
		{
			sgTurtlePenUp(handle);
		}
		void Turtle::penDown()
		{
			sgTurtlePenDown(handle);
		}

		void Turtle::setPen(bool pen)
		{
			sgTurtleSetPen(handle, pen);
		}
		bool Turtle::getPen()
		{
			return sgTurtleGetPen(handle);
		}

		// alias of jump
		void Turtle::setPos(float x, float y)
		{
			sgTurtleSetPos(handle, x, y);
		}
		void Turtle::setPosX(float x)
		{
			sgTurtleSetPosX(handle, x);
		}
		void Turtle::setPosY(float y)
		{
			sgTurtleSetPosY(handle, y);
		}
		void Turtle::getPos(float* x, float* y)
		{
			sgTurtleGetPos(handle, x, y);
		}
		void Turtle::getPos(float& x, float& y)
		{
			sgTurtleGetPos(handle, &x, &y);
		}
		float Turtle::getPosX()
		{
			return sgTurtleGetPosX(handle);
		}
		float Turtle::getPosY()
		{
			return sgTurtleGetPosY(handle);
		}

		void Turtle::turnLeftRads(float rads)
		{
			sgTurtleTurnLeftRads(handle, rads);
		}
		void Turtle::turnLeftDegs(float degs)
		{
			sgTurtleTurnLeftDegs(handle, degs);
		}
		void Turtle::turnRightRads(float rads)
		{
			sgTurtleTurnRightRads(handle, rads);
		}
		void Turtle::turnRightDegs(float degs)
		{
			sgTurtleTurnRightDegs(handle, degs);
		}

		void Turtle::setAngleRads(float rads)
		{
			sgTurtleSetAngleRads(handle, rads);
		}
		float Turtle::getAngleRads()
		{
			return sgTurtleGetAngleRads(handle);
		}

		void Turtle::setAngleDegs(float degs)
		{
			sgTurtleSetAngleDegs(handle, degs);
		}
		float Turtle::getAngleDegs()
		{
			return sgTurtleGetAngleDegs(handle);
		}
	}
}
