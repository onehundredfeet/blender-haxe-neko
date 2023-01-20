package blend;

class Blender {
    function new() {

    }
    public static function create() : Blender{

        var b = new Blender();

        b.test = neko.Lib.load("blender", "blenderTest", 0);

        return b;
    }
    public dynamic function test() : Void {

    }

}