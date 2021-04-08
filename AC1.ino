//variaveis da led
const int vermelho = 5;
const int verde = 6;
const int azul = 7;

bool estadoLedVermelho = false;
bool estadoLedAzul = false;
bool estadoLedVerde = false;

const int botao1 = 2;
const int botao2 = 3;
unsigned long lastDebounceTime1 = 0;
const int botaoDelay = 100;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  
  Serial.begin(9600);
	
  Serial.println("AC1 - Meu Primeiro Projeto 2021");
  Serial.println("                           V1.0");
  Serial.println("Grupo: Alpha               ");
}

void loop()
{
  if((millis() - lastDebounceTime1) > botaoDelay && digitalRead(botao1)){
  	Serial.println("botao 1 apertado");
    ledVermelho();
  	lastDebounceTime1 = millis();
  }
  if((millis() - lastDebounceTime1) > botaoDelay && digitalRead(botao2)){
  	Serial.println("botao 2 apertado");
    ledVermelho(false);
  	lastDebounceTime1 = millis();
  
  if(getTemperatura() > 30){
    ledAzul(true);
  }else{
  	ledAzul(false); 
  }
	  
  if(getLuminosidade() > 5){
    ledVerde(true);
  }else{
  	ledVerde(false); 
  }
  	
  delay(100);
}

void ledVermelho(bool estado){
  estadoLedVermelho = estado;
  digitalWrite(vermelho,estadoLedVermelho);
}
void ledVerde(bool estado){
 	estadoLedVerde = estado;
	digitalWrite(verde,estadoLedVerde);
}
void ledAzul(bool estado){
    estadoLedAzul = estado;
	digitalWrite(azul,estadoLedAzul);
}

int getTemperatura(){
  	int temperaturaC;
	temperaturaC = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  	return temperaturaC;
} 

int getLuminosidade(){
  	int luminosidade;
	luminosidade = map(analogRead(A1), 6, 619, -3, 10);
  	return luminosidade;
}
