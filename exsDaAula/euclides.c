// Algoritmo de euclides:
 
int euclides (int a, int b) {
    while (a != 0 && b != 0)
    {
        if(a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a+b;
}



int euclides2 (int a, int b) {
    while (a != 0 && b != 0) {
        if(a > b){
            a %= b;
        } else {
            b %= a;
        }
    }
    return a + b;
}

int main() {

    euclides(12,12);
    euclides2(10,5);

    return 0;
}