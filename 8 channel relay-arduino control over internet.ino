//CREATED BY DIXIT

#include <SPI.h>
#include <Ethernet.h>

int relay1 = 2;
int relay2 = 3;
int relay3 = 4;
int relay4 = 5;
int relay5 = 6;
int relay6 = 7;
int relay7 = 8;
int relay8 = 9; 


int pos = 0; 
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };   //physical mac address
byte ip[] = { 192, 168, 1, 30 };                      // ip in lan (that's what you need to use in your browser. ("192.168.1.178")
byte gateway[] = { 192, 168, 1, 1 };                   // internet access via router
byte subnet[] = { 255, 255, 255, 0 };                  //subnet mask
EthernetServer server(80);                             //server port     
String readString;

void setup() {
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);
  pinMode(relay6, OUTPUT);
  pinMode(relay7, OUTPUT);
  pinMode(relay8, OUTPUT);
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, LOW);
  digitalWrite(relay5, LOW);
  digitalWrite(relay6, LOW);
  digitalWrite(relay7, LOW);
  digitalWrite(relay8, LOW);
    
  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
  Serial.print("Server is at :");
  Serial.println(Ethernet.localIP());
}


void loop() {
  // Create a client connection
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {   
      if (client.available()) {
        char c = client.read();
     
        if (readString.length() < 100) {
          
          readString += c;
          
         }

         
         if (c == '\n') {          
           Serial.println(readString); 
           //html file 
           client.println("HTTP/1.1 200 OK"); 
           client.println("Content-Type: text/html");
           client.println();     
           client.println("<HTML>");
           client.println("<HEAD>");
           client.println("<meta name='apple-mobile-web-app-capable' content='yes' />");
           client.println("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />");
           client.println("<TITLE>DIXIT Projects</TITLE>");
           client.println("</HEAD>");
           client.println("<BODY>");
           client.println("<H1>WELCOME</H1>");
           client.println("<hr />");
           client.println("<br />");  
           client.println("<H2>MY_ARDUINO_ROOM</H2>");
           client.println("<br />");  
           //BUTTON FOR relay1
           client.println("<a href=\"/?button1on\"\">Turn On relay1</a>");
           client.println("<a href=\"/?button1off\"\">Turn Off relay1</a><br />");   
           //SPACES
           client.println("<br />");     
           client.println("<br />"); 
           //BUTTON FOR relay2
           client.println("<a href=\"/?button2on\"\">Turn On relay2</a>");
           client.println("<a href=\"/?button2off\"\">Turn Off relay2</a><br />");   
           client.println("<br />");     
           client.println("<br />"); 
           //BUTTON FOR relay3
           client.println("<a href=\"/?button3on\"\">Turn On relay3</a>");
           client.println("<a href=\"/?button3off\"\">Turn Off relay3</a><br />");   
           client.println("<br />");     
           client.println("<br />"); 
           //BUTTON FOR relay4
           client.println("<a href=\"/?button4on\"\">Turn On relayD4</a>");
           client.println("<a href=\"/?button4off\"\">Turn Off relay4</a><br />");   
           client.println("<br />");     
           client.println("<br />");
           //BUTTON FOR relay5
           client.println("<a href=\"/?button5on\"\">Turn On relay5</a>");
           client.println("<a href=\"/?button5off\"\">Turn Off relay5</a><br />");   
           client.println("<br />");     
           client.println("<br />");
           //BUTTON FOR relay6
           client.println("<a href=\"/?button6on\"\">Turn On relay6</a>");
           client.println("<a href=\"/?button6off\"\">Turn Off relay6/a><br />");   
           client.println("<br />");     
           client.println("<br />");
           //BUTTON FOR relay7
           client.println("<a href=\"/?button7on\"\">Turn On relay7</a>");
           client.println("<a href=\"/?button7off\"\">Turn Off relay7</a><br />");   
           client.println("<br />");     
           client.println("<br />");
           //BUTTON FOR relay8
           client.println("<a href=\"/?button8on\"\">Turn On relay8</a>");
           client.println("<a href=\"/?button8off\"\">Turn Off relay8</a><br />");   
           client.println("<br />");     
           client.println("<br />"); 
            
           client.println("<br />"); 
           client.println("</BODY>");
           client.println("</HTML>");
     
           delay(1);
           //stopping client
           client.stop();
           //controls the Arduino if you press the buttons
           if (readString.indexOf("?button1on") >0){
               digitalWrite(relay1, HIGH);
           }
           if (readString.indexOf("?button1off") >0){
               digitalWrite(relay1, LOW);
           }



          if (readString.indexOf("?button2on") >0){
               digitalWrite(relay2, HIGH);
           }
           if (readString.indexOf("?button2off") >0){
               digitalWrite(relay2, LOW);
           }





            if (readString.indexOf("?button3on") >0){
               digitalWrite(relay3, HIGH);
           }
           if (readString.indexOf("?button3off") >0){
               digitalWrite(relay3, LOW);
           }





            if (readString.indexOf("?button4on") >0){
               digitalWrite(relay4, HIGH);
           }
           if (readString.indexOf("?button4off") >0){
               digitalWrite(relay4, LOW);
           }
           





            if (readString.indexOf("?button5on") >0){
               digitalWrite(relay5, HIGH);
           }
           if (readString.indexOf("?button5off") >0){
               digitalWrite(relay5, LOW);
           }
           





            if (readString.indexOf("?button6on") >0){
               digitalWrite(relay6, HIGH);
           }
           if (readString.indexOf("?button6off") >0){
               digitalWrite(relay6, LOW);
           }
           




            if (readString.indexOf("?button7on") >0){
               digitalWrite(relay7, HIGH);
           }
           if (readString.indexOf("?button7off") >0){
               digitalWrite(relay7, LOW);
           }






            if (readString.indexOf("?button8on") >0){
               digitalWrite(relay8, HIGH);
           }
           if (readString.indexOf("?button8off") >0){
               digitalWrite(relay8, LOW);
           }

           
            //clearing string for next read
            readString="";  
           
         }
       }
    }
}
}

