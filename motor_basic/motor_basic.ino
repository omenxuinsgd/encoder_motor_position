/*......................
 *  BTS7960 HBridge Test
 *  
 *  Simple example of using the BTS7960 HBridge to control a motor
 *  This sketch simply sends a pwm signal to the HBridge to spin the motor 
 *  one way and then spin the motor the other direction.
 *  
 *  PWM Description for Arduino: https://www.arduino.cc/en/tutorial/PWM
 *  
 *  By : Barry Tarlton
*/
// Set the pin out for the Right PWM and Left PWM
// "Right" and "Left" are relative to the motor direction and 
// doesn't make sense from a programming point of view sense 
// depending on how you wire or physcally mount the motor the direction is different.
// But when you send a signal on RPWM the motor will go one way and when you 
// send a signal on LPWM, the motor will go the other way.
int RPWM = 5;  // Digital/PWM pin 5 to the RPWM on the BTS7960
int LPWM = 7;  // Digital/PWM pin 6 to the LPWM on the BTS7960

// Enable "Left" and "Right" movement
int R_EN = 6;  // connect Digital/PWM pin 7 to L_EN on the BTS7960

void setup() {
  // put your setup code here, to run once:

  // initialize all our pins to output
  for (int i = 5; i < 9; i++) {
    pinMode(i, OUTPUT);
  }
  // set all the pins you want to use to LOW
  for (int i = 5; i < 9; i++) {
    digitalWrite(i, LOW);
  }
  delay(1000);// wait a second
  Serial.begin(9600);
  
  //enable "Right" and "Left" movement on the HBridge
  // Notice use of digitalWrite to simply turn it on and keep it on.
  digitalWrite(R_EN, HIGH);  
}



void loop() {
  // put your main code here, to run repeatedly:

  // Use an analogWrite(pin,  which tells it to send a modulated
  // signal (PWM) to specific pin at a specific "duty cycle".
  // Valid values are 0 to 255.  0 means always off(or no power) and 255 means always on(full power)
  // https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/
  digitalWrite(RPWM, LOW); // pulse a signal continually at the rate of 64 
  digitalWrite(LPWM, LOW);
  // the analogWrite line above should start the motor turning in one direction at about 1/4 of power.
  delay(500); // wait 5 seconds, motor continues to move because the analogWrite is still pulsing
  digitalWrite(RPWM, LOW); // pulse a signal continually at the rate of 64 
  digitalWrite(LPWM, LOW);
  // the analogWrite line above should start the motor turning in one direction at about 1/4 of power.
  delay(500); // wait 5 seconds, motor continues to move because the analogWrite is still pulsing
  // analogWrite(RPWM, 128); // pulse signal now at 128 (about half power... half of max 255).
  // delay(500);

  // // after 5 seconds at half power, stop the motor moving
  // analogWrite(RPWM, 0);
  // delay(500);
  // // now start moving in opposite direction.
  // analogWrite(LPWM, 64);
  // delay(500);
  // analogWrite(LPWM, 128);
  // delay(500);
  // analogWrite(LPWM, 0); // Stop moving in this direction
  // // at this point should be no movement.
  
  // delay(500);
}