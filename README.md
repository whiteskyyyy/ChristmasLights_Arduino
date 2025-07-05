# Arduino Holiday Music & LED Light Show 🎄

This project is a **Christmas-themed interactive light and music display** developed as part of an academic activity at **National University – Manila**, College of Engineering.

It features:
- 🎶 Classic Christmas songs played via a buzzer
- 💡 Animated LED light patterns
- 🧠 Smart sensor integration using motion, light, and distance sensing

---

## 📷 Features

- **Songs Played**:
  - Jingle Bells
  - Santa Claus Is Coming to Town
  - We Wish You a Merry Christmas

- **Sensor Inputs**:
  - **PIR Sensor (Pin 6):** Detects motion to trigger events
  - **LDR (A0):** Detects ambient light
  - **Ultrasonic Sensor (Trigger: Pin 4, Echo: Pin 5):** Sets LED animation speed based on distance

- **LED Animations**:
  - Bouncing and sweeping patterns on digital pins 9–13

---

## 🔌 Hardware Used

| Component          | Description                        |
|-------------------|------------------------------------|
| Arduino Uno/Nano  | Microcontroller                    |
| Buzzer            | Sound output (Pin 7)               |
| 5 LEDs            | Connected to pins 9–13             |
| PIR Sensor        | Motion detection (Pin 6)           |
| LDR Module        | Light detection (A0)               |
| Ultrasonic Sensor | Distance sensing (Pins 4 & 5)      |
| Resistors, Wires  | Basic circuit connections          |

---

## 🛠 How It Works

1. **When bright light is detected** (`ldrValue > 200`) and **motion is detected** via PIR:
   - Plays a holiday song (cycles on each motion event).
   - Runs LED patterns.

2. **Ultrasonic sensor** detects distance:
   - Close = Fast LED effects
   - Far = Slow LED effects

3. Songs are played using frequency-based buzzing with delays to simulate musical rhythm.

---

## 🧪 Sample Code Snippet

```cpp
if(ldrValue > 200){
  	if(pir == HIGH){
    	if(!motionDetected){
    		mot++;
      		sing(mot);
      		pk();
      		motionDetected = true;
    	}
  	}
}
```

## 🎓 Academic Context
🏫 National University – Manila
📚 College of Engineering
🎓 Bachelor of Science in Computer Engineering (BSCpE)
Project developed for learning microcontroller programming and sensor integration.

## 📬 Contact

- LinkedIn: Martinsmk

- GitHub: whiteskyyyy

