const int AOUTpin = A0; //the AOUT pin of the alcohol sensor goes into analog pin A0 of the arduino
const int ledPin = 13; //the anode of the LED connects to digital pin D13 of the arduino
#define dataout 12
#define ledPin 7

int i, alco_high, alco_low, mapped, data[200];

void setup() {
  Serial.begin(115200);//sets the baud rate
  pinMode(AOUTpin, INPUT);//sets the pin as an input to the arduino
  for (i = 2; i <= 5; i++)
  {
    pinMode(i, OUTPUT); //sets the pin as an output of the arduino
  }
  pinMode(dataout, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  alco_high = 0; // initially alcohol level is zero
  alco_low = 1023; // low threshold is 1023

  for (i = 200; i > 0; i--) {
    data[i] = data[i - 1]; // decrement of data

    if (data[i] > alco_high)
      alco_high = data[i];
    if (data[i] < alco_low)
      alco_low = data[i];
  }
  data[0] = analogRead(AOUTpin); //reads the analaog value from the alcohol sensor's AOUT pin
  mapped = map(data[0], 0, 1023, 0, 600);
  Serial.print("Alcohol value: ");
  Serial.println(mapped);//prints the alcohol value
  delay(100);
  if (mapped > 5)
  {
    digitalWrite(13, HIGH);
    digitalWrite(dataout, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(2000);
  }
  else
  {
    digitalWrite(13, LOW);
    digitalWrite(dataout, LOW);
    digitalWrite(ledPin, LOW);
    delay(2000);
  }
}

