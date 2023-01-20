#ifndef __BLENDER_HAXE_H__
#define __BLENDER_HAXE_H__
#pragma once
#include <neko.h>

class BlenderHaxe
{

private:
    value vThis;
public:
    BlenderHaxe();
    ~BlenderHaxe();
     value getInterfaceValue() { return vThis;}


};



#endif