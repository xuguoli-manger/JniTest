# JniTest简介
#生成dll文件简略

1）、在本项目路径下将Java本地文件生成c语言头文件

    javac -d .\build\ .\src\cn\xgl\demo\JniHash.java

    javah -d .\jni\ -cp .\build\ cn.xgl.demo.JniHash

2）、会在jni文件下生成cn_xgl_demo_JniHash.h

3）、将头文件引入到cn_xgl_demo_JniHash.cpp c++文件中

4）、通过vs code 将c++文件生成dell文件
