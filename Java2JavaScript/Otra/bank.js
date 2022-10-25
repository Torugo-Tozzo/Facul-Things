class Banco
{
    #clientes = null;
     static #banco = new Banco();
     this.#clientes = new Array();
    adicionarCliente(cliente)
    {
        (this.#clientes.push(cliente) > 0);
    }
    getCliente(indice)
    {
        return this.#clientes[indice];
    }
    getNumeroDeClientes()
    {
        return this.clientes.length;
    }
    getCliente(nome, sobrenome)
    {
        var result = new Array();
        for ( const  cliente of this.#clientes) {
        if (cliente.getNome()== nome && cliente.getSobrenome()== sobrenome)
        {
            (result.push(cliente) > 0);
        }
}
        return result;
    }
    static getBanco()
    {
        return Banco.#banco;
    }
}
class Cliente
{
    #nome = null;
    #sobrenome = null;
    #contas = null;
    constructor(nome, sobrenome)
    {
        this.nome = nome;
        this.sobrenome = sobrenome;
        this.contas = new Array();
    }
    getNome()
    {
        return this.#nome;
    }
    setNome(nome)
    {
        this.nome = nome;
    }
    getSobrenome()
    {
        return this.#sobrenome;
    }
    setSobrenome(sobrenome)
    {
        this.sobrenome = sobrenome;
    }
    getConta(indice)
    {
        return this.#contas[indice];
    }
    getNumeroDeContas()
    {
        return this.#contas.length;
    }
    adicionarConta(conta)
    {
        (this.contas.push(conta) > 0);
    }
}
class Conta
{
    saldo = 0.0;
    constructor(saldoInicial)
    {
        this.saldo = saldoInicial;
    }
    getSaldo()
    {
        return this.saldo;
    }
    depositar(valor)
    {
        this.saldo = this.saldo + valor;
        return true;
    }
    sacar(valor) throws ExcecaoChequeEspecial
    {
        if ((this.saldo - valor) >= 0)
        {
            this.saldo = this.saldo - valor;
        }
        else 
        {
            var deficit = valor - this.saldo;
            throw new Error("Saldo insuficiente".deficit);
        }
    }
}
class ExcecaoChequeEspecial extends Exception
{
    #deficit = 0.0;
    constructor(mensagem, deficit)
    {
        super(mensagem);
        this.deficit = deficit;
    }
    getDeficit()
    {
        return this.#deficit;
    }
}
class ContaCorrente extends Conta
{
    #chequeEspecial = 0.0;
    constructor(saldoInicial, chequeEspecial)
    {
        super(saldoInicial);
        this.chequeEspecial = chequeEspecial;
    }
    constructor(saldoInicial)
    {
        super(saldoInicial);
    }
    sacar(valor) throws ExcecaoChequeEspecial
    {
        // Saldo + valor cheque especial suficientes para cobrir o saque
        if (this.saldo + this.chequeEspecial >= valor)
        {
            this.saldo -= valor;
        }
        else 
        {
            var deficit = valor - this.saldo;
            if (this.chequeEspecial == 0)
            {
                throw new Error("N?o h? cheque especial".deficit);
            }
            else 
            {
                throw new Error("Saldo insuficiente no cheque especial".deficit);
            }
        }
    }
    getChequeEspecial()
    {
        return this.#chequeEspecial;
    }
    setChequeEspecial(chequeEspecial)
    {
        this.chequeEspecial = chequeEspecial;
    }
}
class ContaPoupanca extends Conta
{
    #taxaRendimento = 0.0;
    constructor(saldoInicial, taxaRendimento)
    {
        super(saldoInicial);
        this.taxaRendimento = taxaRendimento;
    }
}
class RelatorioClientes
{
    geraRelatorio()
    {
        // * Exerc?cio: Recupere abaixo o objeto singleton Banco em vez de atribuir null ? vari?vel banco **
        var banco = Banco.getBanco();
        var cliente = null;
        // *
        //         * Exerc?cio: Defina o local do sistema como sendo Brasil e idioma Portugu?s do Brasil
        //         * (O valor 5 mil em ingl?s ? escrito como 5,000.00. Em portugu?s do Brasil 5.000,00). Ao definirmos
        //         * o local, mudamos o esquema de escrita para valores monet?rios para usado no Brasil
        //         * Dica: use a classe Local da API do JRE
        //         * Uma vez definido o Local, ? necess?rio criar um formatador monet?rio com a classe NumberFormat
        //         * antes de exibirmos nossos valores num?ricos no console:
        //         * Dica: Use a classe NumberFormat e os m?todos est?ticos getCurrencyInstance e format *
        var formatadorMonetario = NumberFormat.getCurrencyInstance(java.util.Locale("pt", "BR"));
        console.log("\n\t\t\tRELAT?RIO DE CLIENTES");
        console.log("\t\t\t========================");
        var isContaCorrente = false;
        for (indiceCliente; indiceCliente < banco.getNumeroDeClientes(); indiceCliente++)
        {
            cliente = banco.getCliente(indiceCliente);
            console.log();
            console.log("Cliente: " + cliente.getNome() + ", " + cliente.getSobrenome());
            for (indiceConta; indiceConta < cliente.getNumeroDeContas(); indiceConta++)
            {
                var conta = cliente.getConta(indiceConta);
                var tipoConta = "";
                // Determina o tipo de conta
                if (conta instanceof ContaPoupanca)
                {
                    tipoConta = "Conta Poupanca";
                    isContaCorrente = false;
                }
                else if (conta instanceof ContaCorrente)
                {
                    tipoConta = "Conta Corrente";
                    isContaCorrente = true;
                }
                else 
                {
                    tipoConta = "Tipo desconhecido de conta";
                }
                // Exibe os saldos da conta
                // * Exerc?cio: Complete a lacuna para formatar a sa?da para exibir o padr?o monet?rio brasileiro (R$)
                //                 * sem explicitamente inclur R$ na instru??o System.out.println() **
                console.log("    " + tipoConta + ": Saldo atual de " + formatadorMonetario.format(conta.getSaldo()) + ". ");
                if (isContaCorrente)
                {
                    var contaCorrente = (ContaCorrente)conta;
                    console.log("\tCheque especial de " + (formatadorMonetario.format(contaCorrente.getChequeEspecial())));
                }
            }
        }
    }
}
class TesteBanco
{
    static main(args)
    {
        var banco = Banco.getBanco();
        var cliente = null;
        var relatorio = new RelatorioClientes();
        // Cria v?rios clientes e suas respectivas contas
        console.log("Criando uma conta corrente para o cliente Bruno Henrique.");
        var brunoHenrique = new Cliente("Bruno", "Henrique");
        banco.adicionarCliente(brunoHenrique);
        cliente = banco.getCliente(0);
        cliente.adicionarConta(new ContaPoupanca(50000.0, 0.03));
        cliente.adicionarConta(new ContaCorrente(220000.0, 40000.0));
        // Cria??o do cliente Everton Ribeiro e sua respectiva
        // conta corrente com saldo inicial e cheque especial
        console.log("Criando uma conta corrente para o cliente Everton Ribeiro");
        var evertonRibeiro = new Cliente("Everton", "Ribeiro");
        var contaER = new ContaCorrente(45000, 30000.0);
        evertonRibeiro.adicionarConta(contaER);
        banco.adicionarCliente(evertonRibeiro);
        // Cria??o do cliente Filipe Luis e sua respectiva
        // conta corrente com saldo inicial, sem cheque especial
        console.log("Criando uma conta corrente para o cliente Filipe Luis.");
        var filipeLuis = new Cliente("Filipe", "Luis");
        var contaFilipeLuis = new ContaCorrente(70000);
        filipeLuis.adicionarConta(contaFilipeLuis);
        banco.adicionarCliente(filipeLuis);
        console.log("Criando uma conta corrente para o cliente Gabriel Barbosa.");
        var gabrielBarbosa = new Cliente("Gabriel", "Barbosa");
        banco.adicionarCliente(gabrielBarbosa);
        cliente = banco.getCliente(2);
        cliente.adicionarConta(new ContaPoupanca(220000.0, 0.03));
        // Cria??o do cliente Diego Alves e sua respectiva conta com saldo inicial
        console.log("Criando uma conta corrente para o cliente Diego Alves.");
        var diegoAlves = new Cliente("Diego", "Alves");
        var contaDA = new ContaCorrente(50000);
        diegoAlves.adicionarConta(contaDA);
        banco.adicionarCliente(diegoAlves);
        // Cria??o da cliente Lorena Lara com conta conjunta com Diego Alves
        console.log("Diego Alves autorizou o cadastro de sua conta corrente como sendo conjunta com a cliente Lorena Lara.");
        var lorenaLara = new Cliente("Lorena", "Lara");
        lorenaLara.adicionarConta(contaDA);
        banco.adicionarCliente(lorenaLara);
        // gerar o relatorio
        relatorio.geraRelatorio();
    }
}
TesteBanco.main([]);