#include <SoftwareSerial.h>

SoftwareSerial bt(2,1);
int THUMB=A4;
int INDEX=A3;
int MIDDLE=A2;
int RING=A1;
int LITTLE=A0;

void setup(){
  //Setting up the anlog pins for inputs
  pinMode(THUMB,INPUT);
  pinMode(INDEX,INPUT);
  pinMode(MIDDLE,INPUT); 
  pinMode(RING,INPUT);
  pinMode(LITTLE,INPUT);
  Serial.begin(9600);
  bt.begin(9600);
}
//Function to print out the pin values
void printfn(int flexADC0,int flexADC1,int flexADC2,int flexADC3,int flexADC4){
    Serial.print("A4 ");
    Serial.print(flexADC4);
    Serial.print("  ");
    Serial.print("A3 ");
    Serial.print(flexADC3);
    Serial.print("  ");
    Serial.print("A2 ");
    Serial.print(flexADC2);
    Serial.print("  ");
    Serial.print("A1 ");
    Serial.print(flexADC1);
    Serial.print("  ");
    Serial.print("A0 ");
    Serial.print(flexADC0);
    Serial.println("  ");   
}

void loop(){
  //Taking inputs from the sensors
  int flexADC4 = analogRead(THUMB);
  int flexADC3 = analogRead(INDEX);
  int flexADC2 = analogRead(MIDDLE);
  int flexADC1 = analogRead(RING);
  int flexADC0 = analogRead(LITTLE); 
  if(Serial.available()>0){
    char c;
    c=Serial.read();
    if(c=='a'){
      printfn( flexADC0, flexADC1, flexADC2, flexADC3, flexADC4);
    }
  }
  // printfn( flexADC0, flexADC1, flexADC2, flexADC3, flexADC4);

  //CONDITION FOR A
  if((flexADC0>=837&&flexADC0<=900) && (flexADC1>=818&&flexADC1<=900) && (flexADC2>=795&&flexADC2<=900) && (flexADC3>=835&&flexADC3<=900) && (flexADC4>=760&&flexADC4<=790)){
    Serial.print('A');
    bt.write('A');
  }
  //CONDITION FOR B
  else if((flexADC0>=739&&flexADC0<=769) && (flexADC1>=716&&flexADC1<=746) && (flexADC2>=725&&flexADC2<=756) && (flexADC3>=750&&flexADC3<=785) && (flexADC4>=825&&flexADC4<=900)){
    Serial.print('B');
    bt.write('B');
  }
  //CONDITION FOR C
  else if((flexADC0>=793&&flexADC0<=825) && (flexADC1>=780&&flexADC1<=810) && (flexADC2>=770&&flexADC2<=800) && (flexADC3>=800&&flexADC3<=836) && (flexADC4>=757&&flexADC4<=789)){
    Serial.print('C');
    bt.write('C');
  }
  //CONDITION FOR D
  else if((flexADC0>=850&&flexADC0<=920) && (flexADC1>=800&&flexADC1<=900) && (flexADC2>=810&&flexADC2<=900) && (flexADC3>=754&&flexADC3<=785) && (flexADC4>=820&&flexADC4<=900)){
    Serial.print('D');
    bt.print('D');
  }
  //CONDITION FOR E
  else if((flexADC0>=830&&flexADC0<=900) && (flexADC1>=813&&flexADC1<=900) && (flexADC2>=790&&flexADC2<=900) && (flexADC3>=830&&flexADC3<=900) && (flexADC4>=870&&flexADC4<=910)){
    Serial.print('E');
    bt.print('E');
  }
  //CONDITION FOR F
  else if((flexADC0>=739&&flexADC0<=769) && (flexADC1>=716&&flexADC1<=746) && (flexADC2>=732&&flexADC2<=777) && (flexADC3>=860&&flexADC3<=905) && (flexADC4>=815&&flexADC4<=900)){
    Serial.print('F');
    bt.print('F');
  }
  //CONDITION FOR I
  else if((flexADC0>=740&&flexADC0<=790) && (flexADC1>=800&&flexADC1<=900) && (flexADC2>=800&&flexADC2<=900) && (flexADC3>=835&&flexADC3<=900) && (flexADC4>=822&&flexADC4<=900)){
    Serial.print("I");
    bt.write('I');
  }
  //CONDITION FOR K
  else if((flexADC0>=790&&flexADC0<=835) && (flexADC1>=780&&flexADC1<=830) && (flexADC2>=720&&flexADC2<=770) && (flexADC3>=800&&flexADC3<=900) && (flexADC4>=800&&flexADC4<=900)){
    Serial.print('K');
    bt.print('K');
  }
  //CONDITION FOR L
  else if((flexADC0>=810&&flexADC0<=850) && (flexADC1>=825&&flexADC1<=870) && (flexADC2>=835&&flexADC2<=880) && (flexADC3>=720&&flexADC3<=795) && (flexADC4>=748&&flexADC4<=790)){
    Serial.print('L');
    bt.write('L');
  }
  //CONDITION FOR W
  else if((flexADC0>=780&&flexADC0<=900) && (flexADC1>=715&&flexADC1<=750) && (flexADC2>=725&&flexADC2<=765) && (flexADC3>=750&&flexADC3<=785) && (flexADC4>=830&&flexADC4<=890)){
    Serial.print('W');
    bt.print('W');
  }
  //CONDITION FOR Y
  else if((flexADC0>=720&&flexADC0<=785) && (flexADC1>=790&&flexADC1<=900) && (flexADC2>=790&&flexADC2<=900) && (flexADC3>=825&&flexADC3<=900) && (flexADC4>=740&&flexADC4<=789)){
    Serial.print('Y');
    bt.print('Y');
  }
  
  delay(500);
  
  
  
}
