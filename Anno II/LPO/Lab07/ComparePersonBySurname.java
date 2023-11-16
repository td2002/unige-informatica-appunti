package lab07;

import java.util.Comparator;

public class ComparePersonBySurname implements Comparator<Person> {

	// for people with the same surname the natural order on id is considered
	@Override
	public int compare(Person p1, Person p2) {
	    int r = p1.getSurname().compareTo(p2.getSurname());
	    if (r == 0)
	    	return (int) (p1.getId()-p2.getId());
	    return r;
	}

}