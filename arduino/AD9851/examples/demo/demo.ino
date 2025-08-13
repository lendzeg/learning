#include <ad9851.h> 

// Define the pin connections based on your schematic
const int W_CLK_PIN     = 13;  // Connected to D13/SCK
const int FQ_UD_PIN     = 10;  // Connected to D10
const int DATA_PIN      = 11;  // Connected to D11/MOSI
const int RESET_PIN     = 9;   // Connected to D9
const float k = 30/5; // Experimental correction factor for frequency scaling

// Create an instance of the AD9851 library with the correct pins
AD9851 dds(W_CLK_PIN, FQ_UD_PIN, DATA_PIN, RESET_PIN);

void setup() {
  // Start the serial monitor for debugging messages
  Serial.begin(9600);
  Serial.println("AD9851 Module Test Sketch");

  // Initialize the AD9851 module
  dds.begin();
  
  // Set an initial frequency to start
  Serial.println("Setting initial frequency to 1 MHz...");
  dds.setFrequency(1000000.0); // 1.0 MHz
}

void loop() {

    // Sweep frequencies from 1 MHz to 20 MHz
    for (int i=1; i<21; i++){
        Serial.print("Setting frequency to ");
        Serial.print(i);
        Serial.println(" MHz...");
        dds.setFrequency(i*1e6*k); 
        delay(3e3);
    }

}