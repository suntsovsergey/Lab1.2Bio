/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: macbookpro
 *
 * Created on 19 ноября 2017 г., 18:27
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int number_pattern(string str, string pattern){
    int count=0;
    int i=0;
    for (i=str.find(pattern,i);i!=string::npos; i=str.find(pattern,i+1)){
        count++;
    }
    return count;
}

int main(int argc, char** argv) {

    ifstream input_file("/Users/macbookpro/NetBeansProjects/Lab1.1/Input.txt");
    ofstream output_file("/Users/macbookpro/NetBeansProjects/Lab1.1/Output.txt");
    string str ;
    string string_length;
    string result;
    string *all_patterns;
    int *count_patterns;
    int int_length, length_str;
   //считываем первую строку
    getline(input_file, str, '\n' );
   //считываем вторую строку
    getline(input_file,string_length,'\n');
   //переводим длину из строки в int
    int_length=atoi( string_length.c_str() );
    length_str=str.length();
    all_patterns=new string [length_str];
    count_patterns=new int [length_str];
    int f=0; //отвечает за кол-во элементов в массиве с паттернами

    for(int i=0;i<length_str-int_length+1;i++){
        string temp;
        for(int j=i;j<i+int_length;j++){
            
            temp+=str[j];
        }
        
        if(f==0){
            all_patterns[f]=temp;
            count_patterns[f]=number_pattern(str,temp);
            f++;
        }
        else{
            bool flag=true; // флаг на наличие повторяющихся паттренов
            int k=0;
            while (k<f){
                if(all_patterns[k]==temp) flag=false;
                k++;
            }
            if(flag){
                all_patterns[f]=temp;
                count_patterns[f]=number_pattern(str,temp);
                f++; 
            }
        }       
    }
    int max_el=0;
    for(int i=0;i<f;i++){
        if(max_el<count_patterns[i]) max_el=count_patterns[i];
    }
    
    for(int i=0;i<f;i++){
        if(count_patterns[i]==max_el) result=result+all_patterns[i]+" ";
    }
    
    output_file<<result;
    output_file.close();
    input_file.close();
    return 0;
}

