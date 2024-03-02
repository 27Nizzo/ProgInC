void circulo (int raio) {
    int l, c;

    for(l = raio; l >= -raio; l--) {
        for(c = -raio; c <= raio; c++) {
            if(l*l + c*c >= raio*raio) {
                putchar('#');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}

int main () {

    circulo(3);

    return 0;
}