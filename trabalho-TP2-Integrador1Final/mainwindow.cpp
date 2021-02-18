#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    path = qApp->applicationFilePath();//applicationDirPath
    a->setPath(path);
    a->persistir(0);
    try {
        persistirP->setPath(path);
        persistirP->persistir(0);
        eng.setPath(path);
        eng.abrirArquivo();
    } catch (QString &erro) {
        QMessageBox::warning(this,"Erro",erro);
    }
    ui->tableWidget->setColumnCount(4);
    QStringList comeco = {"Codigo", "Produto", "Quantidade","Preço"};
    ui->tableWidget->setHorizontalHeaderLabels(comeco);
}

MainWindow::~MainWindow()
{
    try {
        eng.atualizarArquivo();
    } catch (QString &erro) {
        QMessageBox::warning(this,"Erro",erro);
    }
    delete a;
    delete persistirP;
    delete ui;
}
void MainWindow::on_pushButtonListar_clicked()
{
    try {
        //LIMPANDO TABELA
        while(ui->tableWidget->rowCount()!=0){
            ui->tableWidget->removeRow(0);
        }
        ui->tableWidget->clear();
        QStringList comeco = {"Codigo", "Produto", "Quantidade","Preço"};
        ui->tableWidget->setHorizontalHeaderLabels(comeco);
        QTableWidgetItem *item1, *item2, *item3, *item4;
        QString saida = eng.listarProdutos();
        //throw saida;
        int contLinhas = 0, tamanho = saida.size();
        for(int i=0;i<tamanho;i++){
            QString codigo = "", descricao = "", quantidade = "", preco = "";
            while(saida[i]!="|"){
                codigo += saida[i];
                i++;
            }
            i++;
            while(saida[i]!="|"){
                descricao += saida[i];
                i++;
            }
            i++;
            while(saida[i]!="|"){
                quantidade += saida[i];
                i++;
            }
            i++;
            while(saida[i]!="-"){
                preco += saida[i];
                i++;
            }
            item1 = new QTableWidgetItem(codigo);
            item2 = new QTableWidgetItem(descricao);
            item3 = new QTableWidgetItem(quantidade);
            item4 = new QTableWidgetItem(preco);
            ui->tableWidget->insertRow(contLinhas);
            ui->tableWidget->setItem(contLinhas,0,item1);
            ui->tableWidget->setItem(contLinhas,1,item2);
            ui->tableWidget->setItem(contLinhas,2,item3);
            ui->tableWidget->setItem(contLinhas,3,item4);
            ui->tableWidget->setRowHeight(contLinhas,20);
            contLinhas++;
            ui->tableWidget->setColumnWidth(0,50);
            ui->tableWidget->setColumnWidth(1,199);
            ui->tableWidget->setColumnWidth(2,70);
            ui->tableWidget->setColumnWidth(3,70);
            ui->tableWidget->setStyleSheet("QTableView {selection-background-color: gray}");
            ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//n pode editar
            ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//seleciona a linha toda
            ui->tableWidget->verticalHeader()->setVisible(false);//tira a contagem de linhas
        }
    } catch (QString &erro) {
        QMessageBox::warning(this,"Erro",erro);
    }
}
void MainWindow::on_pushButtonExcluir_clicked()
{
    try {
        int testeSelecionou = ui->tableWidget->currentRow();
        QString codigoLinha = ui->lineEditConsultar->text();
        if(testeSelecionou == -1 && codigoLinha == ""){
            throw QString("Selecione o produto primeiro");
        }
        QMessageBox::StandardButton opcao = QMessageBox::question(this,"Excluir","Confirma exclusão do produto?",QMessageBox::Yes | QMessageBox::No);
        if(opcao==QMessageBox::Yes){
            if(codigoLinha == ""){
                QString codigo = ui->tableWidget->item(ui->tableWidget->currentRow(),0)->text();
                eng.excluirProdutos(codigo);
                if(ui->tableWidget->rowCount()==1){
                    ui->tableWidget->clear();
                    QStringList comeco = {"Codigo", "Produto", "Quantidade","Preço"};
                    ui->tableWidget->setHorizontalHeaderLabels(comeco);
                }
                ui->pushButtonListar->click();
            }
            else{
                eng.excluirProdutos(codigoLinha);
                ui->lineEditConsultar->clear();
                ui->pushButtonListar->click();
            }
        }
        ui->lineEditConsultar->clear();
        QMessageBox::information(this,"Excluir","Produto excluido com sucesso");
    } catch (QString &erro) {
        QMessageBox::warning(this,"Erro",erro);
    }
}

