<h1 align="center">MARBLE MAZE LABYRINTH</h1>
<p align="center">
<img src="http://img.shields.io/static/v1?label=STATUS&message=EM%20DESENVOLVIMENTO&color=GREEN&style=for-the-badge"/>
</p>
<h2>Membros do Grupo</h2>
<p>João Pedro Camargo Batista

João Pedro de Oliveira Nascente

Pedro Antônio Rosa de Souza

Roger Leonardo Coimbra Silva</p>
<h2>Resumo</h2>
<p>O game em questão consiste em uma plataforma 
suspensa que é controlada por um joystick, movendo-se de acordo com o 
manuseio do jogador. O objetivo é levar a bolinha de gude até o final do labirinto 
sem cair nos buracos do caminho, havendo 3 chances.</p>
<h2>Descrição Detalhada</h2>
<p>O Marble Maze Labyrinth é um jogo no qual o jogador 
deve levar uma bolinha de gude até o final do labirinto sem deixar que ela caia 
nos buracos do caminho, desviando dos mesmos e das paredes do jogo.

Para isso, o jogador conta com um joystick, que pode ser movido em várias 
direções e em diferentes eixos. Com o movimento do joystick, dois servo motores 
giram as bases do labirinto (feitas com MDF), fazendo com 
que a plataforma se mova e a bolinha ande pelo percurso.

O percurso conta com paredes e buracos. Se a bolinha cair em um desses 
buracos, o jogador deve colocá-la de volta no início do percurso e recomeçar.

Esse jogo foi proposto pela primeira vez em 1946 pela empresa sueca BRIO. O 
protótipo do jogo ficaria semelhante a este:</p>
<p align="center">
<img src="https://user-images.githubusercontent.com/105085521/209408116-4f47b0f7-e918-47e8-8a1a-c92e583f327e.png">
</p>
<p align="center">Fonte: https://create.arduino.cc/projecthub/AhmedAzouz/arduino-marble-maze-labyrinth-bd9ea6</p>
<p align="center">
<img src="https://user-images.githubusercontent.com/105085521/209408347-14b3304a-ee10-4248-86f2-e00f852c2659.png">
</p>
<p align="center">Fonte: https://create.arduino.cc/projecthub/AhmedAzouz/arduino-marble-maze-labyrinth-bd9ea6</p>
<p>
Nós propomos que cada jogador tenha três vidas. Quando as três vidas forem 
perdidas e o jogo for encerrado sem sucesso, o joystick irá parar de funcionar e 
será preciso reiniciar o jogo.

</p>
<h2>Lista de Itens Necessários</h2>
<p>2 Arduinos</p>
<p>2 Protoboards</p>
<p>Jumpers</p>
<p>2 Servo Motores</p>
<p>1 Módulo Joystick para Arduino</p>
<p>Papelão e LEGO para a montagem da base</p>
<p>1 Display LCD</p>
<p>1 Cápsula piezoelétrica</p>
<h2>Esquemáticos do Circuito</h2>
<p align="center">
<img src="https://user-images.githubusercontent.com/105085521/209408891-1c054df5-b180-4321-8ffe-a2e8d00dd175.png">
</p>
<p align="center">Fonte: https://create.arduino.cc/projecthub/AhmedAzouz/arduino-marble-maze-labyrinth-bd9ea6</p>
<p>Esse é o esquemático de ligação do joystick para controlar os dois servo motores 
que movem a plataforma:</p>
<p align="center">
<img src="lcd.png">
</p>
<p>Esse é o esquemático de ligação do display LCD com o Arduino UNO e o sensor piezoelétrico.

Um único Arduino não será capaz de manter funcionando os dois servo motores 
e o display LCD, por isso propomos usar um Arduino UNO para controlar os 
motores por meio do joystick e outro para controlar o display LCD.

A alimentação do circuito também deverá ser feita a parte, por pilha</p>
