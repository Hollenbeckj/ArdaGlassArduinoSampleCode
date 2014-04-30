#include <SoftwareSerial.h>// library for setting software serial ports 

int bluetoothTx = 5;// set TX ti digital pin 5 
int bluetoothRx = 6;// set RX to digital pin 6
int grnd = 2;// set ground connection to digtial pin 2
int pwr = 4;// set power pin to pin 4
int analogPort = A0;// sets the analog port A0 to be the described variable 
int data = 0;// initializes a variable for the potentiometer data 
int incomingByte; // reads incoming bytes 


SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);//tells the arduino to set RX and TX to the desired pin varables 

void setup() 
{
  bluetooth.begin(115200); // set the baud rate of data stream
  pinMode(grnd, OUTPUT);// set ground to be an output 
  pinMode(pwr, OUTPUT);// set power to be an output 
  digitalWrite(grnd, LOW); // establish ground 
  digitalWrite(pwr, HIGH);// establish power 
}

void loop() 
{
  
 data = analogRead(analogPort);
 
  if (Serial.available() > 0) // if serial data is available 
    {
      incomingByte = Serial.read();// read the oldest byte in the serial buffer:
  
        if (incomingByte == 'r')// if the incoming byte is equal = R reset the counter
          {
            Serial.println("RESET");// print reset to terminal 
            
          }
    }
    
bluetooth.println(data);// send the variable data to the bluetooth shield and output it as data 
delay(10); // delay the data by 10 mili-second so it is more readable to the user
}