void MainWindow::on_pushButtonCadastrarNovo_clicked()
{
    try {
        Produto produto;
        ui->lineEditCodigoGe->setFocus();
        std::string teste = ui->lineEditCodigoGe->text().toStdString();
        if(teste == ""){
            ui->lineEditCodigoGe->setFocus();
            throw QString("Digite um código");
        }
        int soNumero = std::stoi(teste);
        QString codigo = QString::number(soNumero);
        codigo = eng.padronizarCodigo(codigo);
        if(eng.analisarProduto(codigo) == true){
            ui->lineEditCodigoGe->clear();
            ui->lineEditCodigoGe->setFocus();
            throw QString("Este código já foi cadastrado");
        }
        else{
            QString descricao = ui->lineEditDescricaoGe->text();
            if(descricao == ""){
                ui->lineEditDescricaoGe->setFocus();
                throw QString("Digite uma descrição");
            }
            QString preco = ui->lineEditPrecoGe->text();
            preco = eng.precoComVirgula(preco);
            if(preco == ""){
                ui->lineEditPrecoGe->setFocus();
                throw QString("Digite um preço");
            }
            QString quantidade = ui->lineEditQuantidadeGe->text();
            if(quantidade == ""){
                ui->lineEditQuantidadeGe->setFocus();
                throw QString("Digite uma quantidade");
            }
            eng.cadastrarProduto(codigo,descricao,quantidade.toInt(),preco.toFloat());
            //QMessageBox::information(this,"Cadastro",QString::number(eng.quantidade()));
        }
        QMessageBox::information(this,"Cadastro","Produto cadastrado com sucesso");
        ui->lineEditPrecoGe->clear();
        ui->lineEditCodigoGe->clear();
        ui->lineEditDescricaoGe->clear();
        ui->lineEditQuantidadeGe->clear();
    } catch (QString &erro) {
        QMessageBox::warning(this,"Erro",erro);
    }
    catch (std::invalid_argument) {
        QMessageBox::information(this,"Erro","O código não pode ter letras");
        ui->lineEditCodigoGe->clear();
        ui->lineEditCodigoGe->setFocus();
    }
}

void MainWindow::on_pushButtonConsultar_clicked()
{
    try {
        QString codigo = ui->lineEditConsultar->text();
        if(codigo == ""){
            ui->lineEditConsultar->setFocus();
            throw QString("Digite o código para consultar");
        }
        codigo = eng.padronizarCodigo(codigo);
        eng.consultarProduto(codigo);
        while(ui->tableWidget->rowCount()!=0){
            ui->tableWidget->removeRow(0);
        }
        //atualizar tabela
        QTableWidgetItem *item1, *item2;

        Produto prod = eng.consultarProduto(codigo);
        item1 = new QTableWidgetItem(prod.getCodigo());
        item2 = new QTableWidgetItem(prod.getDescricao());
        ui->tableWidget->insertRow(0);
        ui->tableWidget->setItem(0,0,item1);
        ui->tableWidget->setItem(0,1,item2);
        item1 = new QTableWidgetItem(QString::number(prod.getQuantidade()));
        item2 = new QTableWidgetItem(QString::number(prod.getPreco()));
        ui->tableWidget->setItem(0,2,item1);
        ui->tableWidget->setItem(0,3,item2);
        ui->tableWidget->setRowHeight(0,20);
        ui->tableWidget->verticalHeader()->setVisible(false);
        ui->lineEditConsultar->clear();
    } catch (QString &erro) {
        ui->lineEditConsultar->clear();
        ui->lineEditConsultar->setFocus();
        QMessageBox::warning(this,"Erro",erro);
    }
}

