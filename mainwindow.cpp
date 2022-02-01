
#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    main_widget = new QWidget();

    cap = new Fname();


    setCentralWidget(main_widget);
    setGeometry(0, 0, 1200, 800);
    setWindowTitle("Protocol Analyzer");
    move(300, 0);
    setMaximumSize(1200, 800);
    setMinimumSize(1200, 800);

    grid_layout = new QGridLayout;
    main_widget->setLayout(grid_layout);

    grid_layout1 = new QGridLayout();

    hbox_layout = new QHBoxLayout();
    hbox_layout1 = new QHBoxLayout();
    hbox_layout2 = new QHBoxLayout();

    vbox_layout = new QVBoxLayout();
    vbox_layout1 = new QVBoxLayout();
    vbox_layout2 = new QVBoxLayout();
    vbox_layout3 = new QVBoxLayout();

    path_to_file = new QLineEdit();
    path_to_file->setPlaceholderText("Enter the path of cap file...");
    path_to_file->setStyleSheet("color: white;");

    button_browse = new QPushButton("Browse");
    button_browse->setCursor(Qt::PointingHandCursor);

    button_apply = new QPushButton("Apply");
    button_apply->setCursor(Qt::PointingHandCursor);

    file_dialog = new QFileDialog();

    status_bar = new QStatusBar();
    status_bar->showMessage("...");

    form_layout = new QFormLayout();

    main_table = new QTableWidget();
    main_table->setRowCount(7);
    main_table->setColumnCount(1);
    main_table->setVerticalHeaderLabels(QStringList() << "Magic:" << "Version major:"
                                                      << "Version minor:" << "This zone:"
                                                      << "Sigfigs:" << "Snaplen:" << "Linktype:");

    main_table->setHorizontalHeaderLabels(QStringList() << "");

    pkt_table = new QTableWidget();
    pkt_table->setColumnCount(5);
    pkt_table->setHorizontalHeaderLabels(QStringList() << "TV_sec" << "TV_usec" << "Caplen" << "Len" << "IP");
    pkt_table->setCornerButtonEnabled(false);
    pkt_table->setCursor(Qt::CursorShape::PointingHandCursor);

    info_table = new QTableWidget();
    info_table->setRowCount(4);
    info_table->setColumnCount(1);
    info_table->setVerticalHeaderLabels(QStringList() << "Number of frames:" << "Average frame length:"
                                                                                 << "Max frame length:" << "Min frame length:");

    info_table->setHorizontalHeaderLabels(QStringList() << "");

    ip_count_table = new QTableWidget();
    ip_count_table->setColumnCount(2);
    ip_count_table->setRowCount(5);
    ip_count_table->setHorizontalHeaderLabels(QStringList() << "Ipv4" << "Not Ipv4");
    ip_count_table->setVerticalHeaderLabels(QStringList() << "Total:" << "TCP:" << "UDP:" << "ICMP" << "Other:");
    ip_count_table->setStyleSheet(";");

    vbox_layout->setAlignment(Qt::AlignmentFlag::AlignBottom);

    button_calc = new QPushButton("Calculator");

    button_browse->setStyleSheet("margin: 0px 140px;");
    button_apply->setStyleSheet("margin: 0px 140px;");

    encoded_info = new QTextEdit();
    encoded_info->setReadOnly(true);

    decoded_info = new QTextEdit();
    decoded_info->setReadOnly(true);

    main_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    info_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    pkt_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ip_count_table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    for (u_int16_t i = 0; i < info_table->rowCount(); i++) {
        info_table->setRowHeight(i, 24);
    }

    grid_layout->addWidget(path_to_file, 1, 1);
    grid_layout->addWidget(status_bar, 2, 1);
    grid_layout->addWidget(button_browse, 1, 2);
    grid_layout->addWidget(button_calc, 1, 3);
    grid_layout->addWidget(button_apply, 2, 2);
    grid_layout->addLayout(grid_layout1, 3, 1);

    grid_layout1->addWidget(main_table, 1, 1);
    grid_layout1->addLayout(vbox_layout, 1, 2);

    vbox_layout->addWidget(info_table, 1);
    vbox_layout->addWidget(ip_count_table, 2);

    grid_layout1->addWidget(encoded_info, 2, 1);
    grid_layout1->addWidget(decoded_info, 2, 2);

    grid_layout->addWidget(pkt_table, 3, 2);

    connect(button_calc, &QPushButton::clicked, this, &MainWindow::open_calc);
    connect(button_browse, SIGNAL(clicked()), this, SLOT(browse_files()));
    connect(button_apply, &QAbstractButton::clicked, this, &MainWindow::check_filename);

    connect(this, &MainWindow::file_opened, this, &MainWindow::show_main_info);
    connect(this, &MainWindow::file_opened, this, &MainWindow::print_ip_count);
    connect(this, &MainWindow::file_opened, this, &MainWindow::show_pkt_info);

    connect(pkt_table, &QTableWidget::cellClicked, this, &MainWindow::show_more_info);

}

