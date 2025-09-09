package jogo;

public class Carta {
    private String naipe;
    private String valor;
    private int manilha;
    private int ponto;

    public Carta(String n, String v, int m){
        this.naipe = n;
        this.manilha = m;
        this.valor = v;
    }

    public int getManilha() {
        return manilha;
    }

    public String getValor() {
        return valor;
    }

    public String getNaipe() {
        return naipe;
    }

    public String toString() {
        return valor + " de " + naipe + " (força " + manilha + ")";
    }
}
