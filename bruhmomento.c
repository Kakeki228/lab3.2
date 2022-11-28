#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


double func (double x);
unsigned int method_choose( void );
double half_devision_met ( double x1, double x2, double esp, unsigned int iter_variant, unsigned int iter_step);
double hord_met ( double x1, double x2, double eps, unsigned int iter_variant, unsigned int iter_step);

int main(){

unsigned int method, iter_variant;
double x1, x2, eps,  root, delta_t;
int iter_step = 5;
clock_t start, end;


do{
    printf("\nEnter input values:");
    printf("\n\nX1=");
    scanf("%lf", &x1);
    printf("\nX2=");
    scanf("%lf", &x2);
    printf("\neps=");
    scanf("%lf", &eps);

}while( func(x1) * func(x2) > 0);

do{
     system("cls");
     printf("\nShow the result on each iteration?");
     printf("\n\n1.Yes\n2.No\n\n>");
     scanf("%u", &iter_variant);

}while( iter_variant != 1 && iter_variant != 2 );

method = method_choose();

start = clock();

switch(method){

    case 1:
        root = half_devision_met ( x1, x2, eps, iter_variant, iter_step);
        system("cls");
        printf("\n\n root=%lf\n\n F(x)=%lf", root, func(root));
    break;

    case 2:
        root = hord_met ( x1, x2, eps, iter_variant, iter_step);
        system("cls");
        printf("\n\n root=%lf\n\n F(x)=%lf", root, func(root));

    break;

}

end = clock();
delta_t = ( end - start )/1000;
printf("\n\n Elapsed time:%.3f seconds\n", delta_t);

return 0;
}



double func (double x){

 return -0.5*pow(x-64,3)-3*pow(x,2)+10;
}



unsigned int method_choose( void ){

unsigned int var;

printf("\nChoose the method of calculating:");
printf("\n\n\t1.By Half devision method.");
printf("\n\t2.By Chord method.\n\n>");
scanf("%u", &var);

    while( var != 1 && var != 2 ){

        printf("\n!!!! Invalid variant of method !!!!\n");
        printf("\nChoose from the variant list:/n>");
        scanf("%u", &var);
    }

return var;
}

double half_devision_met ( double x1, double x2, double eps, unsigned int iter_variant, unsigned int iter_step){

double Xi;
unsigned int iter_count = 0;

    if(iter_variant == 1){

        do{
            int variant_of_continue = 0;
            iter_count ++;

            Xi = (x1+x2)/2;

                if ( func(Xi) * func(x1) > 0)
                    x1 = Xi;
                else
                    x2 = Xi;

                if (iter_count = iter_step ){
                    printf("\n%d iterations done", iter_count);
                    printf("\n X=%lf\n F(x)=%lf", Xi, func(Xi));
                    printf("\n 1.Continue with the same number of iterations");
                    printf("\n 2.Run the program to the end until the roots of the equation are found");
                    printf("\n 3.Display the intermediate result and exit the program");

                        while( variant_of_continue !=1 && variant_of_continue != 2 && variant_of_continue != 3 ){
                            printf("\n>");
                            scanf("%u", &variant_of_continue);

                        }

                        if(variant_of_continue == 1){

                            iter_step = iter_count + 5;
                        }

                        if(variant_of_continue == 2){

                            iter_step = iter_step * 0;

                        }

                        if(variant_of_continue == 3){

                            break;
                        }

                }



        }while(fabs(x1-x2)>= eps);
    }


    if(iter_variant == 2){

        do{

        Xi = (x1+x2)/2;

            if ( func(Xi) * func(x1) > 0)
                x1 = Xi;
            else
                x2 = Xi;

        }while(fabs(x1-x2)>= eps);

    }

return Xi;
}

double hord_met ( double x1, double x2, double eps, unsigned int iter_variant, unsigned int iter_step){

unsigned int iter_count = 0;
double Xi = 0;

    if(iter_variant == 1){

        do{
            int variant_of_continue = 0;
            iter_count ++;

            x1 = x2 - (x2 - x1) * func(x2) / (func(x2) - func(x1));
            Xi = x1 - (x1 - x2) * func(x1) / (func(x1) - func(x2));

                if (iter_count = iter_step ){
                    printf("\n%d iterations done", iter_count);
                    printf("\n X=%lf\n F(x)=%lf", Xi, func(Xi));
                    printf("\n 1.Continue with the same number of iterations");
                    printf("\n 2.Run the program to the end until the roots of the equation are found");
                    printf("\n 3.Display the intermediate result and exit the program");

                        while( variant_of_continue !=1 && variant_of_continue != 2 && variant_of_continue != 3 ){
                            printf("\n>");
                            scanf("%u", &variant_of_continue);

                        }

                        if(variant_of_continue == 1){

                            iter_step = iter_count + 5;
                        }

                        if(variant_of_continue == 2){

                            iter_step = iter_step * 0;
                        }

                        if(variant_of_continue == 3){

                            break;
                        }
              }

        }while(fabs(Xi - x1) > eps);

    }

    if(iter_variant == 2){

        do{

            x1 = x2 - (x2 - x1) * func(x2) / (func(x2) - func(x1));
            Xi = x1 - (x1 - x2) * func(x1) / (func(x1) - func(x2));

        }while(fabs(Xi - x1) > eps);

    }

return Xi;
}
