#ifndef TEXTGUFO_H
#define TEXTGUFO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class textGufo; }
QT_END_NAMESPACE

class textGufo : public QMainWindow
{
    Q_OBJECT

public:
    textGufo(QWidget *parent = nullptr);
    ~textGufo();

private slots:
    void on_actionAbrir_triggered();

    void on_actionNovo_triggered();

    void on_actionSalvar_como_triggered();

    void on_actionSalvar_triggered();

    void on_actionSair_triggered();

    void on_actionCopiar_triggered();

    void on_actionRecortar_triggered();

    void on_actionColar_triggered();

    void on_actionDesfazer_triggered();

    void on_actionRefazer_triggered();

    void on_actionFonte_triggered();

    void on_actionCor_da_fonte_triggered();

    void on_actionCor_de_fundo_triggered();

private:
    Ui::textGufo *ui;
    QString localArquivo;
};
#endif // TEXTGUFO_H
