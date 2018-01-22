/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ian
 *
 * Created on January 20, 2018, 12:19 AM
 */

/*
 * Good morning. Here's your coding interview problem for today.
 * This problem was asked by Amazon.
 *
 * Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.
 *
 * For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb", so your function should return 3.
 *
 * Best of luck! As always, shoot me an email if there's anything I can help with!
 *
 * Lawrence
 */

#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;

string subKDistinct(int k, string s) {
    if (s.length() < k) {return s;}
    
    map<char, bool> letterPresent;
    int front = 0;
    int length = 0;
    int count = 0;
    
    for (int i=0; i<s.length(); i++) {
        if (count < k) {
            length += 1;
            if (!letterPresent[s[i]]) {
                count += 1;
                letterPresent[s[i]] = true;
            }
        } else if (letterPresent[s[i]]) {
            length += 1;
        } else {
            letterPresent[s[front]] = false;
            front += 1;
        }
    }
    
    return s.substr(front, length);
}

/*
 * 
 */
int main(int argc, char** argv) {

    cout << subKDistinct(2, "abcba") << endl;
    
    return 0;
}

