package cn.xgl.demo;

/**
 * @Description:
 * @Author: xgl
 * @Date: 2022/7/18 14:22
 */
public class JniDemo {

    public static native void sayHello();

    static {
        System.loadLibrary("JniTest");
    }

    public static void main(String[] args) {
        sayHello();
    }
}
