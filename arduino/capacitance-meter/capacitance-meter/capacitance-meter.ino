// Function prototypes

float measureC_once();

// Constants and global variables definition

const int PIN_STEP = 8;     // digital pin that steps 0->5V
const int PIN_ADC = A0;     // node voltage
const float R_OHMS = 1000000.0; // the resistor value (1 Mohms)

const int ADC_MAX = 1023; // UNO's ADC is 10-bit: readings are 0...1023
const int THRESH = (int)(0.6321205588 * ADC_MAX); // the ADC code at 63.2%

// Setup and loop functions that synthesize as main()

void setup() {
  Serial.begin(115200);
  pinMode(PIN_STEP, OUTPUT);
  digitalWrite(PIN_STEP, LOW); // so the capacitor starts discharged 
}

void loop() {
  // put your main code here, to run repeatedly:

}

// Function definitions

float measureC_once(){
  // Fast discharge of the capacitor
  pinMode(PIN_ADC, OUTPUT);
  digitalWrite(PIN_ADC, LOW);
  delay(5);
  pinMode(PIN_ADC, INPUT);

  
}






