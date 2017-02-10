/*
 * CS:APP Data Lab
 *
 * Daniel Lorigan W01163069
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */
You will provide your solution to the Data Lab by
editing the collection of functions in this source file.
INTEGER CODING RULES:
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;
      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }
  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.
  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.
EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }
  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }
FLOATING POINT CODING RULES
For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.
You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.
NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */
#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.
   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.
   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/*
 *
 *
 *
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 * int test_dl10(int parameter1, int parameter2)
 * {
 *   int result = 0;
 *   int i;
 *   for (i = parameter2; i <= parameter1; i++)
 *   result |= 1 << i;
 *   return result;
 *  }
 *
 *   Assume 0 <= parameter2 <= 31, and 0 <= parameter1 <= 31
 *   If parameter2 > parameter1, then return 0
 *   Legal ops: ~ & + <<
 *   Max ops: 12
 *   Rating: 3
 */
 /*Returns result with bits set in the range lowbit-highbit*/
int dl10(int highbit, int lowbit) {
  /*Makes a mask for bits > lowbit and bits < highbit, saves the intersections*/
  return (~0<< lowbit) & ~(~0<< highbit <<1);
}
/*
 *
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *   int test_dl11(int x, int y)
 *   {
 *       return ~(x|y);
 *   }
 *
 *
 *   Legal ops: ~ &
 *   Max ops: 5
 *   Rating: 1
 */
 /*Uses DeMorgan's law of logical negation*/
int dl11(int x, int y) {
  return ~x & ~y;
}
/*
 * int test_dl12(int x, int y)
 * {
 *    return x|y;
 * }
 *
 *
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
 /*Inverse of dl11, again with DeMorgan's*/
int dl12(int x, int y) {
  return ~(~x & ~y);
}
/*
 *
 *  int test_dl13(int x) {
 *  int result = 0;
 *  int i;
 *  for (i = 0; i < 32; i++)
 *  result ^=  (x >> i) & 0x1;
 *  return result; }
 *
 *   Legal ops: ! & ^  >>
 *   Max ops: 20
 *   Rating: 4
 */
 /*Returns 1 if an odd number of bits are set in x, 0 if even*/
int dl13(int x) {
  /*Pair up most and least significant pairs of bytes. x
  now has a number of set bits in its least significant byte
  equal to the number of unpaired bits after comparison.*/
  x ^= x>>16;

  /*Pair up 2nd and 1st least sig. bytes. x's least sig byte
  now contains # of set bits equal to the number of unpaired bits.*/
  x ^= x>>8;

  //save least sig. byte's unpaired bits into last 4
  x ^= x>>4;
  //save last 4 bits upaired into last two
  x ^= x>>2;
  //save last two bits unpaired bit to the 1's place if it exists.
  x ^= x>>1;
  //x&1 will be 1 if a bit went unpaired, i.e. there were an odd # set in x.
  return x&1;
}
/*
 *
 *
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *
 * int test_dl14(int x, int y)
 * {
 *   return x^y; }
 *
 *
 *
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
 /*True if x and y aren't the same value*/
int dl14(int x, int y) {
  return ~(~x & ~y) & ~(x & y);
}
/*
 *
 *
 *
 *
 *
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 * asumming a little endiamachine
 * least significant byte stored first
 *
 * int test_dl15(int x, int n, int m)
 * {
 *
 *   unsigned int nmask, mmask;
 *
 *   switch(n) {
 *   case 0:
 *     nmask = x & 0xFF;
 *     x &= 0xFFFFFF00;
 *     break;
 *   case 1:
 *     nmask = (x & 0xFF00) >> 8;
 *     x &= 0xFFFF00FF;
 *     break;
 *   case 2:
 *     nmask = (x & 0xFF0000) >> 16;
 *     x &= 0xFF00FFFF;
 *     break;
 *   default:
 *     nmask = ((unsigned int)(x & 0xFF000000)) >> 24;
 *     x &= 0x00FFFFFF;
 *     break;
 *    }
 *
 *   switch(m) {
 *   case 0:
 *     mmask = x & 0xFF;
 *     x &= 0xFFFFFF00;
 *     break;
 *   case 1:
 *     mmask = (x & 0xFF00) >> 8;
 *     x &= 0xFFFF00FF;
 *     break;
 *   case 2:
 *     mmask = (x & 0xFF0000) >> 16;
 *     x &= 0xFF00FFFF;
 *     break;
 *   default:
 *     mmask = ((unsigned int)(x & 0xFF000000)) >> 24;
 *     x &= 0x00FFFFFF;
 *     break;
 *   }
 *
 *   nmask <<= 8*m;
 *   mmask <<= 8*n;
 *
 *   return x | nmask | mmask;
 * }
 *
 *
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
 /*Swap byte n with byte m in x.*/
