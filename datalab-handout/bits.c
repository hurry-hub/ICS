/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
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
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
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
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
    /*
     *Shift 0x55 to the left by 8 bits, and then add the original number or to get 0x5555.
     *Then shift 0x5555 to the left by 16 bits and sum the original number or to get 0x5555555.
     */
    int x = 0x55;
    int res = x << 8;
    x = x | res;
    res = x << 16;
    x = x | res;
    return x;
  }
/*
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
  /*
   *If the two operands are XOR, they will return 0 if they are equal. If they are different, they will be non-0.
   *In this case, reverse operation is performed to meet the requirements
   */
  return !(x ^ y);
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
    /*
     *The n-bytes and m-bytes to be swapped are moved to th last bit,and then
     *the original position is set to 0, and then two positions are swapped
     *and added to the original number.
     */
    int num_m = x >> (m << 3);
    int num_n = x >> (n << 3); 
    n = n << 3;
    m = m << 3;
    num_n = num_n & 0xFF;
    num_m = num_m & 0xFF;
    x = x & ~(0xFF << m | 0xFF << n);
    num_n = num_n << m;
    num_m = num_m << n;
    x = x | num_n;
    x = x | num_m;

    return x;
}
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) {
    /*
     *move the highest bit to the right n bit,then the lowest n bit to
     *the left,the highest n bit after the right shift to zero,plus the
     *n bit after the left shift
     */
    x = ((x >> n) & (~(1 << 31) >> (n + ~1 + 1))) | x << (33 + ~n);
    return x; 
}
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
    /*
     *take the original number inversely plus one inverse number,and then take
     *the reverse number inversely,if the original number is not zero,the 
     *result is 0,the reverse is 1,and finally with 1,can ensure that operation
     *of negative number is feasible.
     */
    return (((~x + 1) | x) >> 31 & 1) ^ 1;
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
    /*
     *Shift 1 to the left by 31 bits, and then take the reverse to get the 0x7fffffff.
     */
    int x = ~(1 << 31);
    return x;
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
    /*
     *take the original number twice to determine whether it is 0,move the
     *original number to the right 31 bits to obtain its symbol bit,find
     *both and you can get the result.
     */
    return (x >> 31) | !!x;
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
    /*
     *add the last number to the first number and take the reverse number to
     *get the last number minus the first number,then let the last number and 
     *the previous number take the reverse and then take the xor and the last
     *number and the previous number take the reverse and then cross to judge
     *whether the two are the same, the three first cross to find or take the
     *sign after the last intersection with 1 to get the answer.
     */
    int x_neg = ~x;
    return ((((y + x_neg + 1) & (y ^ x_neg)) | (y & x_neg)) >> 31) & 1;
}
/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {
    int diff = x + ~y + 1;
    int x_neg = x >> 31;
    int y_neg = y >> 31;
    int d_neg = diff >> 31;
	/*
	*Overflow when x and y have opposite sign, and d different from x 
	*/
    return !(~(x_neg ^ ~y_neg) & (x_neg ^ d_neg));
}
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y) {
    int ans = x + y;
    int over = ((x ^ ans) & (y ^ ans)) >> 31;
	//There are two kinds of results: overflow is 0xFFFFFFFF, non overflow is 0
    return (ans >> ( over & 31)) + (over << 31);
	/*
	*positive overflow, 0xFFFFFFFF + 1 = 0x7FFFFFFF
	*negative overflow,0 + 0x80000000
	*non overflow, ans >> 31 + 0 << 31
	*/
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
    int b16, b8, b4, b2, b1, b0;
    int sign = x >> 31;
    x = sign & (~x) | (~sign) & x;
	//If x is positive, it does not change, otherwise it is reversed by bit.
    b16 = !!(x >> 16) << 4;
	//judge whether there is 1 in the first 16 bits
    x = x >> b16;
	//If there is 1, move 16 bits, otherwise B16 = 0, do not move
    b8 = !!(x >> 8) << 3;//Similarly.
    x = x >> b8;
    b4 = !!(x >> 4) << 2;
    x = x >> b4;
    b2 = !!(x >> 2) << 1;
    x = x >> b2;
    b1 = !!(x >> 1);
    x = x >> b1;
    b0 = x;

    return b16 + b8 + b4 + b2 + b1 + b0 + 1;
	//plus 1 means add a symbol bit.
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
	/*
	*The two-way method. Move 16 bits to the right and get more than 0.
	*Otherwise get 0, determine whether the highest bit is 0, and if not 0, it contains 16 squares of 2.
	*That is, to get the highest bit of the log number, the same as the other.
	*/
    int ret = 0;
    ret = (!!(x >> 16)) << 4;
    ret = ret + ((!!(x >> (ret + 8))) << 3);
    ret = ret + ((!!(x >> (ret + 4))) << 2);
    ret = ret + ((!!(x >> (ret + 2))) << 1);
    ret = ret + (!!(x >> (ret + 1)));
    return ret;
}

/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
    unsigned sign = uf & 0x80000000;
  unsigned exp = uf & 0x7f800000;
  unsigned lsb = ((uf & 3) == 3); // 3 = [11]2
  if (exp == 0x7f800000) // infinity or NaN
  {
    return uf;
  }
  else if (exp <= 0x00800000) // denormalized number
  {
    return sign | (((uf ^ sign) + lsb) >> 1);
  }
  else
  {
    return uf - 0x00800000; // exp - 1
  }
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
    /*Returns 0 if the original floating-point value is 0, 0 if the true index is greater than 31 (the frac portion is greater than or equal to 1,
    *1<<31 bits overwrite the sign bit), returns the specified overflow value of 0x8000000u, and returns 0 if the formula (1 right shift x bit, x>0,
    *result is 0). The rest: first convert the small part (23 bits) into an integer (compared to 23) and then determine whether to overflow:
    *if the original symbol is the same, return directly, otherwise if the result is negative (originally positive), 
    *the overflow returns the cross-border specified value of 0x8000000u, otherwise the original negative, the result is positive,
    *you need to return its complement (the opposite number).
    */
    int s = uf >> 31;
    int exp = (uf >> 23) & 0xff;
    int frac = uf & 0x007fffff;
    int abs;
    if (exp < 0x7f) {
	return 0;
    } else if (exp > 157) {
	return 0x80000000;
    } else {
	if (exp - 150 > 0) {
	    abs = (0x00800000 + frac) << (exp - 150);
	} else {
	    abs = (0x00800000 + frac) >> (150 - exp);
	}
   	if (s) {
	    return -abs;
	} else {
	    return abs;
	}
    }
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
    unsigned f = uf;
    if ((f & 0x7f800000) == 0) {
	f = ((f & 0x007fffff) << 1) | (0x80000000 & f);	//Move one bit to the left.
    } else if ((f & 0x7f800000) != 0x7f800000) {
	f = f + 0x00800000;
    }

    return f;
}
