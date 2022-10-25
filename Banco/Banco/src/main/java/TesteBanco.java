import banco.dominio.*;
import banco.dominio.excecoes.ExcecaoChequeEspecial;

public class TesteBanco {
    public static void main(String[] args) {
        TesteBanco testeBanco = new TesteBanco();
        Banco banco = Banco.getBanco();
        Conta conta = null;
        Cliente cliente = null;

        // Cria dois clientes e suas respectivas contas
        Cliente brunoHenrique = new Cliente("Bruno", "Henrique");
        banco.adicionarCliente(brunoHenrique);
        brunoHenrique.adicionarConta(new ContaCorrente(220000.00, 40000.00));

        Cliente gabrielBarbosa = new Cliente("Gabriel", "Barbosa");
        banco.adicionarCliente(gabrielBarbosa);
        gabrielBarbosa.adicionarConta(new ContaCorrente(30000));

        System.out.println("------------------ RELATÓRIO DE TRANSAÇÕES -------------------\n");

        // Testando uma conta poupança
        System.out.println("Recuperando o cliente Bruno Henrique");
        conta = brunoHenrique.getConta(0);
        // Executa algumas transações na conta
        try {
            System.out.println("Sacando R$ 1.200,00");
            conta.sacar(1200);
            System.out.println("Depositando R$ 8.525,00");
            conta.depositar(8525);
            System.out.println("Sacando R$ 300.000,00");
            conta.sacar(300000);
            System.out.println("Sacando R$ 50.000,00: ");
            conta.sacar(50000);
        } catch (ExcecaoChequeEspecial e1) {
            System.out.println("Exceção: " + e1.getMessage()
                    + "   Déficit: " + e1.getDeficit());
        } finally {
            System.out.println("Cliente [" + brunoHenrique.getNome()
                    + ", " + brunoHenrique.getSobrenome() + "]"
                    + " Tem um saldo em conta corrente de "
                    + conta.getSaldo());
        }

        System.out.println();

        System.out.println("Recuperando o cliente Gabriel Barbosa");
        conta = gabrielBarbosa.getConta(0);
        // Executa algumas transações
        try {
            System.out.println("Saque de R$ 15500.00");
            conta.sacar(15500.00);
            System.out.println("deposito de R$ 3000.00");
            conta.depositar(3000);
            System.out.println("Saque de R$ 18000.00");
            conta.sacar(18000.00);

        } catch (ExcecaoChequeEspecial e1) {
            System.out.println("Exceção: " + e1.getMessage()
                    + "   Déficit: " + e1.getDeficit());
        } finally {
            System.out.println("Cliente [" + gabrielBarbosa.getNome()
                    + ", " + gabrielBarbosa.getSobrenome() + "]"
                    + " Tem um saldo dem conta corrente de "
                    + conta.getSaldo());
        }
     }
}