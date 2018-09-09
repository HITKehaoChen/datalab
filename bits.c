/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 1160300823 Chenkehao
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
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  return ~((~x)|(~y));
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
	int mask = 0xFF;
	return (x>>(n<<3))&mask;//1byte = 8 bits; so 2^3 = 8 then we left shfit 3 
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
 	int mask;
    mask = ~(1 << 31);// To make the first bit  0; // same as the signed int !!!
    //printf("%d\n",mask );
    mask = ((mask>>n)<<1)+1; // because we cannot use '-'
    //printf("%d\n",mask); test 
    return (x>>n)&mask; // mask  is used to cover the first some bits to keep signal? but it cannot bigger than 32 or smaller than 0
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) { // wtf???
	//I think we need some masks???
	int _mask1 = (0x55)|(0x55<<8);
	int _mask2 = (0x33)|(0x33<<8);
	int _mask3 = (0x0f)|(0x0f<<8);
	int mask1 = _mask1|(_mask1<<16);
 	int mask2 = _mask2|(_mask2<<16);
 	int mask3 = _mask3|(_mask3<<16);
 	int mask4 = (0xff)|(0xff<<16);
 	int mask5 = (0xff)|(0xff<<8);
 	
 	int ans = (x & mask1) + ((x>>1) & mask1);
 	ans = (ans & mask2) + ((ans>>2) & mask2);
 	ans = (ans & mask3) + ((ans>>4) & mask3);
  	ans = (ans & mask4) + ((ans>>8) & mask4);
  	ans = (ans & mask5) + ((ans>>16) & mask5);

 	return ans;
  
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
 return ((~(x|(~x+1)))>>31)&1; // what's the difference between 0 and other numbers?
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1<<31;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
	int flag = x>>31; // positive 0 ,negative 1
	int shift = n + ~0; // >>(n-1);
	return ((flag & !((~x) >> shift)) + (~flag & !(x >> shift)));	//~~~~~
  
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
    // we need a bias for negative '(1<<n)-1' 
     return (x+(((x>>31)&1)<<n)+(~0)+(!((x>>31)&1)))>>n; // p73
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  return !(x>>31|!x);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int signx = (x>>31)&1;
  int signy = (y>>31)&1;
  int signdif = (!signy)&signx;
  int signsam = (!(signx^signy))&(((x+(~y))>>31)&1);
  return signdif|signsam;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
  int ans=0;
  ans=(!!(x>>(16)))<<4;
  ans=ans+((!!(x>>(8+ans)))<<3);
  ans=ans+((!!(x>>(4+ans)))<<2);
  ans=ans+((!!(x>>(2+ans)))<<1);
  ans=ans+((!!(x>>(1+ans)))<<0);
  return ans;
  /*
  这题求 x 以 2 为底的对数，解法有点难想到，注意到 32 位数的对数最大也不会超过 32,可以写成是 16*a+8*b+4*c+2*d+e 
  这里 a，b，c，d，e 都是 0 或 1，然后通过向右移 16 位就可以判断符号就可以得到 a ，右移 16*a+8 位可得到 b，以此类推得到其他位。
  */
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  int c=0x00ffffff;
  if(((uf<<1)^(0xffffffff))<c){
    return uf;
  }else{
    return uf^(0x80000000);
  }
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
      int sign=x>>31&1;//获取符号位（1位）
    int i;
    int exponent; //指数域（8位）
    int fraction; //小数域
    int delta;//偏差（用于舍入）
    int fraction_mask;//小数域的掩码（23位）
    if(x==0)//如果为0就直接返回
        return x;
    else if(x==0x80000000)//如果为TMin，解释为-（2^31），对应float就是（1）x1.0x2^31，所以S=1，M=1，E=31，指数域=31+127=158
        exponent=158;
    else{
        if (sign)//通过前面的操作已经确定了符号，先把int的绝对值获取，之后利用浮点数的计算公式即可计算出float的值，现在要获取绝对值存入内存中
            x = -x;
        
        i = 30;//最高位是符号位，次高位是有效数字的起始位
        while ( !(x >> i) )//从左往右查找有效数字第一个不为零的位，对应的位置就是最终的i（这里的位置从0开始标号）
            i--;
        //printf("%x %d\n",x,i);
        exponent = i + 127;//数值的最高位已经找到是第i位（有效数据共有i+1位），又因为int类型不可能是非规格数据的范围（为0的情况在前面已排除），所以小数域就是d第i为后面的位向量（小数域一共有i个位），故阶码E=i（小数部分x2的E次方），指数域等于i+127；
        x = x << (31 - i);//清除有效数据前面的所有0，包括符号位，得到有效数据开头的数据
        fraction_mask = 0x7fffff;//设置23位的小数域掩码
        fraction = fraction_mask & (x >> 8);//虽然按照浮点数格式，最前面的9个位不加入小数位，按道理应该右移9位，
        																		//但是由于int类型的参数不可能是非规格数，所以最前面的一个有效数据也被舍弃（默认M=1+f），
        																		//当向右移动8位，舍弃了有效数据的低8位，再和掩码处理以后，一共舍弃了9位
        																		//除了低八位还包括有效数据的最高位，类比二进制小数中小数点左边的那一位数字，在float存储的时候，小数点左边数字不存入内存
        																		//者9个位用来存储符号位+指数域
        x = x & 0xff;//由于右移8位，舍弃了有效数据第八位，现在获取低八位用于舍入操作
        delta = x > 128 || ((x == 128) && (fraction & 1));//如果低八位超过八位二进制能表示的无符号数的一半，
        																									//要在小数域+1，普通的四舍五入思想
        																									//如果低八位刚好等于八位二进制能表示的无符号数的一半，而且小数域目前最后一位是1，
        																									//根据向偶数舍入的模式，也要在小数域+1，向上舍入的思想，
        																									//如果低八位刚好等于八位二进制能表示的无符号数的一半，如果小数域目前最后一位是0，则向下舍入，不加1
        																									//如果低八位刚好小于八位二进制能表示的无符号数的一半，直接丢弃，不加1，普通的四舍五入思想
        fraction += delta;//进行舍入
        if(fraction >> 23) {//如果舍入过后，小数域多余23位，则只取低23位，高位舍弃，但是阶码E要加1，所以指数域也就要加1
            fraction &= fraction_mask;
            exponent += 1;
        }
    }
    return (sign<<31)|(exponent<<23)|fraction;//符号位最高位（31），指数域（30--23），小数域（22-0）
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
  unsigned res = uf;
	
	if((res & 0x7F800000) == 0)
		{
				res = ((res & 0x007FFFFF)<<1) | (res & 0x80000000);	
		}
	else if((res & 0x7F800000) != 0x7F800000)
		{
			  res = res+0x00800000;
		}	
		
  return res;

}
