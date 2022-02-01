#include "structs.h"

#ifndef INFO_H
#define INFO_H


class Info {
private:
    unsigned int m_max;
    unsigned int m_min;
    unsigned int m_pkt_amount;
    unsigned int m_full_length;
    unsigned int m_average;


public:

    void setMax (unsigned int max) {
      m_max = max;
    }
    void setMin (unsigned int min) {
      m_min = min;
    }
    void setPkt_amount (unsigned int pkt_amount) {
      m_pkt_amount = pkt_amount;
    }
    void setFull_length (unsigned int full_length) {
      m_full_length = full_length;
    }
    void setAverage (unsigned int average) {
      m_average = average;
    }


    unsigned int getMax() {
      return m_max;
    }
    unsigned int getMin() {
      return m_min;
    }
    unsigned int getPkt_amount() {
      return m_pkt_amount;
    }
    unsigned int getFull_length() {
      return m_full_length;
    }
    unsigned int getAverage() {
      return m_average;
    }


    void initialize_frames_info ( Fname *capname);
    void print_frames_info ();
};

extern class Info cap_info;


#endif // INFO_H
