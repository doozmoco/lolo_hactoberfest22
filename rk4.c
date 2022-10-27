#include<stdio.h>
#include<math.h>

double f(double x, double y){
    return y - pow(x,2) + 1;
}

double main(){
    int i;
    double xf,y1,x0,y0,h,k1,k2,k3,k4,k5,k6,y2,scafac,tol,v;
    v=10;
    tol= pow(v,-5);
    printf("x0 : ");
    scanf("%lf",&x0);
    printf("y0 : ");
    scanf("%lf",&y0);
    
    printf("xf : ");
    scanf("%lf",&xf);
    printf("h : ");
    scanf("%lf",&h);
    
    printf("__\n");
    
    /*while((x-x0)>0.0000000001){
        k1=h*f(x0,y0);
        k2=h*f(x0+h/2.0,y0+k1/2.0);
        k3=h*f(x0+h/2.0,y0+k2/2.0);
        k4=h*f(x0+h,y0+k3);
        k5=h
        printf("%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",x0,y0,k1,k2,k3,k4,1/6.0*(k1+2*k2+2*k3+k4));
        y=y0+1.0/6.0*(k1+2*k2+2*k3+k4);
        y0=y;
        x0=x0+h;
    }*/
    while((xf-x0)>0.01){
        k1 = f(x0,y0) * h;
        k2 = h*f(x0+h/4,y0+k1/4);
        k3 = h*f(3*h/8+x0,y0+3*k1/32+9*k2/32);
        k4 = h*f(x0+12*h/13,y0+1932*k1/2197-7200*k2/2197+7296*k3/2197);
        k5 = h*f(x0+h,y0+439*k1/216-8*k2+3680*k3/513-845*k4/4104);
        k6 = h*f(x0+h/2,y0-8*k1/27+2*k2-3544*k3/2565+1859*k4/4104-11*k5/40);
        y1=y0+25*k1/216+1408*k3/2565+2197*k4/4104-k5/5;
        y2=y0+16*k1/135+6656*k3/12825+28561*k4/56430-9*k5/50+2*k6/55;
        scafac=0.84*pow(tol*h/fabs(y2-y1),1/4);
        h=h*scafac;
        y0=y2;
        x0=x0+h;
        printf("%lf\t%lf\n",x0,y0);
        printf("__\n");
        printf("%lf\n\n",y1);
        printf("__\n");
        printf("%lf\n\n",y2);

    }
}