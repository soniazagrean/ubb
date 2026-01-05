[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/-YwNbqP0)
# 💻 Laboratorul 2 - Arhitectura stratificată în Java
Dezvoltați o implementare Java bazată pe principiile arhitecturii stratificate (eng. _layered architecture_) pentru una din problemele enunțate mai jos. Cerințele de îndeplinit pentru laboratorul următor (această temă se va întinde pe durata întregului semestru) sunt:

## Cerințe non-funcționale
- Stratificarea aplicației va include **domeniul**, **repository**-ul, **serviciile**, și **interfața cu utilizatorul**. 
- Definiți operațiile din **repository** folosind o interfață sau clasă abstractă. Implementarea de repository trebuie să utilizeze mecanismul de genericitate din limbajul Java.
- Instanțiați câte un repository generic pentru fiecare entitate definită în cadrul programului (ex. `Repository<Masina>`, `Repository<Inchiriere>`). Adăugați cel puțin câte 5 instanțe în fiecare repository direct din codul sursă.
- Toate entitățile din domeniul problemei trebuie să fie unic identificabile. Toate entitățile vor fi derivate din aceeași clasă abstractă sau interfață, fiecare obiect având un `ID` unic.

## Cerințe pentru următorul laborator
- Interfața cu utilizatorul va fi implementată sub forma unei aplicații în consolă cu meniu de utilizare.
- Interfața cu utilizatorul va permite efectuarea de operații CRUD (creare, citire, actualizare, ștergere - eng. create, read, update, delete) pentru cel puțin una din entitățile din domeniu (ex. `Mașină`).
-  Adăugați validări de bază (ex. obiectele din repository trebuie să aibă `ID` unic, un obiect nu a fost găsit în repository, validări legate de eventuale suprapuneri de date la programări și închirieri etc.) utilizând mecanismul de excepții din Java. Excepțiile aruncate vor fi prinse în interfața cu utilizatorul, unde utilizatorului i se va afișa un mesaj corespunzător.

## Enunțurile problemelor
1. Programările unui cabinet stomatologic. Entitățile din domeniul problemei sunt `Pacient` (**ID** : `int`, nume : `String`, prenume : `String`, vârstă : `int`) și `Programare` (**ID** : `int`, pacient : `Pacient`, data : `Date`, scopul programării : `String`). Fiecare programare are asociată exact un pacient, dar un pacient poate avea mai multe programări. Fiecare programare durează 60 minute. Două programări nu se pot suprapune.
2. Comenzi de torturi. Entitățile din domeniul problemei sunt `Comandă` (**ID** : `int`, tort : `List<Tort>`, data : `Date`) și `Tort` (**ID** : `int`, tipul tortului : `String`). Fiecare comandă are asociată cel puțin un tort. 
3. Închirieri de mașini. Entitățile din domeniul problemei sunt `Mașină` (**ID** : `int`, marcă : `String`, model : `String`) și `Închiriere` (**ID** : `int`, mașina : `Mașină`, data început : `Date`, data sfârșit : `Date`). Fiecare închiriere are asociată exact o mașină. O mașină poate avea înregistrate mai multe închirieri, dar acestea nu au voie să se suprapună ca timp.
4. Comenzi magazin produse electronice. Entitățile din domeniul problemei sunt `Produs` (**ID** : `int`, categorie : `String`, nume : `String`, și pret : `int`) și `Comanda` (**ID** : `int`, produse : `List<Produs>`, data livrare : `Date`). Fiecare comandă va fi asociată cu cel puțin un produs. Pot exista produse duplicat în cadrul unei comenzi.

## Bonus (0.1p)
Implementați o clasă generator pentru ID-urile obiectelor. Generatorul pornește de la valoarea 100, valoarea `ID`-ului generat crescând la fiecare apel cu valoarea 1. Valoarea ultimului `ID` generat va fi salvată într-un fișier text, pentru ca la repornirea programului valorile generate să fie în continuare unice și în creștere. 

