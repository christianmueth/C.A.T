//15, 2, 4
int red = 15;
int green = 2;
int blue = 4;
int buttonPin = 13;
int const SAMPLE_WINDOW = 25; // Sample window width in mS (50 mS = 20Hz)
int const PREAMP_PIN = 12;      // Preamp output pin connected to 12
unsigned int sample;

// the setup routine runs once when you press reset:
void setup()
{
// initialize the digital pin as an output.
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(blue, OUTPUT);
// Define pin #13 as input and activate the internal pull-up resistor
    pinMode(buttonPin, INPUT_PULLUP);
    Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop()
{

    // Read the value of the input. It can either be 1 or 0
    int buttonValue = digitalRead(buttonPin);
    if (buttonValue == LOW)
    {
        digitalWrite(green, LOW); // turn the LED on (HIGH is the voltage level)
        digitalWrite(red, LOW); // turn the LED on (HIGH is the voltage level)
        digitalWrite(blue, LOW); // turn the LED on (HIGH is the voltage level)
        delay(100); // wait for a second
        digitalWrite(blue, HIGH); // turn the LED off by making the voltage LOW
        delay(10); //
        unsigned long startMillis= millis();  // Start of sample window
        unsigned int amplitude = 0;   // peak-to-peak level

        unsigned int soundMax = 0;
        unsigned int soundMin = 1024;

        // collect data for 50 mS and then plot data
        while (millis() - startMillis < SAMPLE_WINDOW)
        {
            sample = analogRead(PREAMP_PIN);
            if (sample > soundMax)
            {
                soundMax = sample;  // save the maximum levels
            }
            else if (sample < soundMin)
            {
                soundMin = sample;  // save the minimum levels
            }
        }
        amplitude = soundMax - soundMin;  // max - min = peak-peak amplitude
        if(amplitude>=1800)
        {
            digitalWrite(green, LOW); // turn the LED on (HIGH is the voltage level)
            digitalWrite(red, LOW); // turn the LED on (HIGH is the voltage level)
            digitalWrite(blue, LOW); // turn the LED on (HIGH is the voltage level)
            digitalWrite(red, HIGH); // turn the LED on (HIGH is the voltage level)
            delay(1000);
        }
        else if(amplitude>=1000)
        {
            digitalWrite(green, LOW); // turn the LED on (HIGH is the voltage level)
            digitalWrite(red, LOW); // turn the LED on (HIGH is the voltage level)
            digitalWrite(blue, LOW); // turn the LED on (HIGH is the voltage level)
            digitalWrite(green, HIGH); // turn the LED on (HIGH is the voltage level)
            delay(1000);
        }
        else
        {
            digitalWrite(green, LOW); // turn the LED on (HIGH is the voltage level)
            digitalWrite(red, LOW); // turn the LED on (HIGH is the voltage level)
            digitalWrite(blue, LOW); // turn the LED on (HIGH is the voltage level)
            delay(100); // wait for a second
            digitalWrite(blue, HIGH); // turn the LED off by making the voltage LOW
            delay(10); //
        }
        //Serial.println(amplitude);
    }
    else
    {
        digitalWrite(green, HIGH); // turn the LED on (HIGH is the voltage level)
        digitalWrite(red, HIGH); // turn the LED on (HIGH is the voltage level)
        digitalWrite(blue, HIGH); // turn the LED on (HIGH is the voltage level)
//delay(100); // wait for a second
//digitalWrite(red, HIGH); // turn the LED off by making the voltage LOW // wait for a second
    }

}
