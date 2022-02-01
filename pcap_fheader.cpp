
#include "mainwindow.h"

#include <iostream>

using std::cout;
using std::endl;

class pcap_Fheader main_pcap;



void pcap_Fheader::print_mainheader_info (Fname *capname) {

    fread(&main_pcap, sizeof(pcap_Fheader), 1,capname->capfile);

}




