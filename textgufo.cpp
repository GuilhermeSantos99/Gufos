#include "textgufo.h"
#include "ui_textgufo.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QFontDialog>
#include <QFont>
#include <QColorDialog>
#include <QColor>
#include <iostream>
#include <typeinfo>

textGufo::textGufo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::textGufo)
{
    ui->setupUi(this);

    this->setCentralWidget(ui->textEdit);
}

textGufo::~textGufo()
{
    delete ui;
}


void textGufo::on_actionAbrir_triggered()
{
    QString filtro = "Todos arquivos *.* ;; Arquivos de texto (*.txt) ;; C++ (*.cpp) ;; Python (*.py)";
    QString nomeArquivo = QFileDialog::getOpenFileName(this, "Abrir", QDir::homePath(), filtro);
    QFile arquivo(nomeArquivo);
    localArquivo = nomeArquivo;

    if(!arquivo.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Aviso", "Não foi possível abrir o arquivo");
        return;
    }

    QTextStream entrada(&arquivo);
    QString texto = entrada.readAll();
    ui->textEdit->setText(texto);

    arquivo.close();
}


void textGufo::on_actionNovo_triggered()
{

    QMessageBox::StandardButton resposta = QMessageBox::question(this, "Atenção",
                                                                 "Deseja salvar arquivo atual antes de abrir um novo",
                                                                 QMessageBox::Yes | QMessageBox::No);

    if(resposta == QMessageBox::Yes)
    {
        on_actionSalvar_como_triggered();

    }else
    {
        localArquivo = "";
        ui->textEdit->clear();
        ui->textEdit->setFocus();
    }
}


void textGufo::on_actionSalvar_como_triggered()
{
    QString filtro = "Todos arquivos *.* ;; Arquivos de texto (*.txt) ;; C++ (*.cpp) ;; Python (*.py)";
    QString nomeArquivo = QFileDialog::getSaveFileName(this, "Salvarcomo", QDir::homePath(), filtro);
    localArquivo = nomeArquivo;
    QFile arquivo(nomeArquivo);

    if(!arquivo.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Aviso", "Não foi possível salvar o arquivo");
        return;
    }

    QTextStream saida(&arquivo);
    QString texto = ui->textEdit->toPlainText();
    saida << texto;
    arquivo.flush();

    arquivo.close();
}


void textGufo::on_actionSalvar_triggered()
{

    QFile arquivo(localArquivo);

    if(!arquivo.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Aviso", "Não foi possível salvar o arquivo");
        return;
    }

    QTextStream saida(&arquivo);
    QString texto = ui->textEdit->toPlainText();
    saida << texto;
    arquivo.flush();

    arquivo.close();
}


void textGufo::on_actionSair_triggered()
{
    close();
}


void textGufo::on_actionCopiar_triggered()
{
    ui->textEdit->copy();
}


void textGufo::on_actionRecortar_triggered()
{
    ui->textEdit->cut();
}


void textGufo::on_actionColar_triggered()
{
    ui->textEdit->paste();
}


void textGufo::on_actionDesfazer_triggered()
{
    ui->textEdit->undo();
}


void textGufo::on_actionRefazer_triggered()
{
    ui->textEdit->redo();
}

// Função quebra a execução
void textGufo::on_actionFonte_triggered()
{
    bool fonteOk;
    QFont fonte = QFontDialog::getFont(&fonteOk, this);
    if(fonteOk){
        ui->textEdit->setFont(fonte);
    }else{
        return;
    }
}

// Função quebra a execução
void textGufo::on_actionCor_da_fonte_triggered()
{
    QColor cor = QColorDialog::getColor(Qt::black, this, "Escolha uma cor");
    if(cor.isValid())
    {
        ui->textEdit->setTextColor(cor);
    }
}

//Função quebra a execução
void textGufo::on_actionCor_de_fundo_triggered()
{
    QColor cor = QColorDialog::getColor(Qt::white, this, "Escolha uma cor");
    if(cor.isValid())
    {
        ui->textEdit->setTextBackgroundColor(cor);
    }
}

