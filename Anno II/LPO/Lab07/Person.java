package lab07;

import static java.util.Objects.requireNonNull;
import static java.util.Objects.hash;

public class Person {

	private final String name, surname;
	private final long id;

	private static long requireNonNeg(long id) {
		if (id < 0)
			throw new IllegalArgumentException("Person's id cannot be negative");
		return id;
	}

	protected Person(String name, String surname, Long id) {
		this.name = requireNonNull(name);
		this.surname = requireNonNull(surname);
		this.id = requireNonNeg(id);
	}

	public static Person newOfNameSurnameId(String name, String surname, long id) {
		return new Person(name, surname, id);
	}

	public String getName() {
		return name;
	}

	public String getSurname() {
		return surname;
	}

	public long getId() {
		return id;
	}

	// two People objects are equal iff they have the same id
	@Override
	public final boolean equals(Object obj) {
	    if (this == obj) return true;
	    if (obj instanceof Person p) return p.id == this.id;
	    return false;
	}

	@Override
	public int hashCode() {
	    return hash(this.id);
	}

	@Override
	public String toString() {
		return name + "," + surname + "," + id;
	}

}
