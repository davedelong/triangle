//
//  main.c
//  triangle
//
//  Created by Dave DeLong on 8/30/22.
//

#include <stdio.h>
#include <stdlib.h>
#import "tibasic.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
LBL_THETA:
    ClrHome
    Menu("CHOOSE ONE:","DEGREES",LBL_M,"RADIANS",LBL_N,"ABOUT",LBL_E,"QUIT",LBL_Z)
    
LBL_M:
    Degree
    ClrHome
    Menu("CHOOSE ONE:","SSS",LBL_A,"SAS",LBL_B,"SSA",LBL_C,"AAS",LBL_D,"BACK",LBL_THETA,"ABOUT",LBL_E,"QUIT",LBL_Z)
    
LBL_A:
    ClrHome
    Disp("ENTER SSS")
    Input(A)
    Input(B)
    Input(C)
    Disp("AAA:")
    Disp(ACOS((pow(A, 2)-pow(B, 2)-pow(C, 2))/(-2*B*C)))
    Disp(ACOS((pow(B, 2)-pow(A, 2)-pow(C, 2))/(-2*A*C)))
    Disp(ACOS((pow(C, 2)-pow(A, 2)-pow(B, 2))/(-2*A*B)))
    S = 0.5*(A+B+C);
    Disp("AREA=")
    Disp(sqrt((S)*(S-A)*(S-B)*(S-C)))
    Disp("PERIMETER=")
    Disp(2*S)
    Pause
    goto LBL_THETA;
    
LBL_B:
    ClrHome
    Disp("ENTER SAS")
    Input(A)
    Input(C)
    Input(B)
    Disp("ASA:")
    D = sqrt(pow(A, 2)+pow(B, 2)-2*A*B*COS(C));
    Disp(ASIN((A*SIN(C))/(D)))
    E = ASIN((A*SIN(C))/(D));
    Disp(D)
    Disp(180-C-E)
    S = (.5*(A+B+D));
    Disp("AREA=")
    Disp(sqrt((S)*(S-A)*(S-B)*(S-D)))
    Disp("PERIMETER=")
    Disp(2*S)
    Pause
    goto LBL_THETA;
    
LBL_D:
    ClrHome
    Disp("ENTER AAS")
    Input(A)
    Input(B)
    Input(C)
    Disp("ASS:")
    Disp(180-A-B)
    D = 180-A-B;
    Disp((C*SIN(B))/SIN(A))
    E = (C*SIN(B))/SIN(A);
    Disp((C*SIN(D))/SIN(A))
    F = (C*SIN(D))/SIN(A);
    S = (.5)*(C+E+F);
    Disp("AREA=")
    Disp(sqrt((S)*(S-C)*(S-E)*(S-F)))
    Disp("PERIMETER=")
    Disp(2*S)
    Pause
    goto LBL_THETA;
    
LBL_E:
    Disp("  prgmTRIANGLE:")
    Disp("")
    Disp("  VERSION 3.3! ")
    Disp("")
    Disp("")
    Disp("CREATED BY DAVE")
    Disp("     DELONG")
    Pause
    goto LBL_THETA;
    
LBL_C:
    Disp("ENTER SSA")
    Input(A)
    Input(B)
    Input(C)
    if (C < 90) {
        goto LBL_G;
    } else {
        goto LBL_F;
    }
    
LBL_G:
    θ = B*SIN(C);
    if (A == θ) {
        goto LBL_L;
    } else if (A > θ) {
        goto LBL_K;
    } else if (A < θ) {
        Disp("NO SOLUTION")
        Pause
        goto LBL_THETA;
    }
    
LBL_L:
    Disp("AAS:")
    Disp(ASIN((B*SIN(C))/A))
    D = ASIN((B*SIN(C))/A);
    Disp(180-D-C)
    E = 180-D-C;
    Disp((A*SIN(E))/SIN(C))
    F = (A*SIN((E))/SIN(C));
    S = (.5)*(A+B+F);
    Disp("AREA=")
    Disp(sqrt((S)*(S-A)*(S-B)*(S-F)))
    Disp("PERIMETER=")
    Disp(2*S)
    Pause
    goto LBL_THETA;
      
