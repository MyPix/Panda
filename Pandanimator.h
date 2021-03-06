#ifndef _pAnimator_
#define _pAnimator_

#include "pGlobals.hpp"
#include <SFML\Graphics.hpp>
#include <iostream>
#include <math.h>
#define PI 3.14159265359
using namespace std;
using namespace panda;
// Algorithms from http://gizma.com/easing/
// t= current time,b= start  value,c= change in value,d=duration

class Pandanimator
{
	public:
		Pandanimator(Pandanimation anim)
		{
			mAnim = anim;

			change_posx = mAnim.end.getPosition().x - mAnim.start.getPosition().x;
			change_posy = mAnim.end.getPosition().y - mAnim.start.getPosition().y;

			change_scalex = mAnim.end.getScale().x - mAnim.start.getScale().x;
			change_scaley = mAnim.end.getScale().y - mAnim.start.getScale().y;

			change_rotation = mAnim.end.getRotation() - mAnim.start.getRotation();

			if (mAnim.duration == 0)
				mAnim.duration = 1;
		}
		sf::Transformable getTransformFor(float time)
		{
			////////////
			if (time < 0)
			{
				time = 0;
			}
			else if (time > mAnim.duration)
			{
				time = mAnim.duration;
			}
			sf::Transformable rtr_val;
			////////////
			rtr_val.setPosition(getValue(mAnim.animType_Position_X, time, mAnim.start.getPosition().x, change_posx), getValue(mAnim.animType_Position_Y, time, mAnim.start.getPosition().y, change_posy));
			rtr_val.setScale(getValue(mAnim.animType_Scale_X,time, mAnim.start.getScale().x, change_scalex), getValue(mAnim.animType_Scale_Y, time, mAnim.start.getScale().y, change_scaley));
			rtr_val.setRotation(getValue(mAnim.animType_Rotation, time, mAnim.start.getRotation(), change_rotation));
			return rtr_val;
		}


		//////////////////////
		/////////////////////
		////////////////////
		float linear_ease(float t,float b,float c, float d)
		{
			return c*t / d + b;
		}
		float quadraticIn_ease(float t, float b, float c, float d)
		{
			t = t/ d;
			return c*t*t + b;
		}
		float quadraticOut_ease(float t, float b, float c, float d)
		{
			t /= d;
			return -c * t*(t - 2) + b;
		}
		float quadraticInOut_ease(float t, float b, float c, float d)
		{
			t /= d / 2;
			if (t < 1) 
				return c / 2 * t*t + b;
			t--;
			return -c / 2 * (t*(t - 2) - 1) + b;
		}
		float cubicIn_ease(float t, float b, float c, float d){
			t /= d;
			return c*t*t*t + b;
		}
		float cubicOut_ease(float t, float b, float c, float d){
			t /= d;
			t--;
			return c*(t*t*t + 1) + b;
		}
		float cubicInOut_ease(float t, float b, float c, float d){
			t /= d / 2;
			if (t < 1) return c / 2 * t*t*t + b;
			t -= 2;
			return c / 2 * (t*t*t + 2) + b;
		}

		float quarticIn_ease(float t, float b, float c, float d){
			t /= d;
			return c*t*t*t*t + b;
		}
		float quarticOut_ease(float t, float b, float c, float d){
			t /= d;
			t--;
			return -c * (t*t*t*t - 1) + b;
		}
		float quarticInOut_ease(float t, float b, float c, float d){
			t /= d / 2;
			if (t < 1) return c / 2 * t*t*t*t + b;
			t -= 2;
			return -c / 2 * (t*t*t*t - 2) + b;
		}

		float quinticIn_ease(float t, float b, float c, float d){
			t /= d;
			return c*t*t*t*t*t + b;
		}
		float quinticOut_ease(float t, float b, float c, float d){
			t /= d;
			t--;
			return c*(t*t*t*t*t + 1) + b;
		}
		float quinticInOut_ease(float t, float b, float c, float d){
			t /= d / 2;
			if (t < 1) return c / 2 * t*t*t*t*t + b;
			t -= 2;
			return c / 2 * (t*t*t*t*t + 2) + b;
		}

		float sinusoidalIn_ease(float t, float b, float c, float d){
			return -c / 2 * (cos(PI*t / d) - 1) + b;
		}
		float sinusoidalOut_ease(float t, float b, float c, float d){
			return c * sin(t / d * (PI / 2)) + b;
		}
		float sinusoidalInOut_ease(float t, float b, float c, float d){
			return -c / 2 * (cos(PI*t / d) - 1) + b;
		}

