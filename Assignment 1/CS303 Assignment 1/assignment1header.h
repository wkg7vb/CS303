// WALTER GILLIAM COMP SCI 303 ASSIGNMENT 1 DUE 9/20/22
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

//declaring functions
//read from a file into an arry return success or failure of read
int readFile(string filename, int (&arr)[200]);
//searches the array for a user input integer
void searchArray(int (&arr)[200], int size);
//modifies an element of the array
void changeElement(int (&arr)[200], int size);
//adds a new element to the array
void newElement(int (&arr)[200], int &size);
//removes an existing element from the array
void removeElement(int (&arr)[200], int &size);
//checks if string is an integer
bool isInt(string input);