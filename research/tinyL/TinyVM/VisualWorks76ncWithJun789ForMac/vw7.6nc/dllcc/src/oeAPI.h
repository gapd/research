/***************************************************************************
 * File: oeAPI.h
 *
 * Interface definitions for the ObjectEngine (OE) Application Programming
 * Interface (API).
 *
 * The following definitions must be included by user code before accessing
 * the public ObjectEngine protocol.  This protocol is designed to provide
 * access to some of the features implemented in the engine, including object
 * allocation, object field accessing, and object identity testing.
 *
 * Read the WARNING on OEUNSAFE below if you intend to use the unsafe interface.
 *
 * This header file is purposely void of comments. Please consult the User's
 * Guide for more detailed information on this API.
 *
 *	Copyright (C) 1999-2007 Cincom Systems, Inc.
 *	Santa Clara, California.  All Rights Reserved.
 *
 ***************************************************************************/

#ifndef _oeAPI_h
#define _oeAPI_h

#if defined(c_plusplus) || defined(__cplusplus)
extern "C" {
#endif

/* ======================== Defines ============================ */

/* default to VW32, but insist on consistent definitions if defined */
#if VW32
# if VW64
#	error "cannot be both VW32 and VW64"
# endif
#elif VW64
#else
# define VW32 1
#endif

#ifndef OEENTRY
#ifdef _OS2
#define OEENTRY _Optlink
#else
#define OEENTRY
#endif
#endif

#define OEnonOop ((OEoop) 0)

/* =================== Type Definitions ======================= */

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif


typedef enum {
	OEFALSE = 0,
	OETRUE  = 1
}                          OEbool;
typedef unsigned char      OEbyte;
/* OEint must be exactly 32 bits long. */
#ifdef OSF32
typedef int                OEint;
#else
typedef long               OEint;
#endif
typedef float              OEfloat;
typedef double             OEdouble;
typedef char               OEchar;
#ifdef OSF32
#	pragma pointer_size (save)
#	pragma pointer_size (short)
#endif
typedef void              *OEoop;
#ifdef OSF32
#	pragma pointer_size (restore)
#endif
typedef void             (*OEvoidFuncPtr)(void);

typedef enum {
	OEnotAClassID		= 0,
	OEfixedSizeClassID	= 1,
	OEvariableSizeClassID	= 2
} OEclassID;

typedef enum {
	OEpointerType	= 0,
	OEbyteType	= 1,
	OEimmediateType	= 2
} OEoopType;

typedef enum {
	OEerrorNone             = 0,
	OEerrorCrange           = 1,
	OEerrorNonOop           = 2,
	OEerrorWrongClass       = 3,
	OEerrorObjectTooSmall   = 4,
	OEerrorAllocationFailed = 5,
	OEerrorStoreFailure     = 6,
    OEerrorSrange           = 7,
    OEerrorArgCheckFailed   = 8
} OEerrorCodeID;

/* ================ Exported Functions ==================== */

extern int oeMain(int, char**, char**);
/* UPfail is to be replaced by oeFail.  We use UPfail for now. */
extern void OEENTRY UPfail(OEint);
#define oeFail(v) UPfail(v)

#ifdef OEUNSAFE
#ifdef OSF32
#	pragma pointer_size (save)
#	pragma pointer_size (short)
#endif
typedef struct oe_otEntryS *oe_oop;
#ifdef OSF32
#	pragma pointer_size (restore)
#endif
#define OEoop oe_oop
#else
typedef OEoop oe_oop;
#endif

#ifndef OEUNSAFE
extern OEoop OEENTRY oeNil(void);
extern OEoop OEENTRY oeTrue(void);
extern OEoop OEENTRY oeFalse(void);
extern OEoop OEENTRY oeSmallIntegerClass(void);
extern OEoop OEENTRY oeCharacterClass(void);
extern OEoop OEENTRY oeFloatClass(void);
extern OEoop OEENTRY oePointClass(void);
extern OEoop OEENTRY oeArrayClass(void);
extern OEoop OEENTRY oeSemaphoreClass(void);
extern OEoop OEENTRY oeByteStringClass(void);
extern OEoop OEENTRY oeLargePositiveIntegerClass(void);
extern OEoop OEENTRY oeLargeNegativeIntegerClass(void);
extern OEoop OEENTRY oeByteArrayClass(void);
extern OEoop OEENTRY oeTwoByteStringClass(void);
extern OEoop OEENTRY oeTwoByteSymbolClass(void);
extern OEoop OEENTRY oeDoubleClass(void);

extern OEoop OEENTRY oeOEToCbool(OEoop, OEbool *);
extern OEoop OEENTRY oeOEToCint(OEoop, OEint *);
extern OEoop OEENTRY oeOEToCchar(OEoop, OEchar *);
extern OEoop OEENTRY oeOEToCfloat(OEoop, OEfloat *);
extern OEoop OEENTRY oeCtoOEbool(OEbool);
extern OEoop OEENTRY oeCtoOEint(OEint);
extern OEoop OEENTRY oeCtoOEchar(OEchar);

extern OEoop OEENTRY oeInstVarSize(OEoop, OEint *);
extern OEoop OEENTRY oeIndexVarSize(OEoop, OEint *);
extern OEoop OEENTRY oeBasicAt(OEoop, OEint);
extern OEoop OEENTRY oeInstVarAt(OEoop, OEint);
extern void *OEENTRY oeOopDataPtr(OEoop);
extern OEoop OEENTRY oeByteAt(OEoop, OEint, OEbyte *);
extern OEoop OEENTRY oeIntegerAt(OEoop, OEint, OEint *);
extern OEoop OEENTRY oeFloatAt(OEoop, OEint, OEfloat *);
extern OEoop OEENTRY oeByteAtPut(OEoop, OEint, OEbyte);
extern OEoop OEENTRY oeIntegerAtPut(OEoop, OEint, OEint);

extern OEbool OEENTRY oeIsCharacter(OEoop);
extern OEbool OEENTRY oeIsInteger(OEoop);
extern OEbool OEENTRY oeIsString(OEoop);
extern OEbool OEENTRY oeIsByteArray(OEoop);
extern OEbool OEENTRY oeIsBoolean(OEoop);
extern OEbool OEENTRY oeIsFloat(OEoop);
extern OEbool OEENTRY oeIsDouble(OEoop);
extern OEbool OEENTRY oeIsByteLike(OEoop);
extern OEbool OEENTRY oeIsImmediate(OEoop);

extern OEoop OEENTRY oeRegisteredHandleAt(OEint);
extern OEoop OEENTRY oeClass(OEoop);
#endif

extern OEoop OEENTRY oeSendMessage0(OEoop, OEoop, OEoop *, OEoop);
extern OEoop OEENTRY oeSendMessage1(OEoop, OEoop, OEoop, OEoop *, OEoop);
extern OEoop OEENTRY oeSendMessage2(OEoop, OEoop, OEoop, OEoop, OEoop *, OEoop);
extern OEoop OEENTRY oeSendMessage3(OEoop, OEoop, OEoop, OEoop, OEoop, OEoop *, OEoop);
extern OEoop OEENTRY oeSendMessageMany(OEoop, OEoop, OEoop, OEoop *, OEoop);

extern OEoop OEENTRY oeCSendMessage0(OEoop, char *, OEoop *, OEoop);
extern OEoop OEENTRY oeCSendMessage1(OEoop, char *, OEoop, OEoop *, OEoop);
extern OEoop OEENTRY oeCSendMessage2(OEoop, char *, OEoop, OEoop, OEoop *, OEoop);
extern OEoop OEENTRY oeCSendMessage3(OEoop, char *, OEoop, OEoop, OEoop, OEoop *, OEoop);
extern OEoop OEENTRY oeCSendMessageMany(OEoop, char *, OEoop *, long, OEoop *, OEoop);

extern void   OEENTRY oeRegisterSymbolAndHandle(char  *, void  *);
extern OEbool OEENTRY oeAddPrimitive(OEint, void *, OEint);

extern OEoop OEENTRY oeOEToCdouble(OEoop, OEdouble *);
extern OEoop OEENTRY oeCtoOEfloat(OEfloat);
extern OEoop OEENTRY oeCtoOEdouble(OEdouble);

extern OEoop OEENTRY oeCopyOEtoCstring(OEoop, OEchar  *, OEint, OEint, OEint *);
extern OEoop OEENTRY oeCopyOEtoCbytes(OEoop, OEbyte  *, OEint, OEint, OEint *);
extern OEoop OEENTRY oeCopyOEtoCintArray(OEoop, OEint  *, OEint, OEint, OEint *);
extern OEoop OEENTRY oeCopyOEtoCfloatArray(OEoop, OEfloat  *, OEint, OEint, OEint *);
extern OEoop OEENTRY oeCopyCtoOEstring(OEoop, OEchar  *, OEint, OEint, OEint *);
extern OEoop OEENTRY oeCopyCtoOEbytes(OEoop, OEbyte  *, OEint, OEint, OEint *);
extern OEoop OEENTRY oeCopyCtoOEintArray(OEoop, OEint  *, OEint, OEint, OEint *);
extern OEoop OEENTRY oeCopyCtoOEfloatArray(OEoop, OEfloat  *, OEint, OEint, OEint *);

extern OEbool OEENTRY oeIsArrayOfInteger(OEoop);
extern OEbool OEENTRY oeIsArrayOfFloat(OEoop);
extern OEbool OEENTRY oeIsKindOf(OEoop, OEoop);
extern OEbool OEENTRY oeCouldBeOop(OEoop);

extern OEoop OEENTRY oeDoubleAt(OEoop, OEint, OEdouble *);
extern OEoop OEENTRY oeBasicAtPut(OEoop, OEint, OEoop);
extern OEoop OEENTRY oeInstVarAtPut(OEoop, OEint, OEoop);
extern OEoop OEENTRY oeFloatAtPut(OEoop, OEint, OEfloat);

extern OEoop OEENTRY oeAllocString(OEchar, OEint);
extern OEoop OEENTRY oeAllocByteArray(OEbyte, OEint);
extern OEoop OEENTRY oeAllocArray(OEoop, OEint);
extern OEoop OEENTRY oeAllocFsObject(OEoop);
extern OEoop OEENTRY oeAllocVsObject(OEoop, OEint);
extern OEoop OEENTRY oeAllocVsObjectInFixedSpace(OEoop, OEint);
extern OEint OEENTRY oeAllocRegistrySlot(void);
extern OEoop OEENTRY oeRegisteredHandleAtPut(OEint, OEoop);

extern OEclassID OEENTRY oeClassType(OEoop);
extern OEbool OEENTRY oeSignalSemaphore(OEoop);
extern void OEENTRY oePostInterrupt(void);
extern OEvoidFuncPtr OEENTRY oeInstallPollHandler(OEvoidFuncPtr);

extern void OEENTRY oeStartLongComputation(OEint);
extern void OEENTRY oeFinishLongComputation(void);

extern OEerrorCodeID OEENTRY oeGetErrorCode(void);

#if defined(c_plusplus) || defined(__cplusplus)
}       /* end of C declarations */
#endif