void MainWindow::print_ip_count() {
    init_ip_count(cap);
}

void MainWindow::init_ip_count(Fname *capname){

    fseek(capname->capfile, 24, SEEK_SET);
    int  ipv4_amount=0, tcp=0, icmp=0, udp=0,other_ipv4=0, other=0;
    char ip1;
    char ip2;
    char prot;


    while (!feof(capname->capfile)){

      fread(&caphdr, sizeof(pcap_pkthdr), 1, capname->capfile);

      if (feof(capname->capfile)!=0)
        break;

      fseek(capname->capfile, 12, SEEK_CUR);

      fread(&ip1, sizeof(ip1), 1, capname->capfile);
      fread(&ip2, sizeof(ip2), 1, capname->capfile);

      if(ip1==8 && ip2==0){
        ipv4_amount++;

        fseek(capname->capfile, -14, SEEK_CUR);

        fseek(capname->capfile, 23, SEEK_CUR);
        fread(&prot, sizeof(prot), 1, capname->capfile);

        if (prot==6) {
          tcp++;
        } else if (prot==1) {
            icmp++;
          } else if(prot==17) {
              udp++;
            } else {
                other_ipv4++;
              }

        fseek(capname->capfile, -24, SEEK_CUR);

        } else {
            fseek(capname->capfile, -14, SEEK_CUR);
            other++;
          }


        fseek(capname->capfile, caphdr.getCaplen(), SEEK_CUR);
    }

    QVector<int> ip_vec = {ipv4_amount, tcp, udp, icmp, other_ipv4, other};

    for (u_int16_t i = 0; i < 5; i++) {

            QTableWidgetItem *itm = new QTableWidgetItem(QString::number(ip_vec[i]));
            ip_count_table->setItem(i, 0, itm);

    }

    QTableWidgetItem *other_itm = new QTableWidgetItem(QString::number(other));
    ip_count_table->setItem(0, 1, other_itm);


}

void MainWindow::print_ip_info(Fname *capname){

    fseek(capname->capfile, 24, SEEK_SET);

    char ip1;
    char ip2;
    char prot;

    size_t j = 0;
    while (!feof(capname->capfile)) {

      fread(&caphdr, sizeof(pcap_pkthdr), 1, capname->capfile);

      if (feof(capname->capfile)!=0)
        break;

      fseek(capname->capfile, 12, SEEK_CUR);

      fread(&ip1, sizeof(ip1), 1, capname->capfile);
      fread(&ip2, sizeof(ip2), 1, capname->capfile);

      if(ip1==8 && ip2==0){

        fseek(capname->capfile, -14, SEEK_CUR);

        fseek(capname->capfile, 23, SEEK_CUR);
        fread(&prot, sizeof(prot), 1, capname->capfile);

        if (prot==6) {
          QTableWidgetItem *itm = new QTableWidgetItem(QString("TCP"));
          pkt_table->setItem(j, 4, itm);
        } else if (prot==1) {

            QTableWidgetItem *itm = new QTableWidgetItem(QString("ICMP"));
            pkt_table->setItem(j, 4, itm);
          } else if (prot==17) {

              QTableWidgetItem *itm = new QTableWidgetItem(QString("UDP"));
              pkt_table->setItem(j, 4, itm);
            } else {
                QTableWidgetItem *itm = new QTableWidgetItem(QString("..."));
                pkt_table->setItem(j, 4, itm);
              }

        fseek(capname->capfile, -24, SEEK_CUR);

        } else {
            fseek(capname->capfile, -14, SEEK_CUR);
            QTableWidgetItem *itm = new QTableWidgetItem(QString("not ipv4"));
            pkt_table->setItem(j, 4, itm);
          }

        fseek(capname->capfile, caphdr.getCaplen(), SEEK_CUR);
        ++j;
    }

}

