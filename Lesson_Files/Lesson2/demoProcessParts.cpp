#include<iostream>
#include<unistd.h>
using namespace std;

int g1, g2;

int main() {
  int l1, l2;
  cout << "Local variable addreses: \n" << &l1 << endl << &l2 << endl;
  cout << "Global variable addreses: \n" << &g1 << endl << &g2 << endl;
  while(1) {
    sleep(1);
  }
}
