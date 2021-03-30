# Zaawansowane programowania w C++

## Zestaw 1

_Szablony 1_ - szablony funkcji, szablony klas.

Na podstawie [wazniak.mimuw.edu.pl](http://wazniak.mimuw.edu.pl/index.php?title=Zaawansowane_CPP/Wykład_1:_Szablony_I)

Program `main.cpp` zawiera

- szablon funkcji `maksimum()`
- szablon funkcji `convert()` dedukującej typ argumentu
- pozatypowe parametry szablonu - funkcja `dot_product` obliczająca iloczyn skalarny wektorów
- szablon parametryzowany szablonem - funkcja typu `void f(C<K>)`
- typ stowarzyszony w implementacji szablonowego stosu

## Zestaw 2

_Programowanie uogólnione_ - polimorfizm dynamiczny i statyczny, kontenery STL, iteratory, generatory.

Na podstawie [wazniak.mimuw.edu.pl](http://wazniak.mimuw.edu.pl/index.php?title=Zaawansowane_CPP/Wyk%C5%82ad_2:_Programowanie_uog%C3%B3lnione)

Plik `polymorphism.cpp` zawiera przykład polimorfizmu dynamicznego oraz polimorfizmu statycznego (osiąganego przez szablon funkcji).

`accumulate.cpp` zawiera szablon funkcji `accumulate()`, która wylicza sumę wszystkich elementów kontenera STL w przedziale zadanych argumentami iteratorów.

W pliku `generator.cpp` znajduje się klasa `SequenceGen` - funktor generujący kolejne instancje zadanego typu powiększonego o zadany krok.
