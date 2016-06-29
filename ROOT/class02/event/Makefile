# Makefile for the ROOT test programs.
# This Makefile shows nicely how to compile and link applications
# using the ROOT libraries on all supported platforms.
#
# Copyright (c) 2000 Rene Brun and Fons Rademakers
#
# Author: Fons Rademakers, 29/2/2000

RC     := root-config
ifeq ($(shell which $(RC) 2>&1 | sed -ne "s@.*/$(RC)@$(RC)@p"),$(RC))
MKARCH := $(wildcard $(shell $(RC) --etcdir)/Makefile.arch)
RCONFIG := $(wildcard $(shell $(RC) --incdir)/RConfigure.h)
endif
ifneq ($(MKARCH),)
include $(MKARCH)
else
ifeq ($(ROOTSYS),)
ROOTSYS = ..
endif
include $(ROOTSYS)/etc/Makefile.arch
endif
# Tutorials dir needed by stressProof
ifneq ($(RCONFIG),)
TUTDIR := $(wildcard $(shell grep ROOTDOCDIR $(RCONFIG) | sed "s|.*\"\(.*\)\"|\1|")/tutorials)
endif
ifeq ($(TUTDIR),)
ifeq ($(ROOTSYS),)
ROOTSYS = ..
endif
TUTDIR := $(ROOTSYS)/tutorials
endif
-include ../MyConfig.mk

#------------------------------------------------------------------------------

EVENTO        = Event.$(ObjSuf) EventDict.$(ObjSuf)
EVENTS        = Event.$(SrcSuf) EventDict.$(SrcSuf)
EVENTSO       = libEvent.$(DllSuf)
EVENT         = Event$(ExeSuf)
ifeq ($(PLATFORM),win32)
EVENTLIB      = libEvent.lib
else
EVENTLIB      = $(shell pwd)/$(EVENTSO)
endif

MAINEVENTO    = MainEvent.$(ObjSuf)
MAINEVENTS    = MainEvent.$(SrcSuf)

OBJS          = $(EVENTO) 
PROGRAMS      = $(EVENT) 

#------------------------------------------------------------------------------
.SUFFIXES: .$(SrcSuf) .$(ObjSuf) .$(DllSuf)
.PHONY:    Aclock Hello Tetris

all:            $(PROGRAMS)

$(EVENTSO):     $(EVENTO)
ifeq ($(ARCH),aix5)
		$(MAKESHARED) $(OutPutOpt) $@ $(LIBS) -p 0 $^
else
ifeq ($(PLATFORM),macosx)
# We need to make both the .dylib and the .so
		$(LD) $(SOFLAGS)$@ $(LDFLAGS) $^ $(OutPutOpt) $@ $(EXPLLINKLIBS)
ifneq ($(subst $(MACOSX_MINOR),,1234),1234)
ifeq ($(MACOSX_MINOR),4)
		ln -sf $@ $(subst .$(DllSuf),.so,$@)
endif
endif
endif
endif
		@echo "$@ done"


$(EVENT):       $(EVENTSO) $(MAINEVENTO)
		$(LD) $(LDFLAGS) $(MAINEVENTO) $(EVENTO) $(LIBS) $(OutPutOpt)$@
		$(MT_EXE)
		@echo "$@ done"


clean:
		@rm -f $(OBJS) *Dict.*

distclean:      clean
		-@(mv -f stressRooStats_ref.root stressRooStats_ref.root- >/dev/null 2>&1;true)
		-@(mv -f stressHistFactory_ref.root stressHistFactory_ref.root- >/dev/null 2>&1;true)
		@rm -f $(PROGRAMS) $(EVENTSO) $(EVENTLIB) *Dict.* *.def *.exp \
		   *.root *.ps *.so *.lib *.dll *.d *.log .def so_locations \
		   files/* testdb.sqlite
		@rm -rf cxx_repository
		-@(mv -f stressRooStats_ref.root- stressRooStats_ref.root >/dev/null 2>&1;true)
		-@(mv -f stressHistFactory_ref.root- stressHistFactory_ref.root >/dev/null 2>&1;true)
		-@cd RootShower && $(MAKE) distclean
		-@cd rhtml && $(MAKE) distclean
		-@cd RootIDE && $(MAKE) distclean
		-@cd periodic && $(MAKE) distclean
		-@cd histviewer && $(MAKE) distclean

.SUFFIXES: .$(SrcSuf)

###
Event.$(ObjSuf): Event.h
EventMT.$(ObjSuf): EventMT.h
MainEvent.$(ObjSuf): Event.h

EventDict.$(SrcSuf): Event.h EventLinkDef.h
	@echo "Generating dictionary $@..."
	$(ROOTCINT) -f $@ -c $^


.$(SrcSuf).$(ObjSuf):
	$(CXX)  $(CXXFLAGS) -c $<

ifeq ($(GCC_MAJOR),4)
ifeq ($(GCC_MINOR),1)
TBenchDict.o: CXXFLAGS += -Wno-strict-aliasing
endif
endif
