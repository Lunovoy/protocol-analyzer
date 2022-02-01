#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "structs.h"
#include "pcap_fheader.h"
#include "pcap_pkthdr.h"
#include "info.h"
#include "calculator.h"

#include <QMainWindow>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QStatusBar>
#include <QString>
#include <QTextEdit>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void file_opened();


public slots:

    void browse_files();
    FILE* open_file(Fname *capname);
    bool check_filename();
    void show_main_info();
    void print_ip_count();
    void init_ip_count(Fname *capname);
    void show_pkt_info();
    void print_ip_info(Fname *capname);
    void show_more_info();
    void open_calc();

public:


    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QWidget *main_widget;

    QGridLayout *grid_layout;

    QGridLayout *grid_layout1;

    QHBoxLayout *hbox_layout;
    QHBoxLayout *hbox_layout1;
    QHBoxLayout *hbox_layout2;

    QFormLayout *form_layout;

    QVBoxLayout *vbox_layout;
    QVBoxLayout *vbox_layout1;
    QVBoxLayout *vbox_layout2;
    QVBoxLayout *vbox_layout3;

    QLineEdit *path_to_file;
    //
    QPushButton *button_browse;
    QPushButton *button_apply;
    QPushButton *button_more_info;
    QPushButton *button_calc;

    Fname *cap;
    QStatusBar *status_bar;

    QFileDialog *file_dialog;

    QTableWidget *main_table;

    QTableWidget *pkt_table;

    QTableWidget *info_table;

    QTableWidget *ip_count_table;

    QTextEdit *encoded_info;
    QTextEdit *decoded_info;

    Calculator *calc;


};


#endif // MAINWINDOW_H
