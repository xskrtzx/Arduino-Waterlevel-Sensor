    int Sensor0 = A0;
    int Sensor1 = A1;
    int Sensor2 = A2;
    int Sensor3 = A3;
    int Sensor4 = A4;
    int Sensor5 = A5;
    int val0,val1,val2,val3,val4,val5 = 0;
    
#include <LiquidCrystal.h>
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);

#include <UIPEthernet.h>
EthernetClient client;
  signed long next;
  String Data="";
  String dev_id="1";
  long count;

void setcon(){
  uint8_t mac[6] = {0x00,0x01,0x02,0x03,0x04,0x06};
  Ethernet.begin(mac);
  lcd.setCursor(0, 0);
  lcd.print("IP:");
  lcd.setCursor(3, 0);  
  lcd.print(Ethernet.localIP());
  Serial.print("subnetMask: ");
  Serial.println(Ethernet.subnetMask());
  Serial.print("gatewayIP: ");
  Serial.println(Ethernet.gatewayIP());
  Serial.print("dnsServerIP: ");
  Serial.println(Ethernet.dnsServerIP());
  //next = 0;

}

void con(String Data){
  /*if (((signed long)(millis() - next)) > 0)
    {
      next = millis() + 1000;
      Serial.println("Client connect");*/
      if (client.connect(IPAddress(10,0,35,9),1314))
        {
          //Serial.println("Client connected");
          client.print(dev_id+"|"+Data);
          Serial.println(dev_id+"|"+Data);
          lcd.setCursor(0, 1);
          lcd.print("<");
          count=0;
          /*while(client.available()==0)
          {
          if (next - millis() < 0)
               goto close;
          }
          int size;
          while((size = client.available()) > 0)
            {
             uint8_t* msg = (uint8_t*)malloc(size);
             size = client.read(msg,size);
             Serial.write(msg,size);
             free(msg);
            } 
close:
          Serial.println("Client disconnect");
          client.stop();*/
        }
      else{
        //lcd.setCursor(0, 1);
        //lcd.print(">");
        Serial.println("Client connect failed");
        count=count+1;
        if (count==1){
          lcd.setCursor(0, 1);
          lcd.print(count);
        }else if (count==2){
          lcd.setCursor(0, 1);
          lcd.print(count);
        }else if (count==3){
          lcd.setCursor(0, 1);
          lcd.print(count);
        }else if (count==4){
          lcd.setCursor(0, 1);
          lcd.print(count);
        }else if (count==5){
          lcd.setCursor(0, 1);
          lcd.print(count);        
        }
        Serial.println(count);
        if (count==5){
          setcon();  
          count=0;
        }
      }
    //}
}

void LEDD(int delayon, int delayoff){
  digitalWrite(3, HIGH);
  delay(delayon);
  digitalWrite(3, LOW);
  delay(delayoff);
  digitalWrite(3, HIGH);
  delay(delayon);
  digitalWrite(3, LOW);
  delay(delayoff);
  }
void setup() {
Serial.begin(9600);
pinMode(3, OUTPUT);
//LEDD(100,50);
pinMode(Sensor0, INPUT_PULLUP);
pinMode(Sensor1, INPUT_PULLUP);
pinMode(Sensor2, INPUT_PULLUP);
pinMode(Sensor3, INPUT_PULLUP);
pinMode(Sensor4, INPUT_PULLUP);
pinMode(Sensor5, INPUT_PULLUP);
lcd.begin(16, 2);
lcd.print("                  ");
setcon();
}
void loop() {
  sensor_read();
}

void sensor_read() {
  val0 = digitalRead(Sensor0);
  val1 = digitalRead(Sensor1);
  val2 = digitalRead(Sensor2);
  val3 = digitalRead(Sensor3);
  val4 = digitalRead(Sensor4);
  val5 = digitalRead(Sensor5);
  if (val5 == LOW){

      lcd.setCursor(3, 1);
      lcd.print("Status: 100%");
      Data="100";
      //LEDD(100,50);
      
  } else {
      if (val0 == HIGH){
        lcd.setCursor(3, 1);
        lcd.print("Status : 9%");
        Data="9";
        //LEDD(100,50);
      
      } else if (val1 == HIGH){
        lcd.setCursor(3, 1);
        lcd.print("Status : 16%");
        Data="16";
      } else if (val2 == HIGH){
        lcd.setCursor(3, 1);
        lcd.print("Status : 33%");
        Data="33";
      } else if (val3 == HIGH){
        lcd.setCursor(3, 1);
        lcd.print("Status : 50%");
        Data="50";
      } else if (val4 == HIGH){
        lcd.setCursor(3, 1);
        lcd.print("Status : 66%");
        Data="66";
      } else if (val5 == HIGH){
        lcd.setCursor(3, 1);
        lcd.print("Status : 83%");
        Data="83";
      }
  }
       con(Data);
}


