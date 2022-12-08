#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;

void move_to_rear(queue<int>& qName);

bool checkPalindrome(string toCheck);

void Part2();

void printMap(map<string, string> mName);

void findCapByState(map<string, string> mName);