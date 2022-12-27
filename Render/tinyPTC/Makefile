APP 	:= game
CCFLAGS := -Wall -pedantic
CFLAGS  := -Wall -pedantic
CC      := g++
C       := gcc
MKDIR   := mkdir -p
SRC     := src
OBJ     := obj
LIBS    := -lX11 -L/usr/lib/i386-linux-gnu/libGLX_nvidia.so.0

# % = * (cualquier cosa)
# iname porque es incase sesitive
ALLCPPS    := $(shell 	  find src/ -type f -iname *.cpp)
ALLCS      := $(shell 	  find src/ -type f -iname *.c)
ALLCPPSOBJ := $(patsubst  %.cpp, %.o, $(ALLCPPS))
ALLCSOBJ   := $(patsubst  %.c, %.o, $(ALLCS))
SUBDIRS    := $(shell 	  find $(SRC) -type d)
OBJSUBDIRS := $(patsubst  $(SRC)%, $(OBJ)%, $(SUBDIRS))

.PHONY: dir 

# APP Depende de los subdirectorios de obj y src/main.cpp
$(APP) : $(OBJSUBDIRS) $(ALLCPPSOBJ) $(ALLCSOBJ)
# Linkear
	$(CC) -o $(APP) $(patsubst $(SRC)%, $(OBJ)%, $(ALLCPPSOBJ) $(ALLCSOBJ)) $(LIBS)


# $@ = %.0 (producto esperado)
# $^ = %.c (dependencia)

%.o : %.c
	$(C) -o $(patsubst $(SRC)%, $(OBJ)%, $@) -c $^ $(CFLAGS)

%.o : %.cpp
	$(CC) -o $(patsubst $(SRC)%, $(OBJ)%, $@) -c $^ $(CCFLAGS)


dir: 
	$(info $(SUBDIRS))
	$(info $(OBJSUBDIRS))
	$(info $(ALLCPPS))
	$(info $(ALLCS))
	$(info $(ALLCSOBJ))
	

$(OBJSUBDIRS) :
	$(MKDIR) $(OBJSUBDIRS)
