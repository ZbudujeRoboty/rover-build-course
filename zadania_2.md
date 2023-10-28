# Podstawy Arduino

## Zadanie 1.

**Utrztówrz program, który zamiga diodą nr 13. w Arduino.**
Dioda na wyjściu cyfrowym 13. jest wbudowana w płytkę i widać ją od góry płytki. W obszarze funkcji `void setup()` lub `viod loop()` stwórz program, który wykonuje dowolną sekwencje zapalania i gaszenia tej diody.

Komendy, które mogą okazać się przydatne:
```
pinMode(numer,OUTPUT);
digitalWrite(numer,LOW/HIGH);
dalay(czas_w_milisekundach);
```

## Zadanie 2.

**Do istniejącego programu dodaj definicję `#define` oraz co najmniej dwa komentarze do kodu.**
Aby poprawić czytelność twojego kodu, przed funkcją `void setup()` zdefiniuj numer pinu diody. Następnie, dodaj do twojego kodu conajmniej dwa komentarze - również zwiększające czytelność kodu dla osób trzecich.

Komendy, które mogą okazać się przydatne:
```
#define moja_nazwa numer
//jestem komentarzem i komputer mnie nie widzi ;)
```

## Zadanie 3.

**Do istniejącego programu dodaj zmienną globalną reprezentującą czas oczekiwania programu.**
Program będzie bardziej modularny i łatwiejszy w ulepszaniu przy zastosowaniu zmiennej. W tym celu posłużymy się typem liczby całkowitej `int` (od integer), którą zadeklarujemy jeszcze przed funkcją `void setup()`. Będzie to zmienna określająca ilość milisekund do odczekania przy każdym wywołaniu funkcji `delay(czas)`.

Komendy, które mogą okazać się przydatne:
```
int czas = XXX;
delay(czas);
```

## Zadanie 4.

**Do istniejącego programu dodaj prostą obsługę wyświetlacza (Monitor Portu Szeregowego UART)**
Wymyśl w jakich miejscach programu algorytm ma przekazywać użytkownikowi informacje na ekranie i jakie to będą konkretnie wiadomości. Ta opcja może się przydać przy bardziej rozbudowanych programach abyśmy przy testach, który fragment jest akurat wykonywany przez mikrokontroler.

Komendy, które mogą okazać się przydatne:
```
Serial.begin(9600);

Serial.println("siema!");
```

# Testy silników

## Zadanie 5a. - serwomechanizm

**Napisz krótką procedurę testową serwomechanizmu**
Za pomocą dostarczonego wzoru (template), napisz procedurę testowania serwomechanizmu. W tym przypadku będzie to test różnych kątów obrotu w wybranych odstępach czasowych.

## Zadanie 5b. - silnik DC

**Napisz krótką procedurę testową silnika DC**
Za pomocą dostarczonego wzoru (template), napisz procedurę testowania silnika DC. W tym przypadku będzie to test różnych kiedunków obrotu i prędkości obrotowch w wybranych odstępach czasowych.
