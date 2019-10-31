//
//  keyboard.cpp
//  kbd_algo_xml
//
//  Created by LeOOON on 2/20/19.
//  Copyright © 2019 LeOOON. All rights reserved.
//

#include <stdio.h>
#include "keyboard.h"

void keyboard::most_frequent_keys(keyboard final_layout,int num){
    key_pos array_pos[26];
    findpos_final(array_pos[0],final_layout,'e');
    findpos_final(array_pos[1],final_layout,'t');
    findpos_final(array_pos[2],final_layout,'a');
    findpos_final(array_pos[3],final_layout,'o');
    findpos_final(array_pos[4],final_layout,'i');
    findpos_final(array_pos[5],final_layout,'n');
    findpos_final(array_pos[6],final_layout,'s');
    findpos_final(array_pos[7],final_layout,'h');
    findpos_final(array_pos[8],final_layout,'r');
    findpos_final(array_pos[9],final_layout,'d');
    findpos_final(array_pos[10],final_layout,'l');
    findpos_final(array_pos[11],final_layout,'c');
    findpos_final(array_pos[12],final_layout,'u');
    findpos_final(array_pos[13],final_layout,'m');
    findpos_final(array_pos[14],final_layout,'w');
    findpos_final(array_pos[15],final_layout,'f');
    findpos_final(array_pos[16],final_layout,'g');
    findpos_final(array_pos[17],final_layout,'y');
    findpos_final(array_pos[18],final_layout,'p');
    findpos_final(array_pos[19],final_layout,'b');
    findpos_final(array_pos[20],final_layout,'v');
    findpos_final(array_pos[21],final_layout,'k');
    findpos_final(array_pos[22],final_layout,'j');
    findpos_final(array_pos[23],final_layout,'x');
    findpos_final(array_pos[24],final_layout,'q');
    findpos_final(array_pos[25],final_layout,'z');

    int k = 1;
    for (int i=0; i<26; i++){
        int Row=array_pos[i].row;
        int Col=array_pos[i].col;
        if (this->layout[Row][Col] != final_layout.layout[Row][Col]){
            int counter = 0;
            char char1 = layout[Row][Col];
            char char2 = final_layout.layout[Row][Col];
            key_pos ref1{Row,Col};
            cout<<"keyboard_layout_set_"+to_string(k)+": \n";
            replacement2(num,counter,char1,char2,ref1,final_layout);
            file_create(k);
            k++;
            print_layout();
        }
    }
}

void keyboard::find_mismatch2(keyboard final_layout,int num){
    key_pos array_pos[26];
    findpos_final(array_pos[0],final_layout,'e');
    findpos_final(array_pos[1],final_layout,'t');
    findpos_final(array_pos[2],final_layout,'a');
    findpos_final(array_pos[3],final_layout,'o');
    findpos_final(array_pos[4],final_layout,'i');
    findpos_final(array_pos[5],final_layout,'n');
    findpos_final(array_pos[6],final_layout,'s');
    findpos_final(array_pos[7],final_layout,'h');
    findpos_final(array_pos[8],final_layout,'r');
    findpos_final(array_pos[9],final_layout,'d');
    findpos_final(array_pos[10],final_layout,'l');
    findpos_final(array_pos[11],final_layout,'c');
    findpos_final(array_pos[12],final_layout,'u');
    findpos_final(array_pos[13],final_layout,'m');
    findpos_final(array_pos[14],final_layout,'w');
    findpos_final(array_pos[15],final_layout,'f');
    findpos_final(array_pos[16],final_layout,'g');
    findpos_final(array_pos[17],final_layout,'y');
    findpos_final(array_pos[18],final_layout,'p');
    findpos_final(array_pos[19],final_layout,'b');
    findpos_final(array_pos[20],final_layout,'v');
    findpos_final(array_pos[21],final_layout,'k');
    findpos_final(array_pos[22],final_layout,'j');
    findpos_final(array_pos[23],final_layout,'x');
    findpos_final(array_pos[24],final_layout,'q');
    findpos_final(array_pos[25],final_layout,'z');
    for (int i=0; i<26; i++){
        int Row=array_pos[i].row;
        int Col=array_pos[i].col;
        if (this->layout[Row][Col] != final_layout.layout[Row][Col]){
            int counter = 0;
            char char1 = layout[Row][Col];
            char char2 = final_layout.layout[Row][Col];
            key_pos ref1{Row,Col};
            replacement2(num,counter,char1,char2,ref1,final_layout);
            return;
        }
    }
}

