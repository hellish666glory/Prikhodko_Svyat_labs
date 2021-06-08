#include <stdio.h>
#include <iostream>


template<typename t>
void cyclicalSwap(t *arr) {
  t temp = arr[4];

  for(int i = 4; i > 0; i--) {
    arr[i] = arr[i-1];
  }
  arr[0] = temp;

  for(int i = 0; i < 5; i++) {
    std::cout << *(arr+i) << " ";
  }
  printf("\n");
}

int main(void) {

  int arr[5]  = {1, 2, 3, 4, 5};
  double arrD[5]  = {1, 2, 3, 4, 5};
  cyclicalSwap<int>(arr);
  cyclicalSwap<double>(arrD);
  cyclicalSwap<double>(arrD);

  return 0;
}
