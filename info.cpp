#include "info.h"
#include "pcap_pkthdr.h"
#include <QString>
#include <iostream>

using std::cout;
using std::endl;

class Info cap_info;

void Info::initialize_frames_info ( Fname *capname) {

    cap_info.setMin(0);
    cap_info.setMax(0);
    cap_info.setPkt_amount(0);
    cap_info.setAverage(0);
    cap_info.setFull_length(0);


    do {

      fread(&caphdr, sizeof(pcap_pkthdr), 1, capname->capfile);
      cap_info.setMin (caphdr.getCaplen());
      cap_info.setMax (caphdr.getCaplen());
      fseek(capname->capfile, 24, SEEK_SET);

    } while (false);


    while (!feof(capname->capfile)) {

       fread(&caphdr, sizeof(pcap_pkthdr), 1, capname->capfile);


       if (feof(capname->capfile)!=0)
           break;


       if(cap_info.getMax()<caphdr.getCaplen())
           cap_info.setMax (caphdr.getCaplen());

       if(caphdr.getCaplen()<cap_info.getMin())
           cap_info.setMin (caphdr.getCaplen());

       cap_info.setPkt_amount (getPkt_amount()+1);
       cap_info.setFull_length (getFull_length()+caphdr.getCaplen());


       fseek(capname->capfile, caphdr.getCaplen(), SEEK_CUR);
    }

    if (cap_info.getPkt_amount() != 0) {
        cap_info.setAverage (cap_info.getFull_length() / cap_info.getPkt_amount());
    }
    else QString::number(cap_info.getPkt_amount()) = "Error";
}


