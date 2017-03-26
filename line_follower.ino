int left = 5;
int right = 6;
int mid = 7;
int power[2];
int finish = 0; // Finish line flag

power[0] = 2;
power[1] = 3;

int vl, vr, vm;
int i;
int lp, lg, rp, rg; // left & right high and ground

lp = 
lg =
rp =
rg =



void setup(){
  pinMode(left, INPUT);
  pinMode(right, INPUT);
  pinMode(mid, INPUT);
  pinMode(power[0], OUTPUT);
  pinMode(power[1], OUTPUT);
  for(i = 8; i < 12; i++){
    pinMode(i, OUTPUT); 
  }
}

void loop(){
  digitalWrite(power[0], HIGH);
  digitalWrite(power[1], HIGH);
  
  vl = digitalRead(left);
  vr = digitalRead(right);
  vm = digitalRead(mid);
  
  digitalWrite(lg, LOW);
  digitalWrite(rg, LOW);
  
  if(finish == 1){
    digitalWrite(rp, LOW);
    digitalWrite(lp, LOW);  
  }
  
  else if (vm == 0){
    digitalWrite(lp, HIGH);
    digitalWrite(rp, HIGH);
  }
 
 else if(vl == 0){
   digitalWrite(rp, HIGH);
   analogWrite(lp, 100); 
 }

 else if(vr == 0){
   digitalWrite(lp, HIGH);
   analogWrite(rp, 100); 
 }


 else{
    digitalWrite(lp, HIGH);
    digitalWrite(rp, HIGH);
    delay(1000);
    
    if(vm == 0 && vl == 0 && vr == 0){
      finish = 1;    
    }
  
 }

 delay(1000); 
}
