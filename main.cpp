#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <cmath>

using namespace std;

void parseIn(int*& parsed, char input[], int &counter);
void heapify(int*& arr, int n, int i);
void buildHeap(int*& arr, int n);
void printHeap(int* arr, int n);
void sortHeap(int* arr, int n);
void visualPrint(int* arr, int n);

int main()
{
  int num;
  char fileName[20];
  char input[1000];
  int* parsed;
  int parsedSize;
  cout << endl << "How would you like to input? 1 for console, 2 for file" << endl;
  cin >> num;
  cin.clear();
  cin.ignore(1000000, '\n');

  if (num == 1)
  {
    //getting input from console, store in char array
    cout << endl << "Input numbers with spaces in between " << endl;
    cin.get(input, 1000);
    cin.clear();
    cin.ignore(1000000, '\n');
  }

  else if (num == 2)
  {
    //getting input from file, store in char array
    cout << endl << "What is the file name?" << endl <<;
    cin.get(fileName, 20);
    cin.clear();
    cin.ignore(1000000, '\n');
    streampos size;
    ifstream file(fileName, ios::in | ios::binary | ios::ate);

    if (file.is_open())
    {
      size = file.tellg();
      file.seekg(0, ios::beg);
      file.read(input, size);
      file.close();
    }
  }
  else
  {
    return 0;
  }

  parseIn(parsed, input, parsedSize);
    
  buildHeap(parsed, parsedSize);
  cout << endl << "The heap in array form: ";
  printHeap(parsed, parsedSize);
  cout << endl << "Visual heap: " << endl;
  visualPrint(parsed, parsedSize);
  cout << "The input sorted from greatest to least: ";
  sortHeap(parsed, parsedSize);
  return 0;
}

void parseIn(int*& parsed, char input[], int &counter) {//remove spaces between the chars, make int pointer (array)
  int pointers[2];
  int value;
  int* temp;
  counter = 1;
  pointers[0] = -1;
  for (int i = 0; i < strlen(input); i++)
  {

    if (input[i] == ' ')
    {
      pointers[1] = i;
      int j = 0;
      char* newArray = new char[pointers[1] - pointers[0]];

      for (int i = pointers[0] + 1; i < pointers[1]; i++)
      {
	newArray[j] = input[i];
	j = j + 1;
      }
      newArray[j] = '\0';
      temp = parsed;
      parsed = new int[counter];

      if (counter > 1)
      {
	for (int i = 0; i < counter - 1; i++)
	{
	  parsed[i] = temp[i];
	}
      }
      parsed[counter - 1] = atoi(newArray);
      counter = counter + 1;
      pointers[0] = pointers[1];
    }
  }
  char* newArray = new char[strlen(input) - pointers[0]];
  int j = 0;

  for (int i = pointers[0] + 1; i < strlen(input); i++)
  {
    newArray[j] = input[i];
    //cout << newArray[j];
    j = j + 1;
  }
  newArray[j] = '\0';
  temp = parsed;
  parsed = new int[counter];

  if (counter > 1)
  {
    for (int i = 0; i < counter - 1; i++)
    {
      parsed[i] = temp[i];
    }
  }
  parsed[counter - 1] = atoi(newArray);

}
