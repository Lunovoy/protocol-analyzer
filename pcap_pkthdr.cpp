#include "pcap_pkthdr.h"

#include <iostream>

using std::cout;
using std::endl;

class pcap_pkthdr caphdr;

void pcap_pkthdr::print_pkt_information() {

    cout<<"TV_sec: "<<caphdr.getTv_sec()<<endl;
    cout<<"TV_usec: "<<caphdr.getTv_usec()<<endl;
    cout<<"Caplen: "<<caphdr.getCaplen()<<endl;
    cout<<"Len: "<<caphdr.getLen()<<endl;
    printf ("-----------------------------------------------------------------------------\n");
}

