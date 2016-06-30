#include <iostream>
#include <vector>

using namespace std;

int main() {
  int a[] = { 10, 20, 30 };
  int b[] = { 1, 2, 3};
  int* c = a+1;
  vector<int> old_arr(4, 100); 
  vector<int> arr;
  arr = old_arr;
  old_arr[1] = 1;  //deep copy of value, rather than just pass the address
   
  *b = *a; // only changes the first element, *(b+1) = *(a+1)
  a[0] = 100;
  printf("%d, %d, %d\n", *a, a[1], *(a+2));
  printf("%d, %d, %d\n", b[0], b[1], *(b+2));
  printf("%d, %d, %d, %d\n", *c, c[1], *(c+2), *(c+3));

  for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
    cout<< ' ' << *it;
  }
  for (vector<int>::iterator it = old_arr.begin(); it != old_arr.end(); it++) {
    cout<< ' ' << *it;
  }
}
