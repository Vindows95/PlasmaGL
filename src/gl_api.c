#include "PGL/pgl_api.h"
#include "GL/gl.h"
#include <dlfcn.h>

#define PGL_ENABLE_FOG (1<<0)
#define PGL_ENABLE_SCISSOR_TEST (1<<1)
#define PGL_ENABLE_SUPERSAMPLE (1<<2)
#define PGL_ENABLE_CULLING (1<<3)
#define PGL_ENABLE_ZCLIPPING (1<<4)
#define PGL_ENABLE_TEXTURE2D (1<<5)
#define PGL_ENABLE_BLENDING (1<<6)
#define PGL_ENABLE_LIGHTING (1<<7)
#define PGL_ENABLE_DEPTH_TEST (1<<8)

static GLbitfield PGL_ENABLE_CAP;
static GLfloat PGL_COLOR_CLEAR[3] = { 0, 0, 0 };

void pglActiveTexture(GLenum texture) {
    void* handle = dlopen("/system/lib/libGLESv2.so", RTLD_GLOBAL);
    if(dlerror() != NULL) {
        printf("PlasmaGL Dlopen Error Throw Program: %s", "Dlopen Failed. %s", dlerror());
    }
    void(*glActiveTexture)(GLenum) = dlsym(handle, "glActiveTexture");
        if(dlerror() != NULL) {
        printf("PlasmaGL Dlopen Error Throw Program: %s", "Dlopen Failed. %s", dlerror());
    }
    glActiveTexture(texture);
}

void pglActiveShaderProgram(GLuint pipeline, GLuint program) {
    void* handle = dlopen("/system/lib/libGLESv2.so", RTLD_GLOBAL);
    if(dlerror() != NULL) {
        printf("PlasmaGL Dlopen Error Throw Program: %s", "Dlopen Failed. %s", dlerror());
    }
    void(*glActiveShaderProgram)(GLuint, GLuint) = dlsym(handle, "glActiveShaderProgram");
        if(dlerror() != NULL) {
        printf("PlasmaGL Dlopen Error Throw Program: %s", "Dlopen Failed. %s", dlerror());
    }
    pglActiveShaderProgram(pipeline, program);
}

void pglClear(GLbitfield mask) {
    void* handle = dlopen("/system/lib/libGLESv2.so", RTLD_GLOBAL);
    if(dlerror() != NULL) {
        printf("PlasmaGL Dlopen Error Throw Program: %s", "Dlopen Failed. %s", dlerror());
    }
    void(*glClear)(GLbitfield) = dlsym(handle, "glClear");
        if(dlerror() != NULL) {
        printf("PlasmaGL Dlopen Error Throw Program: %s", "Dlopen Failed. %s", dlerror());
    }
    glClear(mask);
}

void pglClearBufferfi(GLenum buffer, GLint drawBuffer, GLfloat depth, GLint stencil) {
    void* handle = dlopen("/system/lib/libGLESv2.so", RTLD_GLOBAL);
    if(dlerror() != NULL) {
        printf("PlasmaGL Dlopen Error Throw Program: %s", "Dlopen Failed. %s", dlerror());
    }
    void(*glClearBufferfi)(GLenum, GLint, const GLint) = dlsym(handle, "glClearBufferfi");
        if(dlerror() != NULL) {
        printf("PlasmaGL Dlopen Error Throw Program: %s", "Dlopen Failed. %s", dlerror());
    }
    glClearBufferfi(buffer, drawBuffer, depth, stencil);
}

void pglClearBufferfv(GLenum buffer, GLint drawBuffer, const GLint * value) {
    void* handle = dlopen("/system/lib/libGLESv2.so", RTLD_GLOBAL);
    if(dlerror() != NULL) {
        printf("PlasmaGL Dlopen Error Throw Program: %s", "Dlopen Failed. %s", dlerror());
    }
    void(*glClearBufferfv)(GLenum, GLint, const GLint) = dlsym(handle, "glClearBufferfv");
        if(dlerror() != NULL) {
        printf("PlasmaGL Dlopen Error Throw Program: %s", "Dlopen Failed. %s", dlerror());
    }
    glClearBufferfv(buffer, drawBuffer, *value);
}

void pglClearBufferuiv(GLenum buffer, GLint drawBuffer, const GLint * value) {
    void* handle = dlopen("/system/lib/libGLESv2.so", RTLD_GLOBAL);
    if(dlerror() != NULL) {
        printf("PlasmaGL Dlopen Error Throw Program: %s", "Dlopen Failed. %s", dlerror());
    }
    void(*glClearBufferuiv)(GLenum, GLint, const GLint) = dlsym(handle, "glClearBufferuiv");
        if(dlerror() != NULL) {
        printf("PlasmaGL Dlopen Error Throw Program: %s", "Dlopen Failed. %s", dlerror());
    }
    glClearBufferuiv(buffer, drawBuffer, *value);
}

void pglClearBufferiv(GLenum buffer, GLint drawBuffer, const GLint * value) {
    void* handle = dlopen("/system/lib/libGLESv2.so", RTLD_GLOBAL);
    if(dlerror() != NULL) {
        printf("PlasmaGL Dlopen Error Throw Program: %s", "Dlopen Failed. %s", dlerror());
    }
    void(*glClearBufferiv)(GLenum, GLint, const GLint) = dlsym(handle, "glClearBufferiv");
        if(dlerror() != NULL) {
        printf("PlasmaGL Dlopen Error Throw Program: %s", "Dlopen Failed. %s", dlerror());
    }
    glClearBufferiv(buffer, drawBuffer, *value);
}

