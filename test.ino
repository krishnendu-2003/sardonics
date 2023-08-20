#include <IRremote.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64



Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);



int trigPin=5;
int irPin=3;
int outPin=8;

int mp =20;
int hp=100;
 
int vPin1=13;
int vPin2=12;
int vPin3=11;
int vPin4=10;

int gameOver=0;

void setup() {
  pinMode(trigPin, INPUT_PULLUP);
  pinMode(outPin,OUTPUT);
  Serial.begin(9600);
  pinMode(vPin1, OUTPUT);
  pinMode(vPin2, OUTPUT);
  pinMode(vPin3, OUTPUT);
  pinMode(vPin4, OUTPUT);
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  // put your setup code here, to run once:
   display.clearDisplay();
   display.setTextSize(3);
}

void loop() {

  display.clearDisplay();
  
  display.setTextColor(SSD1306_WHITE);  // Set text color to white
  display.setCursor(0, 0);
  display.print("MP: ");
  display.println(mp);

  display.setTextColor(SSD1306_INVERSE);    // Set text color to black
  display.setCursor(0, 30);
  display.print("HP: ");
  display.println(hp);
  
  display.setTextColor(SSD1306_INVERSE);    // Set text color to black

  display.display();
  
  delay(1000);  // Delay for 1 second (adjust as needed)
  Serial.println(digitalRead(trigPin));
   if(digitalRead(trigPin)){
    display.clearDisplay();  
     mp=mp-5;


     digitalWrite(outPin, HIGH); 
     delay(500);
     digitalWrite(outPin, LOW); 
   }
  // else{
  //     digitalWrite(outPin, LOW); 
  // }
  mp=mp-5;
  if(gameOver==1){
    over();
  }
  endGame();
  // put your main code here, to run repeatedly:

}



void over(){
  digitalWrite(vPin1, HIGH);
  digitalWrite(vPin2, HIGH);
  digitalWrite(vPin3, HIGH);
  digitalWrite(vPin4, HIGH);
  delay(500);
    
  digitalWrite(vPin1,LOW);
  digitalWrite(vPin2,LOW);
  digitalWrite(vPin3,LOW);
  digitalWrite(vPin4,LOW);
  delay(500);
  
  digitalWrite(vPin1, HIGH);
  digitalWrite(vPin2, HIGH);
  digitalWrite(vPin3, HIGH);
  digitalWrite(vPin4, HIGH);
  delay(500);
    
  digitalWrite(vPin1,LOW);
  digitalWrite(vPin2,LOW);
  digitalWrite(vPin3,LOW);
  digitalWrite(vPin4,LOW);
  delay(500);
  
  
  digitalWrite(vPin1, HIGH);
  digitalWrite(vPin2, HIGH);
  delay(500);
  
  digitalWrite(vPin1, LOW);
  digitalWrite(vPin2, LOW);
  digitalWrite(vPin3, HIGH);
  digitalWrite(vPin4, HIGH);
  delay(500);
  
  digitalWrite(vPin3, LOW);
  digitalWrite(vPin4, LOW);
  
  
  
}


void endGame(){
  if(mp == 0 || hp == 0){
  	mp = 0; 
    hp = 0;
    gameOver=1;
      
  }

}