#ifndef __BLENDER_NEKO_VM_H__
#define __BLENDER_NEKO_VM_H__
#pragma once
#include <neko_vm.h>
#include "BlenderHaxe.h"

class BlenderNekoVM
{
private:
    neko_vm *_pVM;
    static int _numVMs;

    BlenderHaxe *_pBlenderInterface;
    value _vBlenderInterface;

public:
    BlenderNekoVM();
    ~BlenderNekoVM();

    value loadModule(const char *modulePath);
    static value resolveSymbol( value module, const char *symbolName);

    static value call0(value function) {
        return val_call0(function);
    }

    static value vm_alloc(int x) {
        return alloc_int(x);
    }
    static value vm_alloc(float x) {
        return alloc_float(x);
    }

    static value vm_alloc(const char *x) {
        return alloc_string(x);
    }

    template<typename T>
    static value call1(value function, T arg0) {
        return val_call1(function, vm_alloc(arg0));
    }

    template<typename T>
    static value call2(value function, T arg0, T arg1) {
        return val_call1(function, vm_alloc(arg0), vm_alloc(arg1));
    }


};



#endif