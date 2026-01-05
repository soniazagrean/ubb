[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/xcmdZrmA)
# 💻 Laboratorul 4 - Baze de date, interfața grafică
Continuați dezvoltarea aplicației de la temele precedente. 

## Cerințe non-funcționale
- Se păstrează cerințele definite în temele **A2** și **A3**.

## Cerințe funcționale
- Implementați un Repository nou, care permite stocarea entităților din domeniu într-o bază de date SQL. Decizia privind ce tip de repository este utilizat se va face prin folosirea fișierului *settings.properties*, implementat în cadrul temei **A3**
- Implementarea ce utilizează repository SQL va avea 100 entități generate pseudo-aleator și salvate în baza de date. Puteți folosi liste de nume/prenume, funcții pentru a genera date și numere aleatoare pentru a genera această listă, precum și unelte de tipul [Java Faker](https://dius.github.io/java-faker/).
- Implementați interfața grafică cu utilizatorul. Utilizați tehnologia [JavaFX](https://openjfx.io/). Păstrați codul sursă al interfeței cu utilizatorul în linia de comandă. Aplicația va putea fi pornită atât în linie de comandă, cât și folosind nou implementata interfață grafică prin efectuarea unor modificări minore al codului sursă (ex. comentarea/decomentarea instanțierii unei clase).
- Implementați cu ajutorul Java 8 streams următoarele rapoarte la nivelul **serviciilor** aplicației, pentru fiecare problemă în parte.

  - **Problema 1**
  - Numărul de programări pentru fiecare pacient în parte. Se vor afișa datele pacientului și numărul total de programări pentru acesta. Afișarea se va face în ordine descrescătoare a numărului de programări.
  - Numărul total de programări pentru fiecare lună a anului. Se va afișa fiecare lună a anului, și numărul total de programări existente pentru acea lună. Afișarea se va face în ordine descrescătoare a numărului de programări.
  - Numărul de zile trecute de la ultima programare a fiecărui pacient. Se vor afișa datele pacientului, data ultimei programări și numărul de zile trecute de la ultima programare. Afișarea se va face în ordine descrescătoare a numărului de zile trecute de la ultima programare.
  - Cele mai aglomerate luni ale anului. Se vor afișa lunile anului, sortate în mod descrescător după numărul de programări. Se va afișa și numărul de programări din fiecare lună.

  - **Problema 2**
  - Numărul de torturi comandate în fiecare zi (o comandă poate avea unul sau mai multe torturi). Se vor afișa doar acele date pentru care au fost înregistrate comenzi, precum și numărul de torturi comandate în fiecare zi. Afișarea se va realiza în ordine descrescătoare a numărului de torturi comandate în fiecare zi.
  - Numărul de torturi comandate în fiecare lună a anului. Se vor afișa lunile anului, precum și numărul de torturi comandate în fiecare lună. Afișarea se va face în ordine descrescătoare a numărului de torturi comandate.
  - Cele mai des comandate torturi. Se vor afișa toate informațiile despre fiecare tort, împreună cu numărul total de comenzi pentru fiecare. Țineți cont că o comandă poate include mai multe torturi de tipuri diferite. Afișarea se va face în ordine descrescătoare a numărului de comenzi pentru fiecare tort.

  - **Problema 3**
  - Cele mai des închiriate mașini. Se vor afișa datele pentru fiecare mașină precum și numărul de închirieri, în ordine descrescătoare a numărului de închirieri.
  - Numărul de închirieri efectuate în fiecare lună a anului. Se vor afișa lunile anului, precum și numărul de închirieri efectuate în fiecare lună, în ordine descrescătoare a numărului de închirieri. O închiriere pentru care data de început și data de sfârșit se găsește în luni diferite se va adăuga statisticii lunii asociate datei de început.
  - Mașinile care au fost închiriate cel mai mult timp. Se vor afișa datele pentru fiecare mașină precum și numărul total de zile de închiriere pentru fiecare. 

  - **Problema 4**
  - Numărul de produse comandate din fiecare categorie. Se vor afișa numele fiecărei categorii precum și numărul de produse comandate din acea categorie, în ordine descrescătoare a numărului de comenzi.
  - Cele mai profitabile luni ale anului. Se vor afișa lunile anului, împreună cu numărul de comenzi din fiecare lună precum și prețul total al produselor comandate.
  - Lista de produse, sortată descrescător după încasările realizate. Încasările pentru un produs reprezintă prețul produsului înmulțit cu numărul total de produse comandate.

Termenul limită pentru predarea temei este **laboratorul din cadrul săptămânii 11 sau 12**, depinzând de orar.

### Bonus (0.2p)
Utilizați un mapper ORM (ex. Hibernate) împreună cu adnotările Java aferente pentru a stoca toate entitățile în cadrul bazei de date SQL.

### Bonus (0.1p)
Implementați un tip adițional de Repository care permite salvarea entităților într-o bază de date NoSQL. Acesta va fi integrat în mecanismul fișierului de setări al aplicației (*setttings.properties*).

### Bonus (0.1p)
Adăugați o setare nouă în fișierul *setttings.properties*, în care se va specifica dacă aplicația pornește în linie de comandă sau prin interfață grafică. Modificarea acestei setări în fișier determină modificarea modului de pornire al aplicației, fără a fi necesare modificări la nivelul codului sursă. 
