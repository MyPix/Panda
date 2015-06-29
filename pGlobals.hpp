#include <SFML\Graphics.hpp>
#ifndef _pGlobals_
#define _pGlobals_
namespace panda
{
	typedef enum pAnimation_types
	{
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
	
		Quintic_In,
		Quintic_Out,
		Quintic_InOut,

		Sinusoidal_In,
		Sinusoidal_Out,
		Sinusoidal_InOut,

		Exponential_In,
		Exponential_Out,
		Exponential_InOut,

		Circular_In,
		Circular_Out,
		Circular_InOut
	}pAnimation_types;
}

typedef struct Pandanimation
{
	int duration; // Duration in FRAMES (Framecap at 30 or 60fps highly recommended for the animations ! )
	sf::Transformable start; // The start position, just link your object
	sf::Transformable end; // The End Position, I Advise you to create a new sf::transformable with your object's parameter and edit it :)
	panda::pAnimation_types animType_Position_X; // Animation type for the specified parameter
	panda::pAnimation_types animType_Position_Y;// Animation type for the specified parameter
	panda::pAnimation_types animType_Scale_X; // Animation type for the specified parameter
	panda::pAnimation_types animType_Scale_Y; // Animation type for the specified parameter 
	panda::pAnimation_types animType_Rotation; // Animation type for the specified parameter
}Pandanimation;
#endif