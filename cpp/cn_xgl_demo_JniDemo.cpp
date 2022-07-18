#include "pch.h"
#include "jni.h"
#include "cn_xgl_demo_JniDemo.h"
#include <iostream>

JNIEXPORT void JNICALL Java_cn_xgl_demo_JniDemo_sayHello
(JNIEnv*, jclass) {
	std::cout << "[CPP] JNI testFunc hello java" << std::endl;
}