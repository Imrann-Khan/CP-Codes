#include<bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1; ///declaration.
{

    /// In this vector, the size of vector is currently 0.

    /// We can set the size of vector like this,
    int n=2;
    vector<int> v2(n);  /// Now the size of the v2 is 2, and the value is initialized by 0.
    /// We can initialize  the vector with different value like this,
    int m=5;
    vector<int> v3(m,7);  /// Now the size of the v3 is 5, and the value is initialized by 7.
    /// We can include values at the end of vector like this,
    v3.push_back(3);    /// Now the size of the v3 is 6.


    /// We can access any value of the vector in two ways,
    ///1. Like array,
    cout << v3[3] << endl;
    ///2. using ".at()"
    cout << v3.at(5) << endl;
    /// We can reserve memory space for any vector using ".reserve()" function.
    v1.reserve();
    ///v1[0]=20;
    ///v1[1]=650;
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    v1.push_back(60);
    cout << v1.size() << " " << v1.capacity();
    ///v1[2]=90;
    /// Here the size of v1 is 3, but the reserved size is 10. Whitch means we have 10 consecutive memory spaces. However we can still put value after 10 values.
    /// We can

}

    //cout << v1[0] << " " << v1[1] << " " << v1[2];
    return 0;
}
