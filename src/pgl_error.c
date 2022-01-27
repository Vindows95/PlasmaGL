#include "PGL/pgl_api.h"
#include "GL/gl.h"

//OOM means Out Of Memory
//INO means Invalid Operation
//INE means Invalid Enum
//INV means Invalid Value

#define PGL_OOM (1<<0)
#define PGL_INO (1<<1)
#define PGL_INE (1<<2)
#define PGL_INV (1<<3)

static GLsizei PGL_ERROR_CODE;

static char PGL_ERROR_FUNCTION[64] = {'\0'};

void pglGetError() {
    return PGL_ERROR_CODE;
}

void pglPrintError() {
    printf("PlasmaGL Error Throwing Program: ", "%s\n", PGL_ERROR_FUNCTION);
    if (PGL_ERROR_CODE & PGL_OOM) {
        printf("PlasmaGL Error: ", "%s", "GL_OUT_OF_MEMORY");
    }
    if (PGL_ERROR_CODE & PGL_INO) {
        printf("PlasmaGL Error: ", "%s", "GL_INVALID_OPERATION");
    }
    if (PGL_ERROR_CODE & PGL_INE) {
        printf("PlasmaGL Error: ", "%s", "GL_INVALID_ENUM");
    }
    if (PGL_ERROR_CODE & PGL_INV) {
        printf("PlasmaGL Error: ", "%s", "GL_INVALID_VALUE");
    }
    pglResetError();
}

void pglResetError() {
    PGL_ERROR_CODE = 0;
    sprintf(PGL_ERROR_FUNCTION, "\n");
}

void pglCatchError(GLenum error, char *function) {
    pglResetError();
    switch(error) {
        case GL_OUT_OF_MEMORY:
            PGL_ERROR_CODE |= PGL_OOM;
            break;
        case GL_INVALID_OPERATION:
            PGL_ERROR_CODE |= PGL_INO;
            break;
        case GL_INVALID_ENUM:
            PGL_ERROR_CODE |= PGL_INE;
            break;
        case GL_INVALID_VALUE:
            PGL_ERROR_CODE |= PGL_INV;
            break;
    }
}
