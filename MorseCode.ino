const int buzzerPin = 12;
const int dotLedPin = 10; // LED for dots
const int dashLedPin = 11; // LED for dashes

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(dotLedPin, OUTPUT);
  
  pinMode(dashLedPin, OUTPUT);

  Serial.begin(9600); 
}

void loop() {
  if (Serial.available() > 0) {
    String inputText = Serial.readStringUntil('\n');
    translateAndPlayMorse(inputText);
  }
}

void translateAndPlayMorse(String text) {
  for (int i = 0; i < text.length(); i++) {
    char c = text.charAt(i);
    if (c == ' ') {
      delay(300); // Gap between words
    } else {
      String morseCode = charToMorse(c);
      for (int j = 0; j < morseCode.length(); j++) {
        if (morseCode.charAt(j) == '.') {
          playDot();
          digitalWrite(dotLedPin, HIGH); // Turn on dot LED
          delay(300);
          digitalWrite(dotLedPin, LOW); // Turn off dot LED
        } else if (morseCode.charAt(j) == '-') {
          playDash();
          digitalWrite(dashLedPin, HIGH); // Turn on dash LED
          delay(300);   
          digitalWrite(dashLedPin, LOW); // Turn off dash LED
        }
        delay(300); // Gap between Morse code elements
      }
      delay(300); // Gap between letters
    }
  }
  Serial.println("Translation done.");
}

String charToMorse(char c) {
  switch (c) {
    // Morse code mapping for letters
    case 'A':
    case 'a':
      return ".-";
    case 'B':
    case 'b':
      return "-...";
    case 'C':
    case 'c':
      return "-.-.";
    case 'D':
    case 'd':
      return "-..";
    case 'E':
    case 'e':
      return ".";
    case 'F':
    case 'f':
      return "..-.";
    case 'G':
    case 'g':
      return "--.";
    case 'H':
    case 'h':
      return "....";
    case 'I':
    case 'i':
      return "..";
    case 'J':
    case 'j':
      return ".---";
    case 'K':
    case 'k':
      return "-.-";
    case 'L':
    case 'l':
      return ".-..";
    case 'M':
    case 'm':
      return "--";
    case 'N':
    case 'n':
      return "-.";
    case 'O':
    case 'o':
      return "---";
    case 'P':
    case 'p':
      return ".--.";
    case 'Q':
    case 'q':
      return "--.-";
    case 'R':
    case 'r':
      return ".-.";
    case 'S':
    case 's':
      return "...";
    case 'T':
    case 't':
      return "-";
    case 'U':
    case 'u':
      return "..-";
    case 'V':
    case 'v':
      return "...-";
    case 'W':
    case 'w':
      return ".--";
    case 'X':
    case 'x':
      return "-..-";
    case 'Y':
    case 'y':
      return "-.--";
    case 'Z':
    case 'z':
      return "--..";

    // Morse code mapping for numbers
    case '0':
      return "-----";
    case '1':
      return ".----";
    case '2':
      return "..---";
    case '3':
      return "...--";
    case '4':
      return "....-";
    case '5':
      return ".....";
    case '6':
      return "-....";
    case '7':
      return "--...";
    case '8':
      return "---..";
    case '9':
      return "----.";

    // Morse code mapping for common punctuation marks
    case '.':
      return ".-.-.-"; // Period
    case ',':
      return "--..--"; // Comma
    case '?':
      return "..--.."; // Question Mark
    case '\'':
      return ".----."; // Apostrophe (single quotation mark)
    case '!':
      return "-.-.--"; // Exclamation Mark
    case '/':
      return "-..-."; // Slash
    case '(':
      return "-.--."; // Left Parenthesis
    case ')':
      return "-.--.-"; // Right Parenthesis
    case '&':
      return ".-..."; // Ampersand
    case ':':
      return "---..."; // Colon
    case ';':
      return "-.-.-."; // Semicolon
    case '=':
      return "-...-"; // Equal Sign
    case '+':
      return ".-.-."; // Plus Sign
    case '-':
      return "-....-"; // Hyphen
    case '_':
      return "..--.-"; // Underscore
    case '"':
      return ".-..-."; // Quotation Marks
    case '$':
      return "...-..-"; // Dollar Sign
    case '@':
      return ".--.-."; // At Sign

    default:
      return "";
  }
}

void playDot() {
  tone(buzzerPin, 1000, 100);
  delay(300);
  noTone(buzzerPin);
}

void playDash() {
  tone(buzzerPin, 1000, 300);
  delay(300);
  noTone(buzzerPin);
}