#ifdef OEUNSAFE

/*
 * ======================================================================
 * WARNING -- If you compile your code with -DOEUNSAFE you will get
 * an equivalent ObjectEngine Access support API which will run somewhat
 * faster but bugs in your code can crash the resulting OE (rather
 * than fail), and worse some bugs can silently corrupt the VI.  You
 * should test your code VERY carefully before compiling with
 * -DOEUNSAFE and using the resulting OE's on VI's you care about.
 * Finally, OEs built with -DOEUNSAFE and their derived VI's will not be
 * handled by Cincom technical support.
 * ======================================================================
 *
 * Note:  This file defines a supported API for user-defined primitives.
 * Specific OE implementation details exposed by this code does *not*
 * represent a supported OE interface and hence will change from
 * release to release, and have hidden dependencies and restrictions which
 * may render them useless outside this context.  In other words, pretend
 * that you can't read the OEUNSAFE portion of this header file!
 * YOU HAVE BEEN WARNED!
 */

/*
 * Arithmetic right-shift operator macro.
 * You need to redefine this if your C compiler doesn't implement the ">>"
 * operator as an arithmetic shift when applied to a signed operand
 * (the shift is guaranteed to be logical if the operand is unsigned).
 */
#define oe_arithRShift(val, count) ((val) >> (count))