void pglClearDepth(GLfloat depth) {
    void* handle = dlopen("/system/lib/libGLESv2.so", RTLD_GLOBAL);
    if(dlerror() != NULL) {
        printf("PlasmaGL Dlopen Error Throw Program: %s", "Dlopen Failed. %s", dlerror());
    }
    void(*glClearBufferiv)(GLfloat) = dlsym(handle, "glClearDepth");
        if(dlerror() != NULL) {
        printf("PlasmaGL Dlopen Error Throw Program: %s", "Dlopen Failed. %s", dlerror());
    }
    glClearDepth(GLfloat);
}

void pglClearStencil(GLint s) {
    void* handle = dlopen("/system/lib/libGLESv2.so", RTLD_GLOBAL);
    if(dlerror() != NULL) {
        printf("PlasmaGL Dlopen Error Throw Program: %s", "Dlopen Failed. %s", dlerror());
    }
    void(*glClearStencil)(GLint) = dlsym(handle, "glClearStencil");
        if(dlerror() != NULL) {
        printf("PlasmaGL Dlopen Error Throw Program: %s", "Dlopen Failed. %s", dlerror());
    }
    glClearStencil(GLint);
}

GLAPI void APIENTRY glActiveTexture(GLenum texture) {
    return pglActiveTexture(texture);
}

GLAPI void APIENTRY glActiveShaderProgram(GLuint pipeline, GLuint program) {
    return pglActiveShaderProgram(pipeline, program);
}

GLAPI void APIENTRY glClearStencil(GLint s) {
    return pglClearStencil(s);
}

GLAPI void APIENTRY glClearDepth(GLfloat depth) {
    return pglClearDepth(depth);
}

GLAPI void APIENTRY glClearBufferiv(GLenum buffer, GLint drawBuffer, const GLint * value) {
    return pglClearBufferiv(buffer, drawBuffer, *value);
}

GLAPI void APIENTRY glClearBufferuiv(GLenum buffer, GLint drawBuffer, const GLint * value) {
    return pglClearBufferuiv(buffer, drawBuffer, *value);
}

GLAPI void APIENTRY glClearBufferfv(GLenum buffer, GLint drawBuffer, const GLint * value) {
    return pglClearBufferfv(buffer, drawBuffer, *value);
}

GLAPI void APIENTRY glClearBufferfi(GLenum buffer, GLint drawBuffer, GLfloat depth, GLint stencil) {
    return pglClearBufferiv(buffer, drawBuffer, depth, stencil);
}

GLAPI void APIENTRY glClear(GLbitfield mask) {
    return pglClear(mask);
}

GLAPI void APIENTRY glClearColor(float r, float g, float b, float a) {
    if(r > 1) r = 1;
    if(g > 1) g = 1;
    if(b > 1) b = 1;
    if(a > 1) a = 1;
    PGL_COLOR_CLEAR[0] = r * a;
    PGL_COLOR_CLEAR[1] = g * a;
    PGL_COLOR_CLEAR[2] = b * a;
}

GLAPI void APIENTRY glEnable(GLenum cap) {
    if(cap >= GL_LIGHT0 && GL_LIGHT15 >= cap) return pglEnableLight(cap);
    switch (cap) {
        case GL_DEPTH_TEST:
            PGL_ENABLE_CAP |= PGL_ENABLE_DEPTH_TEST;
            break;

        case GL_BLEND:
            PGL_ENABLE_CAP |= PGL_ENABLE_BLENDING;
            pglVertexBufferSwitchTR();
            break;

        case GL_LIGHTING:
            PGL_ENABLE_CAP |= PGL_ENABLE_LIGHTING;
            break;
    
        case GL_TEXTURE_2D:
            PGL_ENABLE_CAP |= PGL_ENABLE_TEXTURE2D
            break;

        case GL_FOG:
            PGL_ENABLE_CAP |= PGL_ENABLE_FOG;
            break;
        
        case GL_CULL_FACE:
            PGL_ENABLE_CAP |= PGL_ENABLE_CULLING;
            break;

        case GL_SCISSOR_TEST:
            PGL_ENABLE_CAP |= PGL_ENABLE_SCISSOR_TEST;
    }
}

GLAPI void APIENTRY glDisable(GLenum cap) {
    if(cap >= GL_LIGHT0 && GL_LIGHT15 >= GL_LIGHT15) return pglDisableLight(cap);
    switch (cap) {
        case GL_DEPTH_TEST:
            PGL_ENABLE_CAP &= ~PGL_ENABLE_DEPTH_TEST;
            break;

        case GL_BLEND:
            PGL_ENABLE_CAP $= ~PGL_ENABLE_BLENDING;
            pglVertexBufferSwitchTR();
            break;

        case GL_LIGHTING:
            PGL_ENABLE_CAP $= ~PGL_ENABLE_LIGHTING;
            break;
    
        case GL_TEXTURE_2D:
            PGL_ENABLE_CAP $= ~PGL_ENABLE_TEXTURE2D
            break;

        case GL_FOG:
            PGL_ENABLE_CAP $= ~PGL_ENABLE_FOG;
            break;
        
        case GL_CULL_FACE:
            PGL_ENABLE_CAP $= ~PGL_ENABLE_CULLING;
            break;

        case GL_SCISSOR_TEST:
            PGL_ENABLE_CAP $= ~PGL_ENABLE_SCISSOR_TEST;
    }
}

GLAPI void APIENTRY glBegin(GLenum mode) {
    
}