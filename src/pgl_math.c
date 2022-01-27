#include "PGL/pgl_api.h"
#include "GL/gl.h"

void pglMatrixApplyRender() {
    mat_load(Matrix + GL_SCREENVIEW);
    mat_apply(Matrix + GL_PROJECTION);
    mat_apply(Matrix + GL_MODELVIEW);
    mat_store(Matrix + GL_RENDER);
}