typedef int oe_oopInt;
typedef int oe_oopSized;
typedef unsigned int oe_oopUInt;
#ifdef OSF32
#	pragma pointer_size (save)
#	pragma pointer_size (short)
#endif
struct oe_otEntryS {
    char      *data;
    oe_oop      classOop;
    oe_oopUInt  flagWord;
};
#ifdef OSF32
#	pragma pointer_size (restore)
#endif

/*
 * macros for treatment of oops as bit-strings
 */
#define oe_oopBits(ooop) ((oe_oopUInt)(ooop))
#define oe_oopNum(ooop) ((oe_oopInt)(ooop))
#if VW32
# define oe_numTagBits 2
# define oe_tagBitsMask 3
# define oe_immBitMask 1
# define oe_intBitMask 2
# define oe_charTag 1
# define oe_intTag 3
# define oe_hasPtrsBitMask (1<<31)
# define oe_inRtBitMask (1<<28)
# define oe_firstSizeBit 16
# define oe_sizeBits 11
# define oe_numSizeValuesReserved 32
# define oe_sizeOvflVal ((1<<oe_sizeBits)-1)
# define oe_sizeFieldMask (oe_sizeOvflVal<<oe_firstSizeBit)
# define oe_sizeMaxNormalVal ((1<<oe_sizeBits)-(oe_numSizeValuesReserved+1))
#else
# define oe_numTagBits 3
# define oe_tagBitsMask 7
# define oe_immBitMask 1
# define oe_intBitMask 2
# define oe_dblBitMask 4
# define oe_charTag 1
# define oe_intTag 3
# define oe_dblTag 5
#endif

