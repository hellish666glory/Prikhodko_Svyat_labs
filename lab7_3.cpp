#include <iostream>
#include <cmath>

using namespace std;

class Exp {
  public:

  int x;
    static int n;

    float expCount (int x, int n) {
      float m = 1 + x;

      for(int i = 2; i <= n; i++) {
        m += (pow(x, i)/(float)(factorial(i)));
      }

      return m;
    }

  private:

    int factorial(int n) {
      if(n < 0)
          return 0;
      if (n == 0)
          return 1;
      else
          return n * factorial(n - 1);
    }

};

int main() {

  Exp *e = new Exp();
  float m = e->expCount(1, 2);
  cout << m << endl;

  return 0;
}