void keyboard::replacement2(int num,int counter,char char1,char char2,key_pos ref1,keyboard final_layout){
    char *array_char = new char[num];
    array_char[0]=char1;
    array_char[1]=char2;
    key_pos *array_pos = new key_pos[num+1];
    array_pos[0]=ref1;
    for (int i=0;i<num-1;i++){
        findpos(array_pos[i+1],array_char[i+1]);
        array_char[i+2]=final_layout.layout[array_pos[i+1].row][array_pos[i+1].col];
        counter++;//number of key replaced in one part = number of ref_pos found in this loop + 1
        if (array_char[i+2]==char1){
            break;
        }
    }
    
    cout << layout[array_pos[1].row][array_pos[1].col] << "-->"<< layout[array_pos[0].row][array_pos[0].col] << " ";
    
    cout << layout[array_pos[0].row][array_pos[0].col] << "-->"<< layout[array_pos[counter].row][array_pos[counter].col] << " ";
    
    for (int i=counter;i>0;i--){
        if ((i-1)>0){
            cout<<layout[array_pos[counter].row][array_pos[counter].col]<<"-->"<<layout[array_pos[i-1].row][array_pos[i-1].col]<<" ";
        }
        swap(array_pos[counter],array_pos[i-1]);
    }
    cout << endl;
    int num2 = num-counter-1;
    if (num2>1){
        find_mismatch2(final_layout,num2);
    }
    delete[] array_char;
    delete[] array_pos;
}


void keyboard::vowel_consonant(keyboard final_layout,int num){
    key_pos array_pos[26];
    findpos_final(array_pos[0],final_layout,'a');
    findpos_final(array_pos[1],final_layout,'e');
    findpos_final(array_pos[2],final_layout,'i');
    findpos_final(array_pos[3],final_layout,'o');
    findpos_final(array_pos[4],final_layout,'u');
    findpos_final(array_pos[5],final_layout,'t');
    findpos_final(array_pos[6],final_layout,'n');
    findpos_final(array_pos[7],final_layout,'s');
    findpos_final(array_pos[8],final_layout,'h');
    findpos_final(array_pos[9],final_layout,'r');
    findpos_final(array_pos[10],final_layout,'d');
    findpos_final(array_pos[11],final_layout,'l');
    findpos_final(array_pos[12],final_layout,'c');
    findpos_final(array_pos[13],final_layout,'m');
    findpos_final(array_pos[14],final_layout,'w');
    findpos_final(array_pos[15],final_layout,'f');
    findpos_final(array_pos[16],final_layout,'g');
    findpos_final(array_pos[17],final_layout,'y');
    findpos_final(array_pos[18],final_layout,'p');
    findpos_final(array_pos[19],final_layout,'b');
    findpos_final(array_pos[20],final_layout,'v');
    findpos_final(array_pos[21],final_layout,'k');
    findpos_final(array_pos[22],final_layout,'j');
    findpos_final(array_pos[23],final_layout,'x');
    findpos_final(array_pos[24],final_layout,'q');
    findpos_final(array_pos[25],final_layout,'z');
    int k = 1;
    for (int i=0; i<26; i++){
        int Row=array_pos[i].row;
        int Col=array_pos[i].col;
        if (this->layout[Row][Col] != final_layout.layout[Row][Col]){
            int counter = 0;
            char char1 = layout[Row][Col];
            char char2 = final_layout.layout[Row][Col];
            key_pos ref1{Row,Col};
            cout<<"keyboard_layout_set_"+to_string(k)+": \n";
            replacement3(num,counter,char1,char2,ref1,final_layout);
            file_create(k);
            k++;
            print_layout();
        }
    }
}

