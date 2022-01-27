#ifndef PGL_API_H
#define PGL_API_H

#include "GL/gl.h"

typedef GLushort uint16;
typedef GLubyte uint8;

typedef struct {
    GLfloat u, v;
} glTexCoord;

typedef struct {
    GLfloat pos[3];
    GLfloat norm[3];
} glVertex;

typedef struct {
    GLuint texID;
    GLsizei index;
    GLvoid *data;
    GLvoid *linker;
} GL_FRAMEBUFFER_OBJECT;

typedef struct {
    GLushort width;
    GLushort height;
    GLuint color;
    GLuint index;
    GLubyte env;
    GLubyte filter;
    GLubyte uv_clamp;
    GLubyte mip_map;
    GLvoid *data;
    GLvoid *linker;
} GL_TEXTURE_OBJECT;

GLsizei pglGetError();
void pglPrintError();
void pglResetError();
void pglCatchError();
void pglInputError();
GLuint pglInitTexture(GLenmu mode);
GLuint pglGetTextureData(GLuint index)
GLuint pglGetTextureWidth(GLuint index);
GLuint pglGetTextureHeight(GLuint index);
GLuint pglGetFBOWidth(GLsizei FBI);
GLuint pglGetFBOHeight(GLsizei FBI);
GLsizei pglGetFBO();
void pglEnableLight(const GLuint light);
void pglDisableLight(const GLuint light);
unsigned char pglVertexList();
inline void pglVertexBufferPointer();
inline void pglVertexBufferAddress
inline void pglVertexBufferSwitchOP();
inline void pglVertexBufferSwitchTR();
void pglClear(GLbitfield mask);
void glClearBufferiv(GLenum buffer, GLint drawBuffer, const GLint * value);
void glClearBufferuiv(GLenum buffer, GLint drawBuffer, const GLuint * value);
void glClearBufferfv(GLenum buffer, GLint drawBuffer, const GLfloat * value);
void glClearBufferfi(GLenum buffer, GLint drawBuffer, GLfloat depth, GLint stencil);
void pglClearDepth(GLfloat depth);
void pglClearStencil(GLint s);
void pglActiveShaderProgram(GLuint pipeline, GLuint program);
void pglActiveTexture(GLenum texture);
void pglMatrixApplyRender();