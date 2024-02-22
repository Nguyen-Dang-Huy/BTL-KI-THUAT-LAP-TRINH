/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2023
* Author: Vu Van Tien
* Date: 02.02.2023
*/

//The library here is concretely set, students are not allowed to include any other libraries.

#include "study_in_pink1.h"

using namespace std;

void sa_tc_01() {
    cout << "----- Sample Testcase 01 -----" << endl;
    string input_file("sa_tc_01_input");
    int HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3;
    if (!readFile(input_file, HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3)) {
        return;
    }

    //cout << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", E1: " << E1 << endl;
    //int result1 = firstMeet(EXP1, EXP2, E1);
    //cout << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", result: " << result1 << endl;

    // cout << "HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", E2: " << E2 << endl;
    // int result2 = traceLuggage(HP1, EXP1, M1, E2);
    // cout << "HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result2 << endl;

    // cout << "HP1: " << HP1 << ", EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", HP2: " << HP2 << ", E3: " << E3 << endl;
    // int result3 = chaseTaxi(HP1, EXP1, HP2, EXP2, E3);
    // cout << "HP1: " << HP1 << ", EXP1: " << EXP1 << ", EXP2: " << EXP2  << ", HP2: " << HP2 << ", result: " << result3 << endl;

    int result4=checkPassword("bdefghaaa","pink@gmail.com");
    cout << "result: "<<result4;

    // string arr_pwds[] = {"123xyz", "pink#pink", "pink123", "xxxx@xxxx", "pink#pink", "pink123", "pink123"};
    // // string arr_pwds[]={"pink123", "xxxx@xxxx", "123xyz", "pink#pink", "pink#pink","pink123"};
    // int num_pwds=7;
    // int result5=findCorrectPassword(arr_pwds[]= {"123xyz", "pink#pink", "pink123", "xxxx@xxxx", "pink#pink", "pink123", "pink123"},num_pwds)
}


int main(int argc, const char * argv[]) {
    sa_tc_01();
    return 0;
}