/*
 * Behavior format macros
 * Note that the masks apply to the oopIntVal of the format word.
 */
#define oe_classFixedFieldsMask ((1 << 12) - 1)
#define oe_classIndexableMask (1 << 12)
#define oe_classHasPtrsMask (1 << 14)
typedef struct oe_classS {
	oe_oop superclass;	/* Behavior */
	oe_oop mdict;		/* MethodDictionary */
	oe_oop format;		/* SmallInteger, instance format */
} oe_class;

/*
 * system oop registry and indicies
 */
extern oe_oop *sysOopRegistry;
#define oe_minReservedIndicies 32
#if !defined(nilOopX)
# if VW32
typedef enum {
	nilOopX						= 0,
	trueOopX					= 1,
	falseOopX					= 2,
	smallIntegerClassX			= 7,
	characterClassX				= 8,
	floatClassX					= 9,
	arrayClassX					= 12,
	semaphoreClassX				= 13,
	byteStringClassX			= 19,
	largePositiveIntegerClassX	= 20,
	largeNegativeIntegerClassX	= 28,
	uninterpretedBytesClassX	= 21,
	byteSymbolClassX			= 22,
	byteArrayClassX				= 24,
	twoByteStringClassX			= 29,
	twoByteSymbolClassX			= 30,
	doubleClassX				= 32
} OEknownSysOopSlots;
# else
typedef enum {
	nilOopX						= 0,
	trueOopX					= 1,
	falseOopX					= 2,
	smallIntegerClassX			= 4,
	smallDoubleClassX			= 5,
	characterClassX				= 6,
	floatClassX					= 28,
	arrayClassX					= 15,
	semaphoreClassX				= 16,
	byteStringClassX			= 17,
	largePositiveIntegerClassX	= 18,
	largeNegativeIntegerClassX	= 19,
	uninterpretedBytesClassX	= 20,
	byteSymbolClassX			= 21,
	byteArrayClassX				= 22,
	twoByteStringClassX			= 23,
	twoByteSymbolClassX			= 30,
	doubleClassX				= 25
} OEknownSysOopSlots;
# endif
#else /* e.g. if _DUNSAFE and including userprim.h */
typedef int OEknownSysOopSlots;
#endif

