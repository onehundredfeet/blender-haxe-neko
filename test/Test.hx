package test;

import blend.Blender;



class Test {

    


    public static function doBlender() :Void {
        trace("doing Blender");

    }

    public static function main() {
        var x = Blender.create();

//        var x = neko.Lib.load("blender", "blenderTest", 0);

        trace('Hi!');
        x.test();
        trace(x);

        neko.vm.Module.local().setExport("doBlender", doBlender);
    }
}