//Cliente
void MainWindow::on_pushButtonRegistrarCliente_clicked()
{
    try {
        if(v==0){
            a->setLista();
            v=1;
        }
        if(ui->lineEditCodigoCliente->text().isEmpty()){
            throw QString("Digite um codigo");
        }
        if(ui->lineEditCpf_Cnpj_2->text().isEmpty()){
            throw QString("Digite o Cpf ou Cnpj");
        }
        std::string teste=ui->lineEditCodigoCliente->text().toStdString();
        //int enumero=std::stoi(teste);
        a->cadastrar(ui->lineEditCodigoCliente->text().toInt(),ui->lineEditLogradouro_2->text(),ui->lineEditCpf_Cnpj_2->text().toStdString(),ui->lineEditSetor_2->text(),ui->lineEditCidade_2->text(),ui->lineEditEstado_2->text(),ui->lineEditTelefone_2->text(),ui->lineEditEmail_2->text(),ui->lineEditNome_Razao_Social_2->text(),ui->lineEditCelular_Nome_Contato_2->text());
        a->persistir(1);
        QMessageBox::information(this,"Cadastro","Cliente cadastrado com sucesso");
        ui->lineEditEmail_2->clear();
        ui->lineEditSetor_2->clear();
        ui->lineEditCidade_2->clear();
        ui->lineEditCodigoCliente->clear();
        ui->lineEditEstado_2->clear();
        ui->lineEditCpf_Cnpj_2->clear();
        ui->lineEditTelefone_2->clear();
        ui->lineEditLogradouro_2->clear();
        ui->lineEditNome_Razao_Social_2->clear();
        ui->lineEditCelular_Nome_Contato_2->clear();
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
        if(erro=="Codigo ja cadastrado" || erro=="Digite um codigo"){
            ui->lineEditCodigoCliente->selectAll();
            ui->lineEditCodigoCliente->setFocus();
        }
        else{
            ui->lineEditCpf_Cnpj_2->selectAll();
            ui->lineEditCpf_Cnpj_2->setFocus();
        }
    }
    catch (std::invalid_argument) {
        QMessageBox::information(this,"Erro","O código não pode ter letras");
        ui->lineEditCodigoCliente->selectAll();
        ui->lineEditCodigoCliente->setFocus();
    }
}



void MainWindow::on_pushButtonRetirarCliente_clicked()
{
    try {
        if(v==0){
            a->setLista();
            v=1;
        }
        if(ui->lineEditRetirarCliente_2->text().isEmpty()){
            throw QString("Digite o codigo desejado");
        }
        if(a->listarClientes().isEmpty()){
            throw QString("Não ha Clientes");
        }
        a->consultar(ui->lineEditRetirarCliente_2->text().toInt());
        QMessageBox::StandardButton opcao = QMessageBox::question(this,"Excluir","Confirma exclusão do cliente?",QMessageBox::Yes | QMessageBox::No);
        if(opcao==QMessageBox::Yes){
            a->removerCliente(ui->lineEditRetirarCliente_2->text().toInt());
            ui->textEditRetirarCliente->setText("Codigo do Cliente Retirado:"+ui->lineEditRetirarCliente_2->text());
            a->persistir(1);
            if(a->listarClientes().isEmpty()){
                ui->tableWidgetPessoa->setItem(0,0,new QTableWidgetItem(" "));
                ui->tableWidgetPessoa->setItem(0,1,new QTableWidgetItem(" "));
                ui->tableWidgetPessoa->setItem(0,2,new QTableWidgetItem(" "));
                ui->tableWidgetPessoa->setItem(0,3,new QTableWidgetItem(" "));
                ui->tableWidgetPessoa->setItem(0,4,new QTableWidgetItem(" "));
                ui->tableWidgetPessoa->setItem(0,5,new QTableWidgetItem(" "));
                ui->tableWidgetPessoa->setItem(0,6,new QTableWidgetItem(" "));
                ui->tableWidgetPessoa->setItem(0,7,new QTableWidgetItem(" "));
                ui->tableWidgetPessoa->setItem(0,8,new QTableWidgetItem(" "));
                ui->tableWidgetPessoa->setItem(0,9,new QTableWidgetItem(" "));
            }
            else{
                MainWindow::on_pushButtonListarClientes_clicked();
            }
        }
        else{
            ui->lineEditRetirarCliente_2->clear();
            ui->textEditRetirarCliente->clear();
        }
    } catch (QString erro) {
        if(erro=="Se realmente deseja Retirar o Cliente aperte o botão novamente"){
            QMessageBox::information(this,"AVISO",erro);
        }
        else{
            QMessageBox::information(this,"ERRO",erro);
        }
    }
}

