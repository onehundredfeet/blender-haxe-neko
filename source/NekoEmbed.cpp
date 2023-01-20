#include <stdio.h>
#include <neko_vm.h>

value print( value v ) {
	if( val_is_null(v) )
		printf("null");
	else if( val_is_int(v) )
		printf("int : %d",val_int(v));
	else if( val_is_float(v) )
		printf("float : %f",val_float(v));
	else if( val_is_bool(v) )
		printf("bool : %s",val_bool(v)?"true":"false");
	else if( val_is_array(v) )
		printf("array : size %d",val_array_size(v));
	else if( val_is_function(v) )
		printf("function : %d args",val_fun_nargs(v));
	else if( val_is_string(v) )
		printf("string : %s (%d bytes)",val_string(v),val_strlen(v));
	else if( val_is_object(v) )
		printf("object");
	else if( val_is_abstract(v) )
		printf("abstract of kind %llu",(unsigned long long)val_kind(v));
	else
		printf("?????");
	return val_null;
}


value load( const char *file ) {
    value loader;
    value args[2];
    value exc = NULL;
    value ret;
    loader = neko_default_loader(NULL,0);
    args[0] = alloc_string(file);
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

void execute( value module ) {
    value x = val_field(module,val_id("x"));
    value f = val_field(module,val_id("doBlender"));
    value ret;
   
      if( !val_is_function(f) || val_fun_nargs(f) != 0 ) {
            printf("f is not a function %p\n", f);
            print(f);
            print (module);
         return;
     }

    ret = val_call0(f);

    if( !val_is_int(x) ) {
            printf("x is not an int %p\n", x);
            print(x);
         return;
    }

  

    printf("x = %d\n",val_int(x));
    ret = val_call1(f,x);
    if( !val_is_int(ret) )
         return;
    printf("f(x) = %d\n",val_int(ret));
}


int main( int argc, char *argv[] ) {
    neko_vm *vm;
    value module;
    neko_global_init();
    vm = neko_vm_alloc(NULL);
    neko_vm_select(vm);

    module = load("bin/test.n");
    if( module == NULL ) {
         printf("Failed to load module !\n");
         return -1;
    }
    execute(module);

    neko_global_free();
    return 0;
}