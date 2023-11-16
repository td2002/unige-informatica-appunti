/*Considerare la classe AltIterator<E> che fonde assieme due iteratori it1 e it2 di tipo Iterator<E> in
un nuovo iteratore altIt dello stesso tipo che genera i loro elementi alternandoli a partire da it1. Quando uno
dei due iteratori non ha piu elementi ´ altIt genera i rimanenti elementi dell’altro.
Esempio:
var it1 = ... // iteratore che restituisce 1, 2, 3
var it2 = ... // iteratore che restituisce 4, 5
var it = new AltIterator<>(it1, it2); // nuovo iteratore che alterna it1 e it2
while(it.hasNext())
System.out.println(it.next()); // stampa 1, 4, 2, 5, 3
it1 = ... // iteratore vuoto
it2 = ... // iteratore che restituisce 4, 5
it = new AltIterator<>(it1, it2); // nuovo iteratore che alterna it1 e it2
while(it.hasNext())
System.out.println(it.next()); // stampa 4, 5
it1 = ... // iteratore che restituisce 1, 2, 3
it2 = ... // iteratore vuoto
it = new AltIterator<>(it1, it2); // nuovo iteratore che alterna it1 e it2
while(it.hasNext())
System.out.println(it.next()); // stampa 1, 2, 3*/

Codice della classe CatIterator:
import java.util.Iterator;
import static java.util.Objects.requireNonNull;
public class AltIterator<E> implements Iterator<E> {
    private Iterator<E> first, second; // invariant: first != null and second != null
    public AltIterator(Iterator<E> first, Iterator<E> second) {
        this.first = requireNonNull(first);
        this.second = requireNonNull(second);
    }
    public boolean hasNext() {
        return (fist.hasNext() || second.hasNext());
    }

    public E next(){ 

        if(!first.hasNext())
            return second.next();

        if(!second.hasNext())
            return first.next();

        var tmp  = first;
        first = second;
        second = tmp;

        return second.next();
    }
}
//(a) completare il costruttore della classe AltIterator.
//(b) completare il metodo hasNext() della classe AltIterator.
//(c) completare il metodo next() della classe AltIterator.
