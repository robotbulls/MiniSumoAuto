/*******PINOUT DEFINES*********/
// it is not recommended to make changes
// nao e recomendado que se faca alteracoes
// no se recomienda hacer cambios
 
// LED
#define LED 6
 
// left motor
#define pwmL 9
#define leftMotor1 7
#define leftMotor2 8
 
// right motor
#define pwmR 3
#define rightMotor1 5
#define rightMotor2 4
 
// DIP switch
#define DIP1 10
#define DIP2 11
#define DIP3 12
#define DIP4 13
 
// Robocore's line sensor
#define lineL A0
#define lineR A1
 
// Jsumo's distance sensor
#define distL A2
#define distR A3
 
// Jsumo's micro-start
#define microST 2
/*******PINOUT DEFINES - END*********/
 
/*******FUNCTIONS*******/
void MotorL(int pwm); // left motor / motor esquerdo / motor izquierdo
void MotorR(int pwm); // right motor / motor direito / motor derecho
int readDIP(); // read DIP switch / ler chave DIP / leer el interruptor DIP
/*******FUNCTIONS - END*******/
 
void setup() {
 
  /****************PINOUT CONFIG****************/
  // OUTPUTS
  pinMode(LED, OUTPUT);         // led
 
  // right motor
  pinMode(pwmR, OUTPUT);        // right motor power
  pinMode(rightMotor1, OUTPUT); // right motor dir.
  pinMode(rightMotor2, OUTPUT); // right motor dir.
 
  // left motor
  pinMode(pwmL, OUTPUT);        // left motor power
  pinMode(leftMotor1, OUTPUT);  // left motor dir.
  pinMode(leftMotor2, OUTPUT);  // left motor dir.
 
 
  // INPUTS: DO NOT CHANGE / NAO MUDAR / NO CAMBIAR
  // DIP switch
  pinMode(DIP1, INPUT_PULLUP);  // DO NOT CHANGE / NAO MUDAR / NO CAMBIAR
  pinMode(DIP2, INPUT_PULLUP);  // DO NOT CHANGE / NAO MUDAR / NO CAMBIAR
  pinMode(DIP3, INPUT_PULLUP);  // DO NOT CHANGE / NAO MUDAR / NO CAMBIAR
  pinMode(DIP4, INPUT_PULLUP);  // DO NOT CHANGE / NAO MUDAR / NO CAMBIAR
  
  // line sensor
  pinMode(lineL, INPUT); // DO NOT CHANGE / NAO MUDAR / NO CAMBIAR
  pinMode(lineR, INPUT); // DO NOT CHANGE / NAO MUDAR / NO CAMBIAR
 
  // distance sensor
  pinMode(distR, INPUT); // DO NOT CHANGE / NAO MUDAR / NO CAMBIAR
  pinMode(distL, INPUT); // DO NOT CHANGE / NAO MUDAR / NO CAMBIAR
 
  // micro-start
  pinMode(microST, INPUT); // DO NOT CHANGE / NAO MUDAR / NO CAMBIAR
  /****************PINOUT CONFIG - END***************/
 
  /***************INITIAL CONDITIONS*****************/
  digitalWrite(LED, LOW); // LED off / LED desligado / LED apagado 
  MotorL(0); // left motor stopped / motor esquerdo parado / motor izquierdo parado 
  MotorR(0); // right motor stopped / motor direito parado / motor derecho parado 
  /*************INITIAL CONDITIONS - END*************/
}
 
void loop() {
  
}
 
/**LEFT MOTOR CONTROL / CONTROLE DO MOTOR ESQUERDO / CONTROL DEL MOTOR IZQUIERDO**/
// pwm = 0 -> stopped / parado / parado
// 0<pwm<=255 -> forward / para frente / seguir adelante
// -255<=pwm<0 -> backward / para tras / seguir espalda
void MotorL(int pwm){
  // leftMotor1=0 and leftMotor2=0 -> stopped / parado / parado 
  // leftMotor1=0 and leftMotor2=1 -> moves forward / avanca / avanzar
  // leftMotor1=1 and leftMotor2=0 -> moves back / recua / retrocede
  // leftMotor1=1 and leftMotor2=1 -> stopped (braked) / parado (travado) / parado (frenado)
 
  if(pwm==0){
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
  }
  else if(pwm<0)
  {
    analogWrite(pwmL, -pwm);
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
  }
  else
  {
    analogWrite(pwmL, pwm);
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, HIGH);
  }
}
 
 
/**RIGHT MOTOR CONTROL / CONTROLE DO MOTOR DIREITO / CONTROL DEL MOTOR DERECHO**/
// pwm = 0 -> stopped / parado / parado
// 0<pwm<=255 -> forward / frente / adelante
// -255<=pwm<0 -> backward / tras / espalda
void MotorR(int pwm){
  // rightMotor1=0 and rightMotor2=0 -> stopped / parado / parado 
  // rightMotor1=0 and rightMotor2=1 -> moves forward / avanca / avanzar
  // rightMotor1=1 and rightMotor2=0 -> moves back / recua / retrocede
  // rightMotor1=1 and rightMotor2=1 -> stopped (braked) / parado (travado) / parado (frenado)
 
  if(pwm==0){
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
  }
  else if(pwm<0)
  {
    analogWrite(pwmR, -pwm);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
  }
  else
  {
    analogWrite(pwmR, pwm);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, HIGH);
  }
}
 
/** read DIP switch / ler chave DIP / leer el interruptor DIP **/
// returns a value between 0 and 15
// retorna um valor entre 0 e 15
// devuelve un valor entre 0 y 15
int readDIP(){
  int n=0;
  if(digitalRead(DIP4)==HIGH)
    n=1;
  if(digitalRead(DIP3)==HIGH)
    n|= (1<<1);
  if(digitalRead(DIP2)==HIGH)
    n|= (1<<2);
  if(digitalRead(DIP1)==HIGH)
    n|= (1<<3);
}
