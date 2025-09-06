# 🔐 Base64 Conversion Algorithm

This repository contains a **C implementation of the Base64 encoding algorithm**, developed as an exercise to practice bitwise operations and data encoding, in preparation for the **Computer Networks exam (UNIPD)**.

---

## 📌 Project Description
Base64 is a widely used encoding scheme that represents binary data in an ASCII string format.  
This project manually implements the conversion logic without relying on external libraries, focusing on:
- Bitwise operations
- Left-shift manipulation
- Grouping binary sequences
- Handling padding (`=`)

---

## 🚀 Usage

### 1. Compile the program
```bash
gcc base64.c -o base64
```

### 2. Run with a string to encode
```bash
./base64 "Hello"
```

### 3. Example Output
```
SGVsbG8=
```

---

## 📚 Learning Goals
- Practice **C programming** for low-level data handling.
- Gain hands-on experience with **bitwise operations**.
- Understand how **Base64 encoding** works internally.
- Prepare for **Computer Networks exam (UNIPD)** by exploring encoding/decoding mechanisms.
