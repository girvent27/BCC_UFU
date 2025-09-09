package banco.dados;

public class Pessoa {
    private String cpf;
    public String nome;
    private int score;
    public Pessoa(String nome, String cpf, int score){
        this.cpf = cpf;
        this.nome = nome;
        this.score = score;
    }
    public void updateNome(String nome){
        this.nome = nome;
    }
    public void updateScore(int score){
        this.score = score;
    }
}
