#include "ad9851.h"

// Constructor for the AD9851 class
// It receives data from the user and sent it to the private variables
// The constructor does not have a return type
AD9851::AD9851(int w_clk, int fq_ud, int data, int reset) {
    _w_clk_pin = w_clk;
    _fq_ud_pin = fq_ud;
    _data_pin = data;
    _reset_pin = reset;

    _phase = 0;
    _power_down_state = false;
}

void AD9851::begin(){
    // Set the pin modes of the board pins
    pinMode(_w_clk_pin, OUTPUT);
    pinMode(_fq_ud_pin, OUTPUT);
    pinMode(_data_pin, OUTPUT);
    pinMode(_reset_pin, OUTPUT);

    resetModule();
}

void AD9851::setFrequency(double frequency){
    if (frequency > 70000000.0){
        frequency = 70000000.0;
    }
    if (frequency < 0.0){
        frequency = 0.0;
    }

    _tuning_word = (uint32_t) ((frequency * pow(2, 32)) / _ref_clock);
    sendData();
}

void AD9851::pulsePin(int pin) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(1);
    digitalWrite(pin, LOW);
}

void AD9851::resetModule() {
    pulsePin(_w_clk_pin);
    pulsePin(_reset_pin);
}


void AD9851::sendData() {
    uint64_t data_word = 0;
    data_word |= (uint64_t) _tuning_word; // W0-W31
    if (_power_down_state) {
    // W32 is 0 (6x multiplier disabled)
    // W33 is 0
    if (_power_down_state){
        data_word |= (1ULL << 34); // W34
    }
    data_word |= ((uint64_t) _phase << 35); // W35-W39
    }

    for (int i = 0; i < 40; i++) {
        digitalWrite(_data_pin, (data_word >> i) & 0x01);
        pulsePin(_w_clk_pin);
    }

    pulsePin(_fq_ud_pin); // Pulse the FQ_UD pin to update the frequency
}

void AD9851::setPhase(int phase) {
    // 5 bits for phase, allowing 2^5 different phase steps (from 0 to 31)
    // Each step is 11.5 degrees (so 11.25 x 32 = 360 degrees)
    if (phase >= 0 && phase < 32) {
        _phase = (byte) phase;
        sendData(); // Send the updated phase data
    }
}

void AD9851::powerDown() {
    _power_down_state = true;
    sendData(); // Send the updated power down state
}

void AD9851::powerUp() {
    _power_down_state = false;
    sendData(); // Send the updated power up state
}