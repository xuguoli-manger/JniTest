package cn.xgl.demo;

/**
 * @Description:
 * @Author: xgl
 * @Date: 2022/7/18 15:04
 */
public class JniHash {

    public static native long hashString(String hash);

    static {
        System.loadLibrary("JniDemo");
    }

    public static void main(String[] args) {
        System.out.println(hashString("www.baidu.com"));
    }
}
