
// Configuracion inicial

bool ini = false;
byte J1  = 0x01;
byte J2  = 0x01;

void setup() {

  Serial.begin(9600);

// BOTONES
pinMode(PF_0, INPUT_PULLUP);
pinMode(PF_4, INPUT_PULLUP);
pinMode(PA_3, INPUT_PULLUP);

// LEDS INCORPORADAS EN TIVA

pinMode(RED_LED, OUTPUT);
pinMode(BLUE_LED, OUTPUT);
pinMode(GREEN_LED, OUTPUT);

// JUGADOR 1

pinMode(PB_5, OUTPUT);
pinMode(PB_0, OUTPUT);
pinMode(PB_1, OUTPUT);
pinMode(PE_4, OUTPUT);
pinMode(PE_5, OUTPUT);
pinMode(PB_4, OUTPUT);
pinMode(PA_5, OUTPUT);
pinMode(PA_6, OUTPUT);

// JUGADOR 2

pinMode(PD_0, OUTPUT);
pinMode(PD_1, OUTPUT);
pinMode(PD_2, OUTPUT);
pinMode(PD_3, OUTPUT);
pinMode(PE_1, OUTPUT);
pinMode(PE_2, OUTPUT);
pinMode(PE_3, OUTPUT);
pinMode(PA_7, OUTPUT);

}

void loop() {

  if(digitalRead(PA_3) == LOW) {
  semaforo();
  J1 = 0x01;
  J2 = 0x01;
  }

  if(ini == true) {
  if(J1 == 0x00) {
   J1 = 0x01;
  }
  if(J2 == 0x00) {
    J2 = 0x01;
  }

  if(digitalRead(PF_4) == LOW) {
  J1 = J1 << 1;
  }
  if(digitalRead(PF_0) == LOW) {
  J2 = J2 << 1;
  }

  if(J1 == 0x80) {
  ini = false;
  digitalWrite(BLUE_LED, 255);
  digitalWrite(GREEN_LED, 196);
  }
  if(J2 == 0X80) {
  ini = false;
  digitalWrite(BLUE_LED, 255);
  digitalWrite(RED_LED, 196);
  }

  J_1(J1);
  J_2(J2);

  delay(300);
  
  }
  
}

// FUNCION 1

void semaforo() {

  ini = false;
  digitalWrite(RED_LED, HIGH);
  delay(1000);
  digitalWrite(GREEN_LED, HIGH);
  delay(1000);
  digitalWrite(RED_LED, LOW);
  delay(1000);
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  ini = true;
  
}

void J_1(byte Jugador_1) {

  digitalWrite(PB_5, bitRead(Jugador_1,0));
  digitalWrite(PB_0, bitRead(Jugador_1,1));
  digitalWrite(PB_1, bitRead(Jugador_1,2));
  digitalWrite(PE_4, bitRead(Jugador_1,3));
  digitalWrite(PE_5, bitRead(Jugador_1,4));
  digitalWrite(PB_4, bitRead(Jugador_1,5));
  digitalWrite(PA_5, bitRead(Jugador_1,6));
  digitalWrite(PA_6, bitRead(Jugador_1,7));
  
}

void J_2(byte Jugador_2) {

  digitalWrite(PD_0, bitRead(Jugador_2,0));
  digitalWrite(PD_1, bitRead(Jugador_2,1));
  digitalWrite(PD_2, bitRead(Jugador_2,2));
  digitalWrite(PD_3, bitRead(Jugador_2,3));
  digitalWrite(PE_1, bitRead(Jugador_2,4));
  digitalWrite(PE_2, bitRead(Jugador_2,5));
  digitalWrite(PE_3, bitRead(Jugador_2,6));
  digitalWrite(PA_7, bitRead(Jugador_2,7));
  
}
