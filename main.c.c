#include "mathematics.h"
#include "types.h"
#include <stdio.h>
#define pi 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034
void main (void)
{
  printf("Hello :)\nCopyrights for Yomna Ragab");
  u8 choice=0;
  f32 arg1,arg2,result;
  f32 result_mul;
  //printf("%f\n",Root(9));
  /*printf("\n%f\n",power(-1,9));*/
  while (1)
  {

   printf("\nChoose the operation:\n1)Summation\n2)Subtraction\n3)Multiplication\n4)Division\n5)Sine\n6)Cosine\n7)Tan\n8)Exponential\n9)ln\n10)Logarithm\n11)Square root\n0)For Exit\nYour choice: ");
   scanf("%d",&choice);
   if(choice==0)
   {
     printf("BYE BYE");
     break;
   }
   switch (choice) {
     case 1:
      printf("Enter two numbers: ");
      scanf("%f %f",&arg1,&arg2);
      result= Sum(arg1,arg2);
      break;
    case 2:
      printf("Enter two numbers: ");
      scanf("%f %f",&arg1,&arg2);
      result= Sub(arg1,arg2);
      break;
    case 3:
      printf("Enter two numbers: ");
      scanf("%f %f",&arg1,&arg2);
      result_mul= Mult(arg1,arg2);
      break;
    case 4:
      printf("Enter two numbers: ");
      scanf("%f %f",&arg1,&arg2);
      result= Div(arg1,arg2);
      break;
    case 5:
      printf("Enter the angle in degrees: ");
      scanf("%f",&arg1);
      result= Sin((arg1*pi)/180.0);
      break;
    case 6:
      printf("Enter the angle in degrees: ");
      scanf("%f",&arg1);
      result= Cos((arg1*pi)/180.0);
      break;
    case 7:
      printf("Enter the angle in degrees: ");
      scanf("%f",&arg1);
      result= Tan((arg1*pi)/180.0);
      break;
    case 8:
      printf("Enter the power: ");
      scanf("%f",&arg1);
      result= Exp(arg1);
      break;
    case 9:
      printf("Enter the number: ");
      scanf("%f",&arg1);
      result= ln(arg1);
      break;
    case 10:
      printf("Enter the base then the number: ");
      scanf("%f %f",&arg2,&arg1);
      result= Log(arg1 ,arg2);
      break;
    case 11:
      printf("Enter the number: ");
      scanf("%f",&arg1);
      result= Root(arg1);
      break;
    default:
      printf("***********************************\nERROR choice , please try again\n***********************************\n");
      break;

   }
   if(choice<12)
   printf("The result is %f\n*********************************************\n",result );
}

}
