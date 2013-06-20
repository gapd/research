/************************************************************************
 * File: cpint.c
 *
 * Description:
 *	Registration of the DLL and C Connect test suite
 *	files that are statically linked into an ObjectEngine.
 *
 *	Copyright (C) 1999-2007 Cincom Systems, Inc.
 *	Santa Clara, California.  All Rights Reserved.
 ************************************************************************/

#include "userprim.h"
#include "oeAPI.h"
#define __OOP__
#include "cptst.h"

#if 0
# ifdef MAC /* Macintosh character set differs from other platforms. */
#	define VisualWorks "VisualWorks¨"
# else
#	define VisualWorks "VisualWorks©"
# endif
#else
#	define VisualWorks "VisualWorks(R)"
#endif
char *versionString = VisualWorks "7 with DLL and C Connect testing";

char *resourceClassName = "St80"; /* class name used to look up X resources */

main(int argc, char *argv[])
{
	return oeMain(argc, argv, (char **)0);
}

char*
UPinstall()
{
}

void
UPInitLinkRegistry() {
    UPRegisterSymbolAndHandle("TstExternalUPCtoSTbool", (void*)TstExternalUPCtoSTbool);
    UPRegisterSymbolAndHandle("TstExternalUPCtoSTchar", (void*)TstExternalUPCtoSTchar);
    UPRegisterSymbolAndHandle("TstExternalUPCtoSTfloat", (void*)TstExternalUPCtoSTfloat);
    UPRegisterSymbolAndHandle("TstExternalUPCtoSTint", (void*)TstExternalUPCtoSTint);
    UPRegisterSymbolAndHandle("TstExternalUPSTtoCbool", (void*)TstExternalUPSTtoCbool);
    UPRegisterSymbolAndHandle("TstExternalUPSTtoCchar", (void*)TstExternalUPSTtoCchar);
    UPRegisterSymbolAndHandle("TstExternalUPSTtoCfloat", (void*)TstExternalUPSTtoCfloat);
    UPRegisterSymbolAndHandle("TstExternalUPSTtoCint", (void*)TstExternalUPSTtoCint);
    UPRegisterSymbolAndHandle("TstExternalUPbasicAt", (void*)TstExternalUPbasicAt);
    UPRegisterSymbolAndHandle("TstExternalUPbasicAtPut", (void*)TstExternalUPbasicAtPut);
    UPRegisterSymbolAndHandle("TstExternalUPbyteAt", (void*)TstExternalUPbyteAt);
    UPRegisterSymbolAndHandle("TstExternalUPbyteAtPut", (void*)TstExternalUPbyteAtPut);
    UPRegisterSymbolAndHandle("TstExternalUPcopyCtoSTintArray", (void*)TstExternalUPcopyCtoSTintArray);
    UPRegisterSymbolAndHandle("TstExternalUPcopyCtoSTbytes", (void*)TstExternalUPcopyCtoSTbytes);
    UPRegisterSymbolAndHandle("TstExternalUPcopyCtoSTfloatArray", (void*)TstExternalUPcopyCtoSTfloatArray);
    UPRegisterSymbolAndHandle("TstExternalUPcopyCtoSTstring", (void*)TstExternalUPcopyCtoSTstring);
    UPRegisterSymbolAndHandle("TstExternalUPcopySTtoCbytes", (void*)TstExternalUPcopySTtoCbytes);
    UPRegisterSymbolAndHandle("TstExternalUPcopySTtoCfloatArray", (void*)TstExternalUPcopySTtoCfloatArray);
    UPRegisterSymbolAndHandle("TstExternalUPcopySTtoCintArray", (void*)TstExternalUPcopySTtoCintArray);
    UPRegisterSymbolAndHandle("TstExternalUPcopySTtoCstring", (void*)TstExternalUPcopySTtoCstring);
    UPRegisterSymbolAndHandle("TstExternalUPfloatAt", (void*)TstExternalUPfloatAt);
    UPRegisterSymbolAndHandle("TstExternalUPfloatAtPut", (void*)TstExternalUPfloatAtPut);
    UPRegisterSymbolAndHandle("TstExternalUPindexVarSize", (void*)TstExternalUPindexVarSize);
    UPRegisterSymbolAndHandle("TstExternalUPinstVarAt", (void*)TstExternalUPinstVarAt);
    UPRegisterSymbolAndHandle("TstExternalUPinstVarAtPut", (void*)TstExternalUPinstVarAtPut);
    UPRegisterSymbolAndHandle("TstExternalUPinstVarSize", (void*)TstExternalUPinstVarSize);
    UPRegisterSymbolAndHandle("TstExternalUPintegerAtPut", (void*)TstExternalUPintegerAtPut);
    UPRegisterSymbolAndHandle("TstExternalUPisArrayOfFloat", (void*)TstExternalUPisArrayOfFloat);
    UPRegisterSymbolAndHandle("TstExternalUPisArrayOfInteger", (void*)TstExternalUPisArrayOfInteger);
    UPRegisterSymbolAndHandle("TstExternalUPisBoolean", (void*)TstExternalUPisBoolean);
    UPRegisterSymbolAndHandle("TstExternalUPisByteArray", (void*)TstExternalUPisByteArray);
    UPRegisterSymbolAndHandle("TstExternalUPisCharacter", (void*)TstExternalUPisCharacter);
    UPRegisterSymbolAndHandle("TstExternalUPisFloat", (void*)TstExternalUPisFloat);
    UPRegisterSymbolAndHandle("TstExternalUPisInteger", (void*)TstExternalUPisInteger);
    UPRegisterSymbolAndHandle("TstExternalUPisString", (void*)TstExternalUPisString);
    UPRegisterSymbolAndHandle("TstExternalUPnil", (void*)TstExternalUPnil);
    UPRegisterSymbolAndHandle("TstExternalUPreturnFalse", (void*)TstExternalUPreturnFalse);
    UPRegisterSymbolAndHandle("TstExternalUPreturnTrue", (void*)TstExternalUPreturnTrue);
    UPRegisterSymbolAndHandle("TstExternalUPreturnNil", (void*)TstExternalUPreturnNil);
    UPRegisterSymbolAndHandle("TstExternalUPreturnHandle", (void*)TstExternalUPreturnHandle);
    UPRegisterSymbolAndHandle("TstExternalUPerrorHandler", (void*)TstExternalUPerrorHandler);
	UPRegisterSymbolAndHandle("TstExternalUPisByteLike", (void*)TstExternalUPisByteLike);
	UPRegisterSymbolAndHandle("TstExternalUPintegerAt", (void*)TstExternalUPintegerAt);
	UPRegisterSymbolAndHandle("TstExternalUPregHandleAt", (void*)TstExternalUPregHandleAt);
	UPRegisterSymbolAndHandle("TstExternalUPregHandleAtPut", (void*)TstExternalUPregHandleAtPut);
	UPRegisterSymbolAndHandle("TstExternalUPallocRegSlot", (void*)TstExternalUPallocRegSlot);
	UPRegisterSymbolAndHandle("TstExternalUPallocFs", (void*)TstExternalUPallocFs);
	UPRegisterSymbolAndHandle("TstExternalUPallocVs", (void*)TstExternalUPallocVs);
	UPRegisterSymbolAndHandle("TstExternalUPclassType", (void*)TstExternalUPclassType);
	UPRegisterSymbolAndHandle("TstExternalUPsignalSem", (void*)TstExternalUPsignalSem);
	UPRegisterSymbolAndHandle("TstExternalUPpostInt", (void*)TstExternalUPpostInt);	/* installs poll-handler */
	UPRegisterSymbolAndHandle("TstExternalUPisKindOf", (void*)TstExternalUPisKindOf);
	UPRegisterSymbolAndHandle("TstExternalUPisDouble", (void*)TstExternalUPisDouble);
	UPRegisterSymbolAndHandle("TstExternalUPCtoSTdouble", (void*)TstExternalUPCtoSTdouble);
	UPRegisterSymbolAndHandle("TstExternalUPSTtoCdouble", (void*)TstExternalUPSTtoCdouble);
	UPRegisterSymbolAndHandle("TstExternalUPclass", (void*)TstExternalUPclass);
	UPRegisterSymbolAndHandle("TstExternalUPisImmediate", (void*)TstExternalUPisImmediate);

	UPRegisterSymbolAndHandle("TstExternalUPnestedReturn", (void*)TstExternalUPnestedReturn);
	UPRegisterSymbolAndHandle("TstExternalUPmustBeArrayOfFloat", (void*)TstExternalUPmustBeArrayOfFloat);
	UPRegisterSymbolAndHandle("TstExternalUPmustBeArrayOfInteger", (void*)TstExternalUPmustBeArrayOfInteger);
	UPRegisterSymbolAndHandle("TstExternalUPmustBeBoolean", (void*)TstExternalUPmustBeBoolean);
	UPRegisterSymbolAndHandle("TstExternalUPmustBeByteArray", (void*)TstExternalUPmustBeByteArray);
	UPRegisterSymbolAndHandle("TstExternalUPmustBeByteLike", (void*)TstExternalUPmustBeByteLike);
	UPRegisterSymbolAndHandle("TstExternalUPmustBeCharacter", (void*)TstExternalUPmustBeCharacter);
	UPRegisterSymbolAndHandle("TstExternalUPmustBeInteger", (void*)TstExternalUPmustBeInteger);
	UPRegisterSymbolAndHandle("TstExternalUPmustBeString", (void*)TstExternalUPmustBeString);
	UPRegisterSymbolAndHandle("TstExternalUPdoubleAt", (void*)TstExternalUPdoubleAt);

	/* performance tests */
	UPRegisterSymbolAndHandle("TstExternalSumByteArray", (void*)TstExternalSumByteArray);
	UPRegisterSymbolAndHandle("TstExternalZeroArray", (void*)TstExternalZeroArray);

	UPRegisterSymbolAndHandle("testCallback1", (void*)testCallback1);
	UPRegisterSymbolAndHandle("testCallback2", (void*)testCallback2);
	UPRegisterSymbolAndHandle("testCallback3", (void*)testCallback3);
	UPRegisterSymbolAndHandle("testCallback4", (void*)testCallback4);
	UPRegisterSymbolAndHandle("testCallback5", (void*)testCallback5);
	UPRegisterSymbolAndHandle("testCallback6", (void*)testCallback6);
	UPRegisterSymbolAndHandle("testCallback7", (void*)testCallback7);
	UPRegisterSymbolAndHandle("testCallback8", (void*)testCallback8);
	UPRegisterSymbolAndHandle("testCallback9", (void*)testCallback9);
	UPRegisterSymbolAndHandle("testCallback10", (void*)testCallback10);
	UPRegisterSymbolAndHandle("testCallback11", (void*)testCallback11);
	UPRegisterSymbolAndHandle("testCallback12", (void*)testCallback12);
	UPRegisterSymbolAndHandle("testCallback13", (void*)testCallback13);
	UPRegisterSymbolAndHandle("testCallback14", (void*)testCallback14);
	UPRegisterSymbolAndHandle("testCallback15", (void*)testCallback15);
	UPRegisterSymbolAndHandle("testCallback16", (void*)testCallback16);
	UPRegisterSymbolAndHandle("testCallback17", (void*)testCallback17);
	UPRegisterSymbolAndHandle("testCallback18", (void*)testCallback18);
	UPRegisterSymbolAndHandle("testCallback19", (void*)testCallback19);
	UPRegisterSymbolAndHandle("testCallback20", (void*)testCallback20);
	UPRegisterSymbolAndHandle("testCallback21", (void*)testCallback21);
	UPRegisterSymbolAndHandle("testCallback22", (void*)testCallback22);
	UPRegisterSymbolAndHandle("testCallback23", (void*)testCallback23);
	UPRegisterSymbolAndHandle("testCallback24", (void*)testCallback24);
	UPRegisterSymbolAndHandle("testCallback25", (void*)testCallback25);
	UPRegisterSymbolAndHandle("testCallback26", (void*)testCallback26);
	UPRegisterSymbolAndHandle("testCallback27", (void*)testCallback27);
	UPRegisterSymbolAndHandle("testCallback28", (void*)testCallback28);
	UPRegisterSymbolAndHandle("testCallback29", (void*)testCallback29);
	UPRegisterSymbolAndHandle("testCallback30", (void*)testCallback30);
	UPRegisterSymbolAndHandle("testCallback31", (void*)testCallback31);
	UPRegisterSymbolAndHandle("testCallback32", (void*)testCallback32);
	UPRegisterSymbolAndHandle("testCallback33", (void*)testCallback33);
	UPRegisterSymbolAndHandle("testCallback34", (void*)testCallback34);
	UPRegisterSymbolAndHandle("testCallback35", (void*)testCallback35);
	UPRegisterSymbolAndHandle("testCallback36", (void*)testCallback36);
	UPRegisterSymbolAndHandle("testCallback37", (void*)testCallback37);
	UPRegisterSymbolAndHandle("testCallback38", (void*)testCallback38);
	UPRegisterSymbolAndHandle("testCallback39", (void*)testCallback39);
	UPRegisterSymbolAndHandle("testCallback40", (void*)testCallback40);
	UPRegisterSymbolAndHandle("testCallback41", (void*)testCallback41);
	UPRegisterSymbolAndHandle("testCallback42", (void*)testCallback42);
	UPRegisterSymbolAndHandle("testCallback43", (void*)testCallback43);
	UPRegisterSymbolAndHandle("testCallback44", (void*)testCallback44);
	UPRegisterSymbolAndHandle("testCallback45", (void*)testCallback45);
	UPRegisterSymbolAndHandle("testCallback46", (void*)testCallback46);
	UPRegisterSymbolAndHandle("testCallback47", (void*)testCallback47);
	UPRegisterSymbolAndHandle("testCallback48", (void*)testCallback48);
	UPRegisterSymbolAndHandle("testCallback49", (void*)testCallback49);
	UPRegisterSymbolAndHandle("testCallback50", (void*)testCallback50);
	UPRegisterSymbolAndHandle("testCallback51", (void*)testCallback51);
	UPRegisterSymbolAndHandle("testCallback52", (void*)testCallback52);
	UPRegisterSymbolAndHandle("testCallback53", (void*)testCallback53);
	UPRegisterSymbolAndHandle("testCallback54", (void*)testCallback54);
	UPRegisterSymbolAndHandle("testCallback55", (void*)testCallback55);
	UPRegisterSymbolAndHandle("testCallback56", (void*)testCallback56);
	UPRegisterSymbolAndHandle("testCallback57", (void*)testCallback57);
	UPRegisterSymbolAndHandle("testCallback58", (void*)testCallback58);
	UPRegisterSymbolAndHandle("testCallback59", (void*)testCallback59);
	UPRegisterSymbolAndHandle("testCallback60", (void*)testCallback60);
	UPRegisterSymbolAndHandle("testCallback61", (void*)testCallback61);
	UPRegisterSymbolAndHandle("testCallback62", (void*)testCallback62);
	UPRegisterSymbolAndHandle("testCallback63", (void*)testCallback63);
	UPRegisterSymbolAndHandle("testCallback64", (void*)testCallback64);
	UPRegisterSymbolAndHandle("testCallback65", (void*)testCallback65);
	UPRegisterSymbolAndHandle("testCallback66", (void*)testCallback66);
	UPRegisterSymbolAndHandle("testCallback67", (void*)testCallback67);
	UPRegisterSymbolAndHandle("testCallback68", (void*)testCallback68);
	UPRegisterSymbolAndHandle("testCallback69", (void*)testCallback69);
	UPRegisterSymbolAndHandle("testCallback70", (void*)testCallback70);
	UPRegisterSymbolAndHandle("testCallback71", (void*)testCallback71);
	UPRegisterSymbolAndHandle("testCallback72", (void*)testCallback72);

	UPRegisterSymbolAndHandle("test1", (void*)test1);
	UPRegisterSymbolAndHandle("test2", (void*)test2);
	UPRegisterSymbolAndHandle("test3", (void*)test3);
	UPRegisterSymbolAndHandle("test4", (void*)test4);
	UPRegisterSymbolAndHandle("test5", (void*)test5);
	UPRegisterSymbolAndHandle("test6", (void*)test6);
	UPRegisterSymbolAndHandle("test7", (void*)test7);
	UPRegisterSymbolAndHandle("test8", (void*)test8);
	UPRegisterSymbolAndHandle("test9", (void*)test9);
	UPRegisterSymbolAndHandle("test10", (void*)test10);
	UPRegisterSymbolAndHandle("test11", (void*)test11);
	UPRegisterSymbolAndHandle("test12", (void*)test12);
	UPRegisterSymbolAndHandle("test13", (void*)test13);
	UPRegisterSymbolAndHandle("test14", (void*)test14);
	UPRegisterSymbolAndHandle("test15", (void*)test15);
	UPRegisterSymbolAndHandle("test16", (void*)test16);
	UPRegisterSymbolAndHandle("test17", (void*)test17);
	UPRegisterSymbolAndHandle("test18", (void*)test18);
	UPRegisterSymbolAndHandle("test19", (void*)test19);
	UPRegisterSymbolAndHandle("test20", (void*)test20);
	UPRegisterSymbolAndHandle("test21", (void*)test21);
	UPRegisterSymbolAndHandle("test22", (void*)test22);
	UPRegisterSymbolAndHandle("test23", (void*)test23);
	UPRegisterSymbolAndHandle("test24", (void*)test24);
	UPRegisterSymbolAndHandle("test25", (void*)test25);
	UPRegisterSymbolAndHandle("test26", (void*)test26);
	UPRegisterSymbolAndHandle("test27", (void*)test27);
	UPRegisterSymbolAndHandle("test28", (void*)test28);
	UPRegisterSymbolAndHandle("test29", (void*)test29);
	UPRegisterSymbolAndHandle("test30", (void*)test30);
	UPRegisterSymbolAndHandle("test31", (void*)test31);
	UPRegisterSymbolAndHandle("test32", (void*)test32);
	UPRegisterSymbolAndHandle("test33", (void*)test33);
	UPRegisterSymbolAndHandle("test34", (void*)test34);
	UPRegisterSymbolAndHandle("test35", (void*)test35);
	UPRegisterSymbolAndHandle("test36", (void*)test36);
	UPRegisterSymbolAndHandle("test37", (void*)test37);
	UPRegisterSymbolAndHandle("test38", (void*)test38);
	UPRegisterSymbolAndHandle("test39", (void*)test39);
	UPRegisterSymbolAndHandle("test40", (void*)test40);
	UPRegisterSymbolAndHandle("test41", (void*)test41);
	UPRegisterSymbolAndHandle("test42", (void*)test42);
	UPRegisterSymbolAndHandle("test43", (void*)test43);
	UPRegisterSymbolAndHandle("test44", (void*)test44);
	UPRegisterSymbolAndHandle("test45", (void*)test45);
	UPRegisterSymbolAndHandle("test46", (void*)test46);
	UPRegisterSymbolAndHandle("test47", (void*)test47);
	UPRegisterSymbolAndHandle("test48", (void*)test48);
	UPRegisterSymbolAndHandle("test49", (void*)test49);
	UPRegisterSymbolAndHandle("test50", (void*)test50);
	UPRegisterSymbolAndHandle("test51", (void*)test51);
	UPRegisterSymbolAndHandle("test52", (void*)test52);
	UPRegisterSymbolAndHandle("test53", (void*)test53);
	UPRegisterSymbolAndHandle("test54", (void*)test54);
	UPRegisterSymbolAndHandle("test55", (void*)test55);
	UPRegisterSymbolAndHandle("test56", (void*)test56);
	UPRegisterSymbolAndHandle("test57", (void*)test57);
	UPRegisterSymbolAndHandle("test58", (void*)test58);
	UPRegisterSymbolAndHandle("test59", (void*)test59);
	UPRegisterSymbolAndHandle("test60", (void*)test60);
	UPRegisterSymbolAndHandle("test61", (void*)test61);
	UPRegisterSymbolAndHandle("test62", (void*)test62);
	UPRegisterSymbolAndHandle("test63", (void*)test63);
	UPRegisterSymbolAndHandle("test64", (void*)test64);
	UPRegisterSymbolAndHandle("test65", (void*)test65);
	UPRegisterSymbolAndHandle("test66", (void*)test66);
	UPRegisterSymbolAndHandle("test67", (void*)test67);
	UPRegisterSymbolAndHandle("test68", (void*)test68);
	UPRegisterSymbolAndHandle("test69", (void*)test69);
	UPRegisterSymbolAndHandle("test70", (void*)test70);
	UPRegisterSymbolAndHandle("test71", (void*)test71);
	UPRegisterSymbolAndHandle("test72", (void*)test72);

	UPRegisterSymbolAndHandle("globalChar", (void*)&globalChar);
	UPRegisterSymbolAndHandle("unsignedChar", (void*)&unsignedChar);
	UPRegisterSymbolAndHandle("globalShort", (void*)&globalShort);
	UPRegisterSymbolAndHandle("globalInt", (void*)&globalInt);
	UPRegisterSymbolAndHandle("unsignedInt", (void*)&unsignedInt);
	UPRegisterSymbolAndHandle("globalLong", (void*)&globalLong);
	UPRegisterSymbolAndHandle("unsignedLong", (void*)&unsignedLong);
	UPRegisterSymbolAndHandle("globalFloat", (void*)&globalFloat);
	UPRegisterSymbolAndHandle("globalDouble", (void*)&globalDouble);
	UPRegisterSymbolAndHandle("globalCharStruct", (void*)&globalCharStruct);
	UPRegisterSymbolAndHandle("globalBigStruct", (void*)&globalBigStruct);

	UPRegisterSymbolAndHandle("TstSendBackMany", (void*)TstSendBackMany);
	UPRegisterSymbolAndHandle("TstSendBack0", (void*)TstSendBack0);
	UPRegisterSymbolAndHandle("TstSendBack1", (void*)TstSendBack1);
	UPRegisterSymbolAndHandle("TstSendBack2", (void*)TstSendBack2);
	UPRegisterSymbolAndHandle("TstSendBack3", (void*)TstSendBack3);
	UPRegisterSymbolAndHandle("TstSendcBackMany", (void*)TstSendcBackMany);
	UPRegisterSymbolAndHandle("TstSendcBack0", (void*)TstSendcBack0);
	UPRegisterSymbolAndHandle("TstSendcBack1", (void*)TstSendcBack1);
	UPRegisterSymbolAndHandle("TstSendcBack2", (void*)TstSendcBack2);
	UPRegisterSymbolAndHandle("TstSendcBack3", (void*)TstSendcBack3);
	UPRegisterSymbolAndHandle("TstSendBack0IfFailNoReturn", (void*)TstSendBack0IfFailNoReturn);
	UPRegisterSymbolAndHandle("TstSendBack0IfFailReturnFalse", (void*)TstSendBack0IfFailReturnFalse);
	UPRegisterSymbolAndHandle("TstSendBack0ReturnKeptReceiver", (void*)TstSendBack0ReturnKeptReceiver);

	UPRegisterSymbolAndHandle("oeTstSendBackKeepFailure", (void *)oeTstSendBackKeepFailure);
	UPRegisterSymbolAndHandle("oeTstSendBackMany", (void *)oeTstSendBackMany);
	UPRegisterSymbolAndHandle("oeTstSendBack0", (void *)oeTstSendBack0);
	UPRegisterSymbolAndHandle("oeTstSendBack1", (void *)oeTstSendBack1);
	UPRegisterSymbolAndHandle("oeTstSendBack2", (void *)oeTstSendBack2);
	UPRegisterSymbolAndHandle("oeTstSendBack3", (void *)oeTstSendBack3);
	UPRegisterSymbolAndHandle("oeTstSendcBackMany", (void *)oeTstSendcBackMany);
	UPRegisterSymbolAndHandle("oeTstSendcBack0", (void *)oeTstSendcBack0);
	UPRegisterSymbolAndHandle("oeTstSendcBack1", (void *)oeTstSendcBack1);
	UPRegisterSymbolAndHandle("oeTstSendcBack2", (void *)oeTstSendcBack2);
	UPRegisterSymbolAndHandle("oeTstSendcBack3", (void *)oeTstSendcBack3);
	UPRegisterSymbolAndHandle("oeTstSendBack0IfFailNoReturn", (void *)oeTstSendBack0IfFailNoReturn);
	UPRegisterSymbolAndHandle("oeTstSendBack0IfFailReturnFalse", (void *)oeTstSendBack0IfFailReturnFalse);
	UPRegisterSymbolAndHandle("oeTstSendBack0ReturnKeptReceiver", (void *)oeTstSendBack0ReturnKeptReceiver);
	UPRegisterSymbolAndHandle("oeTstExternalCtoOEbool", (void *)oeTstExternalCtoOEbool);
	UPRegisterSymbolAndHandle("oeTstExternalCtoOEchar", (void *)oeTstExternalCtoOEchar);
	UPRegisterSymbolAndHandle("oeTstExternalCtoOEfloat", (void *)oeTstExternalCtoOEfloat);
	UPRegisterSymbolAndHandle("oeTstExternalCtoOEint", (void *)oeTstExternalCtoOEint);
	UPRegisterSymbolAndHandle("oeTstExternalOEtoCbool", (void *)oeTstExternalOEtoCbool);
	UPRegisterSymbolAndHandle("oeTstExternalOEtoCchar", (void *)oeTstExternalOEtoCchar);
	UPRegisterSymbolAndHandle("oeTstExternalOEtoCfloat", (void *)oeTstExternalOEtoCfloat);
	UPRegisterSymbolAndHandle("oeTstExternalOEtoCint", (void *)oeTstExternalOEtoCint);
	UPRegisterSymbolAndHandle("oeTstExternalBasicAt", (void *)oeTstExternalBasicAt);
	UPRegisterSymbolAndHandle("oeTstExternalBasicAtPut", (void *)oeTstExternalBasicAtPut);
	UPRegisterSymbolAndHandle("oeTstExternalByteAt", (void *)oeTstExternalByteAt);
	UPRegisterSymbolAndHandle("oeTstExternalByteAtPut", (void *)oeTstExternalByteAtPut);
	UPRegisterSymbolAndHandle("oeTstExternalCopyCtoOEintArray", (void *)oeTstExternalCopyCtoOEintArray);
	UPRegisterSymbolAndHandle("oeTstExternalCopyCtoOEbytes", (void *)oeTstExternalCopyCtoOEbytes);
	UPRegisterSymbolAndHandle("oeTstExternalCopyCtoOEfloatArray", (void *)oeTstExternalCopyCtoOEfloatArray);
	UPRegisterSymbolAndHandle("oeTstExternalCopyCtoOEstring", (void *)oeTstExternalCopyCtoOEstring);
	UPRegisterSymbolAndHandle("oeTstExternalCopyOEtoCbytes", (void *)oeTstExternalCopyOEtoCbytes);
	UPRegisterSymbolAndHandle("oeTstExternalCopyOEtoCfloatArray", (void *)oeTstExternalCopyOEtoCfloatArray);
	UPRegisterSymbolAndHandle("oeTstExternalCopyOEtoCintArray", (void *)oeTstExternalCopyOEtoCintArray);
	UPRegisterSymbolAndHandle("oeTstExternalCopyOEtoCstring", (void *)oeTstExternalCopyOEtoCstring);
	UPRegisterSymbolAndHandle("oeTstExternalFloatAt", (void *)oeTstExternalFloatAt);
	UPRegisterSymbolAndHandle("oeTstExternalIntegerAt", (void *)oeTstExternalIntegerAt);
	UPRegisterSymbolAndHandle("oeTstExternalFloatAtPut", (void *)oeTstExternalFloatAtPut);
	UPRegisterSymbolAndHandle("oeTstExternalIndexVarSize", (void *)oeTstExternalIndexVarSize);
	UPRegisterSymbolAndHandle("oeTstExternalInstVarAt", (void *)oeTstExternalInstVarAt);
	UPRegisterSymbolAndHandle("oeTstExternalInstVarAtPut", (void *)oeTstExternalInstVarAtPut);
	UPRegisterSymbolAndHandle("oeTstExternalInstVarSize", (void *)oeTstExternalInstVarSize);
	UPRegisterSymbolAndHandle("oeTstExternalIntegerAtPut", (void *)oeTstExternalIntegerAtPut);
	UPRegisterSymbolAndHandle("oeTstExternalIsArrayOfFloat", (void *)oeTstExternalIsArrayOfFloat);
	UPRegisterSymbolAndHandle("oeTstExternalIsArrayOfInteger", (void *)oeTstExternalIsArrayOfInteger);
	UPRegisterSymbolAndHandle("oeTstExternalIsBoolean", (void *)oeTstExternalIsBoolean);
	UPRegisterSymbolAndHandle("oeTstExternalIsByteArray", (void *)oeTstExternalIsByteArray);
	UPRegisterSymbolAndHandle("oeTstExternalIsCharacter", (void *)oeTstExternalIsCharacter);
	UPRegisterSymbolAndHandle("oeTstExternalIsFloat", (void *)oeTstExternalIsFloat);
	UPRegisterSymbolAndHandle("oeTstExternalIsInteger", (void *)oeTstExternalIsInteger);
	UPRegisterSymbolAndHandle("oeTstExternalIsString", (void *)oeTstExternalIsString);
	UPRegisterSymbolAndHandle("oeTstExternalIsByteLike", (void *)oeTstExternalIsByteLike);
	UPRegisterSymbolAndHandle("oeTstExternalNil", (void *)oeTstExternalNil);
	UPRegisterSymbolAndHandle("oeTstreturn", (void *)oeTstreturn);
	UPRegisterSymbolAndHandle("oeTstExternalReturnFalse", (void *)oeTstExternalReturnFalse);
	UPRegisterSymbolAndHandle("oeTstExternalReturnHandle", (void *)oeTstExternalReturnHandle);
	UPRegisterSymbolAndHandle("oeTstExternalNestedReturn", (void *)oeTstExternalNestedReturn);
	UPRegisterSymbolAndHandle("oeTstExternalReturnNil", (void *)oeTstExternalReturnNil);
	UPRegisterSymbolAndHandle("oeTstExternalReturnTrue", (void *)oeTstExternalReturnTrue);
	UPRegisterSymbolAndHandle("oeTstExternalRegHandleAt", (void *)oeTstExternalRegHandleAt);
	UPRegisterSymbolAndHandle("oeTstExternalIsImmediate", (void *)oeTstExternalIsImmediate);
	UPRegisterSymbolAndHandle("oeTstExternalAllocRegSlot", (void *)oeTstExternalAllocRegSlot);
	UPRegisterSymbolAndHandle("oeTstExternalRegHandleAtPut", (void *)oeTstExternalRegHandleAtPut);
	UPRegisterSymbolAndHandle("oeTstExternalAllocFs", (void *)oeTstExternalAllocFs);
	UPRegisterSymbolAndHandle("oeTstExternalAllocVs", (void *)oeTstExternalAllocVs);
	UPRegisterSymbolAndHandle("oeTstExternalClassType", (void *)oeTstExternalClassType);
	UPRegisterSymbolAndHandle("oeTstExternalSignalSem", (void *)oeTstExternalSignalSem);
	UPRegisterSymbolAndHandle("oeTstExternalMyPollHandler", (void *)oeTstExternalMyPollHandler);
	UPRegisterSymbolAndHandle("oeTstExternalPostInt", (void *)oeTstExternalPostInt);
	UPRegisterSymbolAndHandle("oeTstExternalIsKindOf", (void *)oeTstExternalIsKindOf);
	UPRegisterSymbolAndHandle("oeTstExternalCtoOEdouble", (void *)oeTstExternalCtoOEdouble);
	UPRegisterSymbolAndHandle("oeTstExternalOEtoCdouble", (void *)oeTstExternalOEtoCdouble);
	UPRegisterSymbolAndHandle("oeTstExternalIsDouble", (void *)oeTstExternalIsDouble);
	UPRegisterSymbolAndHandle("oeTstExternalClass", (void *)oeTstExternalClass);
	UPRegisterSymbolAndHandle("oeTstExternalSumByteArray", (void *)oeTstExternalSumByteArray);
	UPRegisterSymbolAndHandle("oeTstExternalZeroArray", (void *)oeTstExternalZeroArray);
	UPRegisterSymbolAndHandle("oeTstExternalDoubleAt", (void *)oeTstExternalDoubleAt);
	UPRegisterSymbolAndHandle("oeTstExternalLongRun", (void *)oeTstExternalLongRun);
}
