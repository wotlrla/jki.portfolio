// Define pins
#define Sensor1 PIN_PC0
#define Sensor2 PIN_PC1
#define Sensor3 PIN_PC2
#define Sensor4 PIN_PC3
#define Sensor5 PIN_PC4

#define MotorLeft PIN_PD3
#define MotorRight PIN_PD5

// Distance of each sensor from the centre, in mm
#define pos1 -95
#define pos2 -42.5
#define pos3 0
#define pos4 42.5
#define pos5 95

// PID control constants
#define kP 0.5
#define kI 0.01
#define kD 0.1

// The base speed of the robot
#define baseSpeed 180

// Calibration parameters
#define CALIBRATION_SAMPLES 100
#define CALIBRATION_DELAY 10

// Global variables
int prevError = 0;
int integral = 0;

// Sensor calibration arrays
uint16_t sensorMin[5] = {1023, 1023, 1023, 1023, 1023}; // Minimum values (white)
uint16_t sensorMax[5] = {0, 0, 0, 0, 0};               // Maximum values (black)
bool calibrated = false;

// Function declarations
void calibrateSensors();
uint16_t readCalibratedSensor(uint8_t sensorPin, uint8_t sensorIndex);
int errorCalc();

void calibrateSensors() {
  for (int i = 0; i < CALIBRATION_SAMPLES; i++) {
    // Read raw sensor values
    uint16_t s1 = analogRead(Sensor1);
    uint16_t s2 = analogRead(Sensor2);
    uint16_t s3 = analogRead(Sensor3);
    uint16_t s4 = analogRead(Sensor4);
    uint16_t s5 = analogRead(Sensor5);
    
    // Update minimum values (white/lower reflectance)
    if (s1 < sensorMin[0]) sensorMin[0] = s1;
    if (s2 < sensorMin[1]) sensorMin[1] = s2;
    if (s3 < sensorMin[2]) sensorMin[2] = s3;
    if (s4 < sensorMin[3]) sensorMin[3] = s4;
    if (s5 < sensorMin[4]) sensorMin[4] = s5;
    
    // Update maximum values (black/higher reflectance)
    if (s1 > sensorMax[0]) sensorMax[0] = s1;
    if (s2 > sensorMax[1]) sensorMax[1] = s2;
    if (s3 > sensorMax[2]) sensorMax[2] = s3;
    if (s4 > sensorMax[3]) sensorMax[3] = s4;
    if (s5 > sensorMax[4]) sensorMax[4] = s5;
    
    delay(CALIBRATION_DELAY);
  }
  
  calibrated = true;
}

uint16_t readCalibratedSensor(uint8_t sensorPin, uint8_t sensorIndex) {
  uint16_t rawValue = analogRead(sensorPin);
  
  // If not calibrated, return raw value
  if (!calibrated) {
    return rawValue;
  }
  
  // Constrain to calibration range
  rawValue = constrain(rawValue, sensorMin[sensorIndex], sensorMax[sensorIndex]);
  
  // Normalize to 0-1000 range (0 = white, 1000 = black)
  uint16_t normalizedValue = map(rawValue, 
                                sensorMin[sensorIndex], 
                                sensorMax[sensorIndex], 
                                0, 1000);
  
  return normalizedValue;
}

int errorCalc() {
  // Read and normalize sensor values
  uint16_t Sensor1In = readCalibratedSensor(Sensor1, 0);
  uint16_t Sensor2In = readCalibratedSensor(Sensor2, 1);
  uint16_t Sensor3In = readCalibratedSensor(Sensor3, 2);
  uint16_t Sensor4In = readCalibratedSensor(Sensor4, 3);
  uint16_t Sensor5In = readCalibratedSensor(Sensor5, 4);

  // Apply threshold to ignore noise
  uint16_t threshold = 100;
  if (Sensor1In < threshold) Sensor1In = 0;
  if (Sensor2In < threshold) Sensor2In = 0;
  if (Sensor3In < threshold) Sensor3In = 0;
  if (Sensor4In < threshold) Sensor4In = 0;
  if (Sensor5In < threshold) Sensor5In = 0;

  // Calculate line position from weighted average
  long sumWeights = (long)Sensor1In * pos1 + 
                   (long)Sensor2In * pos2 + 
                   (long)Sensor3In * pos3 + 
                   (long)Sensor4In * pos4 + 
                   (long)Sensor5In * pos5;
  long sumSignals = Sensor1In + Sensor2In + Sensor3In + Sensor4In + Sensor5In;

  // If no line detected, return previous error
  if (sumSignals == 0) {
    return prevError;
  }

  int linePos = sumWeights / sumSignals;
  int error = -linePos;

  return error;
}

int PControl(int error) {
  return error * kP;
}

int IControl(int error) {
  integral += error;
  // Prevent integral wind-up
  integral = constrain(integral, -1000, 1000);
  return integral * kI;
}

int DControl(int error) {
  int derivative = error - prevError;
  prevError = error;
  return derivative * kD;
}

void setup() {
  // Defining the pin connections
  pinMode(Sensor1, INPUT);
  pinMode(Sensor2, INPUT);
  pinMode(Sensor3, INPUT);
  pinMode(Sensor4, INPUT);
  pinMode(Sensor5, INPUT);

  pinMode(MotorLeft, OUTPUT);
  pinMode(MotorRight, OUTPUT);
  
  // Initialize motor control
  analogWrite(MotorLeft, 0);
  analogWrite(MotorRight, 0);

  // Calibrate sensors on startup
  calibrateSensors();
  
  delay(1000); // Wait before starting
}

void loop() {
  // Calculate error
  int error = errorCalc();

  // Perform control operations
  int PComponent = PControl(error);
  int IComponent = IControl(error);
  int DComponent = DControl(error);

  // Sum control to find correction
  int correction = PComponent + IComponent + DComponent;

  // Alter motor speeds using correction (differential drive)
  int leftSpeed = baseSpeed + correction;
  int rightSpeed = baseSpeed - correction;

  // Constrain motor speeds to valid PWM range
  leftSpeed = constrain(leftSpeed, 0, 255);
  rightSpeed = constrain(rightSpeed, 0, 255);

  // Send motor signals
  analogWrite(MotorLeft, leftSpeed);
  analogWrite(MotorRight, rightSpeed);

  // Small delay for stability
  delay(10);
}