LBL_K:
    if (A < B) {
        goto LBL_H;
    } else if (A > B) {
        goto LBL_I;
    } else if (A == B) {
        Disp("FIGURE IT OUT.")
        Pause
        goto LBL_THETA;
    }
      
LBL_H:
    Disp("AAS:")
    Disp(ASIN((B*SIN(C))/A))
    D = ASIN((B*SIN(C))/A);
    Disp(180-C-D)
    E = 180-C-D;
    Disp((A*SIN(E))/SIN(C))
    F = (A*SIN((E))/SIN(C));
    S = (.5)*(A+B+F);
    Disp("AREA=")
    Disp(sqrt((S)*(S-A)*(S-B)*(S-F)))
    Disp("PERIMETER=")
    Disp(2*S)
    Disp("OR...")
    Pause
    Disp("AAS:")
    Disp(180-D)
    G = 180-D;
    Disp(180-G-C)
    I = 180-G-C;
    Disp((A*SIN(I))/SIN(C))
    F = (A*SIN((I))/SIN(C));
    S = (.5)*(A+B+F);
    Disp("AREA=")
    Disp(sqrt((S)*(S-A)*(S-B)*(S-F)))
    Disp("PERIMETER=")
    Disp(2*S)
    Pause
    goto LBL_THETA;
      
LBL_I:
    Disp("AAS:")
    Disp(ASIN((B*SIN(C))/A))
    D = ASIN((B*SIN(C))/A);
    Disp(180-C-D)
    E = 180-C-D;
    Disp((A*SIN(E))/SIN(C))
    F = (A*SIN(E))/SIN(C);
    S = (.5)*(A+B+F);
    Disp("AREA=")
    Disp(sqrt((S)*(S-A)*(S-B)*(S-F)))
    Disp("PERIMETER=")
    Disp(2*S)
    Pause
    goto LBL_THETA;
      
LBL_F:
    if (A <= B) {
        Disp("NO SOLUTION")
    } else if (A > B) {
        goto LBL_J;
    }
      
LBL_J:
    Disp("AAS:")
    Disp(ASIN((B*SIN(C))/A))
    D = ASIN((B*SIN(C))/A);
    Disp(180-C-D)
    E = 180-C-D;
    Disp((A*SIN(E))/SIN(C))
    F = (A*SIN(E))/SIN(C);
    S = (.5)*(A+B+F);
    Disp("AREA=")
    Disp(sqrt((S)*(S-A)*(S-B)*(S-F)))
    Disp("PERIMETER=")
    Disp(2*S)
    Pause
    goto LBL_THETA;
      
LBL_Z:
    ClrHome
    Stop
      
LBL_N:
    ClrHome
    Radian
    Menu("CHOOSE ONE:","SSS",LBL_O,"SAS",LBL_P,"SSA",LBL_Q,"AAS",LBL_R,"BACK",LBL_THETA,"ABOUT",LBL_E,"QUIT",LBL_Z)

LBL_O:
    Disp("SSS?")
    Input(A)
    Input(B)
    Input(C)
    Disp("AAA:")
    Disp(ACOS((pow(A, 2)-pow(B, 2)-pow(C, 2))/(-2*B*C)))
    Disp(ACOS((pow(B, 2)-pow(A, 2)-pow(C, 2))/(-2*A*C)))
    Disp(ACOS((pow(C, 2)-pow(A, 2)-pow(B, 2))/(-2*A*B)))
    Disp("AREA=")
    S = ((A+B+C)/2.0);
    Disp(sqrt((S)*(S-A)*(S-B)*(S-C)))
    Disp("PERIMETER=")
    Disp(2*S)
    Pause
    goto LBL_THETA;
      
LBL_P:
    Disp("SAS?")
    Input(A)
    Input(B)
    Input(C)
    Disp("ASA:")
    D = sqrt(pow(A, 2)+pow(C, 2)-2*A*C*COS(B));
    Disp(ASIN((A*SIN(B))/D))
    E = ASIN((A*SIN(B))/D);
    Disp(D)
    Disp(π-B-E)
    Disp("AREA=")
    S = ((A+C+D)/2);
    Disp(sqrt((S)*(S-A)*(S-C)*(S-D)))
    Disp("PERIMETER=")
    Disp(2*S)
    Pause
    goto LBL_THETA;
      
