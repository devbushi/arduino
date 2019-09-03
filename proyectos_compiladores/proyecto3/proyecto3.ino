const int sensorPin = A0;
const int sensorPin = 10;
const int sensorPinLluvia = 9;// sensor lluvia
 
void setup() {
   Serial.begin(9600);
   pinMode(sensorPin, INPUT);
   pinMode(sensorPinLluvia, INPUT);  //definir pin como entrada
}
 
void loop() 
{
  // sensor humedad de suelo
   int humedad = analogRead(sensorPin);
   int humedad2 = digitalRead(sensorPin);
   Serial.print(humedad);
  
   if(humedad < 500)
   {
      Serial.println("Encendido");  
      //hacer las acciones necesarias
   }
   delay(1000);

    //mandar mensaje a puerto serie en función del valor leido
   if (humedad2 == HIGH)
   {
      Serial.println("Encendido");   
      //aquí se ejecutarían las acciones
   }
   delay(1000);

   // sensor lluvia
   int value = 0;
   value = digitalRead(sensorPin );  //lectura digital de pin
 
   if (value == LOW) {
      Serial.println("Detectada lluvia");
   }
   delay(1000);
}

