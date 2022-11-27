    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <time.h>
    unsigned int choose_var(void);
    double chord(double x1, double x2, double eps, unsigned int iteration, unsigned int N);
    double half_division (double x1, double x2, double eps, unsigned int iteration, unsigned int N);
    double func (double x);
    int main(){
    double x1,x2,eps, time;
    unsigned int var, iter, N;
    time_t start, end;
     while (1)
        do{
            printf("\n\nX1=");
            scanf("%lf", &x1);
            printf("\nX2=");
            scanf("%lf", &x2);
            printf("\neps=");
            scanf("%lf", &eps);
        }while (func(x1)*func(x2)>0);
        do
        {
             system("cls");
            printf("\nShow the result on each iteration?");
            printf("\n\n1.Yes\n2.No\n\n>");
            scanf("%u", &iter);
        } 
        while( iter != 1 && iter != 2 );

        var = choose_var;

        start = clock();

switch(var){

    case 1:
         printf("Xi = %.10lf\n", chord(x1, x2, eps, iter, N));
    break;

    printf("Xi = %.10lf\n", half_division(x1, x2, eps, iter, N));
    break;

}

end = clock();
time = ( end - start )/1000;
printf("\n\n Elapsed time:%.3f seconds\n", time);

return 0;
}
        
   unsigned int choose_var(void){
        unsigned int var;
        printf("choose method");
        scanf("%u",&var);
        while (var != 1 && var !=2)
        {
            printf("Error: choose variant 1 or 2");
            scanf("%u",&var);
        }
        
    }
    

    double func(double x)
    {
        double y;
        y=-0.5*pow(x-64,3)-3*pow(x,2)+10;
        return y;
    }
    double chord(double x1, double x2, double eps, unsigned int need_iterations, unsigned int N)
{
    double xi;
    while(fabs(func(xi)) > eps)
    {
        xi = (func(x2) * x1 - func(x1) * x2)/(func(x2) - func(x1));
        if (func(xi)*func(x1)>0) x1=xi;
        else x2=xi;
        if(need_iterations==1)
        {
            printf("Xi = %.10lf\n", xi);
            unsigned int i;
            i++;
            if(i>=N)
            {
                i=0;
            }
        }
    }
    return xi;
}

double half_div(double x1, double x2, double eps, unsigned int need_iterations, unsigned int N)
{
    double xi;
    while(fabs(x2-x1) >= eps)
    {
        xi = (x1+x2)/2;
        if(func(xi)==0) break;
        else if(func(xi)*func(x1)>0) x1=xi;
        else x2=xi;
        if(need_iterations==1)
        {
            printf("Xi = %.10lf\n", xi);
            unsigned int i;
            i++;
            if(i>=N)
            {
                i=0;
            }
        }
    }
    return xi;
}