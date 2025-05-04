#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    vector<int> s(n);
    int max1 = -1, max2 = -1, maxIdx = -1;

    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
        if (s[i] > max1) {
            max2 = max1; 
            max1 = s[i];  
            maxIdx = i;   
        } else if (s[i] > max2) {
            max2 = s[i];  
        }
    }

    
    for (int i = 0; i < n; i++) {
        int strongestOther = (i == maxIdx) ? max2 : max1;
        printf("%d\n", s[i] - strongestOther);
    }

    return 0;
}
