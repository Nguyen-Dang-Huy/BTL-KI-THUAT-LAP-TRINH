#include "study_in_pink1.h"

bool readFile(
        const string & filename,
        int & HP1,
        int & HP2,
        int & EXP1,
        int & EXP2,
        int & M1,
        int & M2,
        int & E1,
        int & E2,
        int & E3
) {
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
        return true;
    }
    else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Function Check Money
bool CheckMN(int a, int b){
    if (a<=b)
        return false;
    else
        return true;
}

// Function Reset Money
int ReMN(int mn){
    if (mn>3000)
        return 3000;
    else{
        if (mn<0)
            return 0;
        else    
            return mn;
    }
}

// Function Reset HP
int ReHP(int hp){
    if (hp>666)
        return 666;
    else{
        if ((hp>=0)and(hp<=666))
            return hp;
        else
            return 0;
    }
}

// Function Reset EXP
int ReEXP(int exp){
    if (exp>600)
        return 600;
    else{
        if ((exp>=0)and(exp<=600))
            return exp;
        else
            return 0;
    }
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int d= e1*3+exp1*7;
    if ((e1<0) or (e1>99))
        return -99;
    else{
        if ((e1>=0) and (e1<=3)){

            switch (e1){
                case 0:
                    exp2 = ReEXP(exp2 +29);
                    break;
                case 1: 
                    exp2 = ReEXP(exp2 +45);
                    break;
                case 2: 
                    exp2 = ReEXP(exp2 +75);
                    break;
                default: 
                    exp2 = ReEXP(exp2 +75+29+45);
                    break;
            }

            if (d%2==0)
                exp1=ReEXP(ceil(exp1+((float) d/200)));
            else
                exp1=ReEXP(ceil(exp1-((float) d/100)));
            
        }
        else{
            if ((e1>=4) and (e1<=19)){
                exp2=ReEXP(ceil(exp2 + ((float) e1/4)+19));
            }
            if ((e1>=20) and (e1<=49)){
                exp2=ReEXP(ceil(exp2+((float) e1/9)+21));
            }
            if ((e1>=50) and (e1<=65)){
                exp2=ReEXP(ceil(exp2+((float) e1/16)+17));
            }
            if ((e1>=66) and (e1<=79)){
                exp2=ReEXP(ceil(exp2+((float) e1/4)+19));
                if (exp2>200)
                    exp2=ReEXP(ceil(exp2+((float)e1/9)+21));
            }
            if ((e1>=80) and (e1<=99)){
                exp2=ReEXP(ceil(exp2 +((float) e1/4)+19));
                exp2=ReEXP(ceil(exp2+((float) e1/9)+21));
                if (exp2>400){
                    exp2=ReEXP(ceil(exp2+((float) e1/16)+17));
                    exp2=ReEXP(ceil(((float) exp2*1.15)));
                }
            }
            exp1=ReEXP(exp1-e1);
            }
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    int P1=100,P2=100,P3=100,P_TB;
    while ((P1==100)and(P2==100)and(P3==100)){
        // Con đường 01
        int a=round(sqrt(EXP1)), S;
        if (a<sqrt(EXP1)){
            if ( abs((EXP1-a*a)) <= abs(((a+1)*(a+1)-EXP1)) )
                S = a*a;
            else
                S = (a+1)*(a+1);
        }
        else{
            if ( abs(EXP1-a*a) <= abs(EXP1-(a-1)*(a-1)) )
                S = a*a;
            else
                S = (a-1)*(a-1);
        }
        if (EXP1>=S)
            P1=100;
        else    
            P1=round(((float) ((((float) EXP1/S)+80)*100)/123));

        // Con đường 03
        int arr[10]={32,47,28,79,100,50,22,83,64,11};
        if ((E2<0) or (E2>99))
            return -99;
        else{
            if (E2<10)
                P3=arr[E2];
            else{
                int temp;
                temp = E2/10 + E2%10;
                if (temp<10)
                    P3=arr[temp];
                else
                    P3=arr[temp%10];
            }
        }

        // Con đường 02
        int sotiendadung=0, motnuasotien=round((float) (M1/2));
        if (E2%2==1){
            while (CheckMN(sotiendadung,motnuasotien)==false){
                // Sự kiện 1: Mua đồ ăn
                if (HP1<200){
                    HP1=ReHP(ceil(((float) HP1*1.3)));
                    M1=ReMN(M1-150);
                }
                else{
                    HP1=ReHP(ceil(((float) HP1*1.1)));
                    M1=ReMN(M1-70);
                }

                if (CheckMN(M1,motnuasotien))
                    break;
                
                // Sự kiện 2: Thuê xe
                if (EXP1<400){
                    M1=ReMN(M1-200);
                    EXP1=ReEXP(ceil((float) (EXP1*1.13)));
                }
                else{
                    M1=ReMN(M1-120);
                    EXP1=ReEXP(ceil((float) (EXP1*1.13)));
                }

                if (CheckMN(M1,motnuasotien))
                    break;
                
                // Sự kiện 3: Tìm người hỏi đường
                if (EXP1<300){
                    M1=ReMN(M1-100);
                    EXP1=ReEXP(ceil((float) (EXP1*0.9)));
                }
                else{
                    M1=ReMN(M1-120);
                    EXP1=ReEXP(ceil((float) (EXP1*0.9)));
                }

                if (CheckMN(M1,motnuasotien))
                    break;

            }

            HP1=ReHP(ceil((float) (HP1*0.83)));
            EXP1=ReEXP(ceil((float) (EXP1*1.17)));
        }
        else{
            int dem=0;
            while (dem<3){
                // Sự kiện 1: Mua đồ ăn
                if (HP1<200){
                    HP1=ReHP(ceil(((float) HP1*1.3)));
                    M1=ReMN(M1-150);
                }
                else{
                    HP1=ReHP(ceil(((float) HP1*1.1)));
                    M1=ReMN(M1-70);
                }

                if (M1==0)
                    break;
                dem+=1;
                
                // Sự kiện 2: Thuê xe
                if (EXP1<400){
                    M1=ReMN(M1-200);
                    EXP1=ReEXP(ceil((float) (EXP1*1.13)));
                }
                else{
                    M1=ReMN(M1-120);
                    EXP1=ReEXP(ceil((float) (EXP1*1.13)));
                }

                if (M1==0)
                    break;
                dem+=1;
                
                // Sự kiện 3: Tìm người hỏi đường
                if (EXP1<300){
                    M1=ReMN(M1-100);
                    EXP1=ReEXP(ceil((float) (EXP1*0.9)));
                }
                else{
                    M1=ReMN(M1-120);
                    EXP1=ReEXP(ceil((float) (EXP1*0.9)));
                }

                if (M1==0)
                    break;
                dem+=1;
            }
            HP1=ReHP(ceil((float) (HP1*0.83)));
            EXP1=ReEXP(ceil((float) (EXP1*1.17)));
        }
        int b=round(sqrt(EXP1)), S1;
        if (b<sqrt(EXP1)){
            if ( abs((EXP1-b*b)) <= abs(((b+1)*(b+1)-EXP1)) )
                S1 = b*b;
            else
                S1 = (b+1)*(b+1);
        }
        else{
            if ( abs(EXP1-b*b) <= abs(EXP1-(b-1)*(b-1)) )
                S1 = b*b;
            else
                S1 = (b-1)*(b-1);
        }

        if (EXP1>=S1)
            P2=100;
        else    
            P2=round(((float) ((((float) EXP1/S1)+80)*100)/123));
    }
    
    P_TB=round((float) ((P1+P2+P3)/3));
    if (P_TB<50){
        HP1=ReHP(ceil((float) (HP1*0.85)));
        EXP1=ReEXP(ceil((float) (EXP1*1.15)));
    }
    else{
        HP1=ReHP(ceil((float) (HP1*0.9)));
        EXP1=ReEXP(ceil((float) (EXP1*1.2)));
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////