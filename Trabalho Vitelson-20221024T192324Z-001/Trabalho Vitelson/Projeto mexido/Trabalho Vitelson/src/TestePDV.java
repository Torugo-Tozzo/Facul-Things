public class TestePDV {
    public static void main(String[] args) {


        Endereco endereco = new Endereco("Rua X", "37130-000", "Alfenas", "", "Aeroporto", 5, "MG");

        System.out.println(endereco.getBairro());

        Loja loja = new Loja("Supermercado Preço Bão", endereco);

        Registradora registradora = loja.getRegistradora("R01");

        //CatalogoProdutos catalogo = registradora.getCatalogo();

//        registradora.criarNovaVenda();
//        registradora.entrarItem("01", 3);
//        registradora.entrarItem("02", 2);
//        registradora.entrarItem("03", 1);
//
//        registradora.finalizarVenda();
//        double totalVenda = registradora.getVendaCorrente().calcularTotalVenda();
//
//        registradora.finalizarVenda();
        //double totalVenda = registradora.getVendaCorrente().calcularTotalVenda();
       //registradora.fazerPagamento(totalVenda ,   , 1,   ); //Questão 2.16


        //Pagamento com cartão não gera troco
//        gerarRecibo(registradora, 0.0);
//
//        public static void gerarRecibo (Registradora registradora,double troco){ //Questão 2.17
//            Venda venda = registradora.getVendaCorrente();
//            System.out.println("");
//            System.out.println("--------------------------- Supermercado Preço Bão ---------------------------");
//            System.out.println(" Registradora : " + registradora.getId());
//            System.out.println("\t\t\t\tCUPOM FISCAL");
//            System.out.println(venda);
//            System.out.println("Troco................: R$ " + troco);
//        }


    }


}
