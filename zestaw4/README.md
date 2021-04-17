# Zadania

1. Zaimplementuj szablon funkcji sumującej elementy dla podanego zakresu wskaźników. Przygotowując odpowiednie klasy cech sum_traits dla każdego z typów (char, int, float, double) zadbaj o poprawność typu zmiennej total, która w szablonie sum przechowuje wartość kolejnych kroków sumowania.

2. Rozwiązać za pomocą klas cech również problem inicjalizacji zmiennej total.

3. Szablony funkcji nie dopuszczają stosowania parametrów domyślnych. Można to ograniczenie obejść za pomocą przeciążenia szablonu definiując szablon o mniejszej ilości argumentów, który zwraca wynik podstawienia domyślnych parametrów do bardziej ogólnego szablonu. Zmienić implementację funkcji sum tak aby podając odpowiednią klasę cech (sum_char) jako pierwszy z argumentów szablonu można było zażądać sumowania znaków char do zmiennej total również typu char. Równocześnie, w przypadku gdy nie jest podana klasa cech, szablon powinien działać tak jak w zad. 2.

4. Uogólnić funkcję sum, aby działała nie tylko ze wskaźnikami, ale i iteratorami. Widać, że tu użycie klas cech jest już niezbędne, musimy bowiem dowiedzieć się na obiekty jakiego typu wskazuje iterator. Nie można do tego celu użyć typów stowarzyszonych IT::value_type, bo jako iterator może zostać podstawiony zwykły wskaźnik. Dlatego w STL istnieje klasa iterator_traits, definiująca podstawowe typy dla każdego rodzaju iteratora. Korzystając z tej klasy zdefiniuj ogólny szablon funkcji sum.

5. Zapoznaj się z plikiem kategorie.cpp.(http://wazniak.mimuw.edu.pl/images/c/c4/Kategorie.cpp). Jest w nim przedstawiony sposób selekcji jednej spośród kilku implementacji algorytmu na podstawie możliwości oferowanych przez przekazany iterator; w tym konkretnym przykładzie rozróżniamy dwie grupy: iteratory o swobodnym dostępie oraz wszystkie inne. Rozszerz kod tak, aby wybierana była jedna z trzech możliwości: swobodny dostęp, dwukierunkowe, gorsze niż dwukierunkowe.
