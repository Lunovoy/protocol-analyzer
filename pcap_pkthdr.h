#ifndef PCAP_PKTHDR_H
#define PCAP_PKTHDR_H


class pcap_pkthdr {
private:
    int          m_tv_sec;
    int          m_tv_usec; // time stamp
    unsigned int m_caplen;  // length of portion present
    unsigned int m_len;     // length this packet (off wire)


public:

    int getTv_sec() {
      return m_tv_sec;
    }

    int getTv_usec() {
      return m_tv_usec;
    }

    unsigned int getCaplen() {
      return m_caplen;
    }

    unsigned int getLen() {
      return m_len;
    }

    void print_pkt_information();
};

extern class pcap_pkthdr caphdr;

#endif // PCAP_PKTHDR_H
