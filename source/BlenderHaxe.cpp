
#include <neko_vm.h>
#include "../include/BlenderHaxe.h"

DEFINE_KIND(k_blender_interface);


BlenderHaxe::BlenderHaxe()
{
    vThis = alloc_abstract( k_blender_interface, this );
}
BlenderHaxe::~BlenderHaxe()
{

}

// interface
/*
value blenderTest() {
	return alloc_string("Hello world");
}

static void finalizeBlenderHaxe( value v ) {
	BlenderHaxe *p = (BlenderHaxe *)val_data(v) ;
    if (p != NULL) {
        delete p;
    }
}

value createBlenderInterface() {
    value vi = alloc_abstract( k_blender_interface, new BlenderHaxe() );
    val_gc(vi,finalizeBlenderHaxe);
    return vi;
}

value setBlenderInterface(value v) {
    BlenderHaxe *p = (BlenderHaxe *)val_data(v) ;

    value vi = alloc_abstract( k_blender_interface, new BlenderHaxe() );
    val_gc(vi,finalizeBlenderHaxe);
    return vi;
}

DEFINE_PRIM(blenderTest,0);

*/