		float exponentialIn_ease(float t, float b, float c, float d){
			return c * pow(2, 10 * (t / d - 1)) + b;
		}
		float exponentialOut_ease(float t, float b, float c, float d){
			return c * (-pow(2, -10 * t / d) + 1) + b;
		}
		float exponentialInOut_ease(float t, float b, float c, float d){
			t /= d / 2;
			if (t < 1) return c / 2 * pow(2, 10 * (t - 1)) + b;
			t--;
			return c / 2 * (-pow(2, -10 * t) + 2) + b;
		}

		float circularIn_ease(float t, float b, float c, float d){
			t /= d;
			return -c * (sqrt(1 - t*t) - 1) + b;
		}
		float circularOut_ease(float t, float b, float c, float d){
			t /= d;
			t--;
			return c * sqrt(1 - t*t) + b;
		}
		float circularInOut_ease(float t, float b, float c, float d){
			t /= d / 2;
			if (t < 1) return -c / 2 * (sqrt(1 - t*t) - 1) + b;
			t -= 2;
			return c / 2 * (sqrt(1 - t*t) + 1) + b;
		}

	private:
		float getValue(pAnimation_types type, float time, float value_base,float value_change)
		{
			float rtr_val;
			cout << "type" << type << endl;
			switch (mAnim.animType_Position_X)
			{
				case Linear:
					rtr_val = linear_ease(time, value_base, value_change, mAnim.duration);
					break;

				case Quadratic_In:
					rtr_val = quadraticIn_ease(time, value_base, value_change, mAnim.duration);
					break;
				case Quadratic_Out:
					rtr_val = quadraticOut_ease(time, value_base, value_change, mAnim.duration);
					break;
				case Quadratic_InOut:
					rtr_val = quadraticInOut_ease(time, value_base, value_change, mAnim.duration);
					break;

				case Cubic_In:
					rtr_val = cubicIn_ease(time, value_base, value_change, mAnim.duration);
					break;
				case Cubic_Out:
					rtr_val = cubicOut_ease(time, value_base, value_change, mAnim.duration);
					break;
				case Cubic_InOut:
					rtr_val = cubicInOut_ease(time, value_base, value_change, mAnim.duration);
					break;

				case Quartic_In:
					rtr_val = quarticIn_ease(time, value_base, value_change, mAnim.duration);
					break;
				case Quartic_Out:
					rtr_val = quarticOut_ease(time, value_base, value_change, mAnim.duration);
					break;
				case Quartic_InOut:
					rtr_val = quarticInOut_ease(time, value_base, value_change, mAnim.duration);
					break;

				case Quintic_In:
					rtr_val = quinticIn_ease(time, value_base, value_change, mAnim.duration);
					break;
				case Quintic_Out:
					rtr_val = quinticOut_ease(time, value_base, value_change, mAnim.duration);
					break;
				case Quintic_InOut:
					rtr_val = quinticInOut_ease(time, value_base, value_change, mAnim.duration);
					break;

				case Sinusoidal_In:
					rtr_val = sinusoidalIn_ease(time, value_base, value_change, mAnim.duration);
					break;
				case Sinusoidal_Out:
					rtr_val = sinusoidalOut_ease(time, value_base, value_change, mAnim.duration);
					break;
				case Sinusoidal_InOut:
					rtr_val = sinusoidalInOut_ease(time, value_base, value_change, mAnim.duration);
					break;

				case Exponential_In:
					rtr_val = exponentialIn_ease(time, value_base, value_change, mAnim.duration);
					break;
				case Exponential_Out:
					rtr_val = exponentialOut_ease(time, value_base, value_change, mAnim.duration);
					break;
				case Exponential_InOut:
					rtr_val = exponentialInOut_ease(time, value_base, value_change, mAnim.duration);
					break;

				case Circular_In:
					rtr_val = circularIn_ease(time, value_base, value_change, mAnim.duration);
					break;
				case Circular_Out:
					rtr_val = circularOut_ease(time, value_base, value_change, mAnim.duration);
					break;
				case Circular_InOut:
					rtr_val = circularInOut_ease(time, value_base, value_change, mAnim.duration);
					break;

				default:
					cout << "No Anim selected for a Parameter" << endl;
					break;
			}
			return rtr_val;
		}
		Pandanimation mAnim;
		float change_posx;
		float change_posy;
		float change_scalex;
		float change_scaley;
		float change_rotation;
};

#endif
/*	NoAnim,

	Linear,

	Quadratic_In,
	Quadratic_Out,
	Quadratic_InOut,

	Cubic_In,
	Cubic_Out,
	Cubic_InOut,

	Quartic_In,
	Quartic_Out,
	Quartic_InOut,

	Qufloatic_In,
	Qufloatic_Out,
	Qufloatic_InOut,

	Sinusoidal_In,
	Sinusoidal_Out,
	Sinusoidal_InOut,

	Exponential_In,
	Exponential_Out,
	Exponential_InOut,

	Circular_In,
	Circular_Out,
	Circular_InOut*/