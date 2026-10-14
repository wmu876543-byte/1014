// 宣告引腳（請依實際電路調整引腳編號）
const int buttonPin = 2;
const int RledPin = 3;   // 紅色引腳 (請依實際接線修改)
const int GledPin = 4;  // 綠色引腳 (請依實際接線修改)
const int BledPin = 5;  // 藍色引腳 (請依實際接線修改)

// 全域變數宣告
int buttonState = 0;     // 讀取按鈕狀態的變數
int ledState = LOW;      // LOW 代表亮燈週期，HIGH 代表滅燈週期
int ledcolor = 0;        // 顏色計數器 (0 ~ 7)
bool ButtonPressed = false;
String currentcolor = "LED off";

unsigned long previousMillis = 0; // 將儲存上次 LED 更新的時間
const long interval = 1000;       // 閃爍間隔（毫秒）

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);
  
  Serial.begin(9600);
  Serial.print("Current Color: ");
  Serial.println(currentcolor);
}

void loop() {
  // 1. 讀取按鈕的值
  buttonState = digitalRead(buttonPin);

  // 按下按鈕的邊緣觸發偵測 (切換下一個顏色)
  if (buttonState == HIGH && !ButtonPressed) {
    ledcolor = ledcolor + 1;
    ButtonPressed = true;
  }

  // 放開按鈕的狀態恢復
  if (buttonState == LOW && ButtonPressed) {
    ButtonPressed = false;
  }

  // 2. 非阻塞式 LED 計時閃爍切換
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;   // 儲存上次切換的時間
    
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
  }

  // 3. 核心 RGB 顏色控制與輸出邏輯 (結合圖片邏輯)
  if (ledcolor == 0) {
    currentcolor = "LED off";
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
  } 
  else if (ledcolor == 1) {
    currentcolor = "Red";
    if (ledState == LOW) {
      digitalWrite(RledPin, LOW);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, HIGH);
    } else {
      digitalWrite(RledPin, HIGH);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, HIGH);
    }
  } 
  else if (ledcolor == 2) {
    currentcolor = "Green";
    if (ledState == LOW) {
      digitalWrite(RledPin, HIGH);
      digitalWrite(GledPin, LOW);
      digitalWrite(BledPin, HIGH);
    } else {
      digitalWrite(RledPin, HIGH);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, HIGH);
    }
  } 
  else if (ledcolor == 3) {
    currentcolor = "Blue";
    if (ledState == LOW) {
      digitalWrite(RledPin, HIGH);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, LOW);
    } else {
      digitalWrite(RledPin, HIGH);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, HIGH);
    }
  } 
  else if (ledcolor == 4) {
    currentcolor = "Yellow";
    if (ledState == LOW) {
      digitalWrite(RledPin, LOW);
      digitalWrite(GledPin, LOW);
      digitalWrite(BledPin, HIGH);
    } else {
      digitalWrite(RledPin, HIGH);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, HIGH);
    }
  } 
  else if (ledcolor == 5) {
    currentcolor = "Purple";
    if (ledState == LOW) {
      digitalWrite(RledPin, LOW);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, LOW);
    } else {
      digitalWrite(RledPin, HIGH);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, HIGH);
    }
  } 
  else if (ledcolor == 6) {
    currentcolor = "Cyan";
    if (ledState == LOW) {
      digitalWrite(RledPin, HIGH);
      digitalWrite(GledPin, LOW);
      digitalWrite(BledPin, LOW);
    } else {
      digitalWrite(RledPin, HIGH);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, HIGH);
    }
  } 
  else if (ledcolor == 7) {
    currentcolor = "White";
    if (ledState == LOW) {
      digitalWrite(RledPin, LOW);
      digitalWrite(GledPin, LOW);
      digitalWrite(BledPin, LOW);
    } else {
      digitalWrite(RledPin, HIGH);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, HIGH);
    }
  } 
  else if (ledcolor == 8) {
    ledcolor = 0; // 超過範圍重設為 0
  }

  // 4. 當顏色改變時，同步輸出到 Serial Monitor
  static String lastColor = "";
  if (currentcolor != lastColor) {
    Serial.print("Current Color: ");
    Serial.println(currentcolor);
    lastColor = currentcolor;
  }
}