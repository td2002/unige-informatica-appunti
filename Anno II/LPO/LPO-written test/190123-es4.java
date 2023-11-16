
import static java.util.Objects.requireNonNull;
public class Leaf implements BDT {
    private final boolean value;
    public Leaf(boolean value) {
      this.value = value;
    }
    public <T> T accept(Visitor<T> v) {
      v.visitLeaf(value);
    }
}

public class InnerNode implements BDT {
    private final BDT left, right; // invariant: left,right != null
    public InnerNode(BDT left, BDT right) {
        this.left = requireNonNull(left);
        this.right = requireNonNull(right);
    }
    public <T> T accept(Visitor<T> v) {
        v.visitInnerNode(left, rigth);
    }
}

public interface Visitor<T> {
    T visitLeaf(boolean value);
    T visitInnerNode(BDT left, BDT right);
}
public interface Path {
    int size(); // lunghezza del cammino
    String get(int index); // elemento del cammino a livello index
}

public class GetValue implements Visitor<Boolean> {
    private final Path path; // invariant: path != null
    private int level = 0; // la visita inizia dal livello 0, ossia dalla radice
    public GetValue(Path path) {
        this.path = requireNonNull(path);
    }
    public Boolean visitLeaf(boolean value) {
        if(level < path.size())
            throw new IllegalStateException();
        return value;
    }
    public Boolean visitInnerNode(BDT left, BDT right) {

        if(level >= path.size())
            throw new IllegalStateException();

        if(path.get(level).equals("L")){
              level++;
              return left.accept(this);
        }
        else if(path.get(level).equals("R")){
              level++;
              return right.accept(this);
        }else
              throw new IllegalStateException();



  }
}
