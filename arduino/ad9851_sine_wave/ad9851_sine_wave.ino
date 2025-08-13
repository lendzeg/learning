// //
// //    FILE: AD9851_demo.ino
// //  AUTHOR: Rob Tillaart
// // PURPOSE: demo
// //     URL: https://github.com/RobTillaart/AD985X


// #include "AD985X.h"


// AD9851 freqGen(10, 9, 13, 14, 16);  //  SW SPI
// //    AD9851 pins
// // ----------------------------------------------
// // uint8_t select    MyArduinoNano NO SELECT ??
// // uint8_t resetPin  MyArduinoNano Pin12 D9
// // uint8_t FQUDPin   MyArduinoNano Pin13 D10
// // uint8_t spiData   MyArduinoNano Pin14 D11/MOSI 
// // uint8_t spiClock  MyArduinoNano Pin16 D13/SCK

// // AD9851 freqGen(10, 9, 8, &SPI);  //  HW SPI

// uint32_t freq = 0;
// uint32_t prev = 0;
// uint32_t maxFreq;


// void setup() {
//   //  while(!Serial):  //  uncomment if needed.
//   Serial.begin(115200);
//   Serial.println(__FILE__);
//   Serial.print("AD985X_LIB_VERSION: \t");
//   Serial.println(AD985X_LIB_VERSION);
//   Serial.println();

//   // SPI.begin();  //  HW SPI

//   freqGen.begin();  // Initializes library internals
//   freqGen.powerUp();
//   maxFreq = freqGen.getMaxFrequency();
//   Serial.print("Max Frequency: \t");
//   Serial.println(maxFreq);
//   freqGen.setFrequency(1e6);// uint8_t select    MyArduinoNano NO SELECT ??
// // uint8_t resetPin  MyArduinoNano Pin12 D9
// // uint8_t FQUDPin   MyArduinoNano Pin13 D10
// // uint8_t spiData   MyArduinoNano Pin14 D11/MOSI 
// // uint8_t spiClock 
//   help();
// }

// void loop() {
//   if (Serial.available() > 0) {
//     int c = Serial.read();
//     switch (c) {
//       case '?':
//         help();
//         break;
//       case 'R':
//         freqGen.reset();
//         freq = freqGen.getFrequency();
//         break;
//       case 'P':
//         freqGen.powerDown();
//         break;
//       case 'U':
//         freqGen.powerUp();
//         break;
//       case '+':
//         freq += 1;
//         break;
//       case '-':
//         freq -= 1;
//         break;
//       case '*':
//         freq *= 10;
//         break;
//       case '/':
//         freq /= 10;
//         break;
//     }
//     if (freq > maxFreq) freq = maxFreq;
//   }

//   //  update device if frequency has changed
//   if (prev != freq) {
//     prev = freq;
//     freqGen.setFrequency(freq);
//     Serial.println(freq);
//   }
// }


// void help() {
//   Serial.println();
//   Serial.println("Help Menu:");
//   Serial.println("+ :  f = f + 1");
//   Serial.println("- :  f = f - 1");
//   Serial.println("* :  f = f * 10");
//   Serial.println("/ :  f = f / 10");
//   Serial.println("? :  help");
//   Serial.println("R :  AD9851 reset");
//   Serial.println("P :  AD9851 power down");
//   Serial.println("U :  AD9851 power up");
//   Serial.println();
// }

// //  -- END OF FILE --

#include <PU2REO_AD9851.h>

const int AD9851_PIN_W_CLK = 8;
const int AD9851_PIN_FQ_UD = 9;
const int AD9851_PIN_DATA = 10;
const int AD9851_PIN_RESET = 11;

PU2REO_AD9851   AD9851(AD9851_PIN_W_CLK, AD9851_PIN_FQ_UD, AD9851_PIN_DATA, AD9851_PIN_RESET);  // AD9851 device creation

long value;
int phase = 0; // Remember: each increment means 11.25 degrees. Refer to AD9051 Datasheet for more information

void setup()
{
  // Initializes AD9851
  AD9851.Init();

  // initializes serial
  Serial.begin(115200);
}

void loop(){

  String str;

  // Message:
  Serial.println("Input frequency in [Hz]:");
  while(!Serial.available());

  // read frequency from serial port
  str = Serial.readString();

  // convert
  value = str.toInt(); 
  Serial.print("Frequency set to: ");
  Serial.print(value);
  Serial.println(" [Hz]");
  Serial.println("");
  

  // set frequency
  AD9851.SetFrequency(value, phase);  
}