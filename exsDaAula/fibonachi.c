// Teorema de fibonachi:

 int fib1(int n) {
    if(n < 2) {
        return 1;
    } else {
        return (fib(n - 1) + fib(n - 2));
    }
 }

 // Forma nao optimal

 int fib2(int n) {
    int f[n + 1]; int i;

    f[0] = f[1] = 1;
    for(i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i + 2];
    } 
    return (f[n]);
 }

 // Forma optimal