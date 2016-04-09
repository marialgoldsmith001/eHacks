/*
/* Grove - Temperature Sensor demo v1.0
*  This sensor detects the environment temperature,
*  Connect the signal of this sensor to A0, use the 
*  Serial monitor to get the result.
*  By: http://www.seeedstudio.com
*/
//#include <math.h>
//int a;
//int a1;
//float temperature;
//int B=3975;                  //B value of the thermistor
//float resistance;
 
//void setup()
//{
//  Serial.begin(9600);  
//}
// 
//void loop()
//{
//  a=analogRead(0);
//  resistance=(float)(1023-a)*10000/a; //get the resistance of the sensor;
//  temperature=1/(log(resistance/10000)/B+1/298.15)-273.15;//convert to temperature via datasheet&nbsp;;
//  delay(1000);
//  Serial.print("Current temperature is ");
//  Serial.println(temperature);

//  a1=analogRead(1);
//
//  if(a1 = 1){
//    Serial.println("can't touch this");
//  }
//  else
//  {
//    Serial.println("no touch");
//  }
// }


//int sensorValue;
//const int TouchPin=2;
//void setup() {
//pinMode(TouchPin, INPUT);
//} 
// 
//void loop() {
//  sensorValue = digitalRead(TouchPin);
//  if(sensorValue==1)
//  {
//   Serial.println("can't touch this");
//  }
//  else
//  {
//  Serial.println("no touch");
//  }
//  Serial.println("random line");
//  delay(1000);
//}
//
const int TouchPin=2;
const int ledPin=3;
void setup() {
pinMode(TouchPin, INPUT);
pinMode(ledPin,OUTPUT);
Serial.begin(9600);
} 
 
void loop() {
int sensorValue = digitalRead(TouchPin);
if(sensorValue==1)
{
digitalWrite(ledPin,HIGH);
Serial.println("Can't touch this!");
}
else
{
digitalWrite(ledPin,LOW);
}
}


///*
///* Grove - Light Sensor demo v1.0
//* 
//* signal wire to A0.
//* By: http://www.seeedstudio.com
//*/
//#include <math.h>
//const int ledPin=12;                 //Connect the LED Grove module to Pin12, Digital 12
//const int thresholdvalue=10;         //The threshold for which the LED should turn on. 
//float Rsensor; //Resistance of sensor in K
//void setup() {
//  Serial.begin(9600);                //Start the Serial connection
////  pinMode(ledPin,OUTPUT);            //Set the LED on Digital 12 as an OUTPUT
//}
//void loop() {
//  int sensorValue = analogRead(1); 
//  Rsensor=(float)(1023-sensorValue)*10/sensorValue;
////  if(Rsensor>thresholdvalue)
////  {
////    digitalWrite(ledPin,HIGH);
////  }
////  else
////  {
////  digitalWrite(ledPin,LOW);
////  }
//  Serial.println("the analog read data is ");
//  Serial.println(sensorValue);
//  Serial.println("the sensor resistance is ");
//  Serial.println(Rsensor,DEC);//show the light intensity on the serial monitor;
//  delay(1000);
//}









