Crinclude <LiquidCrystal.h>
//assigning pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
 lcd.begin(16, 2);
 pinMode(switchPin, INPUT);
 lcd.print("Ask the");
 lcd.setCursor(0,1);
 lcd.print("Crystal Ball!");
}

void loop() {
  switchState = digitalRead(switchPin);

  if(switchState != prevSwitchState) {
    if(switchState == LOW){
      reply = random(8);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("The ball says: ");
      lcd.setCursor(0,1);
      switch(reply){
        case 0:
        lcd.print("Yes");
        break;
        case 1:
        lcd.print("The bird lives...");
        break;
        case 2:
        lcd.print("Ceratinly");
        break;
        case 3:
        lcd.print("Outlook good");
        break;
        case 4:
        lcd.print("Unsure");
        break;
        case 5:
        lcd.print("Ask again");
        break;
        case 6:
        lcd.print("Doubtful");
        break;
        case 7:
        lcd.print("No");
        break;
      }//end switch statement     
    }//end if statement
  }//end if statement

  prevSwitchState = switchState;
}//end main loop
