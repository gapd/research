/*
 * 32-bit float Vector Arithmetic Functions for use via
 * VisualWorks DLL & C Connect.
 *
 * Written by David Leibs & Eliot Miranda. February 1998
 *
 * You are free to use this code for any purpose without restriction.
 * Neither the authors nor Cincom Systems Inc. will accept any liability
 * resulting from the use of this code.
 */

extern OEoop vectorMultiplyByScalar(OEoop v1, float s, OEoop result);
extern OEoop vectorDivideByScalar(OEoop v1, float s, OEoop result);

extern OEoop vectorAdd(OEoop v1, OEoop v2, OEoop vecOut);
extern OEoop vectorMinus(OEoop vec1, OEoop vec2, OEoop vecOut);

extern OEoop vectorNegate(OEoop vecin, OEoop vecout);
extern OEoop vectorRound(OEoop vecin, OEoop vecout);
extern float vectorMagnitude(OEoop vec);
extern OEoop vectorNormal(OEoop vec, OEoop result);
extern float vectorDotProduct(OEoop vec1, OEoop vec2);

extern OEoop vectorCrossProduct(OEoop vec1, OEoop vec2, OEoop vecOut);
extern OEoop vectorCrossProductNormal(OEoop vec1, OEoop vec2, OEoop vecOut);
