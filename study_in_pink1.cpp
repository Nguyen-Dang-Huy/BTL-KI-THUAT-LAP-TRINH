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
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
    // TODO: Complete this function

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