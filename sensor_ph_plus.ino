/*
sensor_ph_plus
Luko
Sensor de ph que en funcion del ph mueve 2 motores dc
y se visualisa en una LCD16x2
*/
#include <Wire.h>//comunicacion I2C
#include <LiquidCrystal_I2C.h>//lib pantalla LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);//la direccion en exa, es dependiendo del fabricante
int ph_pin = A0; // Define el pin analógico para la lectura del sensor
int raw_value,suma; // Variable para almacenar la lectura del sensor y promedio
int motor_1 = 2;
int motor_2 = 4;
float voltage; // Variable para almacenar el voltaje correspondiente a la lectura del sensor
float ph_value; // Variable para almacenar el valor de pH correspondiente al voltaje de salida del sensor
//las cte del ph se dan por la calibracion del sensor
float ph_val_c1=-10;
float ph_val_c2=32;
float buffer_arr[10];

void setup() {

  pinMode(motor_1, OUTPUT );
  pinMode(motor_2, OUTPUT );

  digitalWrite(motor_1, HIGH);
  digitalWrite(motor_2, HIGH);
  //se marcan como salidas por el modulo rele 2 canales


  lcd.init();
  lcd.begin(16, 2);//display tamaño
  lcd.backlight();
  // presentacion del display
  lcd.setCursor(0, 0);// seleccciona la primera fila
  lcd.print("   Bienvenido a    ");
  lcd.setCursor(0, 1);
  lcd.print(" Medidor pH    "); //selecciona la segunda fila
  delay(1500);
  lcd.clear();

  //aca abajo se puede poner una firma a gusto
  lcd.setCursor(0, 0);// seleccciona la primera fila
  lcd.print("VICTOR RINCON");
  lcd.setCursor(0, 1);
  lcd.print("MIGUEL CUCANCHON"); //selecciona la segunda fila
  delay(5000);
  lcd.clear();

}

void loop() {

  for (int i = 0; i < 10; i++)  //lectura pin analogo A0 10 vese cada 60ms, deveria ir al pin Po
   {
    buffer_arr[i] = analogRead(ph_pin);// Lee la lectura analógica del pin del sensor
    delay(100);
   }
     for (int k = 0; k < 10; k++) //promedio de lectura
   {
      suma += buffer_arr[k];
   }
  raw_value = (float) suma / 10;//fin del promedio de lectura
  voltage = (float)raw_value * 5 / 1024; // Convierte la lectura en voltaje
  ph_value = ph_val_c1 * voltage + ph_val_c2; // Convierte el voltaje en un valor de pH correspondiente

  lcd.setCursor(0, 0);
  lcd.print("PH Val:");
  lcd.setCursor(8, 0);
  lcd.print(ph_value);
  lcd.setCursor(0, 1);
  lcd.print(voltage);


  if (ph_value<6.8)//valor de ph crucial
  {
    digitalWrite(motor_1, LOW);//pin rele 1 motor bomba
    delay(10000);
    digitalWrite(motor_1, HIGH);

    digitalWrite(motor_2, LOW);//pin rele 2 revolver
    delay(10000);
    digitalWrite(motor_2, HIGH);
  }


//variables control no mover
suma=0;
          for (int j = 0; j < 10; j++)
   {
      buffer_arr[j]=0;
   }
 
}