int dl15(int x, int n, int m) {
  int nshift, mshift, mask1, mask2, nmask, mmask;
  //multiply n and m by 8 to find correct number of bits to shift by
  nshift = n<<3;
  mshift = m<<3;
  //create swap masks
  mask1 = 0xFF << nshift;
  mask2 = 0xFF << mshift;
  //save the specified bytes of x and swap their positions
  nmask = (((x & mask1) >> nshift) & 0xFF) << mshift;
  mmask = (((x & mask2) >> mshift) & 0xFF) << nshift;
  //save the bytes of x not being swapped
  x &= ~(mask1 | mask2);
  //combine. If n == m, their bits are combined.
  return x | nmask | mmask;
}
/*
 *
 *
 *
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *
 *
 *
 * int test_dl16(int x, int y, int z)
 * {
 *   return x?y:z;
 *  }
 *
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int dl16(int x, int y, int z) {
  /*checks if x is equal to 0, then shifts to extend that value.
  if !!x == 1, y, else z.*/
  return ((((!!x)<<31)>>31)&y)|((~(((!!x)<<31)>>31))&z);
}
/*
 *
 *
 *
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *
 *
 *  int test_dl17(int x)
 *  {
 *   return (x & 0x1) ? -1 : 0;
 *  }
 *
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int dl17(int x) {
  //extends 0 if x&1 == 0. Extends 1 (into -1) if x&1 == 1
  return (x << 31) >> 31;
}
/*
 *
 *
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *
 *
 * int test_dl18(int x, int n)
 * {
 *    int p2n = 1<<n;
 *    return x/p2n;
 *
 * }
 *
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
 /*Divides x by 2**n.*/
int dl18(int x, int n) {
  int signx = x >> 31; //extend sign bit of x
  //if x is positive, shift x right by n. Else, add (2**n)-1 to x (rounding),
  //then shift right by n.
  return (((x + (1 << n) +(~0)) & signx) | (x & ~signx)) >> n;
}
/*
 *
 *
 *
 *
 *
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *
 *
 *
 *
 *  int test_dl19(void) {
 *  int result = 0;
 *  int i;
 *  for (i = 0; i < 32; i+=2)
 *    result |= 1<<i;
 *  return result;
 *  }
 *
 *   Legal ops: |  <<
 *   Max ops: 6
 *   Rating: 1
 */
 /*Returns a value with every other bit set, starting at the lsb*/
