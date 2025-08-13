#ifndef ad9851
#define ad9851

#include <Arduino.h>

class AD9851 {
    public:

        // Constructor
        AD9851(int w_clk, int fq_ud, int data, int reset);

        // Initialization method
        void begin();

        // Method to set the output frequency
        void setFrequency(double frequency);

        // Methods for phase control and power down
        void setPhase(int phase);
        void powerDown();
        void powerUp();

    private:

        // Pin assignments
        int _w_clk_pin; 
        int _fq_ud_pin;
        int _data_pin;
        int _reset_pin;

        // Internal state
        uint32_t _tuning_word;
        byte _phase;
        bool _power_down_state;

        // Reference clock frequency
        const double _ref_clock = 180000000.0; // Tipically 180 MHz or 30 MHz with 6x multiplier

        // Private methods for internal operations
        void resetModule();
        void sendData();
        void pulsePin(int pin);
};

#endif