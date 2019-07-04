#include "mathematics.h"
#include "types.h"
#include<stdio.h>
#define LN10 2.3025850929940456840179914546844
f32 Sum(f32 arg1 ,f32 arg2)
{
  f32 sum=arg1+arg2;
  return(sum);
}
f32 Sub(f32 arg1 ,f32 arg2)
{
  f32 sub=arg1-arg2;
  return(sub);
}
f32 Mult(f32 arg1 ,f32 arg2)
{
  f32 mult=arg1*arg2;
  return(mult);
}
f32 Div(f32 arg1 ,f32 arg2)
{
  f32 div=arg1/arg2;
  return(div);
}
//sin(x) = [sum (k=0..inf)] (-1)k x2k+1 / (2k+1)!
f32 Sin(f32 arg)
{
  u16 n=0;
  f32 result=0;
  for(n=0; n<100; n++)
  {
    result+=(power(-1,n)*power(arg,(2*n)+1))/factorial((2*n)+1);
  }
  return(result);
}
//cos(x) = [sum (k=0..inf)] (-1)k x2k / (2k)!
f32 Cos(f32 arg)
{
  f32 result=0;
  u16 n=0;
  for(n=0; n<100; n++)
  {
    result+=(power(-1,n)*power(arg,2*n))/factorial(2*n);
  }
  return(result);
}
f32 Tan(f32 arg)
{
  return(Sin(arg)/Cos(arg));
}
f32 Exp(f32 arg)
{
  u16 n=0;
  f32 result=0;
  for(n=0; n<100; n++)
  {
    result+=power(arg,n)/factorial(n);
  }
  return(result);
}
/*
n = 4  itself is used for initial approximation 
Initialize x = 4, y = 1
Next Approximation x = (x + y)/2 (= 2.500000),
y = n/x  (=1.600000)
Next Approximation x = 2.050000,
y = 1.951220
Next Approximation x = 2.000610,
y = 1.999390
Next Approximation x = 2.000000,
y = 2.000000
Terminate as (x - y) > e now.

*/
f32 Root(f32 n)
{
  /*We are using n itself as initial approximation
   This can definitely be improved */
    f32 x = n;
    f32 y = 1;
    f32 e = 0.000001; /* e decides the accuracy level*/
    while (x - y > e) {
        x = (x + y) / 2;
        y = n / x;
    }
    return x;
}
//log a to b= ln a/ln b
f32 Log(f32 arg1 ,f32 arg2) //arg2 base
{
  //f32 log_arg1=ln(arg1)/LN10;
  //f32 log_arg2=ln(arg2)/LN10;
  return(ln(arg1)/ln(arg2));
}
f32 factorial (f32 x)
{
  if(x>1)
    return(x*=factorial(x-1));
  else
    return(1);
}
f32 power(f32 x,u16 y)
{
    if (y == 0)
        return 1;
    else if (y%2 == 0)
        return (power(x, y/2)*power(x, y/2));
    else
        return (x*power(x, y/2)*power(x, y/2));
}
f32 ln(f32 x)
{
  u32 n=0;
  f32 result=0;
  f32 y=(x-1.0)/(x+1.0);
  for(n=1; n<1000; n++)
  {
    //result+=((power(-1,n+1)*power(x-1,n))*1.0)/(n*1.0);
    result+=(1.0/((2*n)-1))*power(y,((2*n)-1));
  }
  return(2.0*result);
}
