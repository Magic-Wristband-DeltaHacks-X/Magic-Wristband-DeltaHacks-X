//Date created: Jan 13, 2024

// Pin Numbers
int buzzerPin = 8;
int buttonPin = 7;
int buttonPin2 = 2;

//Initialization of pins
void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  tone(buzzerPin, 10, 1);
}

//Main code
void loop() {

  //List of Reminders that can be set by the user
  char Reminder[] = { 'Reminder1', 'Reminder2', 'Reminder3' };
  int i = 0;

  //The time-interval variable between reminders
  int timer = 0;

  //State values of buttons' pins
  int buttonState2 = digitalRead(buttonPin2);
  int buttonState = digitalRead(buttonPin);

  //A loop that iterates till the user has entered the desired time-interval
  do {
    delay(500);

    //When the user presses push button #2,
    //the code starts recording the user-input for the time-interval
    if (digitalRead(buttonPin2) == HIGH) {
      Serial.println("pin 2 pressed");
      delay(1000);

      //Each click of the push button #1 increases the time-interval by 5 seconds
      //The loop will iterate till user has pressed the desired number of clicks
      //The loop will be terminated when the user presses push button #2 again
      do {
        if (digitalRead(buttonPin) == HIGH) {
          timer = timer + 5000;
          Serial.println("timer increase");
          delay(1000);
        }
      } while (digitalRead(buttonPin2) == LOW);

      break;
    }
  } while (true);

  //The following code iterates through the reminders in the Reminders array
  while (i < sizeof(Reminder) / sizeof(Reminder[0])) 
  {
    //the time-interval between each reminder
    delay(timer);

    //the buzzer will keep beeping till the user presses push button #1 to acknowledge it
    while (true) {
      int buttonState = digitalRead(buttonPin);


      if (buttonState == LOW) {
        Serial.println("button not pressed");
        digitalWrite(buzzerPin, HIGH);
      }

      //the buzzer will stop beeping when user presses push button #1 to acknowledge it
      if (buttonState == HIGH) {
        Serial.println("button pressed");
        digitalWrite(buzzerPin, LOW);
        break;
      }
    }

    //incremental variable for iterating though the Reminder array
    i++;
  }

  //end of code
}