int dl19(void) {
  //create mask
  int mask = (0x55<<8)|0x55;
  mask = (mask<<16)|mask;
  return mask;
}
/*
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *   int dl1(int x) {return (x < 0) ? -x : x; }
 *
 *   Example: dl1(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int dl1(int x) {
  int signx = x>>31;
  return (x&~signx)|(((~x)+1)&signx);
}
/*
 *
 *
 *
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *
 *
 *
 *   int test_dl20(int x)
 *   {
 *      return (x*3)/4;
 *   }
 *
 *   Legal ops: ! ~ & + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int dl20(int x) {
  int multr = (x << 1) + x;
  int signm = multr >> 31;
  return (multr+(3&signm)) >> 2;
}
/*
 * Reproduce the functionality of the following C function
 * unsigned test_dl21(unsigned uf) {
 * float f = u2f(uf);
 * float hf = 0.5*f;
 * if (isnan(f))
 *   return uf;
 * else
 *   return f2u(hf);
 * }
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned dl21(unsigned uf) {
  int S = uf & 0x80000000;
  int E = uf & 0x7f800000;
  int M = uf & 0x7fffff;

  if (E == 0x7F800000 || uf == 0 || uf == 0x80000000){
    return uf;
  }
  if (E > 0x00800000){
    return S|(E-=0x00800000)|M;
  }
  if ((M&0x3)==1){
    return S|((E|M)>>1);
  }
  return S|(((E|M)+1)>>1);
}
/*
 * reproduce the functionality of the following C function
 * unsigned test_dl22(int x) {
 * float f = (float) x;
 * return f2u(f);
 * }
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned dl22(int x) {
  int i, mshift, S, E, M, grs;

  if (x==0){
    return x;
  }
  if((x >= 0x80000000)&&(0x80000040 >= x)){
    return 0xCF000000;
  }
  S = x&0x80000000;
  if (x<0){
    x = ~x+1;
  }

  i = x;
  mshift = 0;
  while (i > 1){
    i = (i >> 1)&0x7FFFFFFF;
    mshift++;
  }

  E = (mshift + 127)<<23;
  M = (x<<(32-mshift));

  grs = (M&0x1c0)>>6;

  if (M&0x3F){
    grs|=1;
  }

  M = (M>>9) & 0x7FFFFF;

  if ((grs > 4) || (grs == 4 && (M&1))){
    M++;
  }
  return S|E|M;
}
/*
 * reproduce the functionality of the following C function
 * unsigned test_dl23(unsigned uf) {
 *  float f = u2f(uf); //shift the mantissa over, count how many times = E
 *  float tf = 2*f; //add one to E
 *  if (isnan(f))
 *    return uf;
 *  else
 *    return f2u(tf);
 * }
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned dl23(unsigned uf) {
  //separate parts of float
  int S = uf & 0x80000000;
  int E = uf & 0x7F800000;
  int M = uf & 0x007FFFFF;

  if (E == 0x7F800000 || uf == 0 || uf == 0x80000000){
    return uf;
  }
  if(E != 0){
    return S|(E+=0x00800000)|M;
  }
  if (M == 0x007FFFFF){
    return S|((E|M)<<1);
  }
  return S|E|(M<<=1);
}
/*dl24 - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples:dl24(12) = 5
 *           dl24(298) = 10
 *           dl24(-5) = 4
 *           dl24(0)  = 1
 *           dl24(-1) = 1
 *           dl24(0x80000000) = 32
 * Here is a C function that accomplishes this. Reproduce the functionality
 * of this function using only the legal operations described below.
 * int test_dl24(int x) {
 *   unsigned int a, cnt;
 *
 *   x = x<0 ? -x-1 : x;
 *   a = (unsigned int)x;
 *   for (cnt=0; a; a>>=1, cnt++)
 *       ;
 *   return (int)(cnt + 1);
 * }
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int dl24(int x) {
  int signx = x >> 31;
  int mask1 = (0x55<<8)|0x55;
  int mask2 = (0x33<<8)|0x33;
  int mask3 = (0x0F<<8)|0x0F;
  int mask4 = 0xFF;
  int mask5 = (0xFF<<8)|0xFF;

  x = (x & ~signx) | ((~x) & signx);
  x |= x>>1;
  x |= x>>2;
  x |= x>>4;
  x |= x>>8;
  x |= x>>16;

  mask1 = (mask1<<16)|mask1;
  mask2 = (mask2<<16)|mask2;
  mask3 = (mask3<<16)|mask3;
  mask4 = (mask4<<16)|mask4;

  x = (x & mask1) + ((x>>1) & mask1);
  x = (x & mask2) + ((x>>2) & mask2);
  x = (x & mask3) + ((x>>4) & mask3);
  x = (x & mask4) + ((x>>8) & mask4);
  x = (x & mask5) + ((x>>16) & mask5);
  return x+1;
}
/*
 *
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *   int test_dl2(int x, int y)
 *   { long long lsum = (long long) x + y;
 *    return lsum == (int) lsum;}
 *
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
 //return true if no overflow, false if there was overflow
int dl2(int x, int y) {
  int sx = x>>31;
  int sy = y>>31;
  int sr = (x+y)>>31;
  return !(0x1 & (~(sx^sy) & (sx^sr)));
}
/*
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *   int test_dl3(int x) {
 *    int i;
 *    for (i = 0; i < 32; i+=2)
 *       if ((x & (1<<i)) == 0)
 *	  return 0;
 *    return 1; }
 *
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int dl3(int x) {
  int m = 0x55;
  m = (m<<8)|0x55;
  m = (m<<16)|m;
  x = (x&m)^m;
  return !x;
}
/*
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *   int test_dl4(int x) {
 *   int i;
 *   for (i = 1; i < 32; i+=2)
 *     if ((x & (1<<i)) == 0)
 *	  return 0;
 *    return 1; }
 *
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int dl4(int x) {
  int m = 0xAA;
  m = (m<<8)|0xAA;
  m = (m<<16)|m;
  x = (x&m)^m;
  return !x;
}
/*
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *   int test_dl5(int x) {
 *   int i;
 *   for (i = 0; i < 32; i+=2)
 *     if (x & (1<<i))
 *	  return 1;
 *   return 0; }
 *
 *   Legal ops: ! ~ &  | + << >>
 *   Max ops: 10
 *   Rating: 2
 */
