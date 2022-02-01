#include "structs.h"

#ifndef PCAP_FHEADER_H
#define PCAP_FHEADER_H


//#include "mainwindow.h"



class pcap_Fheader {
private:
    unsigned int       m_magic;
    unsigned short int m_version_major;
    unsigned short int m_version_minor;
    unsigned int       m_thiszone;      // gmt to local correction
    unsigned int       m_sigfigs;       // accuracy of timestamps
    unsigned int       m_snaplen;       // max length saved portion of each pkt
    unsigned int       m_linktype;      // data link type (LINKTYPE_*)

public:

    unsigned int getMagic () {
      return m_magic;
    }

    unsigned short int getVersionMajor () {
      return m_version_major;
    }

    unsigned short int getVersionMinor () {
      return m_version_minor;
    }

    unsigned int getThisZone () {
      return m_thiszone;
    }

    unsigned int getSigfigs () {
      return m_sigfigs;
    }

    unsigned int getSnaplen () {
      return m_snaplen;
    }

    unsigned int getLinkType () {
      return m_linktype;
    }

    void print_mainheader_info (Fname *capname);
    void print_main_information();



};


extern class pcap_Fheader main_pcap;

#endif // PCAP_FHEADER_H