#define oe_bytesToOops(size) ((size) >> oe_numTagBits)
#define oe_oopIsImm(anOop) (oe_oopBits(anOop) & oe_immBitMask)
#define oe_oopIsInt(anOop) (oe_oopBits(anOop) & oe_intBitMask)
#define oe_asSmallInt(value) ((oe_oop)(((value) << oe_numTagBits) + oe_intTag))
#define oe_oopIntVal(anOop) oe_arithRShift(oe_oopNum(anOop), oe_numTagBits)
#define oe_oopIsChar(anOop) ((oe_oopBits(anOop) & oe_tagBitsMask) == oe_charTag)
#define oe_asChar(v) ((oe_oop)(((oe_oopUInt)(v) << oe_numTagBits) + oe_charTag))
#define oe_oopCharVal(anOop) (oe_oopBits(anOop) >> oe_numTagBits)

#define oe_objDataPtr(anOop, theType) ((theType *)((anOop)->data))
#define oe_objHasPtrs(anOop) ((anOop)->flagWord & oe_hasPtrsBitMask)
#define oe_objSizeField(anOop) /* private macro */ \
	(((anOop)->flagWord & oe_sizeFieldMask) >> oe_firstSizeBit)
#if VW32
# define oe_numFixedFields(anOop) \
	(oe_oopIntVal(oe_objDataPtr(oe_objClass(anOop), oe_class)->format) & \
		oe_classFixedFieldsMask)
# define oe_objDataSize(anOop) (oe_objSizeField(anOop) <= oe_sizeMaxNormalVal \
									? oe_objSizeField(anOop) \
									: *(oe_objDataPtr(anOop, oe_oopUInt) - 1))
#endif
#define oe_objVarDataPtr(anOop) \
    (oe_objDataPtr(anOop, oe_oop) + oe_numFixedFields(anOop))
#define oe_objVarOopSize(anOop) \
    (oe_bytesToOops(oe_objDataSize(anOop)) - oe_numFixedFields(anOop))

extern oe_oop oldNewSpaceBoundary;
#define oe_objInRt(ooop) ((ooop)->flagWord & oe_inRtBitMask)
#define oe_objIsNew(ooop) ((ooop) < oldNewSpaceBoundary)
extern OEbool registerInRt(oe_oop);
extern void chStOldObjInNonNew(oe_oop, oe_oopInt, oe_oop);

#if VW32
# define oe_objClass(anOop) ((anOop)->classOop)
# define oe_oopClass(ooop) \
 (!oe_oopIsImm(ooop) ? oe_objClass(ooop): \
  (oe_oopIsInt(ooop) ? oe_sysOop(smallIntegerClassX) : oe_sysOop(characterClassX)))
#endif
#define oe_isByteLike(anOop) (!oe_oopIsImm(anOop) && !oe_objHasPtrs(anOop))
#define oe_sysOop(index)	sysOopRegistry[index]

#define oeNil()							oe_sysOop(nilOopX)
#define oeTrue()						oe_sysOop(trueOopX)
#define oeFalse()						oe_sysOop(falseOopX)
#define oeSmallIntegerClass()			oe_sysOop(smallIntegerClassX)
#define oeCharacterClass()				oe_sysOop(characterClassX)
#define oeFloatClass()					oe_sysOop(floatClassX)
#define oeArrayClass()					oe_sysOop(arrayClassX)
#define oeSemaphoreClass()				oe_sysOop(semaphoreClassX)
#define oeByteStringClass()				oe_sysOop(byteStringClassX)
#define oeLargePositiveIntegerClass()	oe_sysOop(largePositiveIntegerClassX)
#define oeLargeNegativeIntegerClass()	oe_sysOop(largeNegativeIntegerClassX)
#define oeByteArrayClass()				oe_sysOop(byteArrayClassX)
#define oeTwoByteStringClass()			oe_sysOop(twoByteStringClassX)
#define oeTwoByteSymbolClass()			oe_sysOop(twoByteSymbolClassX)
#define oeDoubleClass()					oe_sysOop(doubleClassX)

