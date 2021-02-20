#include <iostream>
using namespace std;
int main()
{
  int t,i;
  cin >> t;
  for(i=0;i<t;i++)
  {
      long long n,ans; 
      cin >> n;

      ans = 2*(n-1);
      cout << ans << endl;
  }
  return 0;
}

