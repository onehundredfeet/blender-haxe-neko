#include <stdio.h>
#include "../include/BlenderNekoVM.h"




BlenderNekoVM::BlenderNekoVM()
{
     auto *x = new BlenderNekoVM();

    if (_numVMs == 0) {
        _numVMs = 1;
        neko_global_init();
    } else {
        _numVMs++;
    }
    neko_vm *vm = neko_vm_alloc(NULL);       
    x->_pVM = vm;
    neko_vm_select(vm);

    _pBlenderInterface = new BlenderHaxe();
    _vBlenderInterface = _pBlenderInterface->getInterfaceValue();

}

BlenderNekoVM::~BlenderNekoVM()
{
    _numVMs--;

    if (_numVMs == 0) {
        neko_global_free();
    }

    delete _pBlenderInterface;
}

value BlenderNekoVM::loadModule(const char *modulePath) {
    value loader;
    value args[2];
    value exc = NULL;
    value ret;
    loader = neko_default_loader(NULL,0);
    args[0] = alloc_string(modulePath);
    args[1] = loader;
    ret = val_callEx(loader,val_field(loader,val_id("loadmodule")),args,2,&exc);
    if( exc != NULL ) {
        buffer b = alloc_buffer(NULL);
        val_buffer(b,exc);
        printf("Uncaught exception - %s\n",val_string(buffer_to_string(b)));
        return NULL;
    }
    if (ret == NULL) {
        printf("loadmodule is null\n");
    }
    return ret;
}

value BlenderNekoVM::resolveSymbol( value module, const char *symbolName) {
    return val_field(module,val_id(symbolName));
}

int BlenderNekoVM::_numVMs = 0;

