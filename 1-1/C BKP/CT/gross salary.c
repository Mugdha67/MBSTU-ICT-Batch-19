/*In a company an employee is paid as:- if his salary is less than taka 1500, House rent allowance = 10% of basic salary
and daily allowance =90% of basic salary. If his salary is either equal to or above Taka 1500 then house rent allowance
= taka 500 and daily allowance =90% of basic salary. If the employee's salary is input through the keyboard write a
program to find his gross salary.*/
#include<stdio.h>
int main()
{
    double bs,total;
    scanf("%lf",&bs);
    if(bs<1500)
    {
        total=bs+(10/100)*bs+(90/100)*bs;
        printf("%lf\n",total);
    }
    else
    {
        total=bs+500+(90/100)*bs;
        printf("%lf\n",total);
    }
    return 0;
}
