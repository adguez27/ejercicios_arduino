void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  String s = "";

  s = Serial.readString();
  if(s!= NULL){
    for (int i=0;i<s.length();i++){
        if ('a'<=s[i] && s[i]<='z'){
           s[i]=char(((int)s[i])-32);
        }

        else if ('A'<=s[i] && s[i]<='Z'){
           s[i]=char(((int)s[i])+32);
        }
    }
    Serial.println(s);
  }
}
  
