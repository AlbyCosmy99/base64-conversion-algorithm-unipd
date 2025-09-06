# 🖧 Client-Server Socket Programming (C)  
Project for practicing for the **Computer Networks** exam  

This repository contains two C programs (`client.c` and `server.c`) that implement a basic **client-server architecture** using TCP sockets.  
The goal is to simulate simple HTTP-like requests/responses and practice with **socket programming**, **request parsing**, and **connection management**.

---

## 📂 Files
- **`client.c`** → connects to the server, sends HTTP-like requests (with optional `keep-alive` or `close`), and displays server responses.  
- **`server.c`** → accepts multiple client connections, parses the request line, headers, body, and sends back responses. It can also execute local programs when the URL starts with `gateway/`.

---

## ⚙️ Features
- Client:
  - Supports `"Connection: keep-alive"` or `"Connection: close"`.
  - Can send multiple requests in sequence.
  - Parses and prints **response headers** and **body**.
- Server:
  - Parses **request line**, **headers**, **method**, **URL**, and **body**.
  - Optional response confirmation mode before sending responses.
  - Special `gateway/` URL handling:
    - Executes the specified file as a program.
    - Sends back its output to the client.
    - Returns `500 INTERNAL SERVER ERROR` if execution fails.

---

## ▶️ How to Compile
Use `gcc` to compile both programs:

```bash
gcc server.c -o server
gcc client.c -o client
```

---

## ▶️ How to Run

### Start the Server
```bash
./server
```

Optionally, with confirmation response mode before sending responses:
```bash
./server confirm
```

### Start the Client
Basic connection:
```bash
./client close
```

Keep-alive with 3 requests:
```bash
./client keep-alive 3 /test
```

This will send 3 requests to the server with a persistent connection.

---

## 📖 Example Output

**Server side**
```
client socket: 4
REQUESTLINE: POST /test HTTP/1.1
HEADER: Connection: keep-alive
METHOD: POST
URL: /test
BODY: body1
INVIO RESPONSE AL CLIENT
```

**Client side**
```
POST /test HTTP/1.1
RESPONSE HEADER: HTTP/1.1 200 OK
REQUEST BODY: body1
```
