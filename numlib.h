#include <stdio.h>
#include <math.h>


/**Newton Raphson Method function is written in the section below*/
double NewtonRaphson(double (*f)(double), double (*df)(double), double x0, double tol, int itermax){
    
    double x_old = x0;
    double x_new,err;
    int i = 0;
    while(1){
        x_new = x_old - f(x_old)/df(x_old);
        err = fabs((x_new-x_old)/x_new)*100;
	//NewtonRaphson method is vulnerable to divergence at inflection point, division by zero
        fprintf(stdout,"x_new(%d)=%g x_old=%g f(x_old)=%g df(x_old)=%g err=%f tol=%g\n",i+1,x_new,x_old,f(x_old),df(x_old),err,tol);
	
	if(i > itermax){
		fprintf(stdout,"Convergence not reached at Maximum iteration %d\n",itermax);
		break;
	}
	else if(err < tol){
		fprintf(stdout,"Convergence Reached at %d th iteration\n",i);
		break;
	}
	x_old = x_new;

	i++;
    }
return x_new;
}

/**Secant Method function is written in the section below*/

double SecantMethod(double (*f)(double), double x0, double x1, double tol, int itermax){
    fprintf(stdout,"**************Secant Method*************************\n");
    double x_neg = x0;
    double x_old = x1;
    double x_new,err;

    int i = 2; // x0 and x1 are already there as initial guesses
    while(1){

	x_new = x_old - f(x_old)*(x_old-x_neg)/(f(x_old)-f(x_neg));
        err = fabs((x_new-x_old)/x_new)*100;
	fprintf(stdout,"x_new(%d)=%g x_old=%g f(x_old)=%g f(x_neg)=%g err=%f tol=%g\n",i,x_new,x_old,f(x_old),f(x_neg),err,tol);
	
	if(i > itermax){
		fprintf(stdout,"Convergence not reached at Maximum iteration %d\n",itermax);
		break;
	}
	else if(err < tol){
		fprintf(stdout,"Convergence Reached at %d th iteration\n",i);
		break;
	}
        //Update variables
	x_neg = x_old;
	x_old = x_new;

	i++;
    }
return x_new;

}


/**Bisection method goes here*/

double BisectionMethod(double (*f)(double), double xl, double xu, double tol, int itermax){
    fprintf(stdout,"**************Bisection Method*************************\n");
    double check,xm, xm_old,err;
    
    check = f(xl)*f(xu);
    if(check < 0){
       fprintf(stdout,"Root lies between two guess\n");
       xm = (xl+xu)/2;
    
       int i = 0;
       xm_old = xm;
       while(1){
	   if(f(xl)*f(xm) < 0){
		//root lies beteen xl and xm
               xl = xl; xu = xm;
	   }
           else if (f(xl)*f(xm) > 0){
           //root lies between xm and xu
               xl = xm; xu = xu;
           }
           else{
           //root is xm, stop iteration!!
               fprintf(stdout,"root xm = %g has been found at %d th iteration\n",xm,i);
	       break;
           }
           xm = (xl+xu)/2;
           err = fabs((xm-xm_old)/xm)*100;
           fprintf(stdout,"ite = %d xm = %g xl = %g xu = %g err = %g\n",i,xm,xl,xu,err);
           //Set Stopping criteria
	   if(i > itermax){
		fprintf(stdout,"Convergence not reached at Maximum iteration %d\n",itermax);
		break;
	   }
	   else if(err < tol){
		fprintf(stdout,"Convergence Reached at %d th iteration\n",i);
		break;
	   }

           //Update vaiables
           xm_old = xm;
           i++;
       }
    }
    else{
       fprintf(stdout,"Root doesn't exists between two initial guess,Make new guess\n");
       fprintf(stdout,"Program has stopped runnigi\n");
       
    }

return xm;
}