void MainWindow::on_pushButtonListarClientes_clicked()
{
    try {
        if(v==0){
            a->setLista();
            v=1;
        }
        ui->tableWidgetPessoa->verticalHeader()->setVisible(false);//tira a contagem de linhas
        QTableWidgetItem *item1, *item2, *item3, *item4,*item5,*item6,*item7,*item8,*item9,*item10;
        QString saida=a->listarClientes();
        if(saida.isEmpty()){
            throw QString("Não ha Clientes");
        }
        int contLinhas = 0, tamanho = saida.size();
        for(int i=0,v=0;i<tamanho;i++,v++){
            ui->tableWidgetPessoa->setRowCount(v+1);
            QString codigo = "", Nome_ou_Razao_Social = "", Celular_ou_Nome_Contato = "", Cpf_ou_Cnpj = "", Telefone = "", Email = "", Logradouro = "", Estado = "", Cidade = "", Setor = "";
            while(saida[i]!="|"){
                codigo += saida[i];
                i++;
            }
            i++;
            while(saida[i]!="|"){
                Nome_ou_Razao_Social += saida[i];
                i++;
            }
            i++;
            while(saida[i]!="|"){
                Celular_ou_Nome_Contato += saida[i];
                i++;
            }
            i++;
            while(saida[i]!="|"){
                Cpf_ou_Cnpj += saida[i];
                i++;
            }
            i++;
            while(saida[i]!="|"){
                Telefone += saida[i];
                i++;
            }
            i++;
            while(saida[i]!="|"){
                Email += saida[i];
                i++;
            }
            i++;
            while(saida[i]!="|"){
                Logradouro += saida[i];
                i++;
            }
            i++;
            while(saida[i]!="|"){
                Estado += saida[i];
                i++;
            }
            i++;
            while(saida[i]!="|"){
                Cidade += saida[i];
                i++;
            }
            i++;
            while(saida[i]!="-"){
                Setor += saida[i];
                i++;
            }
            item1 = new QTableWidgetItem(codigo);
            item2 = new QTableWidgetItem(Nome_ou_Razao_Social);
            item3 = new QTableWidgetItem(Celular_ou_Nome_Contato);
            item4 = new QTableWidgetItem(Cpf_ou_Cnpj);
            item5 = new QTableWidgetItem(Telefone);
            item6 = new QTableWidgetItem(Email);
            item7 = new QTableWidgetItem(Logradouro);
            item8 = new QTableWidgetItem(Estado);
            item9 = new QTableWidgetItem(Cidade);
            item10 = new QTableWidgetItem(Setor);
            ui->tableWidgetPessoa->setItem(v,0,item1);
            ui->tableWidgetPessoa->setItem(v,1,item2);
            ui->tableWidgetPessoa->setItem(v,2,item3);
            ui->tableWidgetPessoa->setItem(v,3,item4);
            ui->tableWidgetPessoa->setItem(v,4,item5);
            ui->tableWidgetPessoa->setItem(v,5,item6);
            ui->tableWidgetPessoa->setItem(v,6,item7);
            ui->tableWidgetPessoa->setItem(v,7,item8);
            ui->tableWidgetPessoa->setItem(v,8,item9);
            ui->tableWidgetPessoa->setItem(v,9,item10);
            contLinhas++;
        }
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}


void MainWindow::on_pushButtonConsultar_2_clicked()
{
    try {
        if(v==0){
            a->setLista();
            v=1;
        }
        if(ui->lineEditConsultar_3->text().isEmpty()){
            throw QString("Digite um codigo");
        }
        a->consultar(ui->lineEditConsultar_3->text().toInt());
        ui->tableWidgetPessoa->setRowCount(1);
        ui->tableWidgetPessoa->verticalHeader()->setVisible(false);//tira a contagem de linhas
        QTableWidgetItem *item1, *item2, *item3, *item4,*item5,*item6,*item7,*item8,*item9,*item10;
        QString saida=a->consultar(ui->lineEditConsultar_3->text().toInt());
        QString codigo = "", Nome_ou_Razao_Social = "", Celular_ou_Nome_Contato = "", Cpf_ou_Cnpj = "", Telefone = "", Email = "", Logradouro = "", Estado = "", Cidade = "", Setor = "";
        int i=0;
        while(saida[i]!="|"){
            codigo += saida[i];
            i++;
        }
        i++;
        while(saida[i]!="|"){
            Nome_ou_Razao_Social += saida[i];
            i++;
        }
        i++;
        while(saida[i]!="|"){
            Celular_ou_Nome_Contato += saida[i];
            i++;
        }
        i++;
        while(saida[i]!="|"){
            Cpf_ou_Cnpj += saida[i];
            i++;
        }
        i++;
        while(saida[i]!="|"){
            Telefone += saida[i];
            i++;
        }
        i++;
        while(saida[i]!="|"){
            Email += saida[i];
            i++;
        }
        i++;
        while(saida[i]!="|"){
            Logradouro += saida[i];
            i++;
        }
        i++;
        while(saida[i]!="|"){
            Estado += saida[i];
            i++;
        }
        i++;
        while(saida[i]!="|"){
            Cidade += saida[i];
            i++;
        }
        i++;
        while(saida[i]!="-"){
            Setor += saida[i];
            i++;
        }
        item1 = new QTableWidgetItem(codigo);
        item2 = new QTableWidgetItem(Nome_ou_Razao_Social);
        item3 = new QTableWidgetItem(Celular_ou_Nome_Contato);
        item4 = new QTableWidgetItem(Cpf_ou_Cnpj);
        item5 = new QTableWidgetItem(Telefone);
        item6 = new QTableWidgetItem(Email);
        item7 = new QTableWidgetItem(Logradouro);
        item8 = new QTableWidgetItem(Estado);
        item9 = new QTableWidgetItem(Cidade);
        item10 = new QTableWidgetItem(Setor);
        ui->tableWidgetPessoa->setItem(0,0,item1);
        ui->tableWidgetPessoa->setItem(0,1,item2);
        ui->tableWidgetPessoa->setItem(0,2,item3);
        ui->tableWidgetPessoa->setItem(0,3,item4);
        ui->tableWidgetPessoa->setItem(0,4,item5);
        ui->tableWidgetPessoa->setItem(0,5,item6);
        ui->tableWidgetPessoa->setItem(0,6,item7);
        ui->tableWidgetPessoa->setItem(0,7,item8);
        ui->tableWidgetPessoa->setItem(0,8,item9);
        ui->tableWidgetPessoa->setItem(0,9,item10);
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_lineEditCodigoCliente_returnPressed()
{
    ui->lineEditCpf_Cnpj_2->selectAll();
    ui->lineEditCpf_Cnpj_2->setFocus();
}

void MainWindow::on_lineEditCpf_Cnpj_2_returnPressed()
{
    ui->lineEditNome_Razao_Social_2->setFocus();
    ui->lineEditNome_Razao_Social_2->selectAll();
}

void MainWindow::on_lineEditNome_Razao_Social_2_returnPressed()
{
    ui->lineEditCelular_Nome_Contato_2->setFocus();
    ui->lineEditCelular_Nome_Contato_2->selectAll();
}

void MainWindow::on_lineEditCelular_Nome_Contato_2_returnPressed()
{
    ui->lineEditTelefone_2->setFocus();
    ui->lineEditTelefone_2->selectAll();
}

void MainWindow::on_lineEditTelefone_2_returnPressed()
{
    ui->lineEditEmail_2->setFocus();
    ui->lineEditEmail_2->selectAll();
}

void MainWindow::on_lineEditEmail_2_returnPressed()
{
    ui->lineEditLogradouro_2->setFocus();
    ui->lineEditLogradouro_2->selectAll();
}

void MainWindow::on_lineEditLogradouro_2_returnPressed()
{
    ui->lineEditEstado_2->setFocus();
    ui->lineEditEstado_2->selectAll();
}

void MainWindow::on_lineEditEstado_2_returnPressed()
{
    ui->lineEditCidade_2->setFocus();
    ui->lineEditCidade_2->selectAll();
}

void MainWindow::on_lineEditCidade_2_returnPressed()
{
    ui->lineEditSetor_2->setFocus();
    ui->lineEditSetor_2->selectAll();
}

void MainWindow::on_lineEditSetor_2_returnPressed()
{
    ui->pushButtonRegistrarCliente->clicked();
}

void MainWindow::on_pushButtonCadastrarItem_clicked()
{
    try {
        QString sCodP, sQuant, sPrecoUni;
       // PersistirPedido persistirP;
        Pedido pedido;
        Itens item;
       // PersistirPedido arquivo;
        if(vl==0){
            persistirP->setLista();
            vl=1;
        }
        int codPedido = ui->lineEditPedido->text().toInt();
        int codCliente = ui->lineEditCliente->text().toInt();
        pedido.analisar(codPedido, codCliente, persistirP->getPath());
        int codProduto = ui->lineEditProduto->text().toInt();
        int quantidade = ui->lineEditQuantidade->text().toInt();
        sCodP = "cod item : " + QString::number(codProduto);
        sQuant = "qntd item[" + QString::number(codProduto) + "]:"  + QString::number(quantidade);
        float total, valor;
        valor = item.PrecoUni(codProduto);
        sPrecoUni = "preco uni. item[" + QString::number(codProduto) +
                "] : R$"  + QString::number(valor);
        total = item.getValorTotal(quantidade, codProduto);
        QString saida = "R$ " + QString::number(valor);
        ui->lineEditPreco->setText(saida);
        saida = "R$ " + QString::number(total);
        ui->lineEditTotalPedido->setText(saida);
        item.cadastrar(codPedido, codProduto, quantidade);
        QMessageBox::StandardButton opcao = QMessageBox::question(this,"Confirmar","Deseja incluir mais itens?",QMessageBox::Yes | QMessageBox::No);
        if(opcao==QMessageBox::Yes){
            item.setCodItem(codProduto);
            item.setCodPedido(codPedido);
            item.setQuantidade(quantidade);
            codProduto = QInputDialog::getInt(this , "Informar código do produto","Código do Produto: ");
            sCodP += " - cod item : " + QString::number(codProduto);
            quantidade = QInputDialog::getInt(this , "Informar quantidade","Quantidade: ");
            sQuant += " - qntd item[" + QString::number(codProduto) + "]:"  + QString::number(quantidade);
            valor = item.PrecoUni(codProduto);
            sPrecoUni += " - preco uni. item[" + QString::number(codProduto) +
                    "] : R$"  + QString::number(valor);
            total += item.getValorTotal(quantidade, codProduto);
            saida = "R$ " + QString::number(valor);
            ui->lineEditPreco->setText(saida);
            item.setCodItem(codProduto);
            item.setCodPedido(codPedido);
            item.setQuantidade(quantidade);
            item.cadastrar(codPedido, codProduto, quantidade);
            QString saidaTotal = "R$ " + QString::number(total);
            ui->lineEditTotalPedido->setText(saidaTotal);
            pedido.setNumeroPedido(codPedido);
            pedido.setValorTotal(total);

        }
        else
        {
            item.setCodItem(codProduto);
            item.setCodPedido(codPedido);
            item.setQuantidade(quantidade);
            item.setUnitario(sPrecoUni);
            QString saida2 = "R$ " + QString::number(total);
            ui->lineEditTotalPedido->setText(saida2);
            pedido.setNumeroPedido(codPedido);
            pedido.setValorTotal(total);

        }
        persistirP->cadastrarPedido(codPedido, pedido.getStatus(), pedido.getData(), total,
                                    sCodP, sQuant, sPrecoUni);
        ui->lineEditPedido->clear();
        ui->lineEditCliente->clear();
        ui->lineEditProduto->clear();
        ui->lineEditQuantidade->clear();
        ui->lineEditPreco->clear();
        persistirP->persistir(1);
        QMessageBox::information(this,"PEDIDO CONFIRMADO","Pedido Cadastrado!!");
    } catch (QString &erro) {
        if(erro=="Pedido já existente"){
            ui->lineEditPedido->setFocus();
            ui->lineEditPedido->selectAll();
        }
        QMessageBox::information(this, "ERRO", erro);
    }
}
void MainWindow::on_pushButtonRemover_clicked()
{
    try {
       // PersistirPedido persistirP;
        if(vl==0){
            persistirP->setLista();
            vl=1;
        }
        int codPedido = ui->lineEditPedidoCodigoRemover->text().toInt();
        QMessageBox::StandardButton opcao = QMessageBox::question(this,"Excluir","Confirma exclusão do produto?",QMessageBox::Yes | QMessageBox::No);
        if(opcao==QMessageBox::Yes){
            persistirP->excluirPedidos(codPedido);
            ui->textEditRemover->setText("Pedido removido com sucesso");
            ui->lineEditPedidoCodigoRemover->clear();
        }
        persistirP->persistir(1);
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO", erro);
    }
}

void MainWindow::on_pushButtonConsultar_3_clicked()
{
    try {
        Itens item;
        //PersistirPedido persistirP;
        QString saida;
        if(vl==0){
            persistirP->setLista();
            vl=1;
        }
        int codPedido = ui->lineEditPedidoCodigoConsultar->text().toInt();
        saida = persistirP->consultarPedido(codPedido);
        ui->textEditConsultar_2->setText(saida);
        ui->lineEditPedidoCodigoConsultar->clear();
    } catch (QString &erro) {
        ui->textEditListar->clear();
        QMessageBox::information(this, "ERRO", erro);
    }
}

void MainWindow::on_pushButtonListar_2_clicked()
{
    try {
        QString saida;
        if(vl==0){
            persistirP->setLista();
            vl=1;
        }
        saida = persistirP->listarPedidos();
        ui->textEditListar->setText(saida);
    } catch (QString &erro) {
        ui->textEditListar->clear();
        QMessageBox::information(this, "ERRO", erro);
    }
}
