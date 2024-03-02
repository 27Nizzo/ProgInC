/* produto por um inteiro:
calcula: n * m == m + m + m + (...)
*/

float multInt1(int n, float m) {
    int r = 0;

    for(int i = 0; i < n; i++) {
        r += m;
    }

    return r;
}


float multInt2(int n, float m) {
    int r = 0;

    while(n > 0) {
        if(n % 2 == 1) {
            r += m;

            n /= 2;
            m *= 2;

        }
    }
    return r;
}


int main() {

    multInt1(5, 2.5);

    return 0;
}