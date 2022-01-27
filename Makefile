CC = gcc
CXX = g++
CFLAGS = -shared -ffast-math -O3 -Iinclude -fPIC -Wall -o
LIBS = -ldlopen -lGLESv2 -Linclude
INCLUDE = -linclude
SRCS = src/gl_api.c src/pgl_error.c src/pgl_math.c 
OBJS = gl_api.o pgl_error.o pgl_math.O
TARGET = libGL.so.1.0.0
LIBPATH = ./libs/
SUBDIRS =

all: $(OBJS)
	$(CC) $(CFLAGS) $(TARGET) $(OBJS)

$(OBJS):$(SRCS)
	$(CC) $(CFLAGS) $(LIBS) -c $^

clean:
	rm -rf *.o
	rm -rf $(LIBPATH)