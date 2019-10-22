//
// Created by ByteFlow on 2019/4/18.
//

#ifndef OPENGLCAMERA2_BYTEFLOWRENDERCONTEXT_H
#define OPENGLCAMERA2_BYTEFLOWRENDERCONTEXT_H


#include <cstdint>
#include <jni.h>
#include <ByteFlowRender.h>

#define GL_RENDER_TYPE   0
#define CL_RENDER_TYPE   1

#define PARAM_TYPE_SET_SHADER_INDEX   201
#define PARAM_TYPE_SET_GL_X_LOCATION  202
#define PARAM_TYPE_SET_GL_Y_LOCATION  203


class ByteFlowRenderContext
{
public:
	ByteFlowRenderContext(int renderType);

	~ByteFlowRenderContext();

	static void CreateRenderContext(JNIEnv *env, jobject instance, jint renderType);

	static void StoreRenderContext(JNIEnv *env, jobject instance, ByteFlowRenderContext *pContext);

	static void DeleteRenderContext(JNIEnv *env, jobject instance);

	static ByteFlowRenderContext* GetRenderContext(JNIEnv *env, jobject instance);

	int Init(int initType);

	int UnInit();

	void UpdateFrame(uint8_t *pBuffer, int width, int height);

	void SetTransformMatrix(float translateX, float translateY, float scaleX, float scaleY, int degree, int mirror);

	void SetParamsInt(int paramType, int param);

	void SetMask(uint8_t *pBuffer, int width, int height, int size);

	int GetParamsInt(int paramType);

	void OnSurfaceCreated();

	void OnSurfaceChanged(int width, int height);

	void OnDrawFrame();

private:
	static jfieldID s_ContextHandle;

	ByteFlowRender *m_pByteFlowRender;
};


#endif //OPENGLCAMERA2_BYTEFLOWRENDERCONTEXT_H