int dl5(int x) {
  int m = 0x55;
  m = (m<<8)|0x55;
  m = (m<<16)|m;
  x = x&m;
  return !!x;
}
/*
 *
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *  int test_dl6(int x) {
 *   int i;
 *   for (i = 1; i < 32; i+=2)
 *       if (x & (1<<i))
 *	     return 1;
 *   return 0; }
 *
 *   Legal ops: ! & | <<
 *   Max ops: 10
 *   Rating: 2
 */
int dl6(int x) {
  int m = 0xAA;
  m = (m<<8)|0xAA;
  m = (m<<16)|m;
  x = x&m;
  return !!x;
}
/*
*
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *   int test_dl7(int x)
 *   {
 *      return !x;
 *   }
 *
 *   Legal ops: ~ & ^ | + >>
 *   Max ops: 10
 *   Rating: 4
 */
int dl7(int x) {
  int negx = x >> 31;
  int posx = (~x + 1) >> 31;
  return 1 & ~(negx | posx);
}
/*
 *
 *
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *   int test_dl8(int x, int y)
 *   {
 *      return x&y;
 *   }
 *
 *   Legal ops: ~ |
 *   Max ops: 6
 *   Rating: 1
 */
int dl8(int x, int y) {
  return ~(~x|~y);
}
/*
 *
 *   reproduce the functionality of the following C function
 *   with the given restrictions
 *
 *   int test_dl9(int x) {
 *   int result = 0;
 *   int i;
 *   for (i = 0; i < 32; i++)
 *   result +=  (x >> i) & 0x1;
 *       return result;
 *   }
 *
 *   Legal ops: & | + << >>
 *   Max ops: 38
 *   Rating: 4
 */
int dl9(int x) {
  int mask1 = (0x55<<8)|0x55;
  int mask2 = (0x33<<8)|0x33;
  int mask3 = (0x0F<<8)|0x0F;
  int mask4 = 0xFF;
  int mask5 = (0xFF<<8)|0xFF;

  mask1 = (mask1<<16)|mask1;
  mask2 = (mask2<<16)|mask2;
  mask3 = (mask3<<16)|mask3;
  mask4 = (mask4<<16)|mask4;

  x = (x & mask1) + ((x>>1) & mask1);
  x = (x & mask2) + ((x>>2) & mask2);
  x = (x & mask3) + ((x>>4) & mask3);
  x = (x & mask4) + ((x>>8) & mask4);
  x = (x & mask5) + ((x>>16) & mask5);

  return x;
}
