#include <Servo.h>

Servo myServoX; // define o servo motor que controlará o eixo X
Servo myServoY; // define o servo motor que controlará o eixo Y
int ServoXPin = 7; // define o pino digital que controlará o eixo X
int ServoYPin = 5; // define o pino digital que controlará o eixo Y
int ServoXHomePos =90; //Define a posicao de origem dos motores
int ServoYHomePos =90; //Define a posicao de origem dos motores
int ServoXPos =103;
int ServoYPos =135; 
int XAxlePin = A0; // define o pino analógico que receberá informações de eixo X do joystick
int YAxlePin = A1; // define o pino analógico que receberá informações de eixo Y do joystick
int XAxleValue = 0; // define valores padrões para o joystick
int YAxleValue = 0;//define valores padrões para o joystick
int Direction = 0;//define valores padrões para o joystick
int range = 12; // define o range (faixa de valores) para os eixos
int center = range/2; // define valor de centro dos eixos
int threshold = range/4; // define limites para o centro

void setup()
{
  //Define quais pinos controlarão cada motor e define a posição inicial para dar continuidade ao programa
  myServoX.attach(ServoXPin); 
  myServoY.attach(ServoYPin);
  ServoXPos = ServoXHomePos;
  ServoYPos = ServoYHomePos;
  myServoX.write(ServoXPos);
  myServoY.write(ServoYPos);
  
  //Inicialização do serial monitor e do pino digital que faz comunicação com Arduino 2
  Serial.begin(9600);
  pinMode(8, INPUT);
}
void loop()
{
  //Ha a leitura do pino digital que vem de outro Arduino para ver se ainda ha vidas para o jogador
  int vida = digitalRead(8);
  if(vida == 0){
    //Caso haja, são lidas as posições analógicas do joystick, que sao logo mapeadas para valores palpáveis
    XAxleValue = readAxis(XAxlePin);
    YAxleValue = readAxis(YAxlePin);

    //Ha a impressao das posicoes no serial monitor
    Serial.print(XAxleValue,DEC);
    Serial.print(" - ");
    Serial.println(YAxleValue,DEC);

    // Verifica a posição do joystick e transforma essa posição em movimentos para os motores com um leve delay
    if (XAxleValue>0) { ServoXPos += 20; myServoX.write(ServoXPos); delay(50*(7-XAxleValue)); }
    if (XAxleValue<0) { ServoXPos -= 20; myServoX.write(ServoXPos); delay(50*(7+XAxleValue)); }
    if (YAxleValue>0) { ServoYPos += 20; myServoY.write(ServoYPos); delay(50*(7-YAxleValue)); }
    if (YAxleValue<0) { ServoYPos -= 20; myServoY.write(ServoYPos); delay(50*(7+YAxleValue)); }

    if (ServoXPos>ServoXHomePos+50) { ServoXPos=ServoXHomePos+50; }
    if (ServoXPos<ServoXHomePos-50) { ServoXPos= ServoXHomePos-50; }
    if (ServoYPos>ServoYHomePos+50) { ServoYPos=ServoYHomePos+50; }
    if (ServoYPos<ServoYHomePos-50) { ServoYPos= ServoYHomePos-50; }
    delay(10);
  }

  //Se o jogador nao possui mais vidas e o sinal esta alto, o jogo fica em loop infinito, parando os motores até que o jogo seja reiniciado
  else if(vida == 1){
    while(digitalRead(8) != 0){
      delay(10);
    }
  }

  //Impressao do estado do pino de comunicacao no serial monitor
  Serial.println(digitalRead(8));
}

int readAxis(int thisAxis) {
  //Leitura da posicao analógica do joystick
  int reading = analogRead(thisAxis);
  // transforma a posicao do range de entrada para o range de saida
  reading = map(reading, 0, 1023, 0, range);
  
  //Para o caso em que a posicao esta alem do limite, a distancia é considerada como 0
  int distance = reading - center;
  if (abs(distance) < threshold) {
  distance = 0;
  }
  // retorna a distancia dos eixos
  return distance;
}