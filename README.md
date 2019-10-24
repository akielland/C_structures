Prosjekt2
https://github.uio.no/IN1910/H19_project2_aasmusae_kielland

All execises were compiled and ran successfully.

Oppgave 1)
Compile commands: 
Code run commands: 

Oppgave 2)
Compile commands: 
Code run commands: 

Oppgave 3)

Get element i by index
ArrayList:  O(1); kan hente element ved hjelp peker+i. Denne operasjonen er konstant
LinkedList: O(i); må iterer frem til indeksert element

Insert at front
ArrayList:  O(n); må flytte alle elementer en minne adresse opp
LinkedList: O(1); må bytte head peker og legge inn next peker i ny node

Insert at back (aka append)
ArrayList:  O(1), O(n) ved resize; legge inn ny verdi på peker+n (hvis arrayen er for liten må kalle resize() som har kompleksitet O(n))
LinkedList: O(n); må iterere igjennom hele listen

Insert into middle of list
ArrayList:  O(n-i), O(n) ved resize; må flytte alle elmenter etter i en minneadresse opp (hvis arrayen er for liten må kalle resize() som har kompleksitet O(n))
LinkedList: O(i); må iterere til i

Remove element from front
ArrayList:  O(n); må flytte alle elmenter en minneadresse ned (shrink to fit er også O(n))
LinkedList: O(1); må bytte head peker til next node og slette gammel node

Remove element from back
ArrayList:  O(1), O(n) hvis kaller på shrink to fit; senke str med ett element er konstant (shrink to fit er også O(n))
LinkedList: O(n); må itere over hele listen

Remove element from middle
ArrayList:  O(n-i), O(n) hvis kaller på shrink to fit; må flytte alle elementer over i en ned (shrink to fit er også O(n))
LinkedList: O(i); må iterere til indexsert Node.

Print
ArrayList:  O(n); må printe ut en verdi fra hver minneadresse
LinkedList: O(n); må printe ut en verdi fra hver node


Oppgave 4g)

Compile commands: 
Code run commands:

L(68, 7) = 68
