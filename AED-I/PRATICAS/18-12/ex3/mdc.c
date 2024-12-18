
int mdc(int n1, int n2) {

    int resto;

    do {
        resto = n1 % n2;
        n1 = n2;
        n2 = resto;

    } while (resto != 0);

    return n1;
}