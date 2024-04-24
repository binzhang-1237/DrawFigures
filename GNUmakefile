#
# In case of building locally, set SKOFL_ROOT variable 
#      setenv SKOFL_ROOT   ... 
#  or directly set in this makefile 
#SKOFL_ROOT = /skofl
#

include $(SKOFL_ROOT)/config.gmk
ROOTLIBS     += $(shell root-config --cflags --glibs) -lMinuit 

PWD     := $(shell pwd)

LOCAL_INC	=   -I$(PWD)/include
LOCAL_LIBS  =  

#
#  Objects
#
OBJS   =  $(PWD)/src/DrawFigures.o

all: $(OBJS)
	$(CXX) $(CXXFLAGS) -c $(PWD)/src/DrawFigures.cpp -o $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo

clean: 
	$(RM) *.o *~ core fort.* $(OBJS)

install.exec: 

