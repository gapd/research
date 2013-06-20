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

!IFDEF MSVCDir
INCLUDE=$(MSVCDir)\include;$(MSVCDir)\PlatformSDK\include
!ELSE
! IFDEF MSDEV
INCLUDE=$(MSDEV)\include;$(MSDEV)\PlatformSDK\include
! ENDIF
!ENDIF

!include <win32.mak>

# define /DOEUNSAFE /DUNSAFE here if you want to live dangerously (i.e. no tech support)
SAFETY =
#SAFETY = /DOEUNSAFE /DUNSAFE

CCDEFS = $(SAFETY) /D__STDC__ /DFATNAME
CCFLAGS = $(cflags) $(cvars) /Zi $(CCDEFS) /I"$(INCLUDE)"

all: cptst.dll

!IF $(MSVC_VER) >= 7
cptst.dll: cptst.obj cptstcabi.obj cptst.def vwntoeimport.lib
	$(link) $(linkdebug) -dll /IMPLIB:$(@B).lib /DEF:cptst.def \
	cptst.obj cptstcabi.obj vwntoeimport.lib /OUT:$(@B).dll /DEBUG /PDB:NONE
!ELSE
cptst.dll: cptst.obj cptstcabi.obj cptst.def vwntoeimport.lib
	$(link) $(linkdebug) \
	-dll /IMPLIB:$(@B).lib /NODEFAULTLIB /DEF:cptst.def \
	cptst.obj cptstcabi.obj vwntoeimport.lib $(conlibsdll) \
	/OUT:$(@B).dll /DEBUG /PDB:NONE /DEBUGTYPE:BOTH
!ENDIF

# User Primitive Support

# The name of resultant OE executable
WHO = vwuser.exe

# The name of the VM static library
LIBSTATIC=vwnt.lib

# Name(s) of test suite files
USER = cpint.obj cptst.obj cptstcabi.obj

# add any user files here -  probably in place of cptst etc.

cpint.obj:  cpint.c userprim.h up_unsafe.h oeAPI.h up_defs.h
	$(cc) $(CCFLAGS) cpint.c

cptst.obj:  cptst.c cptst.h cptstcabi.h userprim.h up_unsafe.h oeAPI.h up_defs.h
	$(cc) $(CCFLAGS) cptst.c

cptstcabi.obj:  cptstcabi.c cptstcabi.h
	$(cc) $(CCFLAGS) cptstcabi.c

testcabi.obj:  testcabi.c cptstcabi.h
	$(cc) $(CCFLAGS) testcabi.c

cptst.exe:	cptstcabi.obj testcabi.obj
	$(link) $(conflags) $(conlibs) cptstcabi.obj testcabi.obj /OUT:cptst.exe

#$(cc) cptstcabi.obj testcabi.obj /Fecptst.exe 

ntvw.res:
	rc -r ntvw.rc

ntvw.obj: ntvw.res
	cvtres -$(CPU) ntvw.rbj ntvw.res

$(WHO): $(USER) ntvw.obj
	$(link) $(guiflags) $(guilibs) advapi32.lib wsock32.lib lz32.lib winmm.lib mpr.lib ntvw.obj cpint.obj cptst.obj $(LIBSTATIC) /OUT:$(WHO) /DEBUG:FULL /ALIGN:0x1000 /DEBUGTYPE:BOTH

clean:;
	del *.obj
	del *.ilk
	del *.dll
	del *.pdb
	del *.exp
	del cp*.lib
