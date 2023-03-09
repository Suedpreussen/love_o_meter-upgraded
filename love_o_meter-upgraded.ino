const int sensorPin = A0;                        
const float baselineTemperature = 22.75;   // temperature in degrees Celsius callibrated from the serial port readings

void setup(){
  Serial.begin(9600);      // open serial port
  pinMode(2, OUTPUT);      // set up LED output pin
  digitalWrite(2, LOW);    // set default for LED as 'off'
}

void loop(){
  int sensorValue = analogRead(sensorPin);     // read data from sensor
  float voltage = (sensorValue/1024.0) * 5.0;  // convert it to voltage
  float temperature = (voltage - 0.5) * 100;   // convert voltage to temperature
  
  // LED flickering frequency as a function of temperature
  float delay_value = 100;                                // default delay for baseline temperature in ms
  float temp_diff = temperature - baselineTemperature;    // dT = t - t_base
  delay_value -= temp_diff*(20 - abs(temp_diff));         // delay(dT) := delay - dT(20 - |dT|)
  
  digitalWrite(2, HIGH);    // set LED on
  delay(delay_value);       // wait the amount of time deiscribed by the function above
  digitalWrite(2, LOW);     // turn LED off
  delay(delay_value);       //  wait the same amount of time till the next iteration with possibly new delay_value
  
  
  // show sensor data on the serial monitor
  Serial.print("sensor value: ");
  Serial.print(sensorValue);
  Serial.print(", volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  Serial.println(temperature);
  
}
