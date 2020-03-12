#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>


#define MIN -2147483648.0
#define MAX  2147483647.0

void entpol(float **a, int* b){
    if(*a!=0){
       free(*a);
    }
    *b=4;
    *a= (float*) malloc( sizeof(float) * 3 );
    if(!(*a)) {
        printf( "Can't allocate memory\n" );
        exit(EXIT_FAILURE);
    }
    printf("Enter the coefficients in ascending degrees of the polynomial.\n");
    if(scanf("%f",&((*a)[0]))==0){
       fflush(stdin);
       printf("Error, you enter invalid value, try to enter polinom again\n");
       *b=0;
       return;
    };
    if((*a)[0]>MAX||(*a)[0]<MIN){
        printf("Error, you enter invalid value, try to enter polinom again\n");
        *b=0;
        return;
    }
    if(scanf("%f",&((*a)[1]))==0){
       fflush(stdin);
       printf("Error, you enter invalid value, try to enter polinom again\n");
       *b=0;
       return;
    };
    if((*a)[1]>MAX||(*a)[1]<MIN){
        printf("Error, you enter invalid value, try to enter polinom again\n");
        *b=0;
        return;
    }
    if(scanf("%f",&((*a)[2]))==0){
       fflush(stdin);
       printf("Error, you enter invalid value, try to enter polinom again\n");
       *b=0;
       return;
    };
    if((*a)[2]>MAX||(*a)[2]<MIN){
        printf("Error, you enter invalid value, try to enter polinom again\n");
        *b=0;
        return;
    }
    if(scanf("%f",&((*a)[3]))==0){
       fflush(stdin);
       printf("Error, you enter invalid value, try to enter polinom again\n");
       *b=0;
       return;
    };
    if((*a)[3]>MAX||(*a)[3]<MIN){
        printf("Error, you enter invalid value, try to enter polinom again\n");
        *b=0;
        return;
    }
    if((*a)[0]==0&&(*a)[1]==0&&(*a)[2]==0&&(*a)[3]==0){
        *b=0;
        printf("Your polinom now=0, you should enter it again\n");
        return;
    }
}

void inf(void){
    printf("Harkevich Anton Pavlovich, the first version of polinom program\n");
}


void outpol(float *a, int b){
    if(a==0){
        printf("First of all, you should enter polinom\n");
        return;
    }
    if(b==0){
        printf("Your polinom now=0, you should enter it again\n");
        return;
    }
    printf("Polinom ");
    int p=0;
    for(int i=b-1; i>0;i--){
        if(a[i]>0&&p==0){
            printf("%.2f*x^%i",a[i],i);
            p++;
        }
        else if(a[i]>0&&p>0){
            printf("+%.2f*x^%i",a[i],i);
        }
        else if(a[i]<0&&p==0){
           printf("%.2f*x^%i",a[i],i);
           p++;
        }
        else if(a[i]<0&&p>0){
           printf("%.2f*x^%i",a[i],i);
        }
    }
    if(a[0]>0&&p>0){
       printf("+%.2f",a[0]);
    }
    else if(a[0]>0&&p==0){
       printf("%.2f",a[0]);
    }
    else if(a[0]<0){
       printf("%.2f",a[0]);
    }
    printf("\n");

}


void normpol(float *a,int b){
    if(a==0){
        printf("First of all, you should enter polinom\n");
        return;
    }
    if(b==0){
        printf("Your polinom now=0, you should enter it again\n");
        return;
    }
    int z=0;;
    for(int i=b-1;i>=0;i--){
        if(a[i]!=0){
            z=i;
            break;
        }
    }
    for(int i=0;i<=z;i++){
        a[i]/=a[z];
    }
}


void calpol(float* a,int b){
    if(a==0){
        printf("First of all, you should enter polinom\n");
        return;
    }
    if(b==0){
        printf("Your polinom now=0, you should enter it again\n");
        return;
    }
    float sum=0;
    float x=0;
    printf("enter argument x\n");
    if(scanf("%f",&x)==0){
        printf("You enter invalid value, error");
            fflush(stdin);
            printf("\n");
            return;
    }
    if(x<MIN||x>MAX){
        printf("Error, you enter invalid value, error\n");
        return;
    }
    for(int i=0;i<b;i++){
        sum+=a[i]*pow(x,i);
    }
    printf("Sum for a given value=%.2f\n",sum);
}


void intpol(float **a, int* b){
    if(*a==0){
        printf("First of all, you should enter polinom\n");
        return;
    }
    if(*b==0){
        printf("Your polinom now=0, you should enter it again\n");
        return;
    }
    (*b)++;
    *a=(float*) realloc(*a,sizeof(float)* (*b));
    if(!(*a)) {
        printf( "Can't allocate memory\n" );
        exit(EXIT_FAILURE);
    }
    for(int i=*b;i>0;i--){
        (*a)[i]=(*a)[i-1]/i;
    }
    (*a)[0]=0;
}

void difpol(float** a, int* b){
    if(*a==0){
        printf("First of all, you should enter polinom\n");
        return;
    }
    if(*b==0){
        printf("Your polinom now=0, you shoud  enter it again\n");
        return;
    }
    for(int i=0;i<(*b)-1;i++){
        (*a)[i]=(*a)[i+1]*(i+1);
    }
    (*b)--;
    if(*b==0){
        printf("Your polinom now=0, you enter it again");
        return;
    }
    *a=(float*) realloc(*a,sizeof(float)* (*b));
    if(!(*a)) {
        printf( "Can't allocate memory\n" );
        exit(EXIT_FAILURE);
    }
}

int main(){
    float *pol=0;
    int n=0;
    printf("Welcome to polinom program:\n");
    while(1){
        printf("\n");
        printf("Press 1 to Entering a polynomial of degree 3.\n");
        printf("Press 2 to The conclusion of the polynomial.\n");
        printf("Press 3 to Normalization of the polynomial.\n");
        printf("Press 4 to Differentiation of a polynomial.\n");
        printf("Press 5 to Integration of the polynomial.\n");
        printf("Press 6 to Calculation of the polynomial value for a given x.\n");
        printf("Press 7 to Information about the version and author of the program.\n");
        printf("Press 8 to Exit the program.\n");
        int a;
        scanf("%d",&a);
        switch(a){
            case 1:entpol(&pol,&n);break;
            case 2:outpol(pol,n);break;
            case 3:normpol(pol,n);break;
            case 4:difpol(&pol,&n);break;
            case 5:intpol(&pol,&n);break;
            case 6:calpol(pol,n);break;
            case 7:inf();break;
            case 8:free(pol);return 0;
            default:printf("Something went wrong, you press another key,error");free(pol);return 1;
        }
    }
}
