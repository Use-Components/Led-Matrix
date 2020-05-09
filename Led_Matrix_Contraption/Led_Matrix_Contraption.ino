  int latchPin = 8;//12 on SIPO
int clockPin = 12;//11 on SIPO
int dataPin = 11;//14 on SIPO
bool led_matrix_pre[8][8]={
  {1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,1},
  {1,0,1,1,1,1,0,1},
  {1,0,1,0,0,1,0,1},
  {1,0,1,0,0,1,0,1},
  {1,0,1,1,1,1,0,1},
  {1,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1}
};

byte led_matrix[8][8]; 
void setup() {
  DDRD=0xff;
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  for(int i=0;i<8;i++){
  for(int j=0;j<8;j++){
  if(led_matrix_pre[i][j]==0){
    led_matrix[i][j]=0x00;
   }
  if(led_matrix_pre[i][j]==1){
    switch(j){
    case 0:
    led_matrix[i][0]=0x80;
    break;
    case 1:
    led_matrix[i][1]=0x40;
    break;
    case 2:
    led_matrix[i][2]=0x20;
    break;
    case 3:
    led_matrix[i][3]=0x10;
    break;
    case 4:
    led_matrix[i][4]=0x08;
    break;
    case 5:
    led_matrix[i][5]=0x04;
    break;
    case 6:
    led_matrix[i][6]=0x02;
    break;
    case 7:
    led_matrix[i][7]=0x01;
    break;
    }
   }
  }
 }
}

void SIPO(byte x){
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, x);
digitalWrite(latchPin, HIGH);
}

void loop() {
  for(int i=0;i<8;i++){
  for(int j=0;j<8;j++){
  PORTD=led_matrix[i][j];//coloum
    switch(i){
    case 0:
    SIPO(0x80);
    break;
    case 1:
    SIPO(0x40);
    break;
    case 2:
    SIPO(0x20);
    break;
    case 3:
    SIPO(0x10);
    break;
    case 4:
    SIPO(0x08);
    break;
    case 5:
    SIPO(0x04);
    break;
    case 6:
    SIPO(0x02);
    break;
    case 7:
    SIPO(0x01);
    break;
   }
   }
  }
 }
