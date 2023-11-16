/*3. Completare il seguente codice che implementa gli alberi di ricerca binari con nodi etichettati da numeri interi (con
la relazione d’ordine usuale) e la ricerca di un elemento nell’albero tramite visitor pattern.
Esempio:
var t = new Node(10,new Leaf(5),new Node(42,new Leaf(31),null));
assert t.accept(new Search(31)); // 31 `e un’etichetta contenuta nell’albero t
assert !t.accept(new Search(43)); // 43 non `e un’etichetta contenuta nell’albero t
assert !t.accept(new Search(30)); // 30 non `e un’etichetta contenuta nell’albero t
Definizione di albero binario di ricerca: Un albero binario di ricerca con nodi etichettati da numeri interi soddisfa le seguenti proprieta: ogni nodo ` v e etichettato da un numero intero ` i, le etichette dei nodi del sottoalbero
sinistro di v sono ≤ i, le etichette dei nodi del sottoalbero destro di v sono ≥ i.
1
Completare costruttori e metodi delle classi Leaf, Node e Search:*/

public interface Visitor<T> {
    T visitLeaf(int value);
    T visitNode(int value, BSTree left, BSTree right);
}
public abstract class BSTree {
    protected final int value;
    protected BSTree(int value){
      this.value = value;
    }
    public abstract <T> T accept(Visitor<T> v);
}
public class Leaf extends BSTree { // nodi foglia
    public Leaf(int value) {
        this.value = value;
     }
    @Override public <T> T accept(Visitor<T> v) {
        return v.visitLeaf(value);
     }
}
public class Node extends BSTree { // nodi interni
    private final BSTree left, right; // left, right possono contenere null, ma non entrambi
    public Node(int value, BSTree left, BSTree right) {
        this.value = value;
        if(!requireNonNull(left) && !requireNonNull(right))
              throw new IllegalStateException();
        else{
              this.left = left;
              this.right = right;
        }

    }
    @Override public <T> T accept(Visitor<T> v) {
          return v.visitInnerNode(value, left, right);
    }
}
public class Search implements Visitor<Boolean> { // ricerca l’elemento searchedValue nell’albero
    private final int searchedValue; // elemento da cercare
    public Search(int searchedValue) {
        this.searchedValue = searchedValue;
    }
    @Override public Boolean visitLeaf(int value) {
        return (searchedValue == value);
    }
    @Override public Boolean visitNode(int value, BSTree left, BSTree right) {

            if(searchedValue < value){
                if(!(left == null)
                    return left.accept(this);
                else
                    return false;
            }

            if(searchedValue > value){
                if(!(right == null)
                    return right.accept(this);
                else
                    return false;
            }

            if(searchedValue == value)
                return True;
    }
}
