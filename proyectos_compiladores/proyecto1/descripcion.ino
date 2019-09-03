#define analogPin  A0 
#define beta 4090 

const int redPin = 11;  // R petal on RGB LED module connected to digital pin 11 
const int greenPin = 10;  // G petal on RGB LED module connected to digital pin 10 
const int bluePin = 9;  // B petal on RGB LED module connected to digital pin 9 

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT); // sets the redPin to be an output 
  pinMode(greenPin, OUTPUT); // sets the greenPin to be an output 
  pinMode(bluePin, OUTPUT); // sets the bluePin to be an output 

}

void loop() {
 //read thermistor value 
  long a =1023 - analogRead(analogPin);
  //the calculating formula of temperature
  float tempC = beta /(log((1025.0 * 10 / a - 10) / 10) + beta / 298.0) - 273.0;
  //float tempF = tempC + 273.15;
  printf("Temperatura = ");
  printf(tempC);

  if(tempC <= 10){
    color(0, 0, 255); // turn the RGB LED blue  
    delay(2000); // delay for 1 second
  } else if((tempC > 10) && (tempC <= 25)){
    color(0,255, 0); // turn the RGB LED green  
    delay(2000); // delay for 1 second 
  } else if((tempC > 25) && (tempC <= 40)){
    color(255,128,0); // turn the RGB LED orange
    delay(2000); // delay for 1 second
  } else if(tempC > 40){
    color(255, 0, 0); // turn the RGB LED red 
    delay(2000); // delay for 1 second
  }

 // Basic colors:  
          color(255, 0, 0); // turn the RGB LED red 
          delay(800); // delay for 1 second  
          color(0,255, 0); // turn the RGB LED green  
          delay(800); // delay for 1 second  
          color(0, 0, 255); // turn the RGB LED blue  
          delay(800); // delay for 1 second 
          // Example blended colors:  
          /*color(255,0,0); // turn the RGB LED red  
          delay(1000); // delay for 1 second  
          color(255,128,0); // turn the RGB LED orange  
          delay(1000); // delay for 1 second  
          color(255,255,0); // turn the RGB LED yellow  
          delay(1000); // delay for 1 second  
          color(0,255,0); // turn the RGB LED green  
          delay(1000); // delay for 1 second 
          color(0,0,255); // turn the RGB LED blue  
          delay(1000); // delay for 1 second
          color(0,0,64); // turn the RGB LED  indigo 
          delay(1000); // delay for 1 second
          color(128,0,128); // turn the RGB LED purple  
          delay(1000); // delay for 1 second
          */
}

void color (unsigned char red, unsigned char green, unsigned char blue)     // the color generating function  
{    
          analogWrite(redPin, red);   
          analogWrite(bluePin, blue); 
          analogWrite(greenPin, green); 
}
