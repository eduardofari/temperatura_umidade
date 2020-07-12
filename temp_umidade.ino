#include "DHT.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Digital pins to which you connect the LCD


const int pino_dht = 9; // pino onde o sensor DHT está conectado
float temperatura; // variável para armazenar o valor de temperatura
float umidade; // variável para armazenar o valor de umidade
DHT dht(pino_dht, DHT11); // define o pino e o tipo de DHT

void setup() {
  // Inicia e configura a Serial
  Serial.begin(9600); // 9600bps
  lcd.begin(16,2);
  lcd.clear();
  dht.begin(); // inicializa o sensor DHT
}

void loop() {
  // Aguarda alguns segundos entre uma leitura e outra
  delay(2000); // 2 segundos (Datasheet)

  // A leitura da temperatura ou umidade pode levar 250ms
  // O atraso do sensor pode chegar a 2 segundos
  temperatura = dht.readTemperature(); // lê a temperatura em Celsius
  umidade = dht.readHumidity(); // lê a umidade

  // Se ocorreu alguma falha durante a leitura
  if (isnan(umidade) || isnan(temperatura)) {
    Serial.println("Falha na leitura do Sensor DHT!");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Falha na leitura!");
  }
  else { // Se não
    // Imprime o valor de temperatura  
    Serial.print("Temp.: ");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temp.: ");
    Serial.print(temperatura);
    lcd.print(temperatura);
    Serial.print(" *C ");
    lcd.print(" *C ");
    Serial.print("\t"); // tabulação
    lcd.print("\t");
    
    // Imprime o valor de umidade
    Serial.print("Umidade: ");
    lcd.setCursor(0,1);
    lcd.print("Umidade: ");
    Serial.print(umidade);
    lcd.print(umidade);
    Serial.print(" %\t"); 
    lcd.print(" %\t");
    
    Serial.println(); // nova linha
  }
}
