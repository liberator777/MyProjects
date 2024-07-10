#include <stdio.h>
#include <math.h>

#include "gnuplot-iostream.h"

#pragma warning(disable:4996)

int Differentiation(float cf[], int n) {

    float df[n]; 

    for(int i = n; i >= 0; i--) {
       df[i] = cf[i]*(i) ;
    }
    printf("result(differentiated): ");
    printf("\n");
    for(int j = n; j>=0; j--) {
        if (j > 0) {
            if (j > 1) {
                printf("%.2fx^%d",df[j],j-1);
                printf(" + ");
            }
            else {
                printf("%.2f",cf[j]);
            }
        }else {
            printf("\n");
        }
        
    }
return 0;

}

int integral(float cf[], int n) {


    int k = n+1;
    float df[k]; 

    printf("result(integraled): \n");
    for (int i = n+1;i>=0;i--) {
        df[i] = ((float)cf[i-1]/i);
    }
    
    for(int j = n+1; j>=0;j--) {
         if (j>=1) {
            printf("%.2fx^%d",df[j],j);
            printf(" + ");
         }
         else {
            printf("C");
         }
    }
return 0;
    
}

void ValueIt(float cf[], int n) {
    int x;

    printf("|-----original-----|-----diffrentiated-----|-----integraled-----|\n\n");
    
    
    for(x = -5; x <= 5; x++) {
        float y = 0,yd = 0,yi = 0;
    
        //output(original)
        for(int i = n; i >=0 ;i--){
            if (x != 0) {
                y += cf[i]*pow(x,i);
            } else {
                y = cf[0];
            }

        } printf("|   (%d, %0.2f)",x,y);
        
        // for blanks(original)
        int vO = y;
        int blankO = 0;
        if (x < 0) {
            blankO++;
        }
        if (vO <= 0) {
            blankO++;
        }
        while( vO != 0) {

            vO = vO/10;
            blankO++;
            
        }
        
        for(int bO = 7-blankO; bO > 0; bO--) {
            printf(" ");
        }

        printf("|");

        //output(differentiated)
        for(int j = n; j >= 0; j--) {
            if (x != 0) {
                yd += cf[j]*j*(pow(x,j-1));
            } else {
                yd = cf[1];
            }
        } printf("      (%d, %0.2f)",x,yd); 

        // for blanks(differentiated)
        int vD = yd;
        int blankD = 0;
        if (x < 0) {
            blankD++;
        }
        if (vD <= 0) {
            blankD++;
        }
        while (vD != 0) {
            vD = vD/10;
            blankD++;
        }
        
        for(int bD = 9-blankD; bD > 0; bD--) {
            printf(" ");
        }

        printf("|");

        //output(integraled)
        for(int k = n; k>=0; k--) {
            if (x != 0) {
                yi += (cf[k]/(k+1))*(pow(x,(k+1)));
            } else {
                yi = 0;
            }
        } printf("    (%d, %0.2f) ",x,yi);

        // for blanks(integraled)
        int vI = yi;
        int blankI = 0;
        if (x < 0) {
            blankI++;
        }
        if (vI <= 0) {
            blankI++;
        }
        while (vI != 0) {
            vI = vI/10;
            blankI++;
        }
        
        for(int bI = 7-blankI; bI > 0; bI--) {
            printf(" ");
        }

        printf("|\n");   
    }


    



}


int main(void) {
    int n;
    float cf[n];
    
    printf("enter the highest degree: " ); scanf("%d",&n);

    for(int i = n;i>=0;i--) {
        printf("enter the coefficient of %dth power: ", i); scanf("%f",&cf[i]);
    }

    printf("your expression is: \n ");

    for(int j = n; j >= 0; j--) {

        if(j!=0) {
            printf("%.2fx^%d",cf[j],j);
            printf(" + ");
        }
        else {
            printf("%.2f",cf[j]);
        }
       
    }

    printf("\n\n");
    Differentiation(cf,n);
    printf("\n");
    integral(cf,n);
    printf("\n");
    printf("\n");
    ValueIt(cf,n);
    printf("\n");
      
}