#define oeOEToCbool(anOop, pOEbool) \
	((*(pOEbool) = ((anOop) == oe_sysOop(trueOopX))), anOop)
#define oeOEToCint(anOop, pOEint) ((*(pOEint) = oe_oopIntVal(anOop)), anOop)
#define oeOEToCchar(anOop, pOEchar) ((*(pOEchar) = oe_oopCharVal(anOop)), anOop)
#define oeOEToCfloat(anOop, pOEfloat) \
	((*(pOEfloat) = (*oe_objDataPtr((anOop), float))), anOop)
#if VW32
# define oeOEToCdouble(anOop, pOEdouble) \
	((*(pOEdouble) = (*oe_objDataPtr((anOop), double))), anOop)
#endif
#define oeCtoOEbool(aUpBool) \
	((aUpBool) ? oe_sysOop(trueOopX) : oe_sysOop(falseOopX))
#define oeCtoOEint(aUpInt) oe_asSmallInt((aUpInt))
#define oeCtoOEchar(aUpChar) oe_asChar(aUpChar)
#define oeInstVarSize(anOop, pOEint) ((*(pOEint) = oe_numFixedFields(anOop)), anOop)
#define oeIndexVarSize(anOop, pOEint) \
	((*(pOEint) = (oe_objHasPtrs(anOop) \
		?  oe_objVarOopSize(anOop) : oe_objDataSize(anOop))), anOop)
#define oeBasicAt(anOop, index) \
	(*(oe_objVarDataPtr(anOop) + (index) - 1))
#define oeInstVarAt(anOop, index) \
	(*(oe_objDataPtr(anOop, oe_oop) + (index) - 1))
#define oeOopDataPtr(anOop) oe_objDataPtr(anOop, void)
#define oeByteAt(anOop, index, pOEbyte) \
	((*(pOEbyte) = (*(oe_objDataPtr((anOop), OEbyte) + (index) - 1))), anOop)
#define oeIntegerAt(anOop, index, pOEint) \
	((*(pOEint) = oe_oopIntVal(*(oe_objVarDataPtr(anOop) + (index) - 1))), \
		anOop)
#define oeFloatAt(anOop, index, pOEfloat) \
	((*(pOEfloat) = \
		(*(oe_objDataPtr((*(oe_objDataPtr(anOop, oe_oop) + (index) - 1 + \
			oe_numFixedFields(anOop))), OEfloat)))), anOop)
#define oeByteAtPut(anOop, index, aUpByte) \
	((*(oe_objDataPtr(anOop, OEbyte) + (index) - 1) = aUpByte), anOop)
#define oeIntegerAtPut(anOop, index, aUpInt) \
	((*(oe_objVarDataPtr(anOop) + (index) - 1) = oe_asSmallInt(aUpInt)), anOop)
#define oeIsCharacter(anOop) (oe_oopIsChar((anOop)))
#define oeIsInteger(anOop) (oe_oopIsInt((anOop)))
#define oeIsString(anOop) (oe_oopClass((anOop)) == oe_sysOop(byteStringClassX))
#define oeIsByteArray(anOop) (oe_oopClass((anOop)) == oe_sysOop(byteArrayClassX))
#define oeIsBoolean(anOop) \
	((anOop) == oe_sysOop(trueOopX) || (anOop) == oe_sysOop(falseOopX))
#define oeIsFloat(anOop) (oe_oopClass((anOop)) == oe_sysOop(floatClassX))
#if VW32
# define oeIsDouble(anOop) (oe_oopClass((anOop)) == oe_sysOop(doubleClassX))
#endif
#define oeIsByteLike(anOop) (oe_isByteLike(anOop))
#define oeIsImmediate(anOop) oe_oopIsImm(anOop)
#define oeRegisteredHandleAt(index) oe_sysOop(index)
#define oeClass(anOop) oe_oopClass(anOop)

#endif /* OEUNSAFE */

#endif /* _oeAPI_h */
