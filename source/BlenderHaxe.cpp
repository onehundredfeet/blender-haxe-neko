#include "BlenderHaxe.h"
#include <neko.h>




BlenderHaxe::BlenderHaxe()
{
}
BlenderHaxe::~BlenderHaxe()
{
}

// interface
value blenderTest() {
	return alloc_string("Hello world");
}

DEFINE_PRIM(blenderTest,0);