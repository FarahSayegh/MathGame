# 🧮 Math Quiz Game

![C++](https://img.shields.io/badge/language-C%2B%2B-blue.svg)
![Platform](https://img.shields.io/badge/platform-Windows%7CLinux-lightgrey.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

A **console-based Math Quiz Game** written in **C++** where users can challenge themselves with randomly generated math problems. Choose the number of questions, difficulty level, and operation type, and aim for a passing score!

---

## 🎮 Features

* ✅ Select number of questions (up to 100)
* ✅ Choose difficulty: Easy, Mid, Hard, or Mixed
* ✅ Choose operation: Add, Subtract, Multiply, Divide, or Mixed
* ✅ Randomized math problems for each quiz
* ✅ Instant feedback (correct/wrong) after each question
* ✅ Color-coded console output for correct/wrong answers
* ✅ Pass/Fail summary at the end
* ✅ Option to replay

---

## 📝 How It Works

1. You’ll be asked:

   * How many questions you want
   * Which difficulty level to use
   * Which operation type to use
2. The game generates random questions accordingly.
3. You answer each question and get instant feedback.
4. A final score summary is displayed at the end.
5. You can choose to play again!

---

## 💻 Compilation & Running

### ✔️ **Requirements:**

* C++ compiler (GCC, Clang, MSVC)
* Works on **Windows** (uses `system("cls")` and `system("color")`)

### 🏃 **To compile:**

```bash
g++ -o math_quiz_game main.cpp
./math_quiz_game
```

⚠️ **Note for macOS/Linux users:**
Replace or comment out `system("cls")` and `system("color")` lines to avoid runtime errors.

---

## 📸 Screenshot

![screenshot placeholder](https://via.placeholder.com/600x300?text=Math+Quiz+Game+Screenshot)

---

## 🚀 Future Enhancements

* 🌐 Cross-platform support for console clearing and coloring
* 📝 Better input validation (handle non-integer inputs)
* ⏱️ Optional timer or countdown per question
* 🏆 High score tracking or leaderboard

---

## 📄 License

This project is licensed under the **MIT License**.
Feel free to use, modify, and distribute!
