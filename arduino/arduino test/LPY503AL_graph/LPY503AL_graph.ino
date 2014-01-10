/******************************************************************
** Código creado en Electrónica 5Hz                              **
** www.5hz-electronica.com                                       **
** Por: Baruc                                                    **
**                                                               **
** Descripción del código:                                       **
**                                                               **
** Ejemplo para el Giroscopio LPY503AL                           **
**                                                               **
*******************************************************************
Conexiones:
UNO   LPY503AL

3.3V  VCC
GND   GND
A3    Vref
A4    X x4
A5    Z x4

*/

const int Vref = A3;
const int ejeX = A4;
const int ejeZ = A5;

void setup()
{
  Serial.begin(9600);
  Serial.println("Programa de prueba para el giroscopio LPY503AL");
  menu();
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
}

void loop()
{
  if(Serial.available())
  {
    switch(Serial.read())
    {
      case '1':
      Serial.println("Presione * para salir");
      do
      {
        printGraph(analogRead(A4), 50, 0, 1023, 'x');
        delay(100);
      }while(Serial.read() != '*');
      break;
      case '2':
      Serial.println("Presione * para salir");
      do
      {
        printGraph(analogRead(A5), 50, 0, 1023, 'z');
        delay(100);
      }while(Serial.read() != '*');
      break;
      default:
      Serial.println("no existe esa opción, nigga");
      break;
    }
    menu();
  }
}

void printGraph(int value, int maxChars, int minVal, int maxVal, char charToPrnt)
{
  int mappedVal = map(value, minVal, maxVal, 0, maxChars);
  for(int count = 0; count < mappedVal; count++)
  {
    Serial.print(charToPrnt);
  }
  Serial.print(": ");
  Serial.println(value);
}

void menu()
{
  Serial.println("Seleccione el eje a medir");
  Serial.println("1.- Eje X");
  Serial.println("2.- Eje Z");
}

