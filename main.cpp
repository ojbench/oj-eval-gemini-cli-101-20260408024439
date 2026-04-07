#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long a, b, c, d, e, f;
    if (!(cin >> a >> b >> c >> d >> e >> f)) return 0;
    
    long long total_seconds = a * b * c;
    long long current_seconds = f * a * b + e * a + d;
    
    long long min_s = -1;
    long long limit = min({a, b, c});
    
    for (long long X = 0; X < limit; ++X) {
        long long target_seconds = X * a * b + X * a + X;
        long long s = (target_seconds - current_seconds) % total_seconds;
        if (s < 0) s += total_seconds;
        
        if (min_s == -1 || s < min_s) {
            min_s = s;
        }
    }
    
    cout << min_s << endl;
    
    return 0;
}
