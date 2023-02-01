#include <LiquidCrystal.h>

//Definicao dos pinos do LCD e da quantidade de vidas que o jogador terá
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int vida = 3;
int primeiro = 1;

//Funcao que imprime a contagem de segundos até que o jogo seja reiniciado em caso de perda de vidas
void ImprimeContagem(){
  int contador = 5;
  
  lcd.clear();

  //Loop com a contagem
  while(contador > 0){
    lcd.print("Restarting in ");
    lcd.print(contador);
    delay(1000);
    lcd.clear();
    contador--;
  }
}

void setup() {
  //Definicao dos modos dos pinos e inicialização do serial monitor e do LCD
  //O pino A0 é o pino de leitura da cápsula piezoelétrica, enquanto o pino 8 é o pino de comunicação com o Arduino 1
  pinMode(A0, INPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  //Se é a primeira passagem do loop, a quantidade inicial de vidas é impressa no LCD
  if(primeiro){
    lcd.print("Vidas: ");
    lcd.print(vida);
    delay(1000);
    primeiro--;
  }

  //Leitura do pino da cápsula piezoelétrica
  int read = analogRead(A0);
  Serial.println(read);

  //Se a leitura indica que algo está gerando corrente, uma vida é diminuída do jogador. Assim, há uma pequena contagem de tempo de 5 segundos para que o jogador recoloque a bolinha em jogo
  if(read > 2){
    vida--;
    if(vida > 0){
      lcd.clear();
      lcd.print("Vidas: ");
      lcd.print(vida);
      delay(5000);
      ImprimeContagem();
      lcd.print("Vidas: ");
      lcd.print(vida);
    }

    //O caso acima é quando o jogador ainda possui vidas. O caso abaixo é quando o jogador perdeu o jogo, então uma mensagem de GAME OVER é exibida na tela
    else if(!vida){
      lcd.clear();
      lcd.print("GAME OVER!");
      delay(2000);
      lcd.clear();
      lcd.print("Press the cardb");
      delay(2000);
      lcd.clear();
      lcd.print("ox in the middle");
      delay(2000);

      //Enquanto o jogador ainda nao toca novamente na base para reiniciar o jogo, o Arduino 2 envia sinal alto para o Arduino 1, bloqueando o circuito principal dos motores
      while(!analogRead(A0)){
        digitalWrite(8, HIGH);
      }

      //Quando o jogador pressiona a base, o sinal passa a ser baixo, os motores são liberados, as vidas recarregadas e o jogo tem seu reinício
      digitalWrite(8, LOW);
      vida += 3;
      primeiro++;
      lcd.clear();
      lcd.print("Restarting...");
      delay(3000);
      lcd.clear();
    }
  }
}