LBL_R:
    Disp("AAS?")
    Input(A)
    Input(B)
    Input(C)
    Disp("ASS:")
    D = (C*SIN(B))/SIN(A);
    E = π-A-B;
    F = (C*SIN(E))/SIN(A);
    Disp(E)
    Disp(D)
    Disp(F)
    Disp("AREA=")
    S = ((C+D+F)/2);
    Disp(sqrt((S)*(S-C)*(S-D)*(S-F)))
    Disp("PERIMETER=")
    Disp(2*S)
    Pause
    goto LBL_THETA;
      
LBL_Q:
    Disp("SSA?")
    Input(A)
    Input(B)
    Input(C)
    if (C < 90) {
        goto LBL_S;
    } else if (C >= 90) {
        goto LBL_T;
    }
      
LBL_S:
    θ = B*SIN(C);
    if (A == θ) {
        goto LBL_W;
    } else if (A > θ) {
        goto LBL_U;
    } else if (A < θ) {
        Disp("NO SOLUTION.")
        Pause
        goto LBL_THETA;
    }
      
LBL_U:
    if (A < B) {
        goto LBL_X;
    } else if (A > B) {
        goto LBL_0;
    } else if (A == B) {
        Disp("FIGURE IT OUT.")
        Pause
        goto LBL_THETA;
    }
      
LBL_W:
    Disp("AAS:")
    Disp(ASIN((B*SIN(C))/A))
    E = ASIN((B*SIN(C))/A);
    Disp(π-C-E)
    D = π-C-E;
    Disp((A*SIN(D))/SIN(C))
    F = (A*SIN(D))/SIN(C);
    Disp("AREA=")
    S = ((A+B+F)/2);
    Disp(sqrt((S)*(S-A)*(S-B)*(S-F)))
    Disp("PERIMETER=")
    Disp(2*S)
    Pause
    goto LBL_THETA;
      
LBL_X:
    Disp("AAS:")
    Disp(ASIN((B*SIN(C))/A))
    D = ASIN((B*SIN(C))/A);
    Disp(π-C-D)
    E = π-C-D;
    Disp((A*SIN(E))/SIN(C))
    F = (A*SIN(E))/SIN(C);
    Disp("AREA=")
    S = ((A+B+F)/2.0);
    Disp(sqrt((S)*(S-A)*(S-B)*(S-F)))
    Disp("PERIMETER=")
    Disp(2*S)
    Disp("OR...")
    Pause
    Disp("AAS:")
    Disp(ASIN((B*SIN(C))/A))
    D = ASIN((B*SIN(C))/A);
    E = π-D-C;
    G = π-E;
    Disp(G)
    Disp((A*SIN(G))/SIN(C))
    F = (A*SIN(G))/SIN(C);
    Disp("AREA=")
    S = ((A+B+F)/2);
    Disp(sqrt((S)*(S-A)*(S-B)*(S-F)))
    Disp("PERIMETER=")
    Disp(2*S)
    Pause
    goto LBL_THETA;
      
LBL_0:
    Disp("AAS:")
    Disp(ASIN((B*SIN(C))/A))
    D = ASIN((B*SIN(C))/A);
    Disp(π-C-D)
    E = π-C-D;
    Disp((A*SIN(E))/SIN(C))
    F = (A*SIN(E))/SIN(C);
    Disp("AREA=")
    S = ((A+B+F)/2.0);
    Disp(sqrt((S)*(S-A)*(S-B)*(S-F)))
    Disp("PERIMETER=")
    Disp(2*S)
    Pause
    goto LBL_THETA;
      
LBL_T:
    if (A > B) {
        goto LBL_V;
    } else if (A <= B) {
        Disp("NO SOLUTION.")
        Pause
        goto LBL_THETA;
    }
      
LBL_V:
    Disp("AAS:")
    Disp(ASIN((B*SIN(C))/A))
    D = ASIN((B*SIN(C))/A);
    Disp(π-C-D)
    E = π-C-D;
    Disp((A*SIN(E))/SIN(C))
    F = (A*SIN(E))/SIN(C);
    Disp("AREA=")
    S = ((A+B+F)/2.0);
    Disp(sqrt((S)*(S-A)*(S-B)*(S-F)))
    Disp("PERIMETER=")
    Disp(2*S)
    Pause
    goto LBL_THETA;
      
    return 0;
}
