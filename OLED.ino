#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

//DEFINICAO DOS BOTOES
#define btnSwitch 8
#define btnSelect 9

//TAMANHO DO DISPLAY
#define LARGURA_OLED  128
#define ALTURA_OLED   64

#define RESET_OLED    -1
  Adafruit_SSD1306 display(LARGURA_OLED, ALTURA_OLED, &Wire, RESET_OLED);

//DEFINICAO DAS VARIAVEIS (NAO ALTERAR NADA AQUI)
String title; 
String opts[4];
bool expandOption; 
int boxSize; 
int btnSwitchPress;
int btnSelectPress;
int optSelected;
int optSize = -1;


void setup() {
  Serial.begin(9600);
  pinMode(btnSwitch, INPUT_PULLUP);
  pinMode(btnSelect, INPUT_PULLUP);
  menuOled("MAIN MENU", "ZERO", "UM", "", ""); //A CHAMADA É FEITA POR ESSE COMANDO 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {
  display.setTextSize(1);
  display.setTextColor(WHITE);

  mainMenu();
  btnSelectPress = digitalRead(btnSelect); // LE O BTN DE SELECAO 
  if (!btnSelectPress) {
    if(optSelected == 0) opt0();
    if(optSelected == 1) opt1();
    if(optSelected == 2) opt2();
    if(optSelected == 3) opt3();
    delay(200);
  }
}

void menuOled(String Stitle,String Sop1,String Sop2,String Sop3,String Sop4)
{
  title = Stitle;
  opts[0] = Sop1;
  opts[1] = Sop2;
  opts[2] = Sop3;
  opts[3] = Sop4;
  for(int roller = 0; roller <= 3; roller++)
  {
    if (opts[roller].length() > 0) ++optSize;
  }
  if (opts[2].length() > 0) expandOption = true;
  boxSize = expandOption ? 62 : 126;
}

void mainMenu(){
  drawMenu();
  //Desenha a parte dinâmica do menu
  btnSwitchPress = digitalRead(btnSwitch);
  if (!btnSwitchPress) {
    optSelected++;
    if (optSelected > 3 || optSelected > optSize) optSelected = 0;
    delay(200);
  }

  display.clearDisplay();
  drawMenu();

  if(optSelected == 0) display.fillRect(2,18, 10, 16,WHITE);  // OP 0 SELECTED
  if(optSelected == 1) display.fillRect(2,43, 10, 16,WHITE);  // OP 1 SELECTED
  if(optSelected == 2) display.fillRect(68,18, 10, 16,WHITE);  // OP 2 SELECTED
  if(optSelected == 3) display.fillRect(68,43, 10, 16,WHITE);  // OP 3 SELECTED

  display.display();
}

//Desenha toda a área estática do menu
void drawMenu(){
  display.drawRect(0,16,boxSize,20,WHITE);  //op 0   E
  display.drawRect(0,41,boxSize,20,WHITE);  //op 1   E
  if (expandOption){    //Se tiver mais que duas escolhas desenha os quadrados referente a cx 3 e cx 4
    display.drawRect(66,16,62,20,WHITE); //op 2   D
    display.drawRect(66,41,62,20,WHITE); //op 3   D
  }
  
  //Desenha área do título
  display.setCursor(0,1); //FAIXA 0,0 A 128,9 AMARELA (ENTRE 0,9 E 0,15 FICAM MISTURADO AZUL E AMARELO GRADATIVAMENTE)
  display.print(title);
  
  //Desenha tela esquerda
  display.setCursor(14,22);
  display.print(opts[0]);
  display.setCursor(14,47);
  display.print(opts[1]);

  //Desenha tela direita SE necessário
  if (expandOption){ 
  
    display.setCursor(80,22);
    display.print(opts[2]);
    display.setCursor(80,47);
    display.print(opts[3]);
  }
}

void opt0(){ //exemplo de utilizacao
  display.clearDisplay();
  display.setCursor(10,16);
  display.print("OPCAO 0");
  display.display();
  delay(3000);
  display.clearDisplay();
}

void opt1(){

}

void opt2(){

}

void opt3(){

}
