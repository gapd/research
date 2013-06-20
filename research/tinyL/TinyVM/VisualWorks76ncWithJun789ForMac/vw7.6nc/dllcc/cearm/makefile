# This is a makefile that will build the the cptst.dll test DLL
# and statically linked ObjectEngine for Windows NT.
# Please see the on-line readme file or consult your documentation
# for more information on building this example.
#
# Note that you will need to copy files from the default
# VisualWorks user-primitive directory to complete a build
# of a statically linked ObjectEngine. The current set of
# files that require copying to the makefile directory are:
#	logo.bmp, ntvw,.h, vw.ico, vw.lib, ntvw.rc
#
# Copyright (C) 1999-2006 Cincom Systems, Inc.  All Rights Reserved.

PLATFORM=STANDARDSDK
MSDEV=$(SDKROOT)\$(OSVERSION)\$(PLATFORM)
INCLUDE="$(MSDEV)\include\armv4"

!IFNDEF LINKER
LINKER=link
!ENDIF

MACHINE=ARM
LIB="$(MSDEV)\Lib\Armv4"
LIBS=corelibc.lib coredll.lib mmtimer.lib ntcompat.lib ws2.lib

# define /DOEUNSAFE /DUNSAFE here if you want to live dangerously (i.e. no tech support)
SAFETY =
#SAFETY = /DOEUNSAFE /DUNSAFE

CCDEFS = $(SAFETY) -DUNDER_CE=1 -DUNICODE=1 -DUNICODE_ONLY=1 -D_WIN32_WCE
CCFLAGS = $(cflags) $(cvars) /c /Z7 $(CCDEFS) /I$(INCLUDE)

all: cptst.dll

cptst.dll: cptst.obj cptstcabi.obj cptst.def vwntoeimport.lib
	$(LINKER) $(linkdebug) -dll /IMPLIB:$(@B).lib /DEF:cptst.def \
	cptst.obj cptstcabi.obj vwntoeimport.lib \
	/OUT:$(@B).dll /LIBPATH:$(LIB) /NODEFAULTLIB $(LIBS) /SUBSYSTEM:WINDOWSCE /DEBUG /PDB:NONE

cpint.obj:  cpint.c userprim.h up_unsafe.h oeAPI.h up_defs.h
	$(CC) $(CCFLAGS) cpint.c

cptst.obj:  cptst.c cptst.h cptstcabi.h userprim.h up_unsafe.h oeAPI.h up_defs.h
	$(CC) $(CCFLAGS) cptst.c

cptstcabi.obj:  cptstcabi.c cptstcabi.h
	$(CC) $(CCFLAGS) cptstcabi.c

testcabi.obj:  testcabi.c cptstcabi.h
	$(CC) $(CCFLAGS) -Dmain=WinMain testcabi.c

cptst.exe:	cptstcabi.obj testcabi.obj
	$(LINKER) $(conflags) $(conlibs) cptstcabi.obj testcabi.obj \
		/OUT:cptst.exe /LIBPATH:$(LIB) $(LIBS) /MACHINE:$(MACHINE) /NODEFAULTLIB /SUBSYSTEM:WINDOWSCE

# User Primitive Support (not functional)

# The name of resultant OE executable
WHO = vwuser.exe

# The name of the VM static library
LIBSTATIC=vwcearm.lib

# Name(s) of test suite files
USER = cpint.obj cptst.obj cptstcabi.obj

# add any user files here -  probably in place of cptst etc.

ntvw.res:
	rc -r ntvw.rc

ntvw.obj: ntvw.res
	cvtres -$(CPU) ntvw.rbj ntvw.res

$(WHO): $(USER) ntvw.obj
	$(LINKER) $(guiflags) $(guilibs) advapi32.lib wsock32.lib lz32.lib winmm.lib mpr.lib \
	ntvw.obj cpint.obj cptst.obj $(LIBSTATIC) \
	/OUT:$(WHO) /SUBSYSTEM:WINDOWSCE /DEBUG:FULL /ALIGN:0x1000 /DEBUGTYPE:BOTH

clean:;
	del *.obj
	del *.ilk
	del *.dll
	del *.pdb
	del *.exp
	del cp*.lib
