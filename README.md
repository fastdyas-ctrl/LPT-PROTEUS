# Arduino-LPT-Emulation-Library

Bibliothèque d'émulation du port parallèle standard IEEE 1284 (LPT / Centronics) pour microcontrôleurs ATmega328P (Arduino Uno / Nano), conçue spécialement pour le prototypage et la simulation sous **Proteus VSM (ISIS)**.

---

## 📌 Présentation

Cette bibliothèque permet d'utiliser les fonctions historiques en C/C++ de bas niveau du monde PC x86 (`inportb()` et `outportb()`) pour piloter un périphérique parallèle virtuel ou réel directement depuis Arduino.

Elle simule les adresses mémoires standard de la carte mère :
* **`0x378` (Data Register)** : Sortie 8 bits de données.
* **`0x37A` (Control Register)** : Sortie des signaux de contrôle (Strobe, AutoFeed, Init, Select Input).
* **`0x379` (Status Register)** : Lecture des signaux d'état (Busy, Ack, Paper End, Select, Error).

---

## ⚠️ Important : Le rôle clé de `initLPT()` dans `setup()`

L'appel à `initLPT()` dans la fonction `void setup()` est **obligatoire** avant toute lecture ou écriture.

```cpp
void setup() {
    initLPT(); // OBLIGATOIRE : Initialise les registres de direction DDRx
    // ... reste de votre code
}