void keyboard::find_mismatch3(keyboard final_layout,int num){
    key_pos array_pos[26];
    findpos_final(array_pos[0],final_layout,'a');
    findpos_final(array_pos[1],final_layout,'e');
    findpos_final(array_pos[2],final_layout,'i');
    findpos_final(array_pos[3],final_layout,'o');
    findpos_final(array_pos[4],final_layout,'u');
    findpos_final(array_pos[5],final_layout,'t');
    findpos_final(array_pos[6],final_layout,'n');
    findpos_final(array_pos[7],final_layout,'s');
    findpos_final(array_pos[8],final_layout,'h');
    findpos_final(array_pos[9],final_layout,'r');
    findpos_final(array_pos[10],final_layout,'d');
    findpos_final(array_pos[11],final_layout,'l');
    findpos_final(array_pos[12],final_layout,'c');
    findpos_final(array_pos[13],final_layout,'m');
    findpos_final(array_pos[14],final_layout,'w');
    findpos_final(array_pos[15],final_layout,'f');
    findpos_final(array_pos[16],final_layout,'g');
    findpos_final(array_pos[17],final_layout,'y');
    findpos_final(array_pos[18],final_layout,'p');
    findpos_final(array_pos[19],final_layout,'b');
    findpos_final(array_pos[20],final_layout,'v');
    findpos_final(array_pos[21],final_layout,'k');
    findpos_final(array_pos[22],final_layout,'j');
    findpos_final(array_pos[23],final_layout,'x');
    findpos_final(array_pos[24],final_layout,'q');
    findpos_final(array_pos[25],final_layout,'z');
    for (int i=0; i<26; i++){
        int Row=array_pos[i].row;
        int Col=array_pos[i].col;
        if (this->layout[Row][Col] != final_layout.layout[Row][Col]){
            int counter = 0;
            char char1 = layout[Row][Col];
            char char2 = final_layout.layout[Row][Col];
            key_pos ref1{Row,Col};
            replacement3(num,counter,char1,char2,ref1,final_layout);
            return;
        }
    }
}

void keyboard::replacement3(int num,int counter,char char1,char char2,key_pos ref1,keyboard final_layout){
    char *array_char = new char[num];
    array_char[0]=char1;
    array_char[1]=char2;
    key_pos *array_pos = new key_pos[num+1];
    array_pos[0]=ref1;
    for (int i=0;i<num-1;i++){
        findpos(array_pos[i+1],array_char[i+1]);
        array_char[i+2]=final_layout.layout[array_pos[i+1].row][array_pos[i+1].col];
        counter++;//number of key replaced in one part = number of ref_pos found in this loop + 1
        if (array_char[i+2]==char1){
            break;
        }
    }
    
    cout << layout[array_pos[1].row][array_pos[1].col] << "-->"<< layout[array_pos[0].row][array_pos[0].col] << " ";
    
    cout << layout[array_pos[0].row][array_pos[0].col] << "-->"<< layout[array_pos[counter].row][array_pos[counter].col] << " ";
    
    for (int i=counter;i>0;i--){
        if ((i-1)>0){
            cout<<layout[array_pos[counter].row][array_pos[counter].col]<<"-->"<<layout[array_pos[i-1].row][array_pos[i-1].col]<<" ";
        }
        swap(array_pos[counter],array_pos[i-1]);
    }
    cout << endl;
    int num2 = num-counter-1;
    if (num2>1){
        find_mismatch3(final_layout,num2);
    }
    delete[] array_char;
    delete[] array_pos;
}