void MainWindow::show_more_info() {

    size_t i = 0;
    size_t pkt_num = pkt_table->currentRow() + 1;

    fseek(cap->capfile, 24, SEEK_SET);

    while (!feof(cap->capfile)) {

      fread(&caphdr, sizeof(pcap_pkthdr), 1, cap->capfile);


      if (feof(cap->capfile)!=0)
          break;

      i++;

      if(i == pkt_num) {
          encoded_info->setText("");
          decoded_info->setText("");

          unsigned char databuff[caphdr.getCaplen()];

          fread(databuff, caphdr.getCaplen(), 1, cap->capfile);


          for (size_t i = 0; i<caphdr.getCaplen(); i++) {

              QString encode;

              encoded_info->insertPlainText(encode.asprintf("%02x\t", databuff[i]));

          }

          for (size_t i = 0; i<caphdr.getCaplen(); i++){
              QString decode;

              decoded_info->insertPlainText(decode.asprintf("%c", databuff[i]));
          }
      }

    fseek(cap->capfile, caphdr.getCaplen(), SEEK_CUR);
    }

}

void MainWindow::open_calc() {
    calc = new Calculator;
    calc->show();
}


void MainWindow::show_pkt_info() {

    pkt_table->clearContents();

    fseek(cap->capfile, 24, SEEK_SET);

    size_t i= 0;

    while (!feof(cap->capfile)) {

        fread(&caphdr, sizeof(pcap_pkthdr), 1, cap->capfile);


        if (feof(cap->capfile)!=0)
            break;

        QVector<int> sub_info = {caphdr.getTv_sec(), caphdr.getTv_usec(), (int)caphdr.getCaplen(), (int)caphdr.getLen() };

        for (size_t j = 0; j < 4 ; j++) {
            QTableWidgetItem *itm = new QTableWidgetItem(QString::number(sub_info[j]));

            pkt_table->setItem(i, j, itm);
        }
        i++;
        fseek(cap->capfile, caphdr.getCaplen(), SEEK_CUR);
    }

    print_ip_info(cap);

}

void MainWindow::show_main_info () {
    main_pcap.print_mainheader_info(cap);

    unsigned int main_info[] = {main_pcap.getMagic(),main_pcap.getVersionMajor(), main_pcap.getVersionMinor(),
                           main_pcap.getThisZone(), main_pcap.getSigfigs(), main_pcap.getSnaplen(), main_pcap.getLinkType() };

    for (u_int16_t i = 0; i < main_table->rowCount(); i++) {

        if (i == 0) {
            QTableWidgetItem *itm = new QTableWidgetItem(QString::number(main_info[i], 16));
            main_table->setItem(i, 0, itm);
        }
        else {
            QTableWidgetItem *itm = new QTableWidgetItem(QString::number(main_info[i]));
            main_table->setItem(i, 0, itm);
        }
    }
    cap_info.initialize_frames_info(cap);
    pkt_table->setRowCount(cap_info.getPkt_amount());

    unsigned int info[] = {cap_info.getPkt_amount(), cap_info.getAverage(), cap_info.getMax(), cap_info.getMin() };

    for (u_int16_t i = 0; i < info_table->rowCount(); i++) {
        QTableWidgetItem *itm = new QTableWidgetItem(QString::number(info[i]));
        info_table->setItem(i, 0, itm);
    }

    encoded_info->clear();
    decoded_info->clear();
}

void MainWindow::browse_files() {
    path_to_file->setText(file_dialog->getOpenFileName(this, "Find cap file", "", "cap (*.cap);; pcap (*.pcap)" ));
}

bool MainWindow::check_filename() {

    if (open_file(cap)) {
        status_bar->showMessage("File opened!");
        emit file_opened();
        return true;
    }
    status_bar->showMessage("Oops, something went wrong, try again");
    return false;
}

FILE* MainWindow::open_file(Fname *capname) {
    capname->name = path_to_file->text();
    return capname->capfile = std::fopen(capname->name.toStdString().c_str(), "r+b");
}

MainWindow::~MainWindow()
{
}

