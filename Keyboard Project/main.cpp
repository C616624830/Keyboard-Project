//
//  main.cpp
//  Keyboard_Algo2
//
//  Created by LeOOON on 2/16/19.
//  Copyright © 2019 LeOOON. All rights reserved.
//
//Those  "latin:moreKeys="!text/morekeys_w"" in xml files may disrupt the output of the keyboard layout, so just delete them all.
//To open a new blank file, have to use the "g++ -o cpp.exe main.cpp" first.
//Make sure your path is correct
/*APK installation error: may occur
 after you move the current path of your
 project. Can be resolved by  Build---> Clean and Build--> Build APK*/
//if the replacement displayed improperly, make sure your input layout is correct

//g++ -std=c++11 main.cpp -o main          on Linux
// ./main

#include <iostream>
#include "keyboard.h"
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    keyboard layout;
    cout << "Enter the first row(10 letters only, no repitition): ";
    string row1;
    cin>>row1;
    cout << "Enter second row(9 letters only, no repitition): ";
    string row2_1=" ";
    string row2_2;
    cin>>row2_2;
    string row2=row2_1+row2_2;
    cout << "Enter third row(8 letters only, no repitition): ";
    string row3_1="  ";
    string row3_2;
    string row3_3=" ";
    cin>>row3_2;
    string row3=row3_1+row3_2+row3_3;
    //Input testing from line 57 - line 89
    if (row1.length()!=10){
        cout << "Row1 Wrong Length!" <<endl;
        return 0;
    }
    if (row2.length()!=10){
        cout << "Row2 Wrong Length!" <<endl;
        return 0;
    }
    if(row3.length()!=10){
        cout << "Row3 Wrong Length!" <<endl;
        return 0;
    }
    
    char array[26];
    for (int i=0;i<10;i++){
        array[i]=row1[i];
    }
    for (int i=1;i<10;i++){
        array[i+9]=row2[i];
    }
    for (int i=2;i<9;i++){
        array[i+17]=row3[i];
    }
    
    for (int i=0;i<26;i++){
        for (int j=25;j>i;j--){
            if (array[i]==array[j]){
                cout << "Key Repitition, Wrong Input!" <<endl;
                return 0;
            }
        }
    }
    keyboard final_layout(row1,row2,row3);
    cout << "Enter max number of keys swapped in one replacement: ";
    int num;
    cin>>num;
    cout << "\nOption menu:\n1. Normal transition.\n2. Most frequent keys prioritization.\n3. Vowel + most frequent consonants prioritization.\nEnter your option of order replacement: ";
    int option;
    cin>>option;
    cout << "\n\n\nOriginal Keyboard layout: ";
    layout.print_layout();
    cout << "\nReplacement start: \n\n";
    layout.transition_layouts(final_layout, num, option);
}


