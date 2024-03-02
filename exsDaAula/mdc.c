// Maximo Divisor Comum

int mdc(int a, int b) {
    int m;

    if(a < b){
        m = a; 
    } else {
        m = b;
    }
    while (m > 0) {
        if (a % m == 0 && b % m == 0)
        {
            return m;
        } else {
            m--;
        }
        
    }
    return m;
}


int mdc2 (int a, int b) {
    int m, r;

    if(a < b) {
        m = a; 
    } else {
        m = b;
    }
    while (m > 0)
    {
        if(a % m == 0 && b % m == 0){
            r = m; m = 0;
        } else {
            m--;
        }

    }
    return r;    
}


int mdc3 (int a, int b) {
    int m;

    if(a < b) {
        m = a; 
    } else {
        m = b;
    }
    while (a % m == 0 && b % m == 0)
    {
        m--;
    }
    return m;

}


int main() {

    mdc(45,18);
    mdc2(45,18);
    mdc3(45,18);
    

    return 0;
}