//#include <SPI.h>
// #include <Ethernet.h>
//
//
// #include <Servo.h>
//  // create servo object to control a servo
// Servo myservo;
//
////physical mac address
// byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xAD };
// byte ip[] = { 10,0,0,32 }; // fixed IP addr in LAN
// byte gateway[] = { 10, 0, 0, 1 }; // internet access via router
// byte subnet[] = { 255, 0, 0, 0 }; //subnet mask
// EthernetServer server(80); //server port
//
// String readString;
// //////////////////////
// void setup(){
// pinMode(2, OUTPUT); //6 pin selected to control LED
// pinMode(3, OUTPUT); //pin 7 control
// pinMode(4, OUTPUT); //pin 4 control
// pinMode(5, OUTPUT); //pin 5 control
// 
// //start Ethernet
// Ethernet.begin(mac, ip, gateway, subnet);
// server.begin();
// //the pin for the servo co
// //enable serial data print
// Serial.begin(9600);
// Serial.println("server LED test 1.0 ---- FILENAME = LED2.ino "); // so I can keep track
// }
//
// void loop(){
// // Create a client connection
// EthernetClient client = server.available();
// if (client) {
// while (client.connected()) {
// if (client.available()) {
// char c = client.read();
//
// //read char by char HTTP request
// if (readString.length() < 100) {
//
// //store characters to string
// readString += c;
// //Serial.print(c);
// }
//
// //if HTTP request has ended
// if (c == '\n') {
//
// ///////////////
// Serial.println(readString); //print to serial monitor for debuging
// client.println("HTTP/1.1 200 OK"); //send new page
// client.println("Content-Type: text/html");
// client.println();
// client.println("<HTML>");
// client.println("<HEAD>");
//client.println("<meta http-equiv='refresh' content='0; url=http://10.0.0.23/' />  ");
// client.println("</HEAD>");
// client.println("<BODY bgcolor='black'>");
// client.println("<H1>VIDEORAMA</H1>");
// client.println("<hr />");
// client.println("<br />");
//
// client.println("<a href=\"/?forward\"\">Forward</a>");
// //client.println("<a href=\"/?lightoff6\"\">Turn Off Light6</a><br />");
// client.println("<a href=\"/?back\"\">Backward</a>");
// //client.println("<a href=\"/?lightoff7\"\">Turn Off Light7</a><br />");
// client.println("<a href=\"/?right\"\">Right</a>");
// //client.println("<a href=\"/?lightoff4\"\">Turn Off Light4</a><br />");
// client.println("<a href=\"/?left\"\">Left</a>");
// client.println("<a href=\"/?stop\"\">Stop</a>");
//
// client.println("</BODY>");
// client.println("</HTML>");
//
// delay(1);
// //stopping client
// client.stop();
//
// ///////////////////// control arduino pin
// //Forward
// if(readString.indexOf("?forward") >0)
// {
//    digitalWrite(2, LOW); //set pin 6 low
//    digitalWrite(3, LOW); //set pin 7 low
//    digitalWrite(4, HIGH); //set pin 4 high
//    digitalWrite(5, HIGH); //set pin 5 high
//    delay(500); // move for 1 second
//    digitalWrite(4, LOW); //stop pin 4
//    digitalWrite(5, LOW); // stop pin 5
// }
// //Backward
// if(readString.indexOf("?back") >0)
// {
//    digitalWrite(4, LOW); //set pin 4 low
//    digitalWrite(5, LOW); //set pin 5 low
//    digitalWrite(2, HIGH); //set pin 6 high
//    digitalWrite(3, HIGH); //set pin 7 high
//    delay(500);
//    digitalWrite(2, LOW);
//    digitalWrite(3, LOW);
// }
// //Right
// if(readString.indexOf("?right") >0)
// {
//    digitalWrite(4, LOW); // set pin 4 low (right forward)
//    digitalWrite(2, LOW); //set pin 6 low (right back)
//    digitalWrite(3, LOW); // set pin 7 low (left back)
//    digitalWrite(5, HIGH); //set pin 5 high (left forward)
//    delay(500);
//    digitalWrite(4, HIGH); //set pin 4 high (right forward)
//    delay(500);
//    digitalWrite(5, LOW);
//    digitalWrite(4, LOW);
//    
// }
// //Left
// if(readString.indexOf("?left") >0)
// {
//    digitalWrite(5, LOW); //set pin 5 low (left forward)
//    digitalWrite(2, LOW); //set pin 6 low (right back)
//    digitalWrite(3, LOW); // set pin 7 low (left back)
//    digitalWrite(4, HIGH); //set pin 4 high (right forward)
//    delay(500);
//    digitalWrite(5, HIGH); // set 5 high (left forward)
//    delay(500);
//    digitalWrite(4, LOW);
//    digitalWrite(5, LOW);
// }
// //STOP
// if(readString.indexOf("?stop") >0)
// {
//    digitalWrite(5, LOW); //set pin 5 low (left forward)
//    digitalWrite(2, LOW); //set pin 6 low (right back)
//    digitalWrite(3, LOW); // set pin 7 low (left back)
//    digitalWrite(4, LOW); //set pin 4 low (right forward)
// }
//  readString=""; //clearing string for next read
// }
// }
// }
// }
// } 

