package lab06_03_16;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class RangeTest {

    public static void main(String[] args) {
	Range r = new Range(3);
	for (int x : r)
	    for (int y : r)
		System.out.println(x + " " + y);
	/* prints
	 * 0 0
	 * 0 1
	 * 0 2
	 * 1 0
	 * 1 1
	 * 1 2
	 * 2 0
	 * 2 1
	 * 2 2
	 */
	
	System.out.println("- - - - - - - - - - -");
	var es2 = new Range(3);
	var it1 = es2.iterator();
	var it2 = es2.iterator();
	while (it1.hasNext()) {
		var x = it1.next();
		while (it2.hasNext()) {
			System.out.println(x + " " + it2.next());
		}
	}
	
	System.out.println("- - - - - - - - - - -");
	try {
		var es2b = new Range(3, 0);
		var it3 = es2b.iterator();
	} catch (NoSuchElementException e) {
		System.out.println("Range non valido, impossibile iterare!");
	}